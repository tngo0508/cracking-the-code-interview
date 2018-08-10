"""Implement an algorithm to determine if a string has all unique characters. What
if you cannot use additional data structure?
Answer: if no additional data structure is used, it will take O(N^2) run time
to do a linear search or O(N log N) run time in binary search"""
import unittest

def unique(string):
    """check if string contains unique characters or not
    """
    #Assuming character set is ASCII (128 characters)
    if len(string) > 128:
        return False

    char_set = [False for _ in range(128)]
    for char in string:
        val = ord(char) # convert char to ASCII code
        if char_set[val]:
            # char already found in string
            return False
        char_set[val] = True

    return True

class Test(unittest.TestCase):
    """testing"""
    dataT = [('abcd'), ('s4fad'), ('')]
    dataF = [('aabcd'), ('hb 6237hj=j ()')]

    def test_unique(self):
        """test function"""
        # true check
        for test_string in self.dataT:
            actual = unique(test_string)
            self.assertTrue(actual)
        # false check
        for test_string in self.dataF:
            actual = unique(test_string)
            self.assertFalse(actual)

if __name__ == '__main__':
    unittest.main()
