//#define _Cheack_return_ _CRT_INSECURE_DEPRECATE
//
//打印杨辉三角
//#include<stdio.h>
//#include<stdlib.h>
//#define a 10
//int main()
//{
//	int i = 0, j = 0;
//	int arr[a][a] = { 0 };
//	for (i = 0; i < a; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0||j==i)
//			{
//				arr[i][j] = 1;
//			}
//			if (j<i&&j > 0)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//	for (i = 0; i < a; i++)
//	{
//		for (j = 0; j <=i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//
//跳水
//#include<stdio.h>
//#include<stdlib.h>
//void predict()
//{
//int a, b, c, d, e;
//for (a = 1; a <= 5; a++)
//{
//	for (b = 1; b <= 5; b++)
//	{
//		for (c = 1; c <= 5; c++)
//		{
//			for (d = 1; d <= 5; d++)
//			{
//				for (e = 1; e <= 5; e++)
//				{
//					if (((b==2)+(a==3)==1)&&((b==2)+(e==4)==1)&&((c==1)+(d==2)==1)&&((c==5)+(d==3)==1)&&((e==4)+(a==1)==1))
//					{
//						if(a*b*c*d*e==120)
//						printf("A=%d,B=%d,C=&d,D=%d,E=%d", a, b, c, d, e);
//					}
//				}
//			}
//
//		}
//	}
//}
//}
//int main()
//{
//	predict();
//	system("pause");
//	return 0;
//}
//
//谋杀案
//
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	char killer = 'A';
//	int i = 4;
//	for (i = 0; i < 4; i++)
//	{
//		killer = killer + 1;
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			printf("凶手是%c", killer);
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}
