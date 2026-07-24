#!/usr/bin/python3
# -*- coding: utf-8 -*-

class IntrospectResult:
    def __init__(self, serial_nums: list[str], arms_left: bool, arms_right: bool, legs: bool, hands: bool):
        self.serial_nums: list[str] = serial_nums
        self.arms_left: bool = arms_left
        self.arms_right: bool = arms_right
        self.legs: bool = legs
        self.hands: bool = hands

    def __str__(self):
        return f"TestResult{{nums:{self.serial_nums},results:{self.arms_left},{self.arms_right},{self.legs},{self.hands}]}}"

    def swap(self, i: int, j: int) -> list[str]:
        """交换序列号数组中指定位置的两个元素，并返回。

        :param i:
        :param j:
        :return: 互换位置后的序列号数组
        """

        rst = [x for x in self.serial_nums]
        tmp = rst[i]
        rst[i] = rst[j]
        rst[j] = tmp
        return rst

    def diff_nums(self, o: 'IntrospectResult') -> dict[int, int]:
        """返回发生变化的序列号的索引

        :param o: 另一个自检结果
        :return: 发生变化的序列号的索引
            { self 索引 : o 索引 }
        """

        rst = {}
        for index, sn in enumerate(self.serial_nums):
            o_idx = o.serial_nums.index(sn)
            if o_idx != index:
                rst[index] = o_idx
        return rst

    def diff_results(self, o: 'IntrospectResult') -> int:
        """返回发生变化的 results 的个数

        :param o: 另一个自检结果
        :return: 发生变化的 results 的个数
        """

        rst = 0
        if self.arms_left != o.arms_left:
            rst += 1
        if self.arms_right != o.arms_right:
            rst += 1
        if self.legs != o.legs:
            rst += 1
        if self.hands != o.hands:
            rst += 1
        return rst

    @staticmethod
    def analyze(indices: dict[str, list[int]], reports: list['IntrospectResult']) -> list[str] | None:
        if len(indices) == 0:
            return None

        last_rpt = reports[-1]
        print("-" * 64)
        print("         last report:", last_rpt)

        count = len(reports)
        for i in range(count - 1):
            rpt = reports[i]
            print("report idx:", i, "report:", rpt)
            diff_nums = last_rpt.diff_nums(rpt)
            diff_results = last_rpt.diff_results(rpt)
            print("diff_results:", diff_results, "diff_nums:", diff_nums)

            if len(diff_nums) != 2:
                continue

            diff_items = list(diff_nums.items())
            assert (diff_items[0][0] == diff_items[1][1])
            assert (diff_items[1][0] == diff_items[0][1])

            idx1 = diff_items[0][0]
            idx2 = diff_items[0][1]

            sn1 = last_rpt.serial_nums[idx1]
            sn2 = last_rpt.serial_nums[idx2]

            if diff_results == 2:
                # sn1 和 sn2 一定 『在 』idx1 和 idx2 处
                for _sn_ in [sn1, sn2]:
                    if _sn_ not in indices:
                        continue
                    for _idx_ in indices[_sn_][:]:
                        if _idx_ != idx1 and _idx_ != idx2:
                            indices[_sn_].remove(_idx_)

                # 其它序列号一定 『不在』 idx1 和 idx2 处
                for _sn_ in [x for x in indices.keys() if x != sn1 and x != sn2]:
                    for _idx_ in [idx1, idx2]:
                        if _idx_ in indices[_sn_]:
                            indices[_sn_].remove(_idx_)

            if diff_results == 0:
                # sn1 和 sn2 一定 『不在』 idx1 和 idx2 处
                for _sn_ in [sn1, sn2]:
                    if _sn_ not in indices:
                        continue
                    for _idx_ in [idx1, idx2]:
                        if _idx_ in indices[_sn_]:
                            indices[_sn_].remove(_idx_)

            for _k_, _v_ in indices.items():
                if len(_v_) == 1:
                    _idx_ = _v_[0]
                    # 其它序列号一定 『不在』 该索引处
                    for _k1_, _v1_ in indices.items():
                        if _k1_ == _k_:
                            if _idx_ in _v1_:
                                _v1_.remove(_idx_)

        success = False
        for _k_, _v_ in indices.items():
            if len(_v_) == 1:
                success = True
                break

        if success:
            rst = []
            for _k_, _v_ in indices.items():
                rst.append(_k_)
            for _k_, _v_ in indices.items():
                rst[_v_[0]] = _k_
            return rst

        return None
