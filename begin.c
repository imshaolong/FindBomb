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
	//1.��ʼ��
	init_board(bomb, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');
	display_board(show, ROW, COL);
	//2.����
	set_bomb(bomb, ROW, COL);
	display_board(bomb, ROW, COL);
	//3.ɨ��
	find_bomb(bomb, show, ROW, COL);

}

int main()
{
	int input = 0;
	do {
		menu();
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			play();
			break;
		case 0:
			printf("��Ϸ���˳���\n");
			break;
		default:
			printf("ѡ������!����������");
			break;
		}
	} while (input);
	return 0;
}
