#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "MathsFuncs.h"
#include <stdbool.h>

#ifndef game_H_   /* Include guard */
#define game_H_

void switchturn(short int *CurrentTurn);
void set_console_color(WORD color);
bool CoinFlip();
void ShowLives(short int CurrentTurn,short int PlayerLives, short int DealerLives);

#endif