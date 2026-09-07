# Big DEEP Blue Architecture

Big DEEP Blue separates game state, graphical representation,
and user interaction into separate components.

## High-Level Architecture

```mermaid
classDiagram

Controller --> Board
Controller --> View
View --> Board

Board *-- Piece

Piece <|-- King
Piece <|-- Queen
Piece <|-- Rook
Piece <|-- Bishop
Piece <|-- Knight
Piece <|-- Pawn
```

## Board

The `Board` class is responsible for maintaining the current
state of the chess game.

...