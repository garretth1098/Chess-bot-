#include "board.h"
#include "view.h"
#include "piece.h"



View::View(const Board &b) : board(b)
{
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

void View::setTexture(const Piece* p) //TODO refactor to use a lookup table for textures but this function will not scale so it works 
{
    if(p->getPieceColor() == Piece::Color::White)
    {
        switch(p->getPieceType())
        {
            case Piece::Type::King : sprite.setTexture(whiteKing); break;
            case Piece::Type::Bishop : sprite.setTexture(whiteBishop); break;
            case Piece::Type::Knight : sprite.setTexture(whiteKnight); break;
            case Piece::Type::Pawn : sprite.setTexture(whitePawn); break;
            case Piece::Type::Rook : sprite.setTexture(whiteRook); break;
            case Piece::Type::Queen : sprite.setTexture(whiteQueen); break;

        }
    }
    else 
    {
        switch(p->getPieceType())
        {
            case Piece::Type::King : sprite.setTexture(blackKing); break;
            case Piece::Type::Bishop : sprite.setTexture(blackBishop); break;
            case Piece::Type::Knight : sprite.setTexture(blackKnight); break;
            case Piece::Type::Pawn : sprite.setTexture(blackPawn); break;
            case Piece::Type::Rook : sprite.setTexture(blackRook); break;
            case Piece::Type::Queen : sprite.setTexture(blackQueen); break;

        }
    }
    
}

void View::drawBoard(sf::RenderWindow& window)
{
    const int BOARD_SIZE = 8;
    const float TILE_SIZE = 100.f;

    sf::RectangleShape square({TILE_SIZE, TILE_SIZE});  //creates the shape 

        for (int row = 0; row < BOARD_SIZE; row++)
        {
            for (int col = 0; col < BOARD_SIZE; col++)
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

void View::drawPieces(sf::RenderWindow& window)
{
    const int BOARD_SIZE = 8;
    const float TILE_SIZE = 100.f;

    for (int row = 0; row < BOARD_SIZE; ++row)
        {
            for (int col = 0; col < BOARD_SIZE; ++col)
            {
                const Piece* p = board.getPiece(row,col);
                if(p != nullptr)
                {
                  setTexture(p);
                  sprite.setPosition(col * TILE_SIZE, row * TILE_SIZE);
                  window.draw(sprite);  
                }
                
            }
        }
}


void View::repaint(sf::RenderWindow& window)
{
    drawBoard(window);
    drawPieces(window);
}