# Big DEEP Blue

Big DEEP Blue is a chess engine and graphical chess application written in C++
using SFML.

## Architecture

The project follows a Model-View-Controller-inspired architecture.

- `Board` — owns and manages the chess position.
- `Piece` — base class for chess pieces.
- `View` — handles SFML rendering.
- `Controller` — processes user input and coordinates interaction.
- Move generation — determines legal and pseudo-legal moves.
- Engine — evaluates positions and searches game trees.

For a detailed explanation of the architecture, see:

[Architecture Documentation](docs/architecture.md)