#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GOL_SIZE_X 10
#define GOL_SIZE_Y 20

void gol_init(bool w[GOL_SIZE_X][GOL_SIZE_Y]);
void gol_print(bool w[GOL_SIZE_X][GOL_SIZE_Y]);
void gol_step(bool wa[GOL_SIZE_X][GOL_SIZE_Y], bool wb[GOL_SIZE_X][GOL_SIZE_Y]);
int gol_count_neighbors(bool w[GOL_SIZE_X][GOL_SIZE_Y], int x, int y);
bool gol_get_cell(bool w[GOL_SIZE_X][GOL_SIZE_Y], int x, int y);
void gol_copy(bool dst[GOL_SIZE_X][GOL_SIZE_Y], bool src[GOL_SIZE_X][GOL_SIZE_Y]);

int main()
{
	int i = 0;
	bool world_a[GOL_SIZE_X][GOL_SIZE_Y];
	bool world_b[GOL_SIZE_X][GOL_SIZE_Y];

	gol_init(world_a);
	do {
		printf("\033cIteration %d\n", i++);
		gol_print(world_a);
		gol_step(world_a, world_b);
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}

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

	gol_copy(wa, wb);
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

void gol_copy(bool dst[GOL_SIZE_X][GOL_SIZE_Y], bool src[GOL_SIZE_X][GOL_SIZE_Y])
{
	for (int i = 0; i < GOL_SIZE_X; i++)
		for (int j = 0; j < GOL_SIZE_Y; j++)
			dst[i][j] = src[i][j];
}
