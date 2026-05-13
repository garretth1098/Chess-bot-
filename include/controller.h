
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "board.h"
#include <SFML/Window.hpp>

namespace sf {class RenderWindow;} //forward declaration
 
class Controller
{
    protected:
        Board& board;
        bool pieceSelected = false;
        int col;
        int row;
        int mouseX;
        int mouseY;
        int selectedRow;
        int selectedCol;
        int startMouseX; 
        int startMouseY;    
        int dragX;
        int dragY;

        bool isDragging;

        const int TILE_SIZE = 100;

    public:
        Controller(Board &b);
        virtual ~Controller();

        void update();
        void handleEvent(const sf::Event& event, sf::RenderWindow& window);
};

#endif