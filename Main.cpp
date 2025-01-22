#include "Source.h"
#include <windows.h>

int main()
{
    sfw window(sf::VideoMode::getFullscreenModes()[0], "Life Game");
    window.setKeyRepeatEnabled(false);

    a8 GameArray = InitArrayRate();
    r16 square = InitArrayB();
     

    sf::Texture StartTexture("image//startButton.png");
    sf::Sprite StartSprite(StartTexture);
    StartSprite.setPosition({ 430., 100. });
    bool startbtn = true;
    bool reset = false;
    bool pause = false;
    int iteration = 0;
    

    while (window.isOpen())
    {
        Sleep(7);
        start:
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                std::cout << iteration;
            }
                
        }

        if (startbtn) {
            window.clear(sf::Color::Black);
            window.draw(StartSprite);
            window.display();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                startbtn = false;
            }
            goto start;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) pause = true;
        while (pause) {
            Sleep(95);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) pause = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            window.clear(sf::Color::Black);
            GameArray = InitArrayRate();
        }

        window.clear(sf::Color::Black);

        GameArray = UpdateArray(GameArray);

        if (GameArray.size() < 4 || square.size() < 4) {
            std::cout << "GameArray ou square est trop petit !\n";
            return 0;
        }

        for (int i = 2; i < GameArray.size() - 2; i++) {
            if (GameArray[i].size() < 4 || square[i].size() < 4) {
                std::cout << "Ligne " << i << " trop petite !\n";
                continue;
            }
            for (int j = 2; j < GameArray[i].size() - 2; j++) {
                sf::Vector2f squarePos(i * 5, j * 5);
                square[i][j].setPosition(squarePos);

                if (GameArray[i][j] == 1) {
                    square[i][j].setFillColor(sf::Color::White);
                    window.draw(square[i][j]);
                }
            }
        }
        window.display();
        iteration++;
    }
    return 0;
}