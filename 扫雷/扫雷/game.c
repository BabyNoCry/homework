#include"game.h"
#include<stdio.h>

void muen()
{
	printf("****************************************\n");
	printf("********         1.play       **********\n");
	printf("********         0.exit       **********\n");
	printf("****************************************\n");
	printf("\n");
}
void inint_mine(char arr[ROW][COL], char arr2[ROW][COL],int row, int col)//初始化期盘
{
	memset(arr, '*', row*col);
	memset(arr2, '0', row*col);
}
void print_player(char arr[ROW][COL], int row, int col)//打印玩家棋盘
{
	int i = 0, j = 0;
	for (i = 0; i < col-1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i < row - 1; i++)
	{
		printf("%d ", i);
		for (j = 1; j < col - 1; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void print_mine(char arr[ROW][COL], int row, int col)//打印答案
{
	int i = 0, j = 0;
	for (i = 0; i < col - 1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i < row - 1; i++)
	{
		printf("%d ", i);
		for (j = 1; j < col - 1; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void set_mine(char arr[ROW][COL], int row, int col)//设置地雷
{
	int x = 0, y = 0;
	int k = COUNT;
	while (k)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			k--;
		}

	}
	
}
void check_mine(char arr[ROW][COL],char arr2[ROW][COL], int a, int b)//计算该位置周围雷数
{
	int i = 0,j = 0;
	char count;
	count = arr2[a - 1][b - 1]-'0' + arr2[a - 1][b]-'0' + arr2[a - 1][b + 1]-'0' + arr2[a][b - 1]-'0'
		+ arr2[a][b + 1]-'0' + arr2[a + 1][b - 1]-'0' + arr2[a + 1][b]-'0'+arr2[a+1][b+1];
	arr[a][b] = count;
}
void safe_mine(char arr[ROW][COL],char arr2[ROW][COL], int row, int col)//避免第一次被炸死
{
	int x = 0, y = 0;
	while (1)
	{
		printf("请输入坐标扫雷：>");
		int i = 0, j = 0;
		scanf("%d%d", &i, &j);
		if (i >= 0 && i <= 9 && j >= 0 && j <= 9)
		{
			if (arr2[i][j] == '1')
			{
				arr2[i][j] ='0';
				while (1)
				{

					x = rand() % 9 + 1;
					y = rand() % 9 + 1;
					if (arr2[x][y] == '0')
					{
						arr2[x][y] ='1';
						break;
					}
				}
				break;
			}
		}

	}
		
	check_mine(arr, arr2, x, y);
	printf("\n");
}
void sweep_mine(char arr[ROW][COL],char arr2[ROW][COL],int row,int col)//判断是否被炸死
{
	int i = 0, j = 0;

	while (1)
	{
		printf("请输入坐标扫雷：>");
		int i = 0, j = 0;
		int count=0;
		scanf("%d%d", &i, &j);
		if (i >= 0 && i <= 9 && j >= 0 && j <= 9)
		{
			if (arr2[i][j] == '1')
			{
				check_mine(arr, arr2, i, j);
				printf("很遗憾，你被炸死了！！！\n");
				printf("地雷布置情况为：\n\n");
				print_mine(arr2,row,col);
				break;
			}
			else
			{
				check_mine(arr, arr2, i, j);
				print_player(arr2, row, col);
				count=ISwin(arr, row, col);
				if (count == 1)
				{
					break;
				}
			}
			
		}

	}
}
int ISwin(char arr[ROW][COL], int row, int col)//是否胜利
{
	int i = 0, j = 0;
	int count = 0;
	for (i = 1; i < row - 1; i++)
	{
		for (j = 1; j < col - 1; j++)
		{
			if (arr[i][j] == '*')
			{
				count++;
			}
		}
	}
	if (count == COUNT)
	{
		printf("恭喜你，你赢了。 \n");
		return 1;
	}
	return 0;
}


//#define _CRT_SECURE_NO_WARNINGS 1
//#include"game.h"
//char show_mine[row][col] = { 0 };
//char real_mine[row][col] = { 0 };
//
//
//void muen()
//{
//	printf("*******************************\n");
//	printf("*****1.play       0.exit*******\n");
//	printf("*******************************\n");
//}
//
//
//void init_mine()//初始化两个棋盘
//{
//	int i = 0;
//	int j = 0;
//	for (int i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			show_mine[i][j] = '*';
//			real_mine[i][j] = '0';
//		}
//	}
//}
//
//
//void print_player()//打印玩家棋盘
//{
//	int i = 0;
//	int j = 0;
//	printf("0  ");
//	for (i = 1; i < row - 1; i++)
//	{
//		printf("%d ", i);//打印横标（0--10）
//	}
//	printf("\n");
//	for (i = 1; i < row - 2; i++)//打印竖标（1--10）
//	{
//		printf("%d  ", i);
//		for (j = 1; j < col - 1; j++)
//		{
//			printf("%c ", show_mine[i][j]);//玩家棋盘数组
//		}
//		printf("\n");
//	}
//	printf("10 ");//开始打印最后一行
//	for (i = 1; i < row - 1; i++)
//	{
//		printf("%c ", show_mine[10][i]);
//	}
//	printf("\n");
//}
//
//
//void print_mine()//打印设计者棋盘
//{
//	int i = 0;
//	int j = 0;
//	printf("0  ");
//	for (i = 1; i < row - 1; i++)
//	{
//		printf("%d ", i);//打印横标（0--10）
//	}
//	printf("\n");
//	for (i = 1; i < row - 2; i++)//打印竖标（1--10）
//	{
//		printf("%d  ", i);
//		for (j = 1; j < col - 1; j++)
//		{
//			printf("%c ", real_mine[i][j]);
//		}
//		printf("\n");
//	}
//	printf("10 ");//开始打印最后一行
//	for (i = 1; i < row - 1; i++)
//	{
//		printf("%c ", real_mine[10][i]);
//	}
//	printf("\n");
//}
//
//
//
//void set_mine()//给设计者棋盘布雷
//{
//	int x = 0;
//	int y = 0;
//	int count = COUNT;//雷总数
//	while (count)//雷布完后跳出循环
//	{
//		int x = rand() % 10 + 1;//产生1到10的随机数，在数组下标为1到10的范围内布雷
//		int y = rand() % 10 + 1;//产生1到10的随机数，在数组下标为1到10的范围内布雷
//		if (real_mine[x][y] == '0')//找不是雷的地方布雷
//		{
//			real_mine[x][y] = '1';
//			count--;
//		}
//	}
//}
//
//
//int count_mine(int x, int y)//检测周围8个区域雷的个数
//{
//	int count = 0;
//	if (real_mine[x - 1][y - 1] == '1')
//		count++;
//	if (real_mine[x - 1][y] == '1')
//		count++;
//	if (real_mine[x - 1][y + 1] == '1')
//		count++;
//	if (real_mine[x][y - 1] == '1')
//		count++;
//	if (real_mine[x][y + 1] == '1')
//		count++;
//	if (real_mine[x + 1][y - 1] == '1')
//		count++;
//	if (real_mine[x + 1][y] == '1')
//		count++;
//	if (real_mine[x + 1][y + 1] == '1')
//		count++;
//	return count;
//}
//
//void safe_mine()//避免第一次炸死
//{
//	int x = 0;
//	int y = 0;
//	char ch = 0;
//	int count = 0;
//	int ret = 1;
//	printf("输入坐标扫雷\n");
//	while (1)
//	{
//		scanf("%d%d", &x, &y);//只能输入1到10，输入错误重新输入
//		if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10))//判断输入坐标是否有误
//		{
//			if (real_mine[x][y] == '1')//第一次踩到雷后补救
//			{
//				real_mine[x][y] = '0';
//				char ch = count_mine(x, y);
//				show_mine[x][y] = ch + '0';//数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
//				open_mine(x, y);
//				while (ret)//在其余有空的地方设置一个雷
//				{
//					int x = rand() % 10 + 1;//产生1到10的随机数，在数组下标为1到10的范围内布雷
//					int y = rand() % 10 + 1;//产生1到10的随机数，在数组下标为1到10的范围内布雷
//					if (real_mine[x][y] == '0')//找不是雷的地方布雷
//					{
//						real_mine[x][y] = '1';
//						ret--;
//						break;
//					}
//				}break;//跳出此函数  
//			}
//			if (real_mine[x][y] == '0')
//			{
//				char ch = count_mine(x, y);
//				show_mine[x][y] = ch + '0';//数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
//				open_mine(x, y);
//				break;
//			}
//		}
//		else//坐标错误
//		{
//			printf("输入错误重新输入\n");
//		}
//	}
//}
//
//
//int sweep_mine()//扫雷函数，踩到雷返回1，没有踩到雷返回0
//{
//	int x = 0;
//	int y = 0;
//	int count = 0;
//	printf("输入坐标扫雷\n");
//	scanf("%d%d", &x, &y);//只能输入1到10
//	if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10))//判断输入坐标是否有误，输入错误重新输入
//	{
//		if (real_mine[x][y] == '0')//没踩到雷
//		{
//			char ch = count_mine(x, y);
//			show_mine[x][y] = ch + '0';//数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
//			open_mine(x, y);
//			if (count_show_mine() == COUNT)//判断剩余未知区域的个数，个数为雷数时玩家赢
//			{
//				print_mine();
//				printf("玩家赢！\n\n");
//				return 0;
//			}
//		}
//		else if (real_mine[x][y] == '1')//踩到雷
//		{
//			return 1;
//		}
//
//	}
//	else
//	{
//		printf("输入错误重新输入\n");
//	}
//	return 0;//没踩到雷
//}
//
//
//
//void open_mine(int x, int y)//坐标周围展开函数
//{
//	if (real_mine[x - 1][y - 1] == '0')
//	{
//		show_mine[x - 1][y - 1] = count_mine(x - 1, y - 1) + '0';//显示该坐标周围雷数
//	}
//	if (real_mine[x - 1][y] == '0')
//	{
//		show_mine[x - 1][y] = count_mine(x - 1, y) + '0';//显示该坐标周围雷数
//	}
//	if (real_mine[x - 1][y + 1] == '0')
//	{
//		show_mine[x - 1][y + 1] = count_mine(x - 1, y + 1) + '0';//显示该坐标周围雷数
//	}
//	if (real_mine[x][y - 1] == '0')
//	{
//		show_mine[x][y - 1] = count_mine(x, y - 1) + '0';//显示该坐标周围雷数
//	}
//	if (real_mine[x][y + 1] == '0')
//	{
//		show_mine[x][y + 1] = count_mine(x, y + 1) + '0';//显示该坐标周围雷数
//	}
//	if (real_mine[x + 1][y - 1] == '0')
//	{
//		show_mine[x + 1][y - 1] = count_mine(x + 1, y - 1) + '0';//显示该坐标周围雷数
//	}
//	if (real_mine[x + 1][y] == '0')
//	{
//		show_mine[x + 1][y] = count_mine(x + 1, y) + '0';//显示该坐标周围雷数
//	}
//	if (real_mine[x + 1][y + 1] == '0')
//	{
//		show_mine[x + 1][y + 1] = count_mine(x + 1, y + 1) + '0';//显示该坐标周围雷数
//	}
//}
//
//
//int count_show_mine()//判断剩余未知区域的个数，个数为雷数时玩家赢
//{
//	int count = 0;
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= row - 2; i++)
//	{
//		for (j = 1; j <= col - 2; j++)
//		{
//			if (show_mine[i][j] == '*')
//			{
//				count++;
//			}
//		}
//
//	}
//	return count;
//}
