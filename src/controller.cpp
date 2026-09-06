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
    
    //================
    //  Mouse events
    //================
    if(event.type == sf::Event::MouseButtonPressed)
    {
        mouseX = event.mouseButton.x;
        mouseY = event.mouseButton.y;

        col = mouseX / TILE_SIZE;
        row = 7 - (mouseY / TILE_SIZE);  //matches drawing logic

        if(pieceSelected)
        {
            board.movePiece(selectedRow, selectedCol, row, col);
            pieceSelected = false;
            isDragging = false;
            selectedRow = -1; //----------> arbitrary values to reset variables
            selectedCol = -1;
            return;  //-------------------> assumes this is the second destination click and returns early
        }
        
        Piece* p = board.getPiece(row, col);

        if (p != nullptr) // if user clicks on a piece  
        {
            pieceSelected = true;
            isDragging = false;

            selectedRow = row;
            selectedCol = col;

            startMouseX = mouseX;
            startMouseY = mouseY;

            dragX = mouseX;
            dragY = mouseY;
        }
    }
    else if (event.type == sf::Event::MouseMoved)
    {
        if (pieceSelected)
        {
            dragX = event.mouseMove.x;
            dragY = event.mouseMove.y;

            // detect if user moved enough to count as a drag makes movement smoother
            if (abs(dragX - startMouseX) > 5 ||
                abs(dragY - startMouseY) > 5)
            {
                isDragging = true;
            }
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased &&
            event.mouseButton.button == sf::Mouse::Left)
    {
        if (pieceSelected && isDragging)
        {
            mouseX = event.mouseButton.x;
            mouseY = event.mouseButton.y;

            col = mouseX / TILE_SIZE;
            row = 7 - (mouseY / TILE_SIZE);

            board.movePiece(selectedRow, selectedCol, row, col);

            pieceSelected = false;
            isDragging = false;
            selectedRow = -1;
            selectedCol = -1;
        }
    }

    // keeps the window fixed TODO: make resizable 
    if (event.type == sf::Event::Resized)
    {
        window.setSize({800, 800});
    }

}