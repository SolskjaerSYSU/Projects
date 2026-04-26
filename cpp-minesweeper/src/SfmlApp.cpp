#include "SfmlApp.h"

#include <algorithm>
#include <cctype>
#include <filesystem>
#include <stdexcept>

namespace {
const std::array<std::string, 7> kUnknownGlyph = {
    "00000",
    "00100",
    "00100",
    "00100",
    "00000",
    "00100",
    "00000"
};

const std::array<std::string, 7> kSpaceGlyph = {
    "00000",
    "00000",
    "00000",
    "00000",
    "00000",
    "00000",
    "00000"
};

const std::array<std::string, 7> kColonGlyph = {
    "00000",
    "00100",
    "00100",
    "00000",
    "00100",
    "00100",
    "00000"
};

const std::array<std::string, 7> kHyphenGlyph = {
    "00000",
    "00000",
    "00000",
    "11111",
    "00000",
    "00000",
    "00000"
};

const std::array<std::string, 7> kDigit0 = {
    "01110",
    "10001",
    "10011",
    "10101",
    "11001",
    "10001",
    "01110"
};

const std::array<std::string, 7> kDigit1 = {
    "00100",
    "01100",
    "00100",
    "00100",
    "00100",
    "00100",
    "01110"
};

const std::array<std::string, 7> kDigit2 = {
    "01110",
    "10001",
    "00001",
    "00010",
    "00100",
    "01000",
    "11111"
};

const std::array<std::string, 7> kDigit3 = {
    "11110",
    "00001",
    "00001",
    "01110",
    "00001",
    "00001",
    "11110"
};

const std::array<std::string, 7> kDigit4 = {
    "00010",
    "00110",
    "01010",
    "10010",
    "11111",
    "00010",
    "00010"
};

const std::array<std::string, 7> kDigit5 = {
    "11111",
    "10000",
    "11110",
    "00001",
    "00001",
    "10001",
    "01110"
};

const std::array<std::string, 7> kDigit6 = {
    "00110",
    "01000",
    "10000",
    "11110",
    "10001",
    "10001",
    "01110"
};

const std::array<std::string, 7> kDigit7 = {
    "11111",
    "00001",
    "00010",
    "00100",
    "01000",
    "01000",
    "01000"
};

const std::array<std::string, 7> kDigit8 = {
    "01110",
    "10001",
    "10001",
    "01110",
    "10001",
    "10001",
    "01110"
};

const std::array<std::string, 7> kDigit9 = {
    "01110",
    "10001",
    "10001",
    "01111",
    "00001",
    "00010",
    "11100"
};

const std::array<std::string, 7> kLetterA = {
    "01110",
    "10001",
    "10001",
    "11111",
    "10001",
    "10001",
    "10001"
};

const std::array<std::string, 7> kLetterB = {
    "11110",
    "10001",
    "10001",
    "11110",
    "10001",
    "10001",
    "11110"
};

const std::array<std::string, 7> kLetterC = {
    "01111",
    "10000",
    "10000",
    "10000",
    "10000",
    "10000",
    "01111"
};

const std::array<std::string, 7> kLetterD = {
    "11110",
    "10001",
    "10001",
    "10001",
    "10001",
    "10001",
    "11110"
};

const std::array<std::string, 7> kLetterE = {
    "11111",
    "10000",
    "10000",
    "11110",
    "10000",
    "10000",
    "11111"
};

const std::array<std::string, 7> kLetterF = {
    "11111",
    "10000",
    "10000",
    "11110",
    "10000",
    "10000",
    "10000"
};

const std::array<std::string, 7> kLetterG = {
    "01111",
    "10000",
    "10000",
    "10011",
    "10001",
    "10001",
    "01110"
};

const std::array<std::string, 7> kLetterH = {
    "10001",
    "10001",
    "10001",
    "11111",
    "10001",
    "10001",
    "10001"
};

const std::array<std::string, 7> kLetterI = {
    "11111",
    "00100",
    "00100",
    "00100",
    "00100",
    "00100",
    "11111"
};

const std::array<std::string, 7> kLetterJ = {
    "00111",
    "00010",
    "00010",
    "00010",
    "00010",
    "10010",
    "01100"
};

const std::array<std::string, 7> kLetterK = {
    "10001",
    "10010",
    "10100",
    "11000",
    "10100",
    "10010",
    "10001"
};

const std::array<std::string, 7> kLetterL = {
    "10000",
    "10000",
    "10000",
    "10000",
    "10000",
    "10000",
    "11111"
};

const std::array<std::string, 7> kLetterM = {
    "10001",
    "11011",
    "10101",
    "10101",
    "10001",
    "10001",
    "10001"
};

const std::array<std::string, 7> kLetterN = {
    "10001",
    "11001",
    "10101",
    "10011",
    "10001",
    "10001",
    "10001"
};

const std::array<std::string, 7> kLetterO = {
    "01110",
    "10001",
    "10001",
    "10001",
    "10001",
    "10001",
    "01110"
};

const std::array<std::string, 7> kLetterP = {
    "11110",
    "10001",
    "10001",
    "11110",
    "10000",
    "10000",
    "10000"
};

const std::array<std::string, 7> kLetterQ = {
    "01110",
    "10001",
    "10001",
    "10001",
    "10101",
    "10010",
    "01101"
};

const std::array<std::string, 7> kLetterR = {
    "11110",
    "10001",
    "10001",
    "11110",
    "10100",
    "10010",
    "10001"
};

const std::array<std::string, 7> kLetterS = {
    "01111",
    "10000",
    "10000",
    "01110",
    "00001",
    "00001",
    "11110"
};

const std::array<std::string, 7> kLetterT = {
    "11111",
    "00100",
    "00100",
    "00100",
    "00100",
    "00100",
    "00100"
};

const std::array<std::string, 7> kLetterU = {
    "10001",
    "10001",
    "10001",
    "10001",
    "10001",
    "10001",
    "01110"
};

const std::array<std::string, 7> kLetterV = {
    "10001",
    "10001",
    "10001",
    "10001",
    "10001",
    "01010",
    "00100"
};

const std::array<std::string, 7> kLetterW = {
    "10001",
    "10001",
    "10001",
    "10101",
    "10101",
    "10101",
    "01010"
};

const std::array<std::string, 7> kLetterX = {
    "10001",
    "10001",
    "01010",
    "00100",
    "01010",
    "10001",
    "10001"
};

const std::array<std::string, 7> kLetterY = {
    "10001",
    "10001",
    "01010",
    "00100",
    "00100",
    "00100",
    "00100"
};

const std::array<std::string, 7> kLetterZ = {
    "11111",
    "00001",
    "00010",
    "00100",
    "01000",
    "10000",
    "11111"
};
}

