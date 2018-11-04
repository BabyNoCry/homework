#define _CRT_SECURE_NO_DEPRECATE
//二进制数中1的个数
//#include<stdio.h>
//#include<stdlib.h>
//int count_one_bits(unsigned int value)
//{
//	int i = 0;
//	while (value != 0)
//	{
//		if (value % 2 == 1)
//		{
//			i++;
//		}
//		
//		value /= 2;
//	}
//	return i;
//
//}
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	printf("%d的二进制数中有%d个1", i, count_one_bits(i));
//	system("pause");
//	return 0;
//}



//用移位操作符
#include<stdio.h>
#include<stdlib.h>
int count(unsigned int n)
{
	/*int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if ((n >> i) & 1 == 1)
		{
			count++;
		}
	}*/
	//方法二
	/*int count = 0;
	unsigned int i = 0;
	for (i = 1; i != 0; i=i << 1)
	{
		if ((n & 1) == 1)
		{
			count++;
		}
		n >>= 1;
	}*/
	//方法三
	/*int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}

	return count;*/
	//以上两种方法均可以；
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d",count(n));
	printf("该数中存在1的个数为：");
	system("pause");
	return 0;
}
//
////输出整数的每一位
//#include<stdio.h>
//#include<stdlib.h>
//void sum(int a)
//{
//	if (a>9)
//	{
//		sum(a / 10);
//		
//		
//	}
//	printf("%d ", a % 10);
//}
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	sum(i);
//	system("pause");
//	
//	return 0;
//}

//两个整数中 二进制 不同的位数
//#include <stdio.h>
//#include <windows.h>
//void fun(int m, int n)
//{
//	int t = 0;
//	int count = 0;
//	t = m ^ n;//得到不同的比特位数
//	while (t)
//	{
//		t = t & (t - 1);//得到比特位为一的个数
//		count++;
//	}
//	printf("count=%d\n", count);
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int count = 0;
//	printf("输入两个整数：");
//	scanf("%d%d", &m, &n);
//	fun(m, n);
//	system("pause");
//	return 0;
//}
//
//
//
//
//获取一个数二进制序列中所有的偶数位和奇数位， 分别输出二进制序列。
//#include <stdio.h>
//int main()
//{	
//	int i=0,j=0;	
//	char arr1[16];  //定义2个数组来存放二进制序列	
//	char arr2[16];	
//	int num=0;	
//	scanf("%d",&num);	
//	for(i = 0; i < 32; i += 2)	
//	{		
//		arr1[j] = ((num >> i) & 1);  //奇数位		
//		j++;	
//	}  	
//	for(i = 1,j=0; i < 32; i += 2)		
//	{
//			arr2[j] = ((num >> i) & 1);  //偶数位			
//			j++;		
//	}		
//	printf("奇数位为：");  //输出数组里的二进制奇数序列		
//	for (i = 15; i >= 0; i--)		
//	{			
//		printf("%d",arr1[i]);		
//	}		
//	printf("\n");		
//	printf("偶数位为：");  //输出数组里的二进制偶数序列		
//	for (i = 15; i >= 0; i--)		
//	{			
//		printf("%d",arr2[i]);		
//	}	
//	system("pause");
//	return 0;
//}
//
//方法二
//int n = 0;
//scanf("%d", &n);
//int i = 0;
//for (i = 31; i > 0; i -= 2)
//{
//	printf("%d",n>>i&1)
//
//}
//printf("\n");
//for (i = 30; i >= 0; i -= 2)
//{
//	printf("%d", n >> i & 1);
//}

//输出两个整数的二进制形式中不同的位数
//方法1
//int cal_diff(int m, int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((m >> i) & 1) == ((n >> i) & 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//方法二：使用异或标记不同位
//int ret = m ^ n;
//int count = 0;
//for (i = 0; i < 32; i++)
//{
//	if ((ret >> i & 1) == 1)
//	{
//		count++;
//	}
//
//}
//return count;
