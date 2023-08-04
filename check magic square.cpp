#include <iostream>
#include <vector>

using namespace std;

bool isMagicSquare(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Calculate the sum of the first row, which will be our target sum
    int targetSum = 0;
    for (int j = 0; j < n; j++) {
        targetSum += matrix[0][j];
    }

    // Check if the sum of each row and each column is equal to the target sum
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        int colSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }

        if (rowSum != targetSum || colSum != targetSum) {
            return false;
        }
    }

    // Check the main diagonal
    int diagonalSum = 0;
    for (int i = 0; i < n; i++) {
        diagonalSum += matrix[i][i];
    }
    if (diagonalSum != targetSum) {
        return false;
    }

    // Check the secondary diagonal
    diagonalSum = 0;
    for (int i = 0; i < n; i++) {
        diagonalSum += matrix[i][n - 1 - i];
    }
    if (diagonalSum != targetSum) {
        return false;
    }

    // If all checks pass, the matrix is a magic square
    return true;
}

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the elements of the square matrix, row by row or column by column:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    if (isMagicSquare(matrix)) {
        cout << "The given matrix is a magic square." << endl;
    } else {
        cout << "The given matrix is not a magic square." << endl;
    }

    return 0;
}