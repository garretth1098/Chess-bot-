#include "controller.h"
#include <SFML/Graphics.hpp>

Controller::Controller(Board &board)
{
    keepGoing = true;
}

Controller::~Controller()
{

}


void Controller::update()
{

}

void Controller::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
    // closes when user presses ESC or X
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            window.close();
        }
    }

    // keeps the window fixed TODO: make resizable 
    if (event.type == sf::Event::Resized)
    {
        window.setSize({800, 800});
    }
}