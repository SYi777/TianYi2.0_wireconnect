import unittest

from introspect_result import IntrospectResult


class IntrospectResultTestCase(unittest.TestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.sn_nums = [f"sn{i}" for i in range(4)]

    def setUp(self):
        self.indices = {x: [0, 1, 2, 3] for x in self.sn_nums}

    def test_same_results_two(self):
        """两个序列号的位置发生变化，两个值互换位置。
        """

        nums1 = [x for x in self.sn_nums]
        rpt1 = IntrospectResult(nums1, True, False, False, False)

        nums2 = rpt1.swap(0, 1)
        rpt2 = IntrospectResult(nums2, False, True, False, False)

        reports = [rpt1, rpt2]
        sn_list = IntrospectResult.analyze(self.indices, reports)
        self.assertEqual(True, sn_list is None)
        self.assertEqual([0, 1], self.indices["sn0"])
        self.assertEqual([0, 1], self.indices["sn1"])

    def test_results(self):
        nums1 = [x for x in self.sn_nums]
        rpt1 = IntrospectResult(nums1, True, False, False, False)
        reports = [rpt1]

        reports.append(
            IntrospectResult(
                rpt1.swap(0, 1),
                True, True, False, False
            )
        )

        sn_list = IntrospectResult.analyze(self.indices, reports)
        self.assertEqual(True, sn_list is None)
        self.assertEqual([0, 1, 2, 3], self.indices["sn0"])
        self.assertEqual([0, 1, 2, 3], self.indices["sn1"])
        self.assertEqual([0, 1, 2, 3], self.indices["sn2"])
        self.assertEqual([0, 1, 2, 3], self.indices["sn3"])

        reports.append(
            IntrospectResult(
                rpt1.swap(0, 2),
                False, False, False, False
            )
        )

        sn_list = IntrospectResult.analyze(self.indices, reports)
        self.assertEqual(True, sn_list is None)
        self.assertEqual([0, 1, 2, 3], self.indices["sn0"])
        self.assertEqual([0, 1, 2, 3], self.indices["sn1"])
        self.assertEqual([0, 1, 2, 3], self.indices["sn2"])
        self.assertEqual([0, 1, 2, 3], self.indices["sn3"])

        reports.append(
            IntrospectResult(
                rpt1.swap(0, 3),
                True, False, False, False
            )
        )

        sn_list = IntrospectResult.analyze(self.indices, reports)
        self.assertEqual(True, sn_list is None)
        self.assertEqual([1, 2], self.indices["sn0"])
        self.assertEqual([0, 1, 2, 3], self.indices["sn1"])
        self.assertEqual([0, 1, 2, 3], self.indices["sn2"])
        self.assertEqual([1, 2], self.indices["sn3"])

        reports.append(
            IntrospectResult(
                rpt1.swap(1, 2),
                False, False, False, False
            )
        )

        sn_list = IntrospectResult.analyze(self.indices, reports)
        self.assertEqual(True, sn_list is None)
        self.assertEqual([1, 2], self.indices["sn0"])
        self.assertEqual([0, 1, 2, 3], self.indices["sn1"])
        self.assertEqual([0, 1, 2, 3], self.indices["sn2"])
        self.assertEqual([1, 2], self.indices["sn3"])

        reports.append(
            IntrospectResult(
                rpt1.swap(1, 3),
                True, False, False, True
            )
        )

        sn_list = IntrospectResult.analyze(self.indices, reports)
        self.assertEqual(True, sn_list is None)
        self.assertEqual([1, 2], self.indices["sn0"])
        self.assertEqual([0, 1, 2, 3], self.indices["sn1"])
        self.assertEqual([0, 1, 2, 3], self.indices["sn2"])
        self.assertEqual([1, 2], self.indices["sn3"])


if __name__ == '__main__':
    unittest.main()
