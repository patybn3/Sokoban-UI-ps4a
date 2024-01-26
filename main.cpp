/*
    Copyright 2023 Patricia Antlitz
*/
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Sokoban.hpp"

int main(int argc, char const *argv[]) {
    /* code */
    if (argc != 2) {
        std::cout << "Args: " << argv[0] << "level text file as level1.txt" << std::endl;
        return 1;
    }

    sf::RenderWindow window;
    Sokoban game(argv[1]);

    window.create(sf::VideoMode(game.width(), game.height()), "Sokoban");

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    game.movePlayer(0);
                } else if (event.key.code == sf::Keyboard::Down) {
                    game.movePlayer(1);
                } else if (event.key.code == sf::Keyboard::Left) {
                    game.movePlayer(2);
                } else if (event.key.code == sf::Keyboard::Right) {
                    game.movePlayer(3);
                }
            }
        }

        window.clear();
        window.draw(game);
        window.display();
    }

    return 0;
}