const std::array<GameConfig, 3> SfmlApp::kDifficulties = {{
    {"BEGINNER", 9, 9, 10},
    {"INTERMEDIATE", 16, 16, 40},
    {"EXPERT", 16, 30, 99}
}};

void BitmapLabel::draw(sf::RenderTarget& target,
                       const std::string& text,
                       sf::Vector2f position,
                       float pixelSize,
                       sf::Color color,
                       bool centered) const {
    const float glyphWidth = 5.0f * pixelSize;
    const float spacing = pixelSize;
    float totalWidth = 0.0f;

    if (!text.empty()) {
        totalWidth = static_cast<float>(text.size()) * glyphWidth +
                     static_cast<float>(text.size() - 1) * spacing;
    }

    if (centered) {
        position.x -= totalWidth / 2.0f;
    }

    sf::RectangleShape pixel({pixelSize, pixelSize});
    pixel.setFillColor(color);

    for (char character : text) {
        const auto& glyph = glyphFor(character);
        for (std::size_t row = 0; row < glyph.size(); ++row) {
            for (std::size_t col = 0; col < glyph[row].size(); ++col) {
                if (glyph[row][col] != '1') {
                    continue;
                }

                pixel.setPosition(position.x + static_cast<float>(col) * pixelSize,
                                  position.y + static_cast<float>(row) * pixelSize);
                target.draw(pixel);
            }
        }

        position.x += glyphWidth + spacing;
    }
}

