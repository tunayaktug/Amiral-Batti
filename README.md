# 🚢 Battleship Game (Amiral Battı) 🎯

**Battleship** (also known as "Amiral Battı") is a classic two-player strategy game where each player tries to locate and sink the opponent’s fleet.  
This version is implemented in the **C programming language** and is designed to run in the terminal.

---

## 🕹️ Getting Started

### ⚙️ Prerequisites
Make sure you have a C compiler (e.g., `gcc`) installed on your system.

### 🧱 Compilation
To compile the program, run the following command in your terminal:

```bash
gcc -o battleship amiral_batti.c
📏 Game Rules
🎲 Board Size Selection
At the start of the game, you will be asked to choose a board size:

10x10

16x16

20x20

🚢 Ship Placement
Ships are randomly placed on each player’s board. Ship lengths:

Small ship: 2 units

Medium ship: 3 units

Large ship: 5 units

🎯 Attacking
On your turn, enter a coordinate (e.g., 3 B) to fire at your opponent’s board.
You’ll be notified whether the attack is a hit or miss.

🧾 Statistics & Feedback
The game tracks both players’ hit rates.

You can monitor hits and misses on the display.

🏁 Game End
The game ends when all ships of one player are destroyed. The other player is declared the winner.

📜 Main Functions in the Code
tahtayaAta(Player *player, int boardSize)
Initializes the game board.

tahtayiYaz(Player *player, int boardSize)
Displays the current state of the board.

kontrolEt(Player *player, int x, int y, int direction, int size, int boardSize)
Checks if a ship can be placed at the given position.

gemiYerlestir(Player *player, int boardSize)
Randomly places ships on the board.

vurus(Player *player, int x, int y, int currentPlayer, int boardSize)
Executes an attack and checks hit or miss.

oyunBitisi()
Verifies whether the game is over.

oyunDurumuGoster(Player *player1, Player *player2, int boardSize)
Shows live game statistics.

serbestBirak(Player *player, int boardSize)
Frees allocated memory at the end of the game.
