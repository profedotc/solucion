#include "gol.h"

#include <stdio.h>

void gol_init(bool w[GOL_SIZE_X][GOL_SIZE_Y])
{
	for (int i = 0; i < GOL_SIZE_X; i++)
		for (int j = 0; j < GOL_SIZE_Y; j++)
			w[i][j] = false;

	// Glider
	w[0][1] = true;
	w[1][2] = true;
	w[2][0] = true;
	w[2][1] = true;
	w[2][2] = true;
}

void gol_print(bool w[GOL_SIZE_X][GOL_SIZE_Y])
{
	for (int i = 0; i < GOL_SIZE_X; i++) {
		for (int j = 0; j < GOL_SIZE_Y; j++) {
			printf("%s", w[i][j] ? " #" : " .");
		}
		printf("\n");
	}
	printf("\n");
}

void gol_step(bool wa[GOL_SIZE_X][GOL_SIZE_Y], bool wb[GOL_SIZE_X][GOL_SIZE_Y])
{
	for (int i = 0; i < GOL_SIZE_X; i++) {
		for (int j = 0; j < GOL_SIZE_Y; j++) {
			int n = gol_count_neighbors(wa, i, j);
			wb[i][j] = (wa[i][j] && n == 2) || n == 3;
		}
	}
}

int gol_count_neighbors(bool w[GOL_SIZE_X][GOL_SIZE_Y], int x, int y)
{
	int count = 0;

	count += gol_get_cell(w, x - 1, y + 1);
	count += gol_get_cell(w, x - 0, y + 1);
	count += gol_get_cell(w, x + 1, y + 1);
	count += gol_get_cell(w, x - 1, y + 0);
	count += gol_get_cell(w, x + 1, y + 0);
	count += gol_get_cell(w, x - 1, y - 1);
	count += gol_get_cell(w, x - 0, y - 1);
	count += gol_get_cell(w, x + 1, y - 1);

	return count;
}

bool gol_get_cell(bool w[GOL_SIZE_X][GOL_SIZE_Y], int x, int y)
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

	return w[x][y];
}
