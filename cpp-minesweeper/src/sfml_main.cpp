#include "SfmlApp.h"

#include <exception>
#include <iostream>

int main() {
    try {
        SfmlApp app;
        app.run();
    } catch (const std::exception& error) {
        std::cerr << "Failed to start SFML Minesweeper: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
