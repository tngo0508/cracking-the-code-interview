import unittest

def pal_perm(string):
    """checks if a string is a permutation of a palindrome or not"""
    table = [0 for _ in range(ord('z') - ord('a') + 1)]
    count_odd = 0
    for char in string:
        val_char = char_number(char)
        if val_char != -1:
            table[val_char] += 1
            if table[val_char] % 2:
                count_odd += 1
            else:
                count_odd -= 1

    return count_odd <= 1


def char_number(char):
    """convert char to number of index in table
    map each character to a number. a->0, b->1, c->2, etc"""
    val_a = ord('a')
    val_z = ord('z')
    val_upper_a = ord('A')
    val_upper_z = ord('Z')
    val = ord(char)

    if val_a <= val <= val_z:
        return val - val_a
    elif val_upper_a <= val <= val_upper_z:
        return val - val_upper_a
    return -1

class Test(unittest.TestCase):
    '''Test Cases'''
    data = [
        ('Tact Coa', True),
        ('jhsabckuj ahjsbckj', True),
        ('Able was I ere I saw Elba', True),
        ('So patient a nurse to nurse a patient so', False),
        ('Random Words', False),
        ('Not a Palindrome', False),
        ('no x in nixon', True),
        ('azAZ', True)]

    def test_pal_perm(self):
        """testing"""
        for [test_string, expected] in self.data:
            actual = pal_perm(test_string)
            self.assertEqual(actual, expected)


if __name__ == "__main__":
    unittest.main()
