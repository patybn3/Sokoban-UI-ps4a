/*
    Copyright 2023 Patricia Antlitz
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <map>

#include <SFML/Graphics.hpp>

enum class Direction {
    Front, Back, Left, Right
};

class Sokoban : public sf::Drawable {
 public:
    std::vector<std::vector<char>> grid;

    explicit Sokoban(const std::string& level);

    void movePlayer(int direction);
    void loadPlayers();
    bool isWon() const;
    int width() const;
    int height() const;

    friend std::istream& operator>>(std::istream& in, Sokoban& soko);
    friend std::ostream& operator<<(std::ostream& out, const Sokoban& soko);

 protected:
    std::map<std::string, sf::Texture> textures;
    sf::Sprite playerSprite;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void loadTexture(const std::string& file, const std::string& name);
    void loadLevel(const std::string& fileName);

 private:
    int width_;
    int height_;
    int tileSize_;
    // player's position
    int playerX, playerY;
    // index of current player image
    int playerIndex;

    Direction playerDirection;
    std::map<char, sf::Texture> playerTextures;
    std::map<std::string, sf::Sprite> sprites;
};

