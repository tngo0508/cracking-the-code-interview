#include <iostream>

void nullifyRow(int ** matrix, int row, int col) {
    for (int j = 0; j < col; j++)
        matrix[row][j] = 0;
}

void nullifyCol(int ** matrix, int row, int col) {
    for (int i = 0; i < row; i++)
        matrix[i][col] = 0;
}

void nullifyMatrix(int ** matrix, int row, int col) {
    bool firstRow = false;

    for  (int i = 0; i < col; i++) {
        if (matrix[0][i] == 0) {
            firstRow = true;
            break;
        }
    }

    for (int i = 1; i < row; i++) {
        bool nullifyThisRow = false;
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                nullifyThisRow = true;
            }
        }
        if (nullifyThisRow)
            nullifyRow(matrix, i, col);
    }

    // We know which column to be nullify using information from previous step.
    for (int j = 0; j < col; j++) {
        if (matrix[0][j] == 0)
            nullifyCol(matrix, row, j);
    }

    // nullify the first row if it has zero
    if (firstRow)
        nullifyRow(matrix, 0, col);
}

void printMatrix(int ** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << '\n';
    }
    std::cout << '\n';
}
int main() {
    int row, col;
    std::cout << "Enter number of rows: ";
    std::cin >> row;
    std::cout << "Enter number of cols: ";
    std::cin >> col;
    int ** matrix = new int*[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }
    std::cout << "Provide MxN matrix " << '\n';
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << "Matrix before: " << '\n';
    printMatrix(matrix, row, col);
    nullifyMatrix(matrix, row, col);
    std::cout << "Matrix after: " << '\n';
    printMatrix(matrix, row, col);
    return 0;
}
