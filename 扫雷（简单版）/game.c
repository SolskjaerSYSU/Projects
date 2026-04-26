#define  _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void  DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("------------扫雷----------\n");
	int i = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

}

//布置雷是在棋盘上随即找10个坐标布置的
//x:1~9
//y:1~9
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count =EASY_COUNT ;
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;

		if (mine[x][y] != '1')
		{
			mine[x][y] = '1';//	布置一个雷
			count--;
		}
	}

}
//排查雷
//1.输入一个坐标
//2.判断这个坐标是否越界
//3.这个位置是雷 
//如果是雷，就炸死了，游戏结束
//如果不是雷，就统计这个位置周围雷的个数，显示
int GetMineCount(char mine[ROWS][COLS],int x,int y)
{
	return (mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y-1] + mine[x + 1][y] +mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0');
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<col*row-EASY_COUNT)
	{
		printf("请输入要排查的坐标:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')  //输入的位置是雷
			{
				printf("很遗憾，你踩雷了，游戏结束\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else //不是雷
			{
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("输入的坐标有误，请重新输入");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, ROW, COL);
	}
}