const std::array<std::string, 7>& BitmapLabel::glyphFor(char character) const {
    switch (static_cast<char>(std::toupper(static_cast<unsigned char>(character)))) {
        case ' ': return kSpaceGlyph;
        case ':': return kColonGlyph;
        case '-': return kHyphenGlyph;
        case '0': return kDigit0;
        case '1': return kDigit1;
        case '2': return kDigit2;
        case '3': return kDigit3;
        case '4': return kDigit4;
        case '5': return kDigit5;
        case '6': return kDigit6;
        case '7': return kDigit7;
        case '8': return kDigit8;
        case '9': return kDigit9;
        case 'A': return kLetterA;
        case 'B': return kLetterB;
        case 'C': return kLetterC;
        case 'D': return kLetterD;
        case 'E': return kLetterE;
        case 'F': return kLetterF;
        case 'G': return kLetterG;
        case 'H': return kLetterH;
        case 'I': return kLetterI;
        case 'J': return kLetterJ;
        case 'K': return kLetterK;
        case 'L': return kLetterL;
        case 'M': return kLetterM;
        case 'N': return kLetterN;
        case 'O': return kLetterO;
        case 'P': return kLetterP;
        case 'Q': return kLetterQ;
        case 'R': return kLetterR;
        case 'S': return kLetterS;
        case 'T': return kLetterT;
        case 'U': return kLetterU;
        case 'V': return kLetterV;
        case 'W': return kLetterW;
        case 'X': return kLetterX;
        case 'Y': return kLetterY;
        case 'Z': return kLetterZ;
        default: return kUnknownGlyph;
    }
}

SfmlApp::SfmlApp()
    : window_(sf::VideoMode(1500, 980), "C++ Minesweeper V2"),
      currentConfig_(kDifficulties[0]),
      board_(currentConfig_.rows, currentConfig_.cols, currentConfig_.mines) {
    window_.setFramerateLimit(60);
    if (!loadAssets()) {
        throw std::runtime_error("Failed to load GUI assets from assets/images.");
    }

    const float buttonWidth = 440.0f;
    const float buttonHeight = 92.0f;
    const float left = (static_cast<float>(window_.getSize().x) - buttonWidth) / 2.0f;
    const float firstTop = 340.0f;
    const float gap = 28.0f;

    for (std::size_t i = 0; i < kDifficulties.size(); ++i) {
        difficultyButtons_.push_back({
            sf::FloatRect(left, firstTop + static_cast<float>(i) * (buttonHeight + gap), buttonWidth, buttonHeight),
            kDifficulties[i].label
        });
    }

    startGame(currentConfig_);
    screen_ = AppScreen::Menu;
}

void SfmlApp::run() {
    while (window_.isOpen()) {
        processEvents();
        render();
    }
}

bool SfmlApp::loadAssets() {
    return loadTexture(assets_.hiddenTile, "assets/images/tile_hidden.png") &&
           loadTexture(assets_.revealedTile, "assets/images/tile_revealed.png") &&
           loadTexture(assets_.mine, "assets/images/icon_mine.png") &&
           loadTexture(assets_.flag, "assets/images/icon_flag.png");
}

bool SfmlApp::loadTexture(sf::Texture& texture, const std::string& relativePath) {
    namespace fs = std::filesystem;

    const fs::path current = fs::current_path();
    const std::array<fs::path, 4> candidates = {{
        current / relativePath,
        current / ".." / relativePath,
        current / ".." / ".." / relativePath,
        current / ".." / ".." / ".." / relativePath
    }};

    for (const auto& candidate : candidates) {
        std::error_code error;
        if (fs::exists(candidate, error) && texture.loadFromFile(candidate.string())) {
            texture.setSmooth(true);
            return true;
        }
    }

    return false;
}

