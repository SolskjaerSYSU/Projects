#pragma once

#include <cstddef>
#include <random>
#include <vector>

struct Cell {
    bool hasMine = false;
    bool isRevealed = false;
    bool isFlagged = false;
    int adjacentMines = 0;
};

class Board {
public:
    Board(std::size_t rows, std::size_t cols, std::size_t mineCount);

    void reset();
    bool reveal(std::size_t row, std::size_t col);
    bool toggleFlag(std::size_t row, std::size_t col);
    bool inBounds(std::size_t row, std::size_t col) const;
    bool hasWon() const;
    bool hasExploded() const;
    bool isFirstMove() const;
    std::size_t flagCount() const;
    bool isExplodedCell(std::size_t row, std::size_t col) const;

    std::size_t rows() const;
    std::size_t cols() const;
    std::size_t mineCount() const;
    const Cell& cell(std::size_t row, std::size_t col) const;

private:
    void placeMines(std::size_t safeRow, std::size_t safeCol);
    void calculateAdjacency();
    void floodReveal(std::size_t row, std::size_t col);
    int countAdjacentMines(std::size_t row, std::size_t col) const;

    std::size_t rows_;
    std::size_t cols_;
    std::size_t mineCount_;
    std::vector<std::vector<Cell>> grid_;
    bool firstMove_ = true;
    bool exploded_ = false;
    std::size_t explodedRow_ = 0;
    std::size_t explodedCol_ = 0;
    std::mt19937 rng_;
};
