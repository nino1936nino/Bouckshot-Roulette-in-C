#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "MathsFuncs.h"
#include "game.h"
#include <stdbool.h>

void switchturn(short int *CurrentTurn)
{
    if (*CurrentTurn == 1){
        *CurrentTurn = 0;
    }
    else if (*CurrentTurn == 0){
        *CurrentTurn = 1;
    }

}
void set_console_color(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
bool CoinFlip(){
    short int result = random_range(1,2);
    if (result == 1){
        return true;
    }
    else{
        return false;
    }
}
void ShowLives(short int CurrentTurn,short int PlayerLives, short int DealerLives){
        printf("\033[0;32m"); //mettiamo verde
        printf("Player Lives:%d\n", PlayerLives);
        printf("Dealer Lives:%d\n", DealerLives);
        printf("\033[0m");
}