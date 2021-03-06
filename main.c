#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include "mine.h"
#include <time.h>

//bomb array
int x = 10, y = 10;


mine_t **new_map(int rows, int colums){
    mine_t **map = malloc(rows * sizeof(mine_t *));
    if(map == NULL){
        //error
        return NULL;
    }

    //create all the colums in the array with arrays
    for (int i = 0; i < colums; i++)
    {
        mine_t *c_map = malloc(rows * sizeof(mine_t)); 
        if(c_map == NULL){
            //error
            return NULL;
        }
        map[i] = c_map;
    }
    
    //mine_t map = (mine_t *)malloc(rows * colums * sizeof(mine_t)); 
    if(map == NULL){
        return NULL;
    }
    return map;
}

//place bombs in map
int fill_map(mine_t *map, int x, int y, int bombs){
    mine_t *new;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            //map[i][j] = mine_create(j, 0, 0);
        }
        
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            //printf("[%d], ", array[i][j]->bomb);
        }
        printf("\n");
    }
    
}

//open bomb


/* 
*  map bombs, 
*  safe x,y is the position the player first opens 
*  bombs is nr. of bombs
*/
int map_bombs(mine_t **map, int rows, int colums, int safe_x, int safe_y, int bombs){
    if(rows * colums <= bombs){//error to many bombs
        return -1;
    }

    int placement[rows * colums]; //array to choose bomb position
    for (int i = 0; i < rows * colums; i++)
    {
        placement[i] = i;
    }

    //randomize placements
    for (int i = 0; i < rows * colums; i++)
    {
        int r = rand() % rows * colums;
        int tmp = placement[r];
        placement[r] = placement[i];
        placement[i] = tmp;
    }

    //place all the bombs into the map
    
    int count = 0, i = 0;
    while(count < bombs){ //add all bombs
        if(i >= rows * colums){
            //somthing went wrong..
            return -1;
        }

        //calculate the n'th positon in the matrix
        int colum = placement[i] % (colums);
        int row = (placement[i] - colum) / rows;

        i++;

        if(!(row == safe_x && colum == safe_y)){//increase bomb count in map if spot shouldn't be safe
            count++;
            map[row][colum].bomb = 1;    
        }

    }
    
    return 0;
}

void print_bombs(mine_t **map, int rows, int colums){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            printf("[%d]", map[i][j].bomb);
        }
        printf("\n");
    }
    
}

void print_count(mine_t **map, int rows, int colums){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            printf("[%d]", map[i][j].count);
        }
        printf("\n");
    }
    
}

/*
* Count how many bombs surround the bomb map[x][y] -> map_nearby_bombs helper function
*/
void check_nearby(mine_t **map, int rows, int colums, int x, int y){
    //check left
    mine_t *current = &map[x][y];
    if(x - 1 >= 0){ //if left exist..
        if(y - 1 >= 0){//check upper left corner
            current->count += map[x-1][y-1].bomb;
        }

        //middle left exists
        current->count += map[x-1][y].bomb;

        //check lower left
        if(y + 1 < rows){
            current->count += map[x-1][y+1].bomb;
        }
    }

    if(x + 1 < colums){ //if right exist..
        if(y - 1 >= 0){ //check upper right
            current->count += map[x+1][y-1].bomb;
        }

        //middle right exists
        current->count += map[x+1][y].bomb;

        if(y + 1 < rows){ //check lower right
            current->count += map[x+1][y + 1].bomb;
        }
    }


    if(y - 1 >= 0){ //if up exist...
        current->count += map[y-1][x].bomb;
    }

    if(y + 1 < rows){ //if down exist...
        current->count += map[y+1][x].bomb;
    }

}

/*
* Count the bombs next to each bomb in the matrix.
*/
void map_nearby_bombs(mine_t **map, int rows, int colums){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            check_nearby(map, rows, colums, i, j);
        }
        
    }
    
}

int main(){
    initscr();//initialize ncurses screen

    srand(time(NULL));   //for random function

        while(1){//TODO add user input
            printf("%c",getch());
        }
        printf("end\n");

    
    /*
    mine_t **map = new_map(x,y);

    map_bombs(map, y, x, 5, 5, 99);
    map_nearby_bombs(map, y, x);


    print_bombs(map, x, y);
    printf("\n");
    print_count(map, x, y);
    */
}
/*
int game_loop(){
    while(1){
        int c = getch();

        switch (c)
        {
        case 1:
             
            break;
        
        default:
            break;
        }
    }
}*/