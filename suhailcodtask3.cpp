#include <iostream>

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

    // Initialize the game board
    void initializeBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
    }

    // Print the current state of the board
    void printBoard() {
        std::cout << "  1 2 3\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << i + 1 << ' ';
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                if (j < 2) std::cout << '|';
            }
            std::cout << '\n';
            if (i < 2) std::cout << "  -----\n";
        }
    }

    // Check if the current player has won
    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }

        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }

        return false;
    }

    // Check if the board is full (draw)
    bool checkDraw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

public:
    TicTacToe() : currentPlayer('X') {
        initializeBoard();
    }

    void play() {
        int row, col;
        bool gameOver = false;

        while (!gameOver) {
            printBoard();
            std::cout << "Player " << currentPlayer << ", enter row and column (1-3): ";
            std::cin >> row >> col;
            --row; // Convert to 0-based index
            --col; // Convert to 0-based index

            if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
                std::cout << "Invalid move. Try again.\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if (checkWin()) {
                printBoard();
                std::cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                printBoard();
                std::cout << "It's a draw!\n";
                gameOver = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}