#include "controller.h"
#include "piece.h"
#include <SFML/Graphics.hpp>

#include <iostream>

Controller::Controller(Board &b) : board(b)
{
    
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
    if(event.type == sf::Event::MouseButtonPressed)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            int mouseX = event.mouseButton.x;
            int mouseY = event.mouseButton.y;

            int col = mouseX / TILE_SIZE;
            int row = 7 - (mouseY / TILE_SIZE);  //matches drawing logic  

            Piece* p = board.getPiece(row,col);

            if(p != nullptr)
            {
                pieceSelected = true;
                selectedRow = row;
                selectedCol = col;
                
            }
            if(pieceSelected  && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                cout << "start row:" << selectedRow << "start colm:" << selectedCol << "end dest:" << mouseX << "end colm" << mouseY;
                board.movePiece(selectedRow,selectedCol,row, col);
            }

        }
    }

    // keeps the window fixed TODO: make resizable 
    if (event.type == sf::Event::Resized)
    {
        window.setSize({800, 800});
    }
}