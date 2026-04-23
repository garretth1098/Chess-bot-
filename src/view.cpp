#include "board.h"
#include "view.h"
#include "piece.h"



View::View(const Board &b) : board(b)
{
    loadImages();
    sprite.setScale(0.8,0.8);  //so pieces properly fit the board squares 
}


View::~View()
{
    //deconstruct 
}

void View::loadImages()  
{
    blackBishop.loadFromFile("assets/black-bishop.png"); blackBishop.setSmooth(true);
    blackRook.loadFromFile("assets/black-rook.png"); blackRook.setSmooth(true);
    blackKing.loadFromFile("assets/black-king.png"); blackKing.setSmooth(true);
    blackKnight.loadFromFile("assets/black-knight.png"); blackKnight.setSmooth(true);
    blackPawn.loadFromFile("assets/black-pawn.png"); blackPawn.setSmooth(true);
    blackQueen.loadFromFile("assets/black-queen.png"); blackQueen.setSmooth(true);

    whiteBishop.loadFromFile("assets/white-bishop.png"); whiteBishop.setSmooth(true);
    whiteRook.loadFromFile("assets/white-rook.png"); whiteRook.setSmooth(true);
    whiteKing.loadFromFile("assets/white-king.png"); whiteKing.setSmooth(true);
    whiteKnight.loadFromFile("assets/white-knight.png"); whiteKnight.setSmooth(true);
    whitePawn.loadFromFile("assets/white-pawn.png"); whitePawn.setSmooth(true);
    whiteQueen.loadFromFile("assets/white-queen.png"); whiteQueen.setSmooth(true);
}

void View::setTexture(const Piece* p) //TODO refactor to use a lookup table for textures but this function will not scale so it works 
{
    if(p->getPieceColor() == Piece::Color::White) // piece is white 
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
    else // piece is black 
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

    for (int row = 0; row < BOARD_SIZE; ++row)
        {
            for (int col = 0; col < BOARD_SIZE; ++col)
            {
                const Piece* p = board.getPiece(row,col);
                if(p != nullptr)
                {
                  setTexture(p);
                  sprite.setPosition(col * TILE_SIZE, (7 - row) * TILE_SIZE);  // must invert y coordinate to account for inverse y axis on window
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