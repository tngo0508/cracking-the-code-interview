"""write a method to repace all spaces in a string with '%20'. You may assume
that the string has sufficient space at the end to hold the additional characters,
and that you are given the "true" length of the string.
"""
import unittest

def urlify(string, length):
    """function replaces single space with %20 and removes trailing spaces"""
    new_idx = len(string)

    for i in reversed(range(length)):
        if string[i] == ' ':
            # replace spaces
            string[new_idx - 3: new_idx] = '%20'
            new_idx -= 3
        else:
            # move characters
            string[new_idx - 1] = string[i]
            new_idx -= 1

    return string


class Test(unittest.TestCase):
    """docstring for Test."""
    # using lists because python strings are immutable
    data = [
        (list('Mr John Smith    '), 13, list('Mr%20John%20Smith')),
        (list('hello world  '), 11, list('hello%20world'))
    ]

    def test_urlify(self):
        """testing"""
        for [test_string, length, expected] in self.data:
            actual = urlify(test_string, length)
            self.assertEqual(actual, expected)

if __name__ == '__main__':
    unittest.main()