void SfmlApp::startGame(const GameConfig& config) {
    currentConfig_ = config;
    board_ = Board(config.rows, config.cols, config.mines);
    roundState_ = RoundState::InProgress;
    roundStart_ = std::chrono::steady_clock::now();
    frozenElapsedSeconds_ = 0;

    const float availableWidth = static_cast<float>(window_.getSize().x) - 120.0f;
    const float availableHeight = static_cast<float>(window_.getSize().y) - topPanelHeight_ - 90.0f;
    const float widthCell = availableWidth / static_cast<float>(config.cols);
    const float heightCell = availableHeight / static_cast<float>(config.rows);
    cellSize_ = std::max(26.0f, std::min(46.0f, std::min(widthCell, heightCell)));
}

void SfmlApp::restartGame() {
    startGame(currentConfig_);
}

void SfmlApp::processEvents() {
    sf::Event event{};
    while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window_.close();
        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            screen_ = AppScreen::Menu;
        } else if (event.type == sf::Event::MouseButtonPressed) {
            handleMousePress(window_.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y}),
                             event.mouseButton.button);
        }
    }
}

void SfmlApp::handleMousePress(sf::Vector2f mousePosition, sf::Mouse::Button button) {
    if (screen_ == AppScreen::Menu) {
        if (button == sf::Mouse::Left) {
            handleMenuClick(mousePosition);
        }
        return;
    }

    handleGameClick(mousePosition, button);
}

void SfmlApp::handleMenuClick(sf::Vector2f mousePosition) {
    for (std::size_t i = 0; i < difficultyButtons_.size(); ++i) {
        if (difficultyButtons_[i].bounds.contains(mousePosition.x, mousePosition.y)) {
            startGame(kDifficulties[i]);
            screen_ = AppScreen::Playing;
            return;
        }
    }
}

void SfmlApp::handleGameClick(sf::Vector2f mousePosition, sf::Mouse::Button button) {
    if (menuButton().bounds.contains(mousePosition.x, mousePosition.y)) {
        screen_ = AppScreen::Menu;
        return;
    }

    if (resetButton().bounds.contains(mousePosition.x, mousePosition.y)) {
        restartGame();
        return;
    }

    if (!boardBounds().contains(mousePosition.x, mousePosition.y) || roundState_ != RoundState::InProgress) {
        return;
    }

    const sf::Vector2f origin = boardOrigin();
    const std::size_t col = static_cast<std::size_t>((mousePosition.x - origin.x) / cellSize_);
    const std::size_t row = static_cast<std::size_t>((mousePosition.y - origin.y) / cellSize_);
    if (!board_.inBounds(row, col)) {
        return;
    }

    if (button == sf::Mouse::Left) {
        board_.reveal(row, col);
    } else if (button == sf::Mouse::Right) {
        board_.toggleFlag(row, col);
    }

    updateRoundState();
}

void SfmlApp::updateRoundState() {
    const RoundState previousState = roundState_;

    if (board_.hasExploded()) {
        roundState_ = RoundState::Lost;
    } else if (board_.hasWon()) {
        roundState_ = RoundState::Won;
    } else {
        roundState_ = RoundState::InProgress;
    }

    if (previousState == RoundState::InProgress && roundState_ != RoundState::InProgress) {
        frozenElapsedSeconds_ = static_cast<int>(
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::steady_clock::now() - roundStart_).count());
    }
}

void SfmlApp::render() {
    window_.clear();
    drawBackground();

    if (screen_ == AppScreen::Menu) {
        drawMenu();
    } else {
        drawGame();
    }

    window_.display();
}

void SfmlApp::drawBackground() {
    sf::RectangleShape topGlow({static_cast<float>(window_.getSize().x), 300.0f});
    topGlow.setFillColor(sf::Color(232, 242, 255));
    window_.draw(topGlow);

    sf::RectangleShape lower({static_cast<float>(window_.getSize().x), static_cast<float>(window_.getSize().y) - 300.0f});
    lower.setPosition(0.0f, 300.0f);
    lower.setFillColor(sf::Color(242, 238, 225));
    window_.draw(lower);

    sf::CircleShape accentA(190.0f);
    accentA.setFillColor(sf::Color(210, 224, 240, 120));
    accentA.setPosition(90.0f, 80.0f);
    window_.draw(accentA);

    sf::CircleShape accentB(220.0f);
    accentB.setFillColor(sf::Color(241, 205, 155, 100));
    accentB.setPosition(1080.0f, 580.0f);
    window_.draw(accentB);
}

