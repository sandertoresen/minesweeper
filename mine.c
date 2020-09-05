#include <stdlib.h>
#include <stdio.h>
#include "mine.h"

mine_t *mine_create(int bomb, int visible, int count){
    mine_t *new = malloc(sizeof(mine_t));
    if(new == NULL){
        //toggle error msg?
        return NULL;
    }

    new->bomb = bomb;
    new->visible = visible;
    new->count = count;

    return new;
}

int mine_delete(mine_t *remove){
    return -1;
    //return free(&remove);
}


int is_bomb(mine_t *bomb){
    if(bomb->bomb){
        return 1;
    }
    return 0;
}