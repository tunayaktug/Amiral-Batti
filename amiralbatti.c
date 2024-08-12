#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int size;
    int *hits;       
    int hamleSayisi; 
} Ship;

typedef struct
{
    Ship ships[3];
    char **board;
    int hamleSayisi; 
} Player;

#define BOARD_SIZE_SMALL 10
#define BOARD_SIZE_MEDIUM 16
#define BOARD_SIZE_LARGE 20
#define NUM_SHIPS 3

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

int p1Hit = 0;
int p2Hit = 0;

void tahtayaAta(Player *player, int boardSize);
void tahtayiYaz(Player *player, int boardSize);
int kontrolEt(Player *player, int x, int y, int direction, int size, int boardSize);
void gemiYerlestir(Player *player, int boardSize);
int vurus(Player *player, int x, int y, int currentPlayer, int boardSize);
int oyunBitisi();
void oyunDurumuGoster(Player *player1, Player *player2, int boardSize);
void serbestBirak(Player *player, int boardSize);

int main()
{
    srand(time(NULL));

    printf("******Amiral Batti Oyunu******\n");

    Player player1, player2;
    int boardSizeOption;

    printf("Tahta boyutunu secin (1: 10x10, 2: 16x16, 3: 20x20): ");

    if (scanf("%d", &boardSizeOption) != 1 || (boardSizeOption < 1 || boardSizeOption > 3))
    {
        printf("Gecersiz secenek! Oyun baslatilamadi.\n");
        return 1;
    }

    int boardSize;
    switch (boardSizeOption)
    {
    case 1:
        boardSize = 10;
        break;
    case 2:
        boardSize = 16;
        break;
    case 3:
        boardSize = 20;
        break;
    default:
        printf("Gecersiz secenek! Oyun baslatilamadi.\n");
        return 1;
    }

    tahtayaAta(&player1, boardSize);
    tahtayaAta(&player2, boardSize);

    player1.hamleSayisi = 0;
    player2.hamleSayisi = 0;

    gemiYerlestir(&player1, boardSize);
    gemiYerlestir(&player2, boardSize);

    int currentPlayer = 1;

    while (oyunBitisi() == 0)
    {

        oyunDurumuGoster(&player1, &player2, boardSize);

        if (player1.hamleSayisi > 0 || player2.hamleSayisi > 0)
        {
            printf("Sira diger oyuncuda!\n");
        }

        int x;
        char y;
        int validShot = 0;

        do
        {
            printf("Oyuncu %d atis yapmak icin koordinatlari girin (Ornek: 3 B): ", currentPlayer);
            if (scanf("%d %c", &x, &y) != 2)
            {
                printf("Gecersiz giris! Lutfen sayi ve harfi dogru formatta girin (Ornek: 3 B).\n");
                while (getchar() != '\n')
                    ;     
                continue; 
            }

            
            if (x < 1 || x > boardSize || y < 'A' || y >= 'A' + boardSize)
            {
                printf("Gecersiz giris! Lutfen tahta sinirlari icinde bir satir ve bir sutun girin.\n");
                continue; 
            }

            Player *currentPlayerBoard = (currentPlayer == 1) ? &player2 : &player1;

            validShot = vurus(currentPlayerBoard, x, y, currentPlayer, boardSize);

            
            currentPlayerBoard->hamleSayisi++;

            if (validShot)
            {

                
                oyunDurumuGoster(&player1, &player2, boardSize);
                
                printf("Oyuncu %d isabetli atis yapti! ", currentPlayer);
                printf("Oyuncu %d Tekrar atis yapabilirsiniz!\n", currentPlayer);
            }
            else
            {
                
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }

        } while (validShot && oyunBitisi() == 0); 
    }

    if (currentPlayer == 1)
    {
        printf("2. Oyuncunun tum gemileri yok edildi! Oyuncu 1 kazandi!\n");
    }
    else
    {
        printf("1. Oyuncunun tum gemileri yok edildi! Oyuncu 2 kazandi!\n");
    }

    
    serbestBirak(&player1, boardSize);
    serbestBirak(&player2, boardSize);

    return 0;
}

