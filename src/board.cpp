
#include "board.h"
#include <cctype>
#include "piece.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "pawn.h"


Board::Board()
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLM; j++)
            CurrBoard[i][j] = nullptr;
}

Board::~Board() 
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLM; j++)
            delete CurrBoard[i][j];
}

void Board::loadBoard(string fen)  //rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1
{

    int row = 7;   //Fen strings read off from top left -> bottom right 
    int col = 0;   //whereas arrays build bottom left -> top right 
                   // begin at [7][0] to properly index pieces 

    for (char c : fen)  //loops through each character of the string 
    {
        if (c == '/') 
        {
            // go to next rank
            row--;
            col = 0;
        } 
        else if (isdigit(c))
        {
            int empty = c - '0'; //--------> converts char to int 
            for(int i = 0; i < empty; i++) //skips over empty squares 
            {
                CurrBoard[row][col] = nullptr;  // no piece here
                col++; 
            }
        }
        else if(isalpha(c))
        {
            int color = isupper(c) ? Piece::White : Piece::Black;  //lowercase is black upper is white 
            
            char pieceType = tolower(c);  // simplify switch statement
            
            switch (pieceType)
            {
                case 'k': CurrBoard[row][col] = new King(color); break;
                case 'q': CurrBoard[row][col] = new Queen(color); break;
                case 'r': CurrBoard[row][col] = new Rook(color); break;
                case 'b': CurrBoard[row][col] = new Bishop(color); break;
                case 'n': CurrBoard[row][col] = new Knight(color); break;
                case 'p': CurrBoard[row][col] = new Pawn(color); break;
                default:  CurrBoard[row][col] = nullptr; 

            }
            
            col++; //creates a piece and then moves to the next square 
        }
        else if(c == ' ' )
        {
            break;
        }
       
        //prevent code from crashing if Incorrect Fen TODO: user error chcecking
    }
}

// prints a text version of the board to the terminal 
void Board::printBoard()
{
    cout << "\n  ---------------------------------\n";
    for (int i = ROWS - 1; i >= 0; i--)
    {
        cout << i + 1 << " | ";
        for (int j = 0; j < COLM; j++)
        {
            if(CurrBoard[i][j] != nullptr)
                cout << CurrBoard[i][j]->getSymbol() << " | ";    //If element is nullptr prints empty character
            else
                cout << " " << " | "; 
        }
        cout << "\n  ---------------------------------\n";
    }
    
    cout << "    a   b   c   d   e   f   g   h" << endl << endl;

}
 