void SfmlApp::drawMenu() {
    bitmapLabel_.draw(window_, "MINESWEEPER", {static_cast<float>(window_.getSize().x) / 2.0f, 130.0f}, 12.0f, sf::Color(27, 45, 74), true);
    bitmapLabel_.draw(window_, "CHOOSE DIFFICULTY", {static_cast<float>(window_.getSize().x) / 2.0f, 235.0f}, 5.0f, sf::Color(98, 80, 48), true);

    for (std::size_t i = 0; i < difficultyButtons_.size(); ++i) {
        const sf::Color fills[3] = {
            sf::Color(165, 210, 142),
            sf::Color(241, 196, 109),
            sf::Color(224, 118, 102)
        };

        drawButton(difficultyButtons_[i], fills[i], sf::Color(61, 55, 46));

        const GameConfig& config = kDifficulties[i];
        bitmapLabel_.draw(window_,
                          difficultyButtons_[i].label,
                          {difficultyButtons_[i].bounds.left + difficultyButtons_[i].bounds.width / 2.0f,
                           difficultyButtons_[i].bounds.top + 18.0f},
                          4.0f,
                          sf::Color(33, 33, 33),
                          true);

        const std::string details = std::to_string(config.rows) + "X" + std::to_string(config.cols) +
                                    "  MINES " + std::to_string(config.mines);
        bitmapLabel_.draw(window_,
                          details,
                          {difficultyButtons_[i].bounds.left + difficultyButtons_[i].bounds.width / 2.0f,
                           difficultyButtons_[i].bounds.top + 54.0f},
                          2.6f,
                          sf::Color(59, 59, 59),
                          true);
    }

    bitmapLabel_.draw(window_,
                      "LEFT CLICK REVEALS  RIGHT CLICK FLAGS  ESC RETURNS TO MENU",
                      {static_cast<float>(window_.getSize().x) / 2.0f, 760.0f},
                      2.8f,
                      sf::Color(72, 72, 72),
                      true);
}

void SfmlApp::drawGame() {
    drawPanel();
    drawBoard();
    drawStatusBanner();
}

void SfmlApp::drawButton(const Button& button, const sf::Color& fillColor, const sf::Color& outlineColor) {
    sf::RectangleShape background({button.bounds.width, button.bounds.height});
    background.setPosition({button.bounds.left, button.bounds.top});
    background.setFillColor(fillColor);
    background.setOutlineThickness(4.0f);
    background.setOutlineColor(outlineColor);
    window_.draw(background);

    sf::RectangleShape highlight({button.bounds.width - 12.0f, 10.0f});
    highlight.setPosition({button.bounds.left + 6.0f, button.bounds.top + 6.0f});
    highlight.setFillColor(sf::Color(255, 255, 255, 70));
    window_.draw(highlight);
}

