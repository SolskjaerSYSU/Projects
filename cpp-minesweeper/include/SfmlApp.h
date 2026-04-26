#pragma once

#include "Board.h"
#include "GameConfig.h"

#include <SFML/Graphics.hpp>

#include <array>
#include <chrono>
#include <string>
#include <vector>

enum class AppScreen {
    Menu,
    Playing
};

enum class RoundState {
    InProgress,
    Won,
    Lost
};

class BitmapLabel {
public:
    void draw(sf::RenderTarget& target,
              const std::string& text,
              sf::Vector2f position,
              float pixelSize,
              sf::Color color,
              bool centered = false) const;

private:
    const std::array<std::string, 7>& glyphFor(char character) const;
};

class SfmlApp {
public:
    SfmlApp();
    void run();

private:
    struct Button {
        sf::FloatRect bounds;
        std::string label;
    };

    struct Assets {
        sf::Texture hiddenTile;
        sf::Texture revealedTile;
        sf::Texture mine;
        sf::Texture flag;
    };

    bool loadAssets();
    bool loadTexture(sf::Texture& texture, const std::string& relativePath);
    void startGame(const GameConfig& config);
    void restartGame();
    void processEvents();
    void handleMousePress(sf::Vector2f mousePosition, sf::Mouse::Button button);
    void handleMenuClick(sf::Vector2f mousePosition);
    void handleGameClick(sf::Vector2f mousePosition, sf::Mouse::Button button);
    void updateRoundState();

    void render();
    void drawBackground();
    void drawMenu();
    void drawGame();
    void drawButton(const Button& button, const sf::Color& fillColor, const sf::Color& outlineColor);
    void drawPanel();
    void drawBoard();
    void drawCell(std::size_t row, std::size_t col, sf::Vector2f topLeft);
    void drawStatusBanner();

    sf::Vector2f boardOrigin() const;
    sf::FloatRect boardBounds() const;
    Button menuButton() const;
    Button resetButton() const;
    std::string minesLabel() const;
    std::string timerLabel() const;
    int elapsedSeconds() const;
    sf::Color numberColor(int value) const;

    static const std::array<GameConfig, 3> kDifficulties;

    sf::RenderWindow window_;
    Assets assets_;
    BitmapLabel bitmapLabel_;
    AppScreen screen_ = AppScreen::Menu;
    RoundState roundState_ = RoundState::InProgress;
    GameConfig currentConfig_;
    Board board_;
    std::vector<Button> difficultyButtons_;
    float cellSize_ = 44.0f;
    float topPanelHeight_ = 130.0f;
    std::chrono::steady_clock::time_point roundStart_;
    int frozenElapsedSeconds_ = 0;
};
