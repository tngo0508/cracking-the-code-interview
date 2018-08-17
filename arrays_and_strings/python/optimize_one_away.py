import unittest


def one_edit_away(str1, str2):
    """check if string is one edit away"""
    # lenth checks
    if abs(len(str1) - len(str2)) > 1:
        return False

    # get shorter and longer string
    short_str = str1 if len(str1) < len(str2) else str2
    long_str = str2 if len(str1) < len(str2) else str1

    idx1, idx2 = 0, 0
    found = False
    while idx1 < len(short_str) and idx2 < len(long_str):
        if short_str[idx1] != long_str[idx2]:
            # ensure that this is the first difference found
            if found:
                return False
            found = True
            # on replace, move shorter pointer
            if len(short_str) == len(long_str):
                idx1 += 1
        else:
            idx1 += 1  # if maching, move shorter pointer
        idx2 += 1  # always move pointer for longer string
    return True


class Test(unittest.TestCase):
    """docstring for test."""
    data = [
        ('pale', 'ple', True),
        ('pales', 'pale', True),
        ('pale', 'bale', True),
        ('pale', 'bake', False),
    ]

    def test_one_away(self):
        """testing"""
        for [test_s1, test_s2, expected] in self.data:
            actual = one_edit_away(test_s1, test_s2)
            self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
