#!/bin/bash
set -e

# header files 
INCLUDE_DIR="include"  # project-specific header files 

# source files
SRC_FILES="src/main.cpp src/board.cpp src/view.cpp src/controller.cpp 
           src/pieces/piece.cpp src/pieces/king.cpp src/pieces/queen.cpp src/pieces/pawn.cpp src/pieces/knight.cpp src/pieces/rook.cpp src/pieces/bishop.cpp"

# library paths  
LIB_DIR="/usr/lib"  

# Compile 
g++ -Wall -g -I$INCLUDE_DIR -I/usr/include $SRC_FILES -L$LIB_DIR -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Run
./main "$@"