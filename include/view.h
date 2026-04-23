#ifndef VIEW_H
#define VIEW_H

//can only use forward declarations for references and pointers but if entire object is created 
//compiler needs full library (for sf::Texture)
#include <SFML/Graphics.hpp> 

//forward declarations
class Board; 

class View
{
    private:
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

        sf::Sprite sprite; //----------------> chess has only a single object moving at a given time so only one sprite object is needed 
        const Board& board; //---------------> reference to the board created in main so that changes are always tracked

        void loadImages(); // --------------------------> load assests once upon creation 
        void setTexture(const Piece* p); // ------------> updates the single sprite skin before drawing 
        void drawBoard(sf::RenderWindow& window);
        void drawPieces(sf::RenderWindow& window);

        const int BOARD_SIZE = 8;
        const float TILE_SIZE = 100.f;

    public: 
        View(const Board &b);
        virtual ~View();

        void repaint(sf::RenderWindow& window); //------> maintains draw order by correctly calling each draw function 

};

#endif