void SfmlApp::drawPanel() {
    sf::RectangleShape panel({static_cast<float>(window_.getSize().x) - 60.0f, topPanelHeight_ - 20.0f});
    panel.setPosition(30.0f, 20.0f);
    panel.setFillColor(sf::Color(248, 244, 235, 230));
    panel.setOutlineThickness(4.0f);
    panel.setOutlineColor(sf::Color(67, 78, 97));
    window_.draw(panel);

    const Button menu = menuButton();
    const Button reset = resetButton();
    drawButton(menu, sf::Color(122, 168, 218), sf::Color(41, 62, 90));
    drawButton(reset, sf::Color(234, 184, 92), sf::Color(84, 64, 31));

    bitmapLabel_.draw(window_, menu.label, {menu.bounds.left + menu.bounds.width / 2.0f, menu.bounds.top + 16.0f}, 3.1f, sf::Color::Black, true);
    bitmapLabel_.draw(window_, reset.label, {reset.bounds.left + reset.bounds.width / 2.0f, reset.bounds.top + 16.0f}, 3.1f, sf::Color::Black, true);

    bitmapLabel_.draw(window_, "MODE " + std::string(currentConfig_.label), {360.0f, 38.0f}, 4.0f, sf::Color(34, 43, 66));
    bitmapLabel_.draw(window_, minesLabel(), {360.0f, 83.0f}, 3.2f, sf::Color(134, 25, 31));
    bitmapLabel_.draw(window_, timerLabel(), {720.0f, 83.0f}, 3.2f, sf::Color(29, 74, 112));

    sf::Sprite mineSprite(assets_.mine);
    mineSprite.setScale(0.08f, 0.08f);
    mineSprite.setPosition(1140.0f, 38.0f);
    window_.draw(mineSprite);

    sf::Sprite flagSprite(assets_.flag);
    flagSprite.setScale(0.08f, 0.08f);
    flagSprite.setPosition(1230.0f, 38.0f);
    window_.draw(flagSprite);

    bitmapLabel_.draw(window_, std::to_string(currentConfig_.mines), {1195.0f, 54.0f}, 3.2f, sf::Color(40, 40, 40));
    bitmapLabel_.draw(window_, std::to_string(board_.flagCount()), {1285.0f, 54.0f}, 3.2f, sf::Color(40, 40, 40));
}

void SfmlApp::drawBoard() {
    const sf::Vector2f origin = boardOrigin();

    sf::RectangleShape frame({board_.cols() * cellSize_ + 20.0f, board_.rows() * cellSize_ + 20.0f});
    frame.setPosition(origin.x - 10.0f, origin.y - 10.0f);
    frame.setFillColor(sf::Color(246, 244, 239, 235));
    frame.setOutlineThickness(4.0f);
    frame.setOutlineColor(sf::Color(64, 72, 82));
    window_.draw(frame);

    for (std::size_t row = 0; row < board_.rows(); ++row) {
        for (std::size_t col = 0; col < board_.cols(); ++col) {
            drawCell(row, col, {origin.x + static_cast<float>(col) * cellSize_,
                                origin.y + static_cast<float>(row) * cellSize_});
        }
    }
}

void SfmlApp::drawCell(std::size_t row, std::size_t col, sf::Vector2f topLeft) {
    const Cell& current = board_.cell(row, col);
    const bool revealMine = roundState_ == RoundState::Lost && current.hasMine;
    const bool revealed = current.isRevealed || revealMine;

    sf::Sprite tile(revealed ? assets_.revealedTile : assets_.hiddenTile);
    tile.setPosition(topLeft);
    tile.setScale(cellSize_ / static_cast<float>(tile.getTexture()->getSize().x),
                  cellSize_ / static_cast<float>(tile.getTexture()->getSize().y));
    window_.draw(tile);

    if (board_.isExplodedCell(row, col)) {
        sf::RectangleShape overlay({cellSize_, cellSize_});
        overlay.setPosition(topLeft);
        overlay.setFillColor(sf::Color(210, 68, 58, 150));
        window_.draw(overlay);
    }

    if (!revealed) {
        if (current.isFlagged) {
            sf::Sprite flag(assets_.flag);
            const float scale = (cellSize_ * 0.72f) / static_cast<float>(assets_.flag.getSize().x);
            flag.setScale(scale, scale);
            const sf::FloatRect bounds = flag.getGlobalBounds();
            flag.setPosition(topLeft.x + (cellSize_ - bounds.width) / 2.0f,
                             topLeft.y + (cellSize_ - bounds.height) / 2.0f);
            window_.draw(flag);
        }
        return;
    }

    if (current.hasMine) {
        sf::Sprite mine(assets_.mine);
        const float scale = (cellSize_ * 0.74f) / static_cast<float>(assets_.mine.getSize().x);
        mine.setScale(scale, scale);
        const sf::FloatRect bounds = mine.getGlobalBounds();
        mine.setPosition(topLeft.x + (cellSize_ - bounds.width) / 2.0f,
                         topLeft.y + (cellSize_ - bounds.height) / 2.0f);
        window_.draw(mine);
        return;
    }

    if (current.adjacentMines > 0) {
        bitmapLabel_.draw(window_,
                          std::to_string(current.adjacentMines),
                          {topLeft.x + cellSize_ / 2.0f, topLeft.y + cellSize_ * 0.16f},
                          cellSize_ / 9.0f,
                          numberColor(current.adjacentMines),
                          true);
    }
}

