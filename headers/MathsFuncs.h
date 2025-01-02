#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>




#ifndef MathsFuncs_H_   /* Include guard */
#define MathsFuncs_H_

void shuffle_bullets(char array[],short int *BlankBullets,short int *LiveBullets,short int *TotalBullets);
int random_range(int min, int max);
static void menu_input_buffer_clear();
void menu_input_strings(char* buff, int size);
#endif