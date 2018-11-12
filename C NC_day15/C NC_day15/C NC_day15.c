#define _CRT_SECURE_NO_WARNINGS
////模拟strcpy函数
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
//void str_cpy(char* dest, const char*src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//}
//void str_cpy(char* arr1, const char* arr2)
//{
//	while (*arr2 != '\0')
//	{
//		
//		*arr1 = *arr2;
//		arr1++;
//		arr2++;
//	}
//	*arr1 = '\0';
//}
//int main()
//{
//	char arr1[] = "fdagdagduikyky";
//	char arr2[] = "zhangyhang";
//	printf("拷贝前：\narr1=%s\narr2=%s", arr1, arr2);
//	str_cpy(arr1, arr2);
//	printf("\n拷贝后：\narr1=%s\narr2=%s", arr1, arr2);
//	system("pause");
//	return 0;
//}


//模拟strcat函数
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//int str_len(char* arr)
//{
//	int i = 0;
//	for (i = 0; *arr++; i++);
//	return i;
//}
//void str_cat(char* dest, const char* src, int len)
//{
//	
//	assert(dest!= NULL);
//	assert(src!= NULL);
//	dest = dest + len;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//int main()
//{
//	char arr1[100] = "zhoushidan";
//
//	int len= str_len(arr1);
//	char arr2[] = "zhangyuhang";
//	printf("连接前：\narr1=%s\narr2=%s\n", arr1, arr2);
//
//	str_cat(arr1, arr2,len);
//	printf("连接后：\narr1=%s\narr2=%s", arr1, arr2);
//	system("pause");
//	return 0;
//

//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水， 
//给20元，可以多少汽水。
//编程实现。
//#include<stdio.h>
//#include<stdlib.h> 
//int sum(int i)
//{
//
//	int j = 0, a = 0, b = 0, c = 0, d = 0;
//	int count = i;
//	while (i>=2)
//	{
//		j = i / 2;
//		count += j;
//		//空瓶数
//		i = j + i % 2;
//		
//	}
//	return count;
//	
//}
//int main()
//{
//	int i = 0;
//	printf("请问你有多少钱：>");
//	scanf("%d", &i);
//	printf("你总共可以买%d瓶汽水", sum(i));
//	system("pause");
//	return 0;
//}
//1.一个数组中只有两个数字是出现一次， 
//其他所有数字都出现了两次。
//找出这两个数字，编程实现
//#include<stdio.h>
//#include<stdlib.h>
//void print(int arr[], int sz)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < sz; i++)
//	{
//		count = arr[i] ^count;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		int c = arr[i] ^ count;
//		int d = arr[i] ^ c;
//		if (d == count)
//		{
//			printf("%d\n", arr[i]);
//		}
//		
//	}
//}
//int main()
//{
//	int arr[] = {1,2,3,4,5,3,2,1};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr,sz);
//	system("pause");
//}//c

#include<stdio.h>
#include<windows.h>
void find_num(int arr[], int len)
{
	int i = 0;//循环变量
	int ret = 0;
	//记录所有值异或的结果
	int pos = 0;
	//记录ret二进制为第一个为1的位置
	int x = 0;//将一组值异或在x，得到1个没有相同数字的值
	int y = 0;//将另一组值异或在x，得到另1个没有相同数字的值
	for (i = 0; i < len; i++)
	{
		ret ^= arr[i];
	}//将数组的所有值异或
	for (i = 0; i < 32; i++)
	{
		if (1 == ((ret >> i) & 1))
		{
			pos = i;
			break;
		}
	}//找到ret二进制为第一个为1的位置
	for (i = 0; i < len; i++)
	{
		if (1 == ((arr[i] >> pos) & 1))
		{
			x ^= arr[i];
		}
		else
			y ^= arr[i];
	}//分组异或
	printf("x=%d,y=%d\n", x, y);
}
int main()
{
	int arr[] = { 1, 2, 3, 4,5,1, 2, 3,};
	int sz = sizeof(arr) / sizeof(arr[0]);
	find_num(arr, sz);
	system("pause");
	return 0;
}
