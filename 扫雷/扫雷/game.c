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
void inint_mine(char arr[ROW][COL], char arr2[ROW][COL],int row, int col)//��ʼ������
{
	memset(arr, '*', row*col);
	memset(arr2, '0', row*col);
}
void print_player(char arr[ROW][COL], int row, int col)//��ӡ�������
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
void print_mine(char arr[ROW][COL], int row, int col)//��ӡ��
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
void set_mine(char arr[ROW][COL], int row, int col)//���õ���
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
void check_mine(char arr[ROW][COL],char arr2[ROW][COL], int a, int b)//�����λ����Χ����
{
	int i = 0,j = 0;
	char count;
	count = arr2[a - 1][b - 1]-'0' + arr2[a - 1][b]-'0' + arr2[a - 1][b + 1]-'0' + arr2[a][b - 1]-'0'
		+ arr2[a][b + 1]-'0' + arr2[a + 1][b - 1]-'0' + arr2[a + 1][b]-'0'+arr2[a+1][b+1];
	arr[a][b] = count;
}
void safe_mine(char arr[ROW][COL],char arr2[ROW][COL], int row, int col)//�����һ�α�ը��
{
	int x = 0, y = 0;
	while (1)
	{
		printf("����������ɨ�ף�>");
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
void sweep_mine(char arr[ROW][COL],char arr2[ROW][COL],int row,int col)//�ж��Ƿ�ը��
{
	int i = 0, j = 0;

	while (1)
	{
		printf("����������ɨ�ף�>");
		int i = 0, j = 0;
		int count=0;
		scanf("%d%d", &i, &j);
		if (i >= 0 && i <= 9 && j >= 0 && j <= 9)
		{
			if (arr2[i][j] == '1')
			{
				check_mine(arr, arr2, i, j);
				printf("���ź����㱻ը���ˣ�����\n");
				printf("���ײ������Ϊ��\n\n");
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
int ISwin(char arr[ROW][COL], int row, int col)//�Ƿ�ʤ��
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
		printf("��ϲ�㣬��Ӯ�ˡ� \n");
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
//void init_mine()//��ʼ����������
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
//void print_player()//��ӡ�������
//{
//	int i = 0;
//	int j = 0;
//	printf("0  ");
//	for (i = 1; i < row - 1; i++)
//	{
//		printf("%d ", i);//��ӡ��꣨0--10��
//	}
//	printf("\n");
//	for (i = 1; i < row - 2; i++)//��ӡ���꣨1--10��
//	{
//		printf("%d  ", i);
//		for (j = 1; j < col - 1; j++)
//		{
//			printf("%c ", show_mine[i][j]);//�����������
//		}
//		printf("\n");
//	}
//	printf("10 ");//��ʼ��ӡ���һ��
//	for (i = 1; i < row - 1; i++)
//	{
//		printf("%c ", show_mine[10][i]);
//	}
//	printf("\n");
//}
//
//
//void print_mine()//��ӡ���������
//{
//	int i = 0;
//	int j = 0;
//	printf("0  ");
//	for (i = 1; i < row - 1; i++)
//	{
//		printf("%d ", i);//��ӡ��꣨0--10��
//	}
//	printf("\n");
//	for (i = 1; i < row - 2; i++)//��ӡ���꣨1--10��
//	{
//		printf("%d  ", i);
//		for (j = 1; j < col - 1; j++)
//		{
//			printf("%c ", real_mine[i][j]);
//		}
//		printf("\n");
//	}
//	printf("10 ");//��ʼ��ӡ���һ��
//	for (i = 1; i < row - 1; i++)
//	{
//		printf("%c ", real_mine[10][i]);
//	}
//	printf("\n");
//}
//
//
//
//void set_mine()//����������̲���
//{
//	int x = 0;
//	int y = 0;
//	int count = COUNT;//������
//	while (count)//�ײ��������ѭ��
//	{
//		int x = rand() % 10 + 1;//����1��10����������������±�Ϊ1��10�ķ�Χ�ڲ���
//		int y = rand() % 10 + 1;//����1��10����������������±�Ϊ1��10�ķ�Χ�ڲ���
//		if (real_mine[x][y] == '0')//�Ҳ����׵ĵط�����
//		{
//			real_mine[x][y] = '1';
//			count--;
//		}
//	}
//}
//
//
//int count_mine(int x, int y)//�����Χ8�������׵ĸ���
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
//void safe_mine()//�����һ��ը��
//{
//	int x = 0;
//	int y = 0;
//	char ch = 0;
//	int count = 0;
//	int ret = 1;
//	printf("��������ɨ��\n");
//	while (1)
//	{
//		scanf("%d%d", &x, &y);//ֻ������1��10�����������������
//		if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10))//�ж����������Ƿ�����
//		{
//			if (real_mine[x][y] == '1')//��һ�βȵ��׺󲹾�
//			{
//				real_mine[x][y] = '0';
//				char ch = count_mine(x, y);
//				show_mine[x][y] = ch + '0';//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
//				open_mine(x, y);
//				while (ret)//�������пյĵط�����һ����
//				{
//					int x = rand() % 10 + 1;//����1��10����������������±�Ϊ1��10�ķ�Χ�ڲ���
//					int y = rand() % 10 + 1;//����1��10����������������±�Ϊ1��10�ķ�Χ�ڲ���
//					if (real_mine[x][y] == '0')//�Ҳ����׵ĵط�����
//					{
//						real_mine[x][y] = '1';
//						ret--;
//						break;
//					}
//				}break;//�����˺���  
//			}
//			if (real_mine[x][y] == '0')
//			{
//				char ch = count_mine(x, y);
//				show_mine[x][y] = ch + '0';//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
//				open_mine(x, y);
//				break;
//			}
//		}
//		else//�������
//		{
//			printf("���������������\n");
//		}
//	}
//}
//
//
//int sweep_mine()//ɨ�׺������ȵ��׷���1��û�вȵ��׷���0
//{
//	int x = 0;
//	int y = 0;
//	int count = 0;
//	printf("��������ɨ��\n");
//	scanf("%d%d", &x, &y);//ֻ������1��10
//	if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10))//�ж����������Ƿ��������������������
//	{
//		if (real_mine[x][y] == '0')//û�ȵ���
//		{
//			char ch = count_mine(x, y);
//			show_mine[x][y] = ch + '0';//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
//			open_mine(x, y);
//			if (count_show_mine() == COUNT)//�ж�ʣ��δ֪����ĸ���������Ϊ����ʱ���Ӯ
//			{
//				print_mine();
//				printf("���Ӯ��\n\n");
//				return 0;
//			}
//		}
//		else if (real_mine[x][y] == '1')//�ȵ���
//		{
//			return 1;
//		}
//
//	}
//	else
//	{
//		printf("���������������\n");
//	}
//	return 0;//û�ȵ���
//}
//
//
//
//void open_mine(int x, int y)//������Χչ������
//{
//	if (real_mine[x - 1][y - 1] == '0')
//	{
//		show_mine[x - 1][y - 1] = count_mine(x - 1, y - 1) + '0';//��ʾ��������Χ����
//	}
//	if (real_mine[x - 1][y] == '0')
//	{
//		show_mine[x - 1][y] = count_mine(x - 1, y) + '0';//��ʾ��������Χ����
//	}
//	if (real_mine[x - 1][y + 1] == '0')
//	{
//		show_mine[x - 1][y + 1] = count_mine(x - 1, y + 1) + '0';//��ʾ��������Χ����
//	}
//	if (real_mine[x][y - 1] == '0')
//	{
//		show_mine[x][y - 1] = count_mine(x, y - 1) + '0';//��ʾ��������Χ����
//	}
//	if (real_mine[x][y + 1] == '0')
//	{
//		show_mine[x][y + 1] = count_mine(x, y + 1) + '0';//��ʾ��������Χ����
//	}
//	if (real_mine[x + 1][y - 1] == '0')
//	{
//		show_mine[x + 1][y - 1] = count_mine(x + 1, y - 1) + '0';//��ʾ��������Χ����
//	}
//	if (real_mine[x + 1][y] == '0')
//	{
//		show_mine[x + 1][y] = count_mine(x + 1, y) + '0';//��ʾ��������Χ����
//	}
//	if (real_mine[x + 1][y + 1] == '0')
//	{
//		show_mine[x + 1][y + 1] = count_mine(x + 1, y + 1) + '0';//��ʾ��������Χ����
//	}
//}
//
//
//int count_show_mine()//�ж�ʣ��δ֪����ĸ���������Ϊ����ʱ���Ӯ
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
