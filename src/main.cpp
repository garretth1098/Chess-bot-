#include <iostream>
#include <SFML/Graphics.hpp> 
#include "board.h"
#include "view.h"
#include "controller.h"

using std::string;
using std::exit;
using std::cerr;

struct Config
{
    bool debug = false;
    int depth = 1;

    void parse(int argc, char* argv[])
    {        
        for (int i = 1; i < argc; ++i)
        {
            string arg = argv[i];
            if (string(argv[i]) == "--debug")
            {
                debug = true;
            }
            else if (arg == "--depth")
            {
                if (i + 1 >= argc)
                {
                    cerr << "Error: --depth requires a value\n";
                    exit(1);
                }

                depth = stoi(argv[++i]);

                if (depth <= 0)
                {
                    std::cerr << "Error: depth must be > 0\n";
                    std::exit(1);
                }
            }

            if (debug)
                std::cout << "Debug mode enabled\n";
        }
    }
};

void test(Board& game) //pass by reference for objects 
{
    game.loadBoard("8/5k2/3p4/1p1Pp2p/pP2Pp1P/P4P1K/8/8 b - - 99 50");
    game.printBoard();
}

void start(Board& game)
{
    const string startFen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    game.loadBoard(startFen);
    game.printBoard();

}


void run(Board& game, View& view, Controller& controller, int depth)
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Big DEEP Blue", sf::Style::Close);

    // Event object to hold the event data
    sf::Event event;

    while (window.isOpen())
    {
        // Poll for events
        while (window.pollEvent(event))
        {   
            controller.handleEvent(event, window);
        }

        window.clear();
        view.repaint(window);
        window.display();
    }

    // do
	// 	{
	// 		keepGoing = controller.update();
	// 		model.update();
	// 		view.repaint(); // This will indirectly call View.paintComponent
	// 		Toolkit.getDefaultToolkit().sync(); // Updates screen

	// 		// Go to sleep for 50 milliseconds
	// 		try
	// 		{
	// 			Thread.sleep(50);
	// 		} catch(Exception e) {
	// 			e.printStackTrace();
	// 			System.exit(1);
	// 		}
	// 	}
	// 	while(keepGoing);
}

int main (int argc, char* argv[])
{

    //debugging 
    Config config;
    config.parse(argc,argv); 

    //create a new starting board and prints it 
    Board game;
    View view(game);
    Controller controller(game);
    

    start(game);

    if(config.debug)
    {
        test(game);
    }

    run(game, view, controller, config.depth);

    return 0;
}







/* Planning:

TODO: piece polymorphism, psuedo legal moves, check moves, castling game state, en passant





Additional Notes:
ansci terminal escape codes for terminal animation 


*/