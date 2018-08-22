import unittest


def parity(x):
    result = 0
    while x:
        result ^= x & 1
        x >>= 1
    return result


class Test(unittest.TestCase):
    """Test case"""
    data = [
        (1101, 1),
        (10001000, 0),
    ]

    def test_parity(self):
        """testing"""
        for [test_string, expected] in self.data:
            actual = parity(test_string)
            self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
