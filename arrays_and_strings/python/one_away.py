import unittest


def one_away(str1, str2):
    """check if string is one edit away
    The lengths of the strings will indicate which of these you need to check
    """
    if len(str1) == len(str2):
        return one_edit_replace(str1, str2)
    elif len(str1) + 1 == len(str2):
        return one_edit_insert(str1, str2)
    elif len(str1) - 1 == len(str2):
        return one_edit_insert(str2, str1)
    return False


def one_edit_replace(str1, str2):
    """check if string is one edit away by replacing a character"""
    found = False
    for char1, char2 in zip(str1, str2):
        if char1 != char2:
            if found:
                return False
            found = True
    return True


def one_edit_insert(str1, str2):
    """check if string is one edit away by inserting/removing a character"""
    found = False
    idx1, idx2 = 0, 0
    while idx1 < len(str1) and idx2 < len(str2):
        if str1[idx1] != str2[idx2]:
            if found:
                return False
            found = True
            idx2 += 1
        else:
            idx1 += 1
            idx2 += 1
    return True


class Test(unittest.TestCase):
    """docstring for Test."""
    data = [
        ('pale', 'ple', True),
        ('pales', 'pale', True),
        ('pale', 'bale', True),
        ('paleabc', 'pleabc', True),
        ('pale', 'ble', False),
        ('a', 'b', True),
        ('', 'd', True),
        ('d', 'de', True),
        ('pale', 'pale', True),
        ('pale', 'ple', True),
        ('ple', 'pale', True),
        ('pale', 'bale', True),
        ('pale', 'bake', False),
        ('pale', 'pse', False),
        ('ples', 'pales', True),
        ('pale', 'pas', False),
        ('pas', 'pale', False),
        ('pale', 'pkle', True),
        ('pkle', 'pable', False),
        ('pal', 'palks', False),
        ('palks', 'pal', False)
    ]

    def test_one_away(self):
        """testing"""
        for [test_s1, test_s2, expected] in self.data:
            actual = one_away(test_s1, test_s2)
            self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
