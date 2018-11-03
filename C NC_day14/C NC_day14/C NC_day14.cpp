#define _CRT_SECURE_NO_WARNINGS
//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void change( char arr[], int right,int y)
{
	int i = 0, j = 0;
		while (y--)
		{
			char m = arr[0];
			for (i = 0; i<right; i++)
			{
				arr[i] = arr[i+1];
	
			}	
			arr[right-1] = m;
		}
		printf("%s",arr);

}
int main()
{
	char arr[] = "abcdefg";
	//int right = sizeof(arr) / sizeof(arr[0]);//区别：sizeof（arr）=strlen(arr)+1;
	//printf("%d\n",right);
	//printf("%d", strlen(arr));//字符的大小与长度不同 大小即输出含截止符在内的总字符个数，而长度不包含截止符。
	int right = strlen(arr);
	int a = 0;
	printf("请输入你要左旋的字符个数：>");
	scanf("%d", &a);
	change(arr,right,a);
	system("pause");
	return 0;
}

//判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int change( char arr1[],char arr2[], int right)
{
	int i = 0, j =right;
		while (j--)
		{
			char m = arr1[0];
			for (i = 0; i<right; i++)
			{
				arr1[i] = arr1[i+1];
	
			}	
			arr1[right-1] = m;
			if (strcmp(arr1, arr2) == 0)
			{
				return 1;
			}
		}
		return 0;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cdkfab";
	int right = strlen(arr1);
	int i=change(arr1, arr2, right);
	if (i == 1)
	{
		printf("字符串arr1是由字符串arr2旋转的得到的\n");
	}
	else
	{
		printf("字符串arr1不是由字符串arr2旋转的得到的\n");
	}
	system("pause");
	return 0;
}