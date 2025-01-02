#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include "MathsFuncs.h"
#include "game.h"


enum GameStates {
    ENDED,
    PENDING,
};


int main()
{
    while(1){
    srand(time(NULL));
    char answer[10]; // mettiamo abbastanza spazi così il player può scrivere , Allocate sufficient space for user input
    char Bullets[10]; // mettiamo 10 perchè si
    printf("\033[1;31m");
    printf("Welcome to buckshot roulette. Do you want to play? (y/n)\n");
    printf("\033[0m");
    menu_input_strings(answer , 10);

    if (strcmp(answer, "y\n") == 0) {
        short int BlankBullets;
        short int LiveBullets;
        short int TotalBullets;
        short int Lives = random_range(2, 5);
        shuffle_bullets(Bullets, &BlankBullets, &LiveBullets,&TotalBullets);

        printf("Shuffled bullets: ");
        printf("%d.LiveBullets ",LiveBullets);
        printf("%d.BlankBullets\n ",BlankBullets);
        printf("\033[0;33m");
        for (int i = 0; i < BlankBullets + LiveBullets; i++) {
            printf("%d ", Bullets[i]);
        }
        printf("\033[0m");
        printf("\n");
        short int PlayerLives = Lives;//non faccio un pointer perchè voglio una copia del valore non quel valore direttamente
        short int DealerLives = Lives;
        printf("\033[0;32m"); //mettiamo verde
        printf("Player Lives:%d\n", PlayerLives);
        printf("Dealer Lives%d\n", DealerLives);
        printf("\033[0m");
        short int CurrentTurn = 0;
        short int CurrentRound = 1;
        short int CurrentShell = 0;
        char answer2[10];
        short int Score = 0;
        enum GameStates State = PENDING;
        while(State == PENDING)
        {
            if (CurrentTurn == 0){                 //Praticamente il turno del giocatore  
                    printf("\033[0;36m");
                    printf("now you're playing\n");
                    printf("\033[1;31m");
                    printf("do you wanna shoot you or the dealer?:) myself/dealer\n");
                    printf("\033[0m");
                    menu_input_strings(answer2 , 10);
                    if (strcmp(answer2, "myself\n") == 0){
                        if (Bullets[CurrentShell] == 1){
                            CurrentShell += 1;
                            printf("blud you shot yourself\n");
                            PlayerLives -= 1;
                            Score -= 20;
                            ShowLives(CurrentTurn,PlayerLives,DealerLives);
                            switchturn(&CurrentTurn);
                        }
                        else{
                            CurrentShell += 1;
                            Score += 50;
                            printf("great you ain't dead\n");
                            ShowLives(CurrentTurn,PlayerLives,DealerLives);
                        }
                    }
                    else if (strcmp(answer2, "dealer\n") == 0){
                        printf("attemps to shoot the dealer\n");
                        if (Bullets[CurrentShell] == 1){
                            printf("\033[1;31m");
                            printf("succesfully shot him\n");
                            printf("\033[0m");
                            Score += 50;
                            CurrentShell += 1;
                            DealerLives -= 1;
                            ShowLives(CurrentTurn,PlayerLives,DealerLives);
                            switchturn(&CurrentTurn);
                        }
                        else{
                            printf("the shell was blank\n");
                            ShowLives(CurrentTurn,PlayerLives,DealerLives);
                            CurrentShell += 1;
                            Score -= 10;
                            switchturn(&CurrentTurn);
                        }

                    }

                    
            }
            if (CurrentTurn == 1){             //Turno dell'IA per non dire codice che fa robe a 50/50
                    printf("\033[0;36m");
                    printf("now the dealer is playing\n");
                    printf("\033[0m");
                    bool Action = CoinFlip();
                    if ((Action == true) && (Bullets[CurrentShell] == 1)){
                        printf("The dealer shot you");
                        CurrentShell += 1;
                        PlayerLives -= 1;
                        ShowLives(CurrentTurn,PlayerLives,DealerLives);
                        switchturn(&CurrentTurn);
                    }
                    else if ((Action == true) && (Bullets[CurrentShell] == 0)){
                        printf("The dealer didn't shoot you");
                        CurrentShell += 1;
                        ShowLives(CurrentTurn,PlayerLives,DealerLives);
                        switchturn(&CurrentTurn);
                    }
                    else if ((Action == false) && (Bullets[CurrentShell] == 1)){
                        CurrentShell += 1;
                        DealerLives -= 1;
                        printf("the dealer shot himself\n");
                        ShowLives(CurrentTurn,PlayerLives,DealerLives);
                        switchturn(&CurrentTurn);
                    }
                    else if ((Action == false) && (Bullets[CurrentShell] == 0)){
                        printf("the dealer didn't shoot himself\n");
                        CurrentShell += 1;
                        ShowLives(CurrentTurn,PlayerLives,DealerLives);
                        
                    }


            }
            if ((CurrentShell >= TotalBullets) || (PlayerLives <= 0) || (DealerLives <= 0)) {
                State = ENDED;
            }



        }
        printf("\033[0;33m");
        printf("%d.Score ",Score);
        printf("\033[0m");
        printf("\033[1;31m");
        printf("Do you want to play again? (y/n)\n");
        printf("\033[0m");
        menu_input_strings(answer , 10);
        if (strcmp(answer, "y\n") == 0) {
                printf("Great.\n");
        }
        if (strcmp(answer, "n\n") == 0) {
                printf("Thanks for playing! Goodbye.\n");
                exit(0);
                break; // Exit the loop and terminate the program
        }
    } else {
        printf("Maybe next time!\n");
    }

    }

    return 0;
}


