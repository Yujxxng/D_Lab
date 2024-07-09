// TODO
#include "minesweeper-utils.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	char state;
	bool is_visible;
} Tile;

typedef Tile* Row;
typedef struct Map
{
	unsigned short int width;
	unsigned short int height;
	Row* grid;
} Map;
///////////////////////////////////////////////

Map* create_map(unsigned short int width, unsigned short int height)
{
	Map* map = malloc(sizeof(Map));
	map->width = width;
	map->height = height;
	map->grid = malloc(sizeof(Tile*) * width);
	
	for(int i = 0; i < (int)width; i++)
	{
		map->grid[i] = malloc(sizeof(Tile) * height);
	}
	
	return map;
}

void destroy_map(Map* map)
{
	if(map == NULL) return;
	
	free(map->grid);
	free(map);
}

void set_tile(Map* map,	unsigned short int column, unsigned short int row, char state, bool is_visible)
{
	map->grid[column][row].state = state;
	map->grid[column][row].is_visible = is_visible;
}

void print_map(const Map* map)
{
	//width
	printf("  ");
	for(int i=0; i < (int)map->width; i++)
	{
		if(i == ((int)map->width - 1))
			printf("%d\n", i);
		else
			printf("%d ", i);
	}
	
	for(int i=0; i < (int)map->height; i++)
	{
		printf("%d|", i);
		for(int j=0; j < (int)map->width; j++)
		{
			if(!map->grid[j][i].is_visible)
				printf(" |");
			else
				printf("%c|", map->grid[j][i].state);
		}
		printf("\n");
	}
}

void initialize_map(Map* map, float probability)
{
	for(int i=0; i < (int)map->height; i++)
	{
		for(int j=0; j < (int)map->width; j++)
		{
			map->grid[j][i].is_visible = false;
			int r = rand()%100;
			if(r >= probability * 100)
				map->grid[j][i].state = 'X';
			else
				map->grid[j][i].state = '0';
		}
	}
	
	int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
	int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	
	for(int i=0; i < (int)map->height; i++)
	{
		for(int j=0; j < (int)map->width; j++)
		{
			if(map->grid[j][i].state != 'X')
			{
				int b = 0;
				for(int k=0; k < 8; k++)
				{
					if(j+dx[k] >= map->width || j+dx[k] < 0 ||
						i+dy[k] >= map->height || i+dy[k] < 0) continue;
					
					if(map->grid[j+dx[k]][i+dy[k]].state == 'X')
						b++;
				}
				map->grid[j][i].state = (char)(b + '0');
			}
		}
	}
	
}

void reveal_all_tiles(Map* map)
{
	for(int i=0; i < (int)map->height; i++)
	{
		for(int j=0; j < (int)map->width; j++)
		{
			map->grid[j][i].is_visible = true;
		}
	}
}

bool all_empty_tiles_visible(const Map* map)
{
	for(int i=0; i < (int)map->height; i++)
	{
		for(int j=0; j < (int)map->width; j++)
		{
			if(map->grid[j][i].state != 'X' && map->grid[j][i].is_visible == false)
				return false;
		}
	}
	return true;
}

bool is_bomb_tile(Map* map,	unsigned short int column, unsigned short int row)
{
	if(column >= map->width || row >= map->height)
	{
		fprintf(stdout, "Error: wrong column or row specified.\n");
		return false;
	}
	
	if(map->grid[column][row].state == 'X')
	{
		map->grid[column][row].is_visible = true;
		return true;
	}
	else
		map->grid[column][row].is_visible = true;
	return false;
}