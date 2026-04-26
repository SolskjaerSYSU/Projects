#include "Game.h"

#include <exception>
#include <iostream>

int main() {
    try {
        Game game(9, 9, 10);
        game.run();
    } catch (const std::exception& error) {
        std::cerr << "Failed to start game: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
