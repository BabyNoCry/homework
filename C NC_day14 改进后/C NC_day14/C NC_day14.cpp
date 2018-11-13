#define _CRT_SECURE_NO_WARNINGS
//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//方法一：
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void left_roate(char* str, int k)
//{
//	k = k % strlen(str);
//	while (k--)
//	{
//		char temp = *str;
//		char* cur = str;
//		//下一个位置的内容向前挪动一次
//		while (*(cur+1) != '\0')
//		{
//			*cur = *(cur + 1);
//			cur++;
//		}
//		//第一个位置的内容放在末尾
//		*cur = temp;	
//	}
//}
//int main()
//{
//	char arr[] = "goodboy";
//	left_roate(arr, 4);
//	printf("%s", arr);
//	system("pause");
//	return 0;
//}
//方法二：三次旋转法(左旋) 如：abcdef k=4
//第一次：逆转前k个元素  dcbaef 
//第二次：逆转剩余元素	 dcbafe
//第三次：整体逆转	     efabcd
//（右旋）abcdef k=2
//第一次：整体逆转  fedcba
//第二次：逆转1~2   efdcba
//第三次：逆转剩余  efabcd
//字符串逆转
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void reverse(char* start, char* end)
//{
//	while (start < end)
//	{
//		char temp = *start;
//		*start = *end;
//		*end = temp;
//		start++;
//		end--;
//	}
//}
//void left_rotate(char* str, int k)
//{
//	//左旋
//	
//	reverse(str, str + k - 1);
//	reverse(str + k, str + strlen(str)- 1);
//	reverse(str, str + strlen(str) - 1);
//
//void right_rotate(char* str, int k)
//{
//	//右旋
//	reverse(str, str + strlen(str) - 1);
//	reverse(str, str + k - 1);
//	reverse(str + k, str + strlen(str) - 1);
//}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	left_rotate(arr, 3);
//	printf("%s", arr);
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void change( char arr[], int right,int y)
//{
//	int i = 0, j = 0;
//		while (y--)
//		{
//			char m = arr[0];
//			for (i = 0; i<right; i++)
//			{
//				arr[i] = arr[i+1];
//	
//			}	
//			arr[right-1] = m;
//		}
//		printf("%s",arr);
//
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	//int right = sizeof(arr) / sizeof(arr[0]);//区别：sizeof（arr）=strlen(arr)+1;
//	//printf("%d\n",right);
//	//printf("%d", strlen(arr));//字符的大小与长度不同 大小即输出含截止符在内的总字符个数，而长度不包含截止符。
//	int right = strlen(arr);
//	int a = 0;
//	printf("请输入你要左旋的字符个数：>");
//	scanf("%d", &a);
//	change(arr,right,a);
//	system("pause");
//	return 0;
//}

//判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC
//方法一：每旋转一次比较一次
//方法二：dest: abcd  roate:cdba
//前提：两个字符串长度相同，若不是直接证明不是。保证字符串长度足够长，防止越界。
//第一步：拼接dest----->abcdabcd
//第二步：判断roate是不是dest的子串  是的话则roate是由dest旋转而来，否则不是；注意：判断字串时，使用strncat 函数，不能使用strcat；
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int change( char arr1[],char arr2[], int right)
//{
//	if (strlen(arr1) != strlen(arr2))
//	{
//	return 0;
//	}
//	int i = 0, j =right;
//		while (j--)
//		{
//			char m = arr1[0];
//			for (i = 0; i<right; i++)
//			{
//				arr1[i] = arr1[i+1];
//	
//			}	
//			arr1[right-1] = m;
//			if (strcmp(arr1, arr2) == 0)
//			{
//				return 1;
//			}
//		}
//		return 0;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "cdkfab";
//	int right = strlen(arr1);
//	int i=change(arr1, arr2, right);
//	if (i == 1)
//	{
//		printf("字符串arr1是由字符串arr2旋转的得到的\n");
//	}
//	else
//	{
//		printf("字符串arr1不是由字符串arr2旋转的得到的\n");
//	}
//	system("pause");
//	return 0;
//}