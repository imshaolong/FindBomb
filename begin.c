#include "game.h"
void menu()
{
	printf("****************************\n");
	printf("**     1. play   0. exit  **\n");
	printf("****************************\n");
}
void play() 
{
	char bomb[ROWS][COLS];
	char show[ROWS][COLS];
	srand((unsigned)time(NULL));
	//1.初始化
	init_board(bomb, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');
	display_board(show, ROW, COL);
	//2.布雷
	set_bomb(bomb, ROW, COL);
	display_board(bomb, ROW, COL);
	//3.扫雷
	find_bomb(bomb, show, ROW, COL);

}

int main()
{
	int input = 0;
	do {
		menu();
		printf("请选择:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			play();
			break;
		case 0:
			printf("游戏已退出！\n");
			break;
		default:
			printf("选择有误!请重新输入");
			break;
		}
	} while (input);
	return 0;
}
