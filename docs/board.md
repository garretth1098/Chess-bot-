

## Update board

@brief: used in my undo function to sync the engine with the GUI
@param: Boardstate object
@return: void
@details:
- used to syncronize the currBoard[8][8] piece array with the current boardstate. 
- first iterates through each square and then searches each bitboard for a bit in that matching square
