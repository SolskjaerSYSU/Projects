#define  _CRT_SECURE_NO_WARNINGS 1


//int Add(int x,int y)
//{ 
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	//输入
//	scanf("%d %d", &a, &b);
//	//调用加法函数，完成a和b的相加
//	//求和结果放在r中
//	int r = Add(a, b);
//	//输出
//	printf("%d\n", r);
//
//	return 0;
//}

//int test()
//{
//	printf("haha\n");
//	return 10;
//}
//int main()
//{
//
//	int r = test();
//	printf("%d\n", r);
//
//	return 0;
//}
//void set_arr(int arr[10], int sz,int set)//void表示干完活就行，不需要返回任何值
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)//sz规定好了数组的长度，这样不多也不少
//	{
//		arr[i] = set;
//	}
//}
//
//void print_arr(int arr[10], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	set_arr(arr, sz,-1);
//	print_arr(arr, sz);
//	return 0;
//
// }
//void test()
//{
//	static int a = 0;
//	a++;
//	printf("%d ", a);
//}
//
//
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		test();
//	}
//	return 0;
//}

//
//void game()
//{
//	int r = rand() % 100 + 1; 
//	int guess = 0;
//	while(1)
//	{
//		printf("请猜数字>:\n");
//		scanf("%d", &guess);
//		if (guess < r)
//		{
//			printf("猜小了\n");
//		}
//		if (guess > r)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("恭喜你,猜对了!\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d ", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 2:
//			printf("游戏结束\n");
//			break;
//		default:
//			printf("选择错误，重新选择\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//
//}
//	int 
//
//void test()
//{
//	static int i= 0;
//	i++;
//	printf("%d ", i);
//
//
//
//}
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 5; i++)
//	{
//		test();
//	}
//
//
//	return 0;
//}


//int g_val = 2026;
//
//int main()
//{
//	
//
//
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//void menu()
//{
//	printf("***********************\n");
//	printf("******  1. play  ******\n");
//	printf("******  0. exit  ******\n");
//	printf("***********************\n");
//}
//void game()
//{
//	int r = rand() % 100 + 1;
//	int guess = 0;
//	while (1)
//	{
//		printf("请猜数>:");
//        scanf("%d", &guess);
//		if (guess < r)
//		{
//			printf("猜小了\n");
//		}
//		else if (guess > r)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("恭喜你，猜对了\n");
//				break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择: >");
//			scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("游戏结束\n");
//			break;
//		default:
//			printf("选择错误，重新选择\n");
//			break;
//		}
//	} while (input);
//	return 0;
//	}
//
//
//#include <stdio.h>
//int main()
//{
//	char arr1[] = { "abc" };
//	char arr2[] = { 'a','b','c','\0'};
//	printf("%zd\n",sizeof(arr1));
//	printf("%zd\n",sizeof(arr2));
//	return  0;
//	
//}
//#include <stdio.h>
//
//int main() {
//    int a = 0, b = 0, c = 0;
//    int MAX = 0, MIN = 0, MID = 0;
//
//    printf("请输入三个1-9之间的整数: ");
//    scanf("%d %d %d", &a, &b, &c);
//
//  
//    if ((a > 0 && a < 10) && (b > 0 && b < 10) && (c > 0 && c < 10)) 
//    {
//        MAX = a >= b ? (a >= c ? a : c) : (b >= c ? b : c);
//        MIN = a <= b ? (a <= c ? a : c) : (b <= c ? b : c);
//        MID = a + b + c - MIN - MAX;
//
//        if (MIN + MID > MAX) 
//        {
//            if (MIN == MAX && MAX == MID) 
//            {
//                printf("Equilateral triangle!\n");
//            }
//            else if (MIN == MID || MID == MAX) 
//            {
//                printf("Isosceles triangle!\n");
//            }
//            else
//            {
//                printf("Ordinary triangle!\n");
//            }
//        }
//        else {
//            printf("Not a triangle!\n");
//        }
//    }
//    else {
//        printf("超出范围，重新输入！\n");
//    }
//
//    return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//    // 外层循环控制行 i
//    for (int i = 1; i <= 9; i++) 
//    {
//
//        for (int j = 1; j <= i; j++) 
//        {
//
//            printf("%d*%d=%d\t", j, i, i * j);
//        }
//
//        printf("\n");
//    }
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int i = 0;
//	for (a = 101; a <= 200; a++)
//	{
//		int flag = 1;
//		for (i = 2; i < a; i++)
//		{
//			if (a % i == 0)
//			{
//				printf("%d ", a);
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			printf("%d ", a);
//		}
//	}
//
//
//	return 0;
//}

#include "game.h"


void menu()
{
    printf("***********************\n");
    printf("*****   1. play   *****\n");
    printf("*****   0. exit   *****\n");
    printf("***********************\n");
}

void game()
{
    char mine[ROWS][COLS] = { 0 };//存放雷的信息
    char show[ROWS][COLS] = { 0 };//存放排查出雷的信息

    //初始化棋盘
    InitBoard(mine,ROWS,COLS,'0');
    InitBoard(show, ROWS, COLS,'*');

    //打印棋盘
    DisplayBoard(show, ROW, COL);
    //DisplayBoard(mine, ROW, COL);

    //布置雷
    SetMine(mine,ROW,COL);
    DisplayBoard(mine, ROW, COL);


    //排查雷
    FindMine(mine, show, ROW, COL);


}
test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择: > ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误，重新选择\n");
            break; printf("请选择: > ");
            scanf("%d", &input);
            switch (input)
            {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("\n");
                break;

            }

        }

    } while (input);
    return 0;
}


int main()
{
    test();
    return 0;
}