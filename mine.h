#ifndef MINE_H
#define MINE_H


typedef struct mine mine_t;

struct mine
{
    int bomb;
    int visible;
    int count;
};

mine_t *mine_create(int bomb, int visible, int count);

int mine_delete(mine_t *remove);


int is_bomb(mine_t *bomb);



#endif