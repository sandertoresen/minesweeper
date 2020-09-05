//#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include "mine.h"

//bomb array
const int x = 10, y = 10;

mine_t array[x][y];

//place bombs
int fill_mine_array(mine_t array, int x, int y, int bombs){
    mine_t *new;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            array[i][j] = mine_create(0, 0, 0);
        }
        
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("[%d], ", &array[i][j].bomb);
        }
        printf("\n");
    }
    
}

//open bomb


//print map

//map bombs


int main(){
    fill_mine_array(array, x, y, 0);
}