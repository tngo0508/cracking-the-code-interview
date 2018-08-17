"""String compression problem"""
import unittest


def string_compression(string):
    """perform basic string compression using the counters of repeated
    characters
    """
    compressed = []
    counter = 0

    str_len = len(string)
    for i in range(str_len):
        if i != 0 and string[i] != string[i - 1]:
            compressed.append(string[i - 1] + str(counter))
            counter = 0
        counter += 1

    # add last repeated character
    compressed.append(string[-1] + str(counter))

    # returns original string if compressed string is not smaller
    return min(string, ''.join(compressed), key=len)


class Test(unittest.TestCase):
    """Test case"""
    data = [
        ('aabcccccaaa', 'a2b1c5a3'),
        ('abcdef', 'abcdef'),
    ]

    def test_string_compression(self):
        """testing"""
        for [test_string, expected] in self.data:
            actual = string_compression(test_string)
            self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
