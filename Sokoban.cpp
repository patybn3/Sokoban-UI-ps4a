/*
    Copyright 2023 Patricia Antlitz
*/
#include "Sokoban.hpp"

Sokoban::Sokoban(const std::string& level) {
    loadTexture("./sokoban/block_06.png", "wall");
    loadTexture("./sokoban/ground_01.png", "background");
    loadTexture("./sokoban/ground_04.png", "storage");
    loadTexture("./sokoban/crate_03.png", "box");

    tileSize_ = 60;

    loadTexture("./sokoban/player_05.png", "player_05");
    loadTexture("./sokoban/player_08.png", "player_08");
    loadTexture("./sokoban/player_17.png", "player_17");
    loadTexture("./sokoban/player_20.png", "player_20");

    loadLevel(level);

    playerX = 0;
    playerY = 0;
    playerDirection = Direction::Front;

    playerSprite.setTexture(textures["player_05"]);
}

void Sokoban::loadLevel(const std::string& fileName) {
    std::ifstream loadFile(fileName);

    if (!loadFile) {
        std::cout << "Error. Level file not loaded" << std::endl;
        return;
    }

    loadFile >> height_ >> width_;
    grid.resize(height_, std::vector<char>(width_));

    for (int i = 0; i < height_; ++i) {
        for (int j = 0; j < width_; ++j) {
            loadFile >> grid[i][j];
        }
    }
    loadFile.close();
}

void Sokoban::movePlayer(int direction) {
    if (direction == 0) {
        // player_05 for front
        playerDirection = Direction::Front;
        playerSprite.setTexture(textures["player_05"]);
    } else if (direction == 1) {
        // player_08 for back
        playerDirection = Direction::Back;
        playerSprite.setTexture(textures["player_08"]);
    } else if (direction == 2) {
        // player_20 for left
        playerDirection = Direction::Left;
        playerSprite.setTexture(textures["player_20"]);
    } else if (direction == 3) {
        // player_17 for right
        playerDirection = Direction::Right;
        playerSprite.setTexture(textures["player_17"]);
    }
}

bool Sokoban::isWon() const {
    return false;
}

int Sokoban::width() const {
    return width_ * tileSize_;
}

int Sokoban::height() const {
    return height_ * tileSize_;
}

void Sokoban::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (unsigned int i = 0; i < grid.size(); ++i) {
        for (unsigned int j = 0; j < grid[i].size(); ++j) {
            char cell = grid[i][j];
            sf::Sprite localSprite;

            switch (cell) {
            case '#':
                if (textures.find("wall") != textures.end()) {
                    localSprite.setTexture(textures.at("wall"));
                } else {
                    std::cout << "Error: Texture 'wall' not found" << std::endl;
                }
                break;
            case '.':
                if (textures.find("background") != textures.end()) {
                    localSprite.setTexture(textures.at("background"));
                } else {
                    std::cout << "Error: Texture 'background' not found" << std::endl;
                }
                break;
            case 'A':
                if (textures.find("box") != textures.end()) {
                localSprite.setTexture(textures.at("box"));
                } else {
                    std::cout << "Error: Texture 'box' not found" << std::endl;
                }
                break;
            case 'a':
                if (textures.find("storage") != textures.end()) {
                localSprite.setTexture(textures.at("storage"));
                } else {
                    std::cout << "Error: Texture 'storage' not found" << std::endl;
                }
                break;
            case '@':
                localSprite = playerSprite;
                break;
            default:
                break;
            }

            localSprite.setPosition(j * tileSize_, i * tileSize_);
            target.draw(localSprite);
        }
    }
}

void Sokoban::loadTexture(const std::string& file, const std::string& name) {
    sf::Texture oneTexture;
    oneTexture.loadFromFile(file);
    textures[name] = oneTexture;
}

std::ostream& operator<<(std::ostream& out, const Sokoban& game) {
    out << game.width_ << " " << game.height_ << '\n';

    for (const auto& row : game.grid) {
        for (char cell : row) {
            out << cell;
        }
        out << '\n';
    }
    return out;
}

std::istream& operator<<(std::istream& in, Sokoban& game) {
    int width, height;
    in >> width >> height;

    game.grid.clear();
    game.grid.resize(height, std::vector<char>(width));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            in >> game.grid[i][j];
        }
    }

    return in;
}
