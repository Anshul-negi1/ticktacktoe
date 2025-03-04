#include<iostream>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
bool checkWinner(char *spaces, char player1, char player2);
bool checkTie(char *spaces);

int main() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player1 = 'X';
    char player2 = 'O';
    bool running = true;

    drawBoard(spaces);

    while (running) {
        std::cout << "Player 1's turn (X)\n";
        playerMove(spaces, player1);
        drawBoard(spaces);
        if (checkWinner(spaces, player1, player2) || checkTie(spaces)) break;

        std::cout << "Player 2's turn (O)\n";
        playerMove(spaces, player2);
        drawBoard(spaces);
        if (checkWinner(spaces, player1, player2) || checkTie(spaces)) break;
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}

void drawBoard(char *spaces) {
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}

void playerMove(char *spaces, char player) {
    int number;
    while (true) {
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a number between 1-9.\n";
            continue;
        }

        number--;
        if (number >= 0 && number < 9 && spaces[number] == ' ') {
            spaces[number] = player;
            break;
        } else {
            std::cout << "Invalid move! Choose an empty spot between 1-9.\n";
        }
    }
}

bool checkTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') return false;
    }
    std::cout << "IT'S A TIE!\n";
    return true;
}

bool checkWinner(char *spaces, char player1, char player2) {
    int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // Columns
        {0, 4, 8}, {2, 4, 6}              // Diagonals
    };

    for (auto &pattern : winPatterns) {
        if (spaces[pattern[0]] != ' ' &&
            spaces[pattern[0]] == spaces[pattern[1]] &&
            spaces[pattern[1]] == spaces[pattern[2]]) {
            
            if (spaces[pattern[0]] == player1) {
                std::cout << "PLAYER 1 (X) WINS!\n";
            } else {
                std::cout << "PLAYER 2 (O) WINS!\n";
            }
            return true;
        }
    }
    return false;
}
