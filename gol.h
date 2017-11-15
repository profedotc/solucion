#ifndef _GOL_H_
#define _GOL_H_

#include <stdbool.h>

#define GOL_SIZE_X 10
#define GOL_SIZE_Y 20

struct gol {
	bool worlds[2][GOL_SIZE_X][GOL_SIZE_Y];
	unsigned int current_world;
};

void gol_init(struct gol *gol);
void gol_print(const struct gol *gol);
void gol_step(struct gol *gol);
int gol_count_neighbors(const struct gol *gol, int x, int y);
bool gol_get_cell(const struct gol *gol, int x, int y);

#endif
