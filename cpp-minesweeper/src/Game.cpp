#include "Game.h"

#include <iomanip>
#include <iostream>
#include <sstream>

Game::Game(std::size_t rows, std::size_t cols, std::size_t mines)
    : board_(rows, cols, mines) {}

void Game::run() {
    printWelcome();
    printHelp();

    std::string input;
    while (true) {
        printBoard(status_ == GameStatus::Lost);

        if (status_ == GameStatus::Won) {
            std::cout << "You cleared the board. Type 'n' for a new game or 'q' to quit.\n";
        } else if (status_ == GameStatus::Lost) {
            std::cout << "Boom! You hit a mine. Type 'n' for a new game or 'q' to quit.\n";
        }

        std::cout << "\nCommand > ";
        if (!std::getline(std::cin, input)) {
            break;
        }

        if (!handleCommand(input)) {
            break;
        }
    }
}

void Game::printWelcome() const {
    std::cout << "==== C++ Minesweeper ====\n";
    std::cout << "Board: " << board_.rows() << " x " << board_.cols()
              << " | Mines: " << board_.mineCount() << "\n\n";
}

void Game::printBoard(bool revealAll) const {
    std::cout << "\n   ";
    for (std::size_t col = 0; col < board_.cols(); ++col) {
        std::cout << std::setw(2) << col;
    }
    std::cout << '\n';

    for (std::size_t row = 0; row < board_.rows(); ++row) {
        std::cout << std::setw(2) << row << ' ';
        for (std::size_t col = 0; col < board_.cols(); ++col) {
            const Cell& current = board_.cell(row, col);
            char symbol = '.';

            if (revealAll && current.hasMine) {
                symbol = '*';
            } else if (current.isFlagged) {
                symbol = 'F';
            } else if (!current.isRevealed) {
                symbol = '.';
            } else if (current.hasMine) {
                symbol = '*';
            } else if (current.adjacentMines == 0) {
                symbol = ' ';
            } else {
                symbol = static_cast<char>('0' + current.adjacentMines);
            }

            std::cout << std::setw(2) << symbol;
        }
        std::cout << '\n';
    }
}

void Game::printHelp() const {
    std::cout << "Commands:\n";
    std::cout << "  r ROW COL  reveal a cell\n";
    std::cout << "  f ROW COL  place/remove a flag\n";
    std::cout << "  n          start a new game\n";
    std::cout << "  h          show help\n";
    std::cout << "  q          quit\n";
}

void Game::reset() {
    board_.reset();
    status_ = GameStatus::InProgress;
}

bool Game::handleCommand(const std::string& input) {
    std::istringstream stream(input);
    char command = '\0';
    stream >> command;

    if (!stream) {
        std::cout << "Please enter a command. Type 'h' for help.\n";
        return true;
    }

    if (command == 'q') {
        return false;
    }

    if (command == 'h') {
        printHelp();
        return true;
    }

    if (command == 'n') {
        reset();
        return true;
    }

    std::size_t row = 0;
    std::size_t col = 0;
    if (command == 'r' || command == 'f') {
        if (!(stream >> row >> col)) {
            std::cout << "Expected row and column, for example: r 3 4\n";
            return true;
        }

        if (!board_.inBounds(row, col)) {
            std::cout << "That position is outside the board.\n";
            return true;
        }
    }

    if (status_ != GameStatus::InProgress && command != 'n') {
        std::cout << "This round is finished. Type 'n' to start a new game.\n";
        return true;
    }

    if (command == 'r') {
        if (!board_.reveal(row, col)) {
            std::cout << "That cell cannot be revealed right now.\n";
            return true;
        }
        updateStatus();
        return true;
    }

    if (command == 'f') {
        if (!board_.toggleFlag(row, col)) {
            std::cout << "That cell cannot be flagged right now.\n";
            return true;
        }
        updateStatus();
        return true;
    }

    std::cout << "Unknown command. Type 'h' for help.\n";
    return true;
}

void Game::updateStatus() {
    if (board_.hasExploded()) {
        status_ = GameStatus::Lost;
    } else if (board_.hasWon()) {
        status_ = GameStatus::Won;
    } else {
        status_ = GameStatus::InProgress;
    }
}
