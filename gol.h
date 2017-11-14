#ifndef _GOL_H_
#define _GOL_H_

#include <stdbool.h>

#define GOL_SIZE_X 10
#define GOL_SIZE_Y 20

void gol_init(bool w[GOL_SIZE_X][GOL_SIZE_Y]);
void gol_print(bool w[GOL_SIZE_X][GOL_SIZE_Y]);
void gol_step(bool wa[GOL_SIZE_X][GOL_SIZE_Y], bool wb[GOL_SIZE_X][GOL_SIZE_Y]);
int gol_count_neighbors(bool w[GOL_SIZE_X][GOL_SIZE_Y], int x, int y);
bool gol_get_cell(bool w[GOL_SIZE_X][GOL_SIZE_Y], int x, int y);

#endif
