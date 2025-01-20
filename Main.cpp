#include "Source.h"
#include <windows.h>

int main()
{
    sfw window(sf::VideoMode::getFullscreenModes()[0], "Life Game");

    window.clear();
    a8 GameArray = InitArray();
    r16 square = InitArrayB();
    window.display();
     

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        GameArray = UpdateArray(GameArray);

        if (GameArray.size() < 4 || square.size() < 4) {
            std::cerr << "GameArray ou square est trop petit !\n";
            return 0;
        }

        for (int i = 2; i < GameArray.size() - 2; i++) {
            if (GameArray[i].size() < 4 || square[i].size() < 4) {
                std::cerr << "Ligne " << i << " trop petite !\n";
                continue;
            }
            for (int j = 2; j < GameArray[i].size() - 2; j++) {
                sf::Vector2f squarePos(i * 5, j * 5);
                square[i][j].setPosition(squarePos);

                if (GameArray[i][j] == 1) {
                    square[i][j].setFillColor(sf::Color::White);
                    window.draw(square[i][j]);
                }
                else {
                    square[i][j].setFillColor(sf::Color::Blue);
                }
            }
        }
        window.display();
    }
    return 0;
}