void SfmlApp::drawStatusBanner() {
    if (roundState_ == RoundState::InProgress) {
        return;
    }

    sf::RectangleShape banner({520.0f, 84.0f});
    banner.setPosition((static_cast<float>(window_.getSize().x) - 520.0f) / 2.0f, topPanelHeight_ + 14.0f);
    banner.setFillColor(roundState_ == RoundState::Won ? sf::Color(179, 224, 157, 235) : sf::Color(232, 143, 125, 235));
    banner.setOutlineThickness(4.0f);
    banner.setOutlineColor(sf::Color(62, 62, 62));
    window_.draw(banner);

    const std::string label = roundState_ == RoundState::Won ? "YOU CLEARED THE BOARD" : "BOOM PRESS RESET TO TRY AGAIN";
    bitmapLabel_.draw(window_,
                      label,
                      {static_cast<float>(window_.getSize().x) / 2.0f, topPanelHeight_ + 39.0f},
                      3.4f,
                      sf::Color(32, 32, 32),
                      true);
}

sf::Vector2f SfmlApp::boardOrigin() const {
    const float width = static_cast<float>(board_.cols()) * cellSize_;
    const float height = static_cast<float>(board_.rows()) * cellSize_;
    const float x = (static_cast<float>(window_.getSize().x) - width) / 2.0f;
    const float y = topPanelHeight_ + 120.0f + std::max(0.0f, (static_cast<float>(window_.getSize().y) - topPanelHeight_ - 140.0f - height) / 2.0f);
    return {x, y};
}

sf::FloatRect SfmlApp::boardBounds() const {
    const sf::Vector2f origin = boardOrigin();
    return {origin.x, origin.y, static_cast<float>(board_.cols()) * cellSize_, static_cast<float>(board_.rows()) * cellSize_};
}

SfmlApp::Button SfmlApp::menuButton() const {
    return {sf::FloatRect(60.0f, 46.0f, 180.0f, 52.0f), "MENU"};
}

SfmlApp::Button SfmlApp::resetButton() const {
    return {sf::FloatRect(60.0f, 108.0f, 180.0f, 52.0f), "RESET"};
}

std::string SfmlApp::minesLabel() const {
    const int remaining = static_cast<int>(currentConfig_.mines) - static_cast<int>(board_.flagCount());
    return "MINES LEFT " + std::to_string(remaining);
}

std::string SfmlApp::timerLabel() const {
    return "TIME " + std::to_string(elapsedSeconds());
}

int SfmlApp::elapsedSeconds() const {
    if (screen_ != AppScreen::Playing) {
        return 0;
    }

    if (roundState_ != RoundState::InProgress) {
        return frozenElapsedSeconds_;
    }

    const auto now = std::chrono::steady_clock::now();
    return static_cast<int>(std::chrono::duration_cast<std::chrono::seconds>(now - roundStart_).count());
}

sf::Color SfmlApp::numberColor(int value) const {
    switch (value) {
        case 1: return sf::Color(54, 99, 196);
        case 2: return sf::Color(56, 142, 60);
        case 3: return sf::Color(198, 40, 40);
        case 4: return sf::Color(84, 43, 161);
        case 5: return sf::Color(124, 65, 26);
        case 6: return sf::Color(0, 121, 140);
        case 7: return sf::Color(55, 55, 55);
        case 8: return sf::Color(130, 130, 130);
        default: return sf::Color::Black;
    }
}