void tahtayaAta(Player *player, int boardSize)
{
    player->board = (char **)malloc(boardSize * sizeof(char *));
    for (int i = 0; i < boardSize; ++i)
    {
        player->board[i] = (char *)malloc(boardSize * sizeof(char));
        for (int j = 0; j < boardSize; ++j)
        {
            player->board[i][j] = '-';
        }
    }
}

void tahtayiYaz(Player *player, int boardSize)
{
    printf("  ");
    for (int i = 0; i < boardSize; ++i)
    {
        printf(" %c", 'A' + i);
    }
    printf("\n");

    for (int i = 0; i < boardSize; ++i)
    {
        printf("%2d", i + 1);
        for (int j = 0; j < boardSize; ++j)
        {
            printf(" %c", player->board[i][j]);
        }
        printf("\n");
    }
}

int kontrolEt(Player *player, int x, int y, int direction, int size, int boardSize)
{
    if (direction == 0)
    {
       
        if (x + size > boardSize)
        {
            return 0; 
        }
        for (int i = 0; i < size; ++i)
        {
            if (player->board[x + i][y] != '-')
            {
                return 0; 
            }
        }
    }
    else
    {
        
        if (y + size > boardSize)
        {
            return 0; 
        }
        for (int i = 0; i < size; ++i)
        {
            if (player->board[x][y + i] != '-')
            {
                return 0; 
            }
        }
    }
    return 1; 
}

void gemiYerlestir(Player *player, int boardSize)
{
    int validSizes[] = {2, 3, 5};

    for (int i = 0; i < 3; ++i)
    {
        int size = validSizes[i];
        player->ships[i].size = size;
        player->ships[i].hits = (int *)malloc(size * sizeof(int));

        
        for (int j = 0; j < size; ++j)
        {
            player->ships[i].hits[j] = 0;
        }

        
        int x, y;
        int direction;

        do
        {
            x = rand() % boardSize;
            y = rand() % boardSize;
            direction = rand() % 2; 
        } while (!kontrolEt(player, x, y, direction, size, boardSize));

        
        if (direction == 0)
        {
            
            for (int j = 0; j < size; ++j)
            {
                player->board[x + j][y] = 'O';
            }
        }
        else
        {
            
            for (int j = 0; j < size; ++j)
            {
                player->board[x][y + j] = 'O';
            }
        }
    }
}

int vurus(Player *player, int x, int y, int currentPlayer, int boardSize)
{

    if (x - 1 >= 0 && x - 1 < boardSize && y - 'A' >= 0 && y - 'A' < boardSize &&
        player->board[x - 1][y - 'A'] == 'O')
    {
        printf("isabet etti!\n");
        player->board[x - 1][y - 'A'] = 'X';
        if (currentPlayer == 1)
        {
            p1Hit = p1Hit + 1;
            printf("\n1. Oyuncunun Puani: %d\n", p1Hit);
        }
        else
        {
            p2Hit = p2Hit + 1;
            printf("\n2. Oyuncunun Puani: %d\n", p2Hit);
        }

        return 1;
    }
    printf("isabet etmedi!\n");
    return 0; 
}

int oyunBitisi()
{
    if (p1Hit < 10 && p2Hit < 10)
    {
        return 0; 
    }
    return 1; 
}

void oyunDurumuGoster(Player *player1, Player *player2, int boardSize)
{
    system(CLEAR); 
    printf("\n");
    printf("Oyuncu 1 Tahtasi:\n");
    printf("2. Oyuncu Toplam Hamle Sayisi: %d\n", player1->hamleSayisi);
    printf("\n");
    tahtayiYaz(player1, boardSize);

    printf("\n");
    printf("Oyuncu 2 Tahtasi:\n");
    printf("1. Oyuncu Toplam Hamle Sayisi: %d\n", player2->hamleSayisi);
    printf("\n");
    tahtayiYaz(player2, boardSize);
    printf("\n");
}

void serbestBirak(Player *player, int boardSize)
{
    for (int i = 0; i < boardSize; ++i)
    {
        free(player->board[i]);
    }
    free(player->board);

    for (int i = 0; i < 3; ++i)
    {
        free(player->ships[i].hits);
    }
}
