import unittest

def rotate_matrix(matrix):
    """rotate a matrix 90 degrees clockwise"""
    matrix_length = len(matrix)
    for layer in range(matrix_length / 2):
        first, last = layer, matrix_length-layer-1
        for i in range(first, last):
            # offset = i - first
            # save top
            top = matrix[layer][i]

            # left->top
            matrix[layer][i] = matrix[-i-1][layer]

            # bottom->left
            matrix[-i-1][layer] = matrix[-layer-1][-i-1]

            # right->bottom
            matrix[-layer-1][-i-1] = matrix[i][-layer-1]

            # top->right
            matrix[i][-layer-1] = top
    return matrix


class Test(unittest.TestCase):
    """test cases"""
    data = [
        ([
            [1, 2, 3, 4, 5],
            [6, 7, 8, 9, 10],
            [11, 12, 13, 14, 15],
            [16, 17, 18, 19, 20],
            [21, 22, 23, 24, 25]
        ], [
            [21, 16, 11, 6, 1],
            [22, 17, 12, 7, 2],
            [23, 18, 13, 8, 3],
            [24, 19, 14, 9, 4],
            [25, 20, 15, 10, 5]
        ])
    ]

    def test_rotate_matrix(self):
        """testing"""
        for [test_matrix, expected] in self.data:
            actual = rotate_matrix(test_matrix)
            self.assertEqual(actual, expected)


if __name__ == '__main__':
    unittest.main()
