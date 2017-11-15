#include "gol.h"

#include <stdio.h>

void gol_init(struct gol *gol)
{
	gol->current_world = 0;

	for (int i = 0; i < GOL_SIZE_X; i++)
		for (int j = 0; j < GOL_SIZE_Y; j++)
			gol->worlds[gol->current_world][i][j] = false;

	// Glider
	gol->worlds[gol->current_world][0][1] = true;
	gol->worlds[gol->current_world][1][2] = true;
	gol->worlds[gol->current_world][2][0] = true;
	gol->worlds[gol->current_world][2][1] = true;
	gol->worlds[gol->current_world][2][2] = true;
}

void gol_print(const struct gol *gol)
{
	for (int i = 0; i < GOL_SIZE_X; i++) {
		for (int j = 0; j < GOL_SIZE_Y; j++) {
			printf("%s", gol->worlds[gol->current_world][i][j] ?
				" #" : " .");
		}
		printf("\n");
	}
	printf("\n");
}

void gol_step(struct gol *gol)
{
	for (int i = 0; i < GOL_SIZE_X; i++) {
		for (int j = 0; j < GOL_SIZE_Y; j++) {
			int n = gol_count_neighbors(gol, i, j);
			gol->worlds[!gol->current_world][i][j] =
				(gol->worlds[gol->current_world][i][j] && n == 2)
				|| n == 3;
		}
	}

	gol->current_world = !gol->current_world;
}

int gol_count_neighbors(const struct gol *gol, int x, int y)
{
	int count = 0;

	count += gol_get_cell(gol, x - 1, y + 1);
	count += gol_get_cell(gol, x - 0, y + 1);
	count += gol_get_cell(gol, x + 1, y + 1);
	count += gol_get_cell(gol, x - 1, y + 0);
	count += gol_get_cell(gol, x + 1, y + 0);
	count += gol_get_cell(gol, x - 1, y - 1);
	count += gol_get_cell(gol, x - 0, y - 1);
	count += gol_get_cell(gol, x + 1, y - 1);

	return count;
}

bool gol_get_cell(const struct gol *gol, int x, int y)
{
	// Fix coords
	if (x >= GOL_SIZE_X)
		x = 0;
	else if (x < 0)
		x = GOL_SIZE_X - 1;

	if (y >= GOL_SIZE_Y)
		y = 0;
	else if (y < 0)
		y = GOL_SIZE_Y - 1;

	return gol->worlds[gol->current_world][x][y];
}
