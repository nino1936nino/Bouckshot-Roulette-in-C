#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "MathsFuncs.h"

void shuffle_bullets(char array[],short int *BlankBullets,short int *LiveBullets, short int *TotalBullets)
{   
    *BlankBullets = random_range(1, 5);
    *LiveBullets = random_range(1, 5);
    *TotalBullets = *BlankBullets + *LiveBullets;

    // Fill the array with bullets riempio l'array di proiettili
    for (int i = 0; i < *LiveBullets; i++) {
        array[i] = 1; // Live bullet pallottola piena
    }
    for (int i = *LiveBullets; i < *TotalBullets; i++) {
        array[i] = 0; // Blank bullet pallottola vuota
    }

    // uaaaa figo sto algoritmo di pescatore yales , fisher yales algorithm
    for (int i = *TotalBullets - 1; i > 0; i--) { // per i da n - 1 fino a 1 fai 
        int randomIndex = rand() % (i + 1); //numero intero casuale con 0 <= j <= i
        char temp = array[i]; 
        array[i] = array[randomIndex];
        array[randomIndex] = temp;
    }
}
int random_range(int min, int max)
{
    int rd_num = rand() % (max - min + 1) + min;
    return rd_num;
}

static void menu_input_buffer_clear()
{
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}
void menu_input_strings(char* buff, int size)
{
    if ((fgets(buff,size,stdin)) && !strchr(buff, '\n'))
    menu_input_buffer_clear();
}