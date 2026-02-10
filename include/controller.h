
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "board.h"
#include <SFML/Window.hpp>

namespace sf {class RenderWindow;} //forward declaration
 
class Controller
{
    protected:
        bool keepGoing;

    public:
        Controller(Board &board);
        virtual ~Controller();

        void update();
        void handleEvent(const sf::Event& event, sf::RenderWindow& window);
};

#endif