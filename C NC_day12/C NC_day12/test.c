#define _CRT_SECURE_NO_DEPRECATE
#include<stdlib.h>
void sum(int a)
{
	if( a / 2 == 0)
	{
		printf("%d ", a%2);
	}
	else
	{
		printf("%d ", a % 2);
		sum(a / 2);
		
	}
}
int main()
{
	int i = 0;
	scanf("%d",&i);
	sum(i);
	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	if (a > b)
	{
		printf("%d", b + (a - b) / 2);
	}
	else
	{
		printf("%d", a + (b - a) / 2);
	}
	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[9] = { 1,2,3,4,5,4,3,2,1 };
	int i = 0, j = arr[0];
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 1; i < sz; i++)
	{
		j = j ^ arr[i];
	}
	printf("改组数中出现一次的数位为：%d\n", j);
	system("pause");
	return 0;
}


#include <stdio.h>
#include <assert.h>
int my_strlen(const char *str)//求字符串长度函数
{
	int count = 0;
	assert(str);
	while (*str != '\0')
	{

		count++;
		str++;
	}
	return count;


}
void reverse(char a[], int left, int right)//逆序函数
{
	while (left < right)
	{
		char tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		left++;
		right--;
	}

}
char* reverse_string(char a[])//逆序字符串
{
	int i = 0;
	int left = 0;
	int right = my_strlen(a) - 1;//逆序整个字符串
	reverse(a, left, right);
	逆序逐个单词
	while (a[i] != '\0')
	{
		left = i;
		while ((a[i] != '\0') && (a[i] != ' '))
		{
			i++;

		}
		right = i - 1;
		reverse(a, left, right);
		if (a[i] != '\0')
			i++;
	}
	return a;
}

int main()
{
	char a[] = "student a am i";
	reverse_string(a);
	printf("%s\n", a);
	return 0;
}



//#include<stdio.h>






//#include<stdio.h>
//#include<stdlib.h>
//void change1(char str[] ,int start,int end)//字符串改变次序
//{
//	while (start <= end)
//	{
//		char tmp = 0;
//		str[start] = str[end];
//		str[start] = str[end];
//		str[end] = tmp;
//		start++;
//		end--;
//	}
//}
//
//void change2(char *str1, char *start, char *end, int left, int right)
//{
//	int i = 0, j = 0;
//	while (*str1)
//	{
//		while (*str1 != '\0' || *str1 != ' ')
//		{
//			j++;
//		}
//		change1(str1, i, j);
//		j++;
//		i = j;
//	}
//}
//void print(char str2[],int a,int b)
//{
//	int i = 0;
//	for (i = 0; i < b; i++)
//	{
//		printf("%c", str2[i]);
//	}
//}
//int main()
//{
//	char arr[]= "Student am i";
//	int sz = sizeof(arr);
//	int l = 0;
//	int r = sz - 1;
//	int i = 0;
//	char *left = arr;
//	char *right = arr+sz-1;
//	change1(arr, l, r);
//	print(arr, l, r);
//	change2(arr,left,right,l,r);
//	change1(arr, l, r);
//	system("pause");
//		return 0;
//}