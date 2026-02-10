#ifndef VIEW_H
#define VIEW_H



//forward declarations
class Board; 
namespace sf {class RenderWindow;} 

class View
{
    protected:
        


    public: 
        View(Board &b);
        virtual ~View();

        void loadImages();
        void repaint(sf::RenderWindow& window);
        void drawBoard(sf::RenderWindow& window);


};

#endif