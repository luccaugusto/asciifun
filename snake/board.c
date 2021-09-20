#include <stdlib.h>
#include <stdio.h>

struct Board{
	int height;
	int width;
	char *board;
	int *empty_spaces;
};

void
board_set_width(struct Board *b, int width)
{
	b->width = width;
}

void
board_set_height(struct Board *b, int height)
{
	b->height = height;
}

int
board_get_width(struct Board *b)
{
	return b->width;
}

int
board_get_height(struct Board *b)
{
	return b->height;
}

int
board_get_size(struct Board *b)
{
	return (board_get_height(b) * board_get_width(b));
}

char *
board_get_board(struct Board *b)
{
	return b->board;
}

int *
board_get_empty_spaces(struct Board *b)
{
	return b->empty_spaces;
}

void
destroy_board(struct Board *b)
{
	free(board_get_board(b));
	free(board_get_empty_spaces(b));
	free(b);
}

void
show_board(struct Board *b)
{
	int height = board_get_height(b);
	int width = board_get_width(b);
	char *board = board_get_board(b);

	for (int y=0; y<height; ++y) {
		for (int x=0; x<width; ++x) {
			printf(" %d", board[y * width + x]);
		}
		printf("\n");
	}
}

void
board_drop_apple(struct Board *b)
{
	(void) b;
}

struct Board *
new_board(int height, int width)
{
	struct Board *b = malloc(sizeof(struct Board));
	board_set_height(b, height);
	board_set_width(b, width);
	b->board = malloc(sizeof(char) * height * width);
	b->empty_spaces = malloc(sizeof(char) * height * width);
	return b;
}
