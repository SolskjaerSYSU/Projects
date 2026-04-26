#pragma once

#include <cstddef>

struct GameConfig {
    const char* label;
    std::size_t rows;
    std::size_t cols;
    std::size_t mines;
};
