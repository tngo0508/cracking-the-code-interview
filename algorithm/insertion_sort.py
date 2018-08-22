import unittest


def insertion_sort(arr):
    """implementation of Insertion sort"""
    for i in range(1, len(arr)):
        key = arr[i]

        # Move elements of arr[0..i-1] that are greater than key, to one
        # position ahead of their current position
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    return arr


class Test(unittest.TestCase):
    """test case"""
    data = [
        ([12, 11, 13, 5, 6], [5, 6, 11, 12, 13]),
        ([2, 3, 1, 0, 7, 4], [0, 1, 2, 3, 4, 7]),
    ]

    def test_insertion_sort(self):
        """testing"""
        for [test_arr, expected] in self.data:
            actual = insertion_sort(test_arr)
            self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
