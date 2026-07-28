# wire_connect_msgs — 自定义消息

> WireConnect 线缆连接比赛所需的 ROS2 自定义消息定义

---

## 消息列表

| 消息 | 用途 |
|------|------|
| `ArmTarget` | 手臂规划目标：位姿 + 线缆方向 + 元信息 |
| `PlugDetect` | 单个 USB-A 插头检测 (含 OBB 方向) |
| `PlugDetectArray` | 插头检测列表 |
| `PortDetect` | 单个 USB-A 母口检测 |
| `PortDetectArray` | 母口检测列表 |

## 依赖

- `geometry_msgs`
- `std_msgs`

## 使用

```xml
<!-- 在你的 package.xml 中: -->
<depend>wire_connect_msgs</depend>
```

```python
from wire_connect_msgs.msg import ArmTarget, PlugDetect, PlugDetectArray, PortDetect, PortDetectArray
```
