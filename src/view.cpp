#include "board.h"
#include "view.h"


View::View(Board &b)
{
    Board game = b; //TODO: make class member variable instead of declaring here; 
    loadImages();
}


View::~View()
{
    //deconstruct 
}

void View::loadImages()  
{
    blackBishop.loadFromFile("assets/black-bishop.png");
    blackRook.loadFromFile("assets/black-rook.png");
    blackKing.loadFromFile("assets/black-king.png");
    blackKnight.loadFromFile("assets/black-knight.png");
    blackPawn.loadFromFile("assets/black-pawn.png");
    blackQueen.loadFromFile("assets/black-queen.png");

    whiteBishop.loadFromFile("assets/white-bishop.png");
    whiteRook.loadFromFile("assets/white-rook.png");
    whiteKing.loadFromFile("assets/white-king.png");
    whiteKnight.loadFromFile("assets/white-knight.png");
    whitePawn.loadFromFile("assets/white-pawn.png");
    whiteQueen.loadFromFile("assets/white-queen.png");
}

void View::repaint(sf::RenderWindow& window)
{
    drawBoard(window);
}

void View::drawBoard(sf::RenderWindow& window)
{
    const int BOARD_SIZE = 8;
    const float TILE_SIZE = 100.f;

    sf::RectangleShape square({TILE_SIZE, TILE_SIZE});  //creates the shape 

        for (int row = 0; row < BOARD_SIZE; ++row)
        {
            for (int col = 0; col < BOARD_SIZE; ++col)
            {
                square.setPosition(col * TILE_SIZE, row * TILE_SIZE);

                bool isLight = (row + col) % 2 == 0;  //calculates even or odd; basically just alternates colors
                square.setFillColor(
                    isLight ? sf::Color(240, 217, 181) : sf::Color(181, 136, 99)
                );

                window.draw(square);  // draw each square 
            }
        }
}
