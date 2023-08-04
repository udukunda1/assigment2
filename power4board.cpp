#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLUMNS = 7;
const char EMPTY = ' ';
const char PLAYER = 'X';
const char COMPUTER = 'O';

class Power4 {
private:
    char board[ROWS][COLUMNS];

public:
    Power4() {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                board[i][j] = EMPTY;
            }
        }
    }

    void displayBoard() {
        cout << "-----------------------------\n";
        for (int i = 0; i < ROWS; i++) {
            cout << "|";
            for (int j = 0; j < COLUMNS; j++) {
                cout << " " << board[i][j] << " |";
            }
            cout << "\n-----------------------------\n";
        }
        cout << "  0   1   2   3   4   5   6\n";
    }

    bool isColumnFull(int col) {
        return board[0][col] != EMPTY;
    }

    bool isValidMove(int col) {
        return col >= 0 && col < COLUMNS && !isColumnFull(col);
    }

    void dropToken(int col, char token) {
        for (int i = ROWS - 1; i >= 0; i--) {
            if (board[i][col] == EMPTY) {
                board[i][col] = token;
                break;
            }
        }
    }

    bool checkWin(char token) {
        // Check for a win
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                // Check horizontally
                if (j + 3 < COLUMNS &&
                    board[i][j] == token &&
                    board[i][j + 1] == token &&
                    board[i][j + 2] == token &&
                    board[i][j + 3] == token) {
                    return true;
                }
                // Check vertically
                if (i + 3 < ROWS &&
                    board[i][j] == token &&
                    board[i + 1][j] == token &&
                    board[i + 2][j] == token &&
                    board[i + 3][j] == token) {
                    return true;
                }
                // Check diagonally (down-right)
                if (i + 3 < ROWS && j + 3 < COLUMNS &&
                    board[i][j] == token &&
                    board[i + 1][j + 1] == token &&
                    board[i + 2][j + 2] == token &&
                    board[i + 3][j + 3] == token) {
                    return true;
                }
                // Check diagonally (up-right)
                if (i - 3 >= 0 && j + 3 < COLUMNS &&
                    board[i][j] == token &&
                    board[i - 1][j + 1] == token &&
                    board[i - 2][j + 2] == token &&
                    board[i - 3][j + 3] == token) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isBoardFull() {
        // Check if the board is full
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (board[i][j] == EMPTY) {
                    return false;
                }
            }
        }
        return true;
    }

    int evaluateMove(int col, char token) {
        // Evaluate the move and return a score for the given token
        // (You can implement a more sophisticated evaluation function)
        return 0;
    }

    int findBestMove(char token) {
        int bestMove = -1;
        int bestScore = -1000;

        for (int col = 0; col < COLUMNS; col++) {
            if (isValidMove(col)) {
                int score = evaluateMove(col, token);
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = col;
                }
            }
        }

        return bestMove;
    }

    void playWithComputer() {
        char currentPlayer = PLAYER;

        while (true) {
            displayBoard();

            if (currentPlayer == PLAYER) {
                int playerMove;
                cout << "Player " << currentPlayer << ", enter column (0-6) to drop your token: ";
                cin >> playerMove;

                if (!isValidMove(playerMove)) {
                    cout << "Invalid move! Please choose a valid column.\n";
                    continue;
                }

                dropToken(playerMove, PLAYER);

                if (checkWin(PLAYER)) {
                    displayBoard();
                    cout << "Congratulations! Player " << currentPlayer << " wins!\n";
                    break;
                }
            } else {
                int computerMove = findBestMove(COMPUTER);
                dropToken(computerMove, COMPUTER);
                cout << "Computer dropped a token in column " << computerMove << endl;

                if (checkWin(COMPUTER)) {
                    displayBoard();
                    cout << "Computer wins! Better luck next time.\n";
                    break;
                }
            }

            if (isBoardFull()) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            currentPlayer = (currentPlayer == PLAYER) ? COMPUTER : PLAYER;
        }
    }
};

int main() {
    Power4 game;
    cout << "Welcome to Power4!\n";
    cout << "Player 'X', Computer 'O'\n";
    game.playWithComputer();
    return 0;
}
