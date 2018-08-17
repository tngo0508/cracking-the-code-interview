"""given two string, write a method to decide if one is permutation of the other"""
import unittest
from collections import Counter

def check_permutation(str1, str2):
    """check permutation"""
    if len(str1) != len(str2):
        return False
    counter = Counter()
    for char in str1:
        counter[char] += 1
    for char in str2:
        if counter[char] == 0:
            return False
        counter[char] -= 1
    return True

class Test(unittest.TestCase):
    """docstring for Test."""
    dataT = (
        ('abcd', 'badc'),
        ('123456', '645321'),
        ('webc123', '213cbwe'),
    )
    dataF = (
        ('abcd', 'eadbl'),
        ('2315', '1234'),
        ('dbcw', 'bcwd5'),
    )

    def test_cp(self):
        """testing"""
        # true check
        for test_string in self.dataT:
            result = check_permutation(*test_string)
            self.assertTrue(result)
        # false check
        for test_string in self.dataF:
            result = check_permutation(*test_string)
            self.assertFalse(result)


if __name__ == '__main__':
    unittest.main()
