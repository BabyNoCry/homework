#define _CRT_SECURE_NO_DEPRECATE
//����������1�ĸ���
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
//	printf("%d�Ķ�����������%d��1", i, count_one_bits(i));
//	system("pause");
//	return 0;
//}



//����λ������
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
	//������
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
	//������
	/*int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}

	return count;*/
	//�������ַ��������ԣ�
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d",count(n));
	printf("�����д���1�ĸ���Ϊ��");
	system("pause");
	return 0;
}
//
////���������ÿһλ
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

//���������� ������ ��ͬ��λ��
//#include <stdio.h>
//#include <windows.h>
//void fun(int m, int n)
//{
//	int t = 0;
//	int count = 0;
//	t = m ^ n;//�õ���ͬ�ı���λ��
//	while (t)
//	{
//		t = t & (t - 1);//�õ�����λΪһ�ĸ���
//		count++;
//	}
//	printf("count=%d\n", count);
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int count = 0;
//	printf("��������������");
//	scanf("%d%d", &m, &n);
//	fun(m, n);
//	system("pause");
//	return 0;
//}
//
//
//
//
//��ȡһ�������������������е�ż��λ������λ�� �ֱ�������������С�
//#include <stdio.h>
//int main()
//{	
//	int i=0,j=0;	
//	char arr1[16];  //����2����������Ŷ���������	
//	char arr2[16];	
//	int num=0;	
//	scanf("%d",&num);	
//	for(i = 0; i < 32; i += 2)	
//	{		
//		arr1[j] = ((num >> i) & 1);  //����λ		
//		j++;	
//	}  	
//	for(i = 1,j=0; i < 32; i += 2)		
//	{
//			arr2[j] = ((num >> i) & 1);  //ż��λ			
//			j++;		
//	}		
//	printf("����λΪ��");  //���������Ķ�������������		
//	for (i = 15; i >= 0; i--)		
//	{			
//		printf("%d",arr1[i]);		
//	}		
//	printf("\n");		
//	printf("ż��λΪ��");  //���������Ķ�����ż������		
//	for (i = 15; i >= 0; i--)		
//	{			
//		printf("%d",arr2[i]);		
//	}	
//	system("pause");
//	return 0;
//}
//
//������
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

//������������Ķ�������ʽ�в�ͬ��λ��
//����1
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
//��������ʹ������ǲ�ͬλ
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
