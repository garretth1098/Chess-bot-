
#include "board.h"
#include <cctype>
#include "piece.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "pawn.h"
#include "move.h"

Board::Board()
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLM; j++)
            CurrBoard[i][j] = nullptr;

    stateStack = new BoardState[MAX_MEM];


    // initial boardstate
	stateStack[0].bitboards[WHITE_PAWN] = 0x000000000000ff00;
	stateStack[0].bitboards[WHITE_KNIGHT] = 0x0000000000000042;
	stateStack[0].bitboards[WHITE_BISHOP] = 0x0000000000000024;
	stateStack[0].bitboards[WHITE_ROOK] = 0x0000000000000081;
	stateStack[0].bitboards[WHITE_QUEEN] = 0x0000000000000008;
	stateStack[0].bitboards[WHITE_KING] = 0x0000000000000010;

    stateStack[0].bitboards[BLACK_PAWN] = 0x00ff000000000000;
	stateStack[0].bitboards[BLACK_KNIGHT] = 0x4200000000000000;
	stateStack[0].bitboards[BLACK_BISHOP] = 0x2400000000000000;
	stateStack[0].bitboards[BLACK_ROOK] = 0x8100000000000000;
	stateStack[0].bitboards[BLACK_QUEEN] = 0x0800000000000000;
	stateStack[0].bitboards[BLACK_KING] = 0x1000000000000000;

	stateStack[0].WKS = true;
	stateStack[0].WQS = true;
	stateStack[0].BKS = true;
	stateStack[0].BQS = true;

	stateStack[0].passantTarget = 0;

	stateStack[0].turn = WHITE;
    
}

Board::~Board() 
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLM; j++)
            delete CurrBoard[i][j];

    delete[] stateStack;
}

void Board::loadBoard(string fen)  //rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1
{

    int row = 7;   //Fen strings read off from top left -> bottom right 
    int col = 0;   //whereas arrays builds the board from bottom left -> top right 
                   //begin at [7][0] to properly index pieces 

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
            int empty = c - '0'; //---------> converts char to int 
            for(int i = 0; i < empty; i++) // skips over empty squares 
            {
                CurrBoard[row][col] = nullptr;  // no piece here
                col++; 
            }
        }
        else if(isalpha(c))
        {
            Piece::Color color = isupper(c) ? Piece::Color::White : Piece::Color::Black;  //in FEN strings, lowercase is black, uppercase is white 
            
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
// Used for testing TODO Remove later
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

// syncs board array given a boardstate 
void Board::updateBoard(const BoardState& state)
{
    for(int square = 0; square < 64; square++)
    {
        int row = square / 8;
        int col = square % 8;

        int pieceType = getPiece(state, square);
        
        Piece* currentPiece = CurrBoard[row][col];

        // square should be empty but currently has a piece; delete piece
        if(pieceType == EMPTY && currentPiece != nullptr) 
        { 
            delete currentPiece;
            CurrBoard[row][col] = nullptr;
            continue;
        }

        // square should have a piece but its empty; create piece, fill square
        if(pieceType != EMPTY && currentPiece == nullptr)
        {
            CurrBoard[row][col] = createPiece(pieceType);
            continue;
        }

        // square has a piece but its different from CurrBoards piece; delete and replace
        // segmentation fault without 'currentPiece != nullptr' because conditional calls method on nullptr otherwise
        if(currentPiece != nullptr && pieceType != currentPiece->getPieceIndex())
        {
            delete currentPiece;
            CurrBoard[row][col] = createPiece(pieceType);
        }
    }
    
}

// 
const Piece* Board::getPiece(int row, int colm) const
{
    return CurrBoard[row][colm];
}

Piece* Board::getPiece(int row, int colm)
{
    return CurrBoard[row][colm];
}

Piece* Board::createPiece(int pieceType)
{
    switch (pieceType)
    {
        case WHITE_PAWN: return new Pawn(Piece::Color::White);// in hindsight using enums as the only piece class param has not helped 
        case WHITE_KNIGHT: return new Knight(Piece::Color::White);
        case WHITE_BISHOP: return new Bishop(Piece::Color::White);
        case WHITE_ROOK: return new Rook(Piece::Color::White);
        case WHITE_QUEEN: return new Queen(Piece::Color::White);
        case WHITE_KING: return new King(Piece::Color::White);
    
        case BLACK_PAWN: return new Pawn(Piece::Color::Black);    
        case BLACK_KNIGHT: return new Knight(Piece::Color::Black);
        case BLACK_BISHOP: return new Bishop(Piece::Color::Black);  
        case BLACK_ROOK: return new Rook(Piece::Color::Black); 
        case BLACK_QUEEN: return new Queen(Piece::Color::Black);   
        case BLACK_KING: return new King(Piece::Color::Black);

        case EMPTY: return nullptr;
    }

    return nullptr;
}

int Board::getPiece(const BoardState& state, int square)
{
    Bitboard mask = Bitboard(1) << square; // creates a boardstate with a single one-bit in selected square
    

    for(int i = 0; i < 12; i++)
    {
        if(state.bitboards[i] & mask){return i;} // searches each bitboard and finds whats at the specified square
    }

    return EMPTY;  

}

void Board::movePiece(const Move& move)
{
    //create copy of last boardstate and add to end of stack
    //edit copy of boardstate with move provided 

    //copies last boardstate and pushes it to the stack 
    stateStack[stackIndex + 1] = stateStack[stackIndex];
    stackIndex++;

    
}

void Board::movePiece(int startRow, int startCol, int endRow, int endCol)
{

    //create a move object to use as a param
    Move move;
    move.from = (startRow * 8) + startCol;
    move.to = (endRow * 8) + endCol;


    // if(!isLegalMove(move)) //returns early if a move is illegal
    // {
    //     return;
    // }

    movePiece(move); // calls to update bitboards using the move object we just created 


    Piece* movingPiece = CurrBoard[startRow][startCol];
    Piece* targetPiece = CurrBoard[endRow][endCol];
    
    //return early if colors match as to not capture your own pieces
    if(targetPiece != nullptr && movingPiece->getPieceColor() == targetPiece->getPieceColor())
    {return;}

    if(targetPiece != nullptr)
    {
        delete targetPiece;
    }
    
    CurrBoard[endRow][endCol] = movingPiece;
    CurrBoard[startRow][startCol] = nullptr;
}

void Board::undo()
{
    if(stackIndex <= 0){return;}
    
    stackIndex--;
    updateBoard(stateStack[stackIndex]);
}


// bool isLegalMove(Move& move)
// {
//     //pulls from move generation class. searches through list of legal moves returns bool 
// }
 
