import unittest
RED, WHITE, BLUE = range(3)


def dutch_flag_partition1(pivot_index, A):
    pivot = A[pivot_index]
    # First pass: group elements smaller than pivot.
    for i in range(len(A)):
        # Look for a smaller elements.
        for j in range(i + 1, len(A)):
            if A[j] < pivot:
                A[i], A[j] = A[j], A[i]
                break

    # Second pass: group elements larger than pivot.
    for i in reversed(range(len(A))):
        # Look for a larger element. Stop when we reach an element less than
        # pivot, since first pass has moved them to the start of A
        for j in reversed(range(i)):
            if A[j] > pivot:
                A[i], A[j] = A[j], A[i]
                break
    return A


def dutch_flag_partition2(pivot_index, A):
    pivot = A[pivot_index]
    # First pass: group elements smaller than pivot
    smaller = 0
    for i in range(len(A)):
        if A[i] < pivot:
            A[i], A[smaller] = A[smaller], A[i]
            smaller += 1
    # Second pass: group elements larger than pivot.
    larger = len(A) - 1
    for i in reversed(range(len(A))):
        if A[i] > pivot:
            A[i], A[larger] = A[larger], A[i]
            larger -= 1
    return A


class Test(unittest.TestCase):
    """Test case"""
    data1 = [
        ([0, 1, 2, 0, 2, 1, 1], 3, [0, 0, 1, 1, 2, 2, 1]),
        ([0, 1, 2, 0, 2, 1, 1], 2, [1, 0, 0, 1, 1, 2, 2]),
    ]

    data2 = [
        ([0, 1, 2, 0, 2, 1, 1], 3, [0, 0, 1, 2, 2, 1, 1]),
        ([0, 1, 2, 0, 2, 1, 1], 2, [0, 1, 0, 1, 1, 2, 2]),
    ]

    def test_dutch_flag_partition1(self):
        """testing"""
        for [test_arr, pivot_index, expected] in self.data1:
            actual = dutch_flag_partition1(pivot_index, test_arr)
            self.assertEqual(actual, expected)

    def test_dutch_flag_partition2(self):
        """testing"""
        for [test_arr, pivot_index, expected] in self.data2:
            actual = dutch_flag_partition2(pivot_index, test_arr)
            self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
