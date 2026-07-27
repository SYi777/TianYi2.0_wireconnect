#!/usr/bin/env python3
"""JSON(labelme) → YOLO detect(ports) + YOLO OBB(plugs) 分开两个数据集."""
import json, os, random, shutil, sys

IMG_DIR = os.path.normpath(os.path.join(os.path.dirname(__file__), "..", "images"))
OUT_PORT = os.path.normpath(os.path.join(os.path.dirname(__file__), "..", "dataset_port"))
OUT_PLUG = os.path.normpath(os.path.join(os.path.dirname(__file__), "..", "dataset_plug_obb"))

def convert():
    jsons = [f for f in os.listdir(IMG_DIR) if f.endswith(".json")]
    pairs_port = []  # (image_name, txt_content)
    pairs_plug = []

    for jf in jsons:
        base = jf.replace(".json", "")
        img = base + ".jpg"
        if not os.path.exists(os.path.join(IMG_DIR, img)):
            continue
        d = json.load(open(os.path.join(IMG_DIR, jf)))
        h, w = d["imageHeight"], d["imageWidth"]
        port_lines = []
        plug_lines = []
        for s in d["shapes"]:
            pts = s["points"]
            if s.get("shape_type") == "rectangle":
                x1, y1 = pts[0]; x2, y2 = pts[1]
                cx = ((x1+x2)/2)/w; cy = ((y1+y2)/2)/h
                bw = abs(x2-x1)/w; bh = abs(y2-y1)/h
                port_lines.append(f"0 {cx:.6f} {cy:.6f} {bw:.6f} {bh:.6f}")
            elif "oriented" in s.get("shape_type", ""):
                # 4 corners → OBB format
                coords = []
                for p in pts:
                    coords.append(f"{p[0]/w:.6f}")
                    coords.append(f"{p[1]/h:.6f}")
                plug_lines.append(f"0 " + " ".join(coords))

        if port_lines:
            pairs_port.append((img, "\n".join(port_lines)))
        if plug_lines:
            pairs_plug.append((img, "\n".join(plug_lines)))

    print(f"port samples: {len(pairs_port)}  plug samples: {len(pairs_plug)}")

    # split and write
    for name, pairs, out_dir in [("port", pairs_port, OUT_PORT), ("plug_obb", pairs_plug, OUT_PLUG)]:
        random.seed(42)
        random.shuffle(pairs)
        split = int(len(pairs) * 0.8)
        for subset, subset_pairs in [("train", pairs[:split]), ("val", pairs[split:])]:
            img_d = os.path.join(out_dir, subset, "images")
            lbl_d = os.path.join(out_dir, subset, "labels")
            os.makedirs(img_d, exist_ok=True); os.makedirs(lbl_d, exist_ok=True)
            for img, txt in subset_pairs:
                shutil.copy2(os.path.join(IMG_DIR, img), os.path.join(img_d, img))
                base = img.replace(".jpg", ".txt")
                with open(os.path.join(lbl_d, base), "w") as f:
                    f.write(txt)
            print(f"  {name} {subset}: {len(subset_pairs)}")

    # write port data.yaml
    with open(os.path.join(OUT_PORT, "data.yaml"), "w") as f:
        f.write(f"path: {OUT_PORT}\ntrain: train/images\nval: val/images\nnames:\n  0: usb_a_port\nnc: 1\n")
    # write plug OBB data.yaml
    with open(os.path.join(OUT_PLUG, "data.yaml"), "w") as f:
        f.write(f"path: {OUT_PLUG}\ntrain: train/images\nval: val/images\nnames:\n  0: usb_a_plug\nnc: 1\n")

    print("done.")
    print(f"\n训练命令:")
    print(f"  yolo detect train data={OUT_PORT}/data.yaml model=yolov8n.pt epochs=100 imgsz=640 project={os.path.dirname(OUT_PORT)}/runs_port name=train")
    print(f"  yolo obb train data={OUT_PLUG}/data.yaml model=yolov8n-obb.pt epochs=100 imgsz=640 project={os.path.dirname(OUT_PLUG)}/runs_plug_obb name=train")

if __name__ == "__main__":
    convert()
