import unittest


def even_odd(A):
    """
    input: an array of integer
    output: an array with reordered entries so that even entries appear
    first
    """
    next_even, next_odd = 0, len(A) - 1
    while next_even < next_odd:
        if A[next_even] % 2 == 0:
            next_even += 1
        else:
            A[next_even], A[next_odd] = A[next_odd], A[next_even]
            next_odd -= 1
    return A


class Test(unittest.TestCase):
    """Testing"""
    data = [
        ([1, 0, 5, 6, 8, 7, 4, 3, 9], [4, 0, 8, 6, 7, 5, 3, 9, 1])
    ]

    def test_even_odd(self):
        for [test, expected] in self.data:
            actual = even_odd(test)
            self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
