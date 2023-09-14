#include <iostream>
using namespace std;
const int BOARD_SIZE = 3;

char board[BOARD_SIZE][BOARD_SIZE];
char currentPlayer = 'X';

// Function to initialize the game board
void InitializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the game board
void DisplayBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j];
            if (j < BOARD_SIZE - 1) {
                std::cout << " | ";
            }
        }
        cout << endl;
        if (i < BOARD_SIZE - 1) {
            cout << "---------\n";
        }
    }
    cout << endl;
}

// Function to check if the current player has won
bool CheckWin() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true; // Row win
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true; // Column win
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false;
}

// Function to check if the game is a draw
bool CheckDraw() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true; 
}

// Function to switch players
void SwitchPlayers() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    }
    else {
        currentPlayer = 'X';
    }
}

int main() {
    bool gameover = false;
    char playAgain;

    do {
        InitializeBoard();
        gameover = false;

        while (!gameover) {
            system("clear"); 
            DisplayBoard();
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            int row, col;
            cin >> row >> col;

            if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if (CheckWin()) {
                system("clear");
                DisplayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameover = true;
            }
            else if (CheckDraw()) {
                system("clear"); 
                DisplayBoard();
                cout << "It's a draw!\n";
                gameover = true;
            }
            else {
                SwitchPlayers();
            }
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
