#pragma once

#include "Board.h"

#include <string>

enum class GameStatus {
    InProgress,
    Won,
    Lost
};

class Game {
public:
    Game(std::size_t rows, std::size_t cols, std::size_t mines);

    void run();

private:
    void printWelcome() const;
    void printBoard(bool revealAll = false) const;
    void printHelp() const;
    void reset();
    bool handleCommand(const std::string& input);
    void updateStatus();

    Board board_;
    GameStatus status_ = GameStatus::InProgress;
};
