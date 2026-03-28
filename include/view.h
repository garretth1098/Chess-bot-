#ifndef VIEW_H
#define VIEW_H

//can only use forward declarations for references and pointer but if entire object is created 
//compiler needs full library for sf::Texture
#include <SFML/Graphics.hpp> 

//forward declarations
class Board; 

class View
{
    protected:
        sf::Texture blackBishop;
        sf::Texture blackRook;
        sf::Texture blackKing;
        sf::Texture blackKnight;
        sf::Texture blackPawn;
        sf::Texture blackQueen;

        sf::Texture whiteBishop;
        sf::Texture whiteRook;
        sf::Texture whiteKing;
        sf::Texture whiteKnight;
        sf::Texture whitePawn;
        sf::Texture whiteQueen; 


    public: 
        View(Board &b);
        virtual ~View();

        void loadImages(); // --------------------------> load assests once upon creation 
        void repaint(sf::RenderWindow& window); //------> maintains draw order by correctly calling the functions below:
        void drawBoard(sf::RenderWindow& window);
        void drawPieces(sf::RenderWindow& window);


};

#endif