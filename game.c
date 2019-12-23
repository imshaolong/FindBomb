#include "game.h"

void init_board(char board[ROWS][COLS], int rows, int cols, char ch)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = ch;
		}
	}
}

void display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("--------------------\n");
	printf("0 1 2 3 4 5 6 7 8 9\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("--------------------\n");

}

void set_bomb(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	while (count < EASY) {
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count++;
		}
	}
}

char get_bomb_num(char board[ROWS][COLS], int x, int y)
{
	return board[x - 1][y] + board[x - 1][y - 1] 
		+ board[x][y - 1]+ board[x + 1][y - 1] 
		+ board[x + 1][y]+ board[x + 1][y + 1]
		+ board[x][y + 1]+ board[x - 1][y + 1] - 7 * '0';
}

void find_bomb(char bomb[ROWS][COLS], \
	char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	while (count < row * col - EASY) 
	{
		printf("请输入要排雷的位置:> ");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col) 
		{
			if (bomb[x][y] == '1')
			{
				printf("恭喜你！你被炸死了！~");
				display_board(bomb, ROW, COL);
				break;
			}
			else 
			{
				show[x][y] = get_bomb_num(bomb, x, y);
				display_board(show,ROW,COL);
				count++;

			}
		}
		else 
		{
			printf("输入位置不合法,请重新输入！~");
		}

	}
	if (count == row * col - EASY)
		printf("恭喜你排雷成功！");
}
