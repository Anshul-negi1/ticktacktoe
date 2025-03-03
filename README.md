# Tic-Tac-Toe in C++

A simple Tic-Tac-Toe game implemented in C++ where a player competes against a computer opponent.

## Features

- Play against a basic AI opponent.
- Input validation for user moves.
- Randomized computer moves.
- Detects win conditions and ties.

## How to Run

1. Compile the program using a C++ compiler like `g++`:
   ```sh
   g++ tic_tac_toe.cpp -o tic_tac_toe
   ```
2. Run the executable:
   ```sh
   ./tic_tac_toe
   ```

## Game Instructions

- The board is represented as a 3x3 grid with positions numbered 1-9.
- The player (X) takes turns against the computer (O).
- Enter a number (1-9) to place your marker.
- The game ends when a player wins or the board is full (tie).

## Example Gameplay

```
     |     |     
  X  |  O  |  X  
_____|_____|_____
     |     |     
  O  |  X  |  O  
_____|_____|_____
     |     |     
  X  |  O  |  X  
     |     |     

IT'S A TIE!
```

## Future Improvements

- Enhance AI with a minimax algorithm.
- Add a graphical interface using a GUI library.
- Implement a multiplayer mode.

## License

This project is open-source and free to use.
