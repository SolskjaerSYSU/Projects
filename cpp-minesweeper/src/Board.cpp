#include "Board.h"

#include <algorithm>
#include <numeric>
#include <queue>
#include <stdexcept>

namespace {
constexpr int kNeighborOffsets[8][2] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1},  {1, 0},  {1, 1}
};
}

Board::Board(std::size_t rows, std::size_t cols, std::size_t mineCount)
    : rows_(rows),
      cols_(cols),
      mineCount_(mineCount),
      grid_(rows, std::vector<Cell>(cols)),
      rng_(std::random_device{}()) {
    if (rows_ == 0 || cols_ == 0) {
        throw std::invalid_argument("Board dimensions must be positive.");
    }

    if (mineCount_ >= rows_ * cols_) {
        throw std::invalid_argument("Mine count must be smaller than the number of cells.");
    }
}

void Board::reset() {
    grid_.assign(rows_, std::vector<Cell>(cols_));
    firstMove_ = true;
    exploded_ = false;
    explodedRow_ = 0;
    explodedCol_ = 0;
}

bool Board::reveal(std::size_t row, std::size_t col) {
    if (!inBounds(row, col)) {
        return false;
    }

    Cell& current = grid_[row][col];
    if (current.isRevealed || current.isFlagged) {
        return false;
    }

    if (firstMove_) {
        placeMines(row, col);
        calculateAdjacency();
        firstMove_ = false;
    }

    current.isRevealed = true;
    if (current.hasMine) {
        exploded_ = true;
        explodedRow_ = row;
        explodedCol_ = col;
        return true;
    }

    if (current.adjacentMines == 0) {
        floodReveal(row, col);
    }

    return true;
}

bool Board::toggleFlag(std::size_t row, std::size_t col) {
    if (!inBounds(row, col)) {
        return false;
    }

    Cell& current = grid_[row][col];
    if (current.isRevealed) {
        return false;
    }

    current.isFlagged = !current.isFlagged;
    return true;
}

bool Board::inBounds(std::size_t row, std::size_t col) const {
    return row < rows_ && col < cols_;
}

bool Board::hasWon() const {
    for (std::size_t row = 0; row < rows_; ++row) {
        for (std::size_t col = 0; col < cols_; ++col) {
            const Cell& current = grid_[row][col];
            if (!current.hasMine && !current.isRevealed) {
                return false;
            }
        }
    }
    return true;
}

bool Board::hasExploded() const {
    return exploded_;
}

bool Board::isFirstMove() const {
    return firstMove_;
}

std::size_t Board::flagCount() const {
    std::size_t total = 0;

    for (std::size_t row = 0; row < rows_; ++row) {
        for (std::size_t col = 0; col < cols_; ++col) {
            if (grid_[row][col].isFlagged) {
                ++total;
            }
        }
    }

    return total;
}

bool Board::isExplodedCell(std::size_t row, std::size_t col) const {
    return exploded_ && row == explodedRow_ && col == explodedCol_;
}

std::size_t Board::rows() const {
    return rows_;
}

std::size_t Board::cols() const {
    return cols_;
}

std::size_t Board::mineCount() const {
    return mineCount_;
}

const Cell& Board::cell(std::size_t row, std::size_t col) const {
    return grid_[row][col];
}

void Board::placeMines(std::size_t safeRow, std::size_t safeCol) {
    std::vector<std::size_t> positions(rows_ * cols_);
    std::iota(positions.begin(), positions.end(), 0);

    const std::size_t safeIndex = safeRow * cols_ + safeCol;
    positions.erase(positions.begin() + static_cast<std::ptrdiff_t>(safeIndex));
    std::shuffle(positions.begin(), positions.end(), rng_);

    for (std::size_t i = 0; i < mineCount_; ++i) {
        const std::size_t index = positions[i];
        const std::size_t row = index / cols_;
        const std::size_t col = index % cols_;
        grid_[row][col].hasMine = true;
    }
}

void Board::calculateAdjacency() {
    for (std::size_t row = 0; row < rows_; ++row) {
        for (std::size_t col = 0; col < cols_; ++col) {
            if (grid_[row][col].hasMine) {
                continue;
            }
            grid_[row][col].adjacentMines = countAdjacentMines(row, col);
        }
    }
}

void Board::floodReveal(std::size_t row, std::size_t col) {
    std::queue<std::pair<std::size_t, std::size_t>> pending;
    pending.push({row, col});

    while (!pending.empty()) {
        const std::pair<std::size_t, std::size_t> current = pending.front();
        pending.pop();

        const std::size_t currentRow = current.first;
        const std::size_t currentCol = current.second;

        for (const auto& offset : kNeighborOffsets) {
            const int nextRow = static_cast<int>(currentRow) + offset[0];
            const int nextCol = static_cast<int>(currentCol) + offset[1];

            if (nextRow < 0 || nextCol < 0) {
                continue;
            }

            const std::size_t neighborRow = static_cast<std::size_t>(nextRow);
            const std::size_t neighborCol = static_cast<std::size_t>(nextCol);
            if (!inBounds(neighborRow, neighborCol)) {
                continue;
            }

            Cell& neighbor = grid_[neighborRow][neighborCol];
            if (neighbor.isRevealed || neighbor.isFlagged || neighbor.hasMine) {
                continue;
            }

            neighbor.isRevealed = true;
            if (neighbor.adjacentMines == 0) {
                pending.push({neighborRow, neighborCol});
            }
        }
    }
}

int Board::countAdjacentMines(std::size_t row, std::size_t col) const {
    int total = 0;

    for (const auto& offset : kNeighborOffsets) {
        const int nextRow = static_cast<int>(row) + offset[0];
        const int nextCol = static_cast<int>(col) + offset[1];

        if (nextRow < 0 || nextCol < 0) {
            continue;
        }

        const std::size_t neighborRow = static_cast<std::size_t>(nextRow);
        const std::size_t neighborCol = static_cast<std::size_t>(nextCol);
        if (inBounds(neighborRow, neighborCol) && grid_[neighborRow][neighborCol].hasMine) {
            ++total;
        }
    }

    return total;
}
