#  Battleship Game in C 

This is a **two-player console-based Battleship game** written in C. The game allows players to choose a board size, automatically places ships randomly, and takes turns to attack the opponent’s board. The player who sinks all opponent ships first wins the game.

---

##  Game Features

- Supports 3 board sizes:  
  `10x10`, `16x16`, `20x20`
- Randomized ship placement
- 2-player turn-based gameplay
- Hit/miss feedback and score tracking
- Displays number of moves per player
- Dynamic memory allocation for flexible board sizing
- Auto-clear screen for better UI experience (cross-platform)

---

##  How to Play

1. When the game starts, you’ll be prompted to choose a board size:

  Select board size (1: 10x10, 2: 16x16, 3: 20x20):

2. Each player’s board will be randomly populated with 3 ships of sizes `2`, `3`, and `5`.

3. Players take turns to enter coordinates to attack:
Player 1, enter coordinates (e.g., 3 B):

4. If a ship part is hit, the player gets another turn. Otherwise, control switches.

5. The game ends when all ships of one player are sunk (10 hits total).

---

## ⚙ Compilation

Use any standard C compiler like `gcc`.

```bash
gcc battleship.c -o battleship
Then run it:
./battleship
```

## Core Mechanics
Board Representation:
Dynamic 2D char arrays. 'O' = ship, '-' = empty, 'X' = hit

Ship Placement:
Random orientation (horizontal or vertical), placed only if cells are unoccupied

Hit Logic:
User inputs a row number and column letter (e.g., 3 B)
Game converts input and checks if it hits a ship on the opponent's board
Score is updated accordingly

## Example Output
```bash
******Amiral Batti Oyunu******
Select board size (1: 10x10, 2: 16x16, 3: 20x20): 1

Player 1 Board:
2. Player Total Moves: 5

  A B C D E F G H I J
 1 - - - - - - - - - -
 2 - - - - - - - - - -
...

Player 1, enter coordinates (e.g., 3 B): 3 B
Hit!
Player 1 Score: 1
You get another turn!
```
## Concepts Used
Structs (Player, Ship)

Dynamic memory (malloc, free)

Recursion-free procedural logic

Multi-dimensional arrays

Input validation and error handling

Platform-aware screen clearing (cls for Windows, clear for UNIX)

## Memory Management
All dynamically allocated memory (board arrays and ship hit arrays) is properly released at the end of the game using:

**void serbestBirak(Player *player, int boardSize);***
