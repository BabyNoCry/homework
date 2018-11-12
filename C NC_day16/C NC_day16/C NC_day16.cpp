#define _CRT_SECURE_NO_WARNINGS 1
//字符串拷贝函数
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//char* str_cpy(char* dest, const char* src)
//{
//	char* p = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return p;
//}
//int main()
//{ 
//
//	char arr[10] = { 0 };
//	char arr2[] = "good boy";
//	
//	printf("%s",str_cpy(arr, arr2));
//	printf("%s",arr2);
//	system("pause");
//	return 0;
//}
//字符串连接函数
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//char* str_cat(char* dest, const char* src)
//{
//	char* p = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest)
//	{
//		dest++;
//	}
//	
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return p;
//}
//int main()
//{
//	char dest[10] = "hellow";
//	char src[] = " good boy";
//	printf("%s",str_cat(dest, src));
//	system("pause");
//}

//字符串比较函数 strcmp
//#include<stdio.h>
//#include<stdlib.h>
//int str_cmp(const char* arr1, const char* arr2)
//{
//	int i = 0;
//	while (*arr1++||*arr2++)
//	{
//		if (*arr1 < *arr2)
//		{
//			i = -1;
//			break;
//		}
//		else if (*arr1 > *arr2)
//		{
//			i = 1;
//			break;
//		}
//
//	}
//	return i;
//}
//int main()
//{
//	char arr1[] = "hellow";
//	char arr2[] = "hellow good boy";
//	int i = str_cmp(arr1, arr2);
//	if (i == 0)
//	{
//		printf("arr1=arr2\n");
//	}
//	else if (i < 0)
//	{
//		printf("arr1<arr2\n");
//	}
//	else
//	{
//		printf("arr1>arr2\n");
//	}
//	system("pause");
//
//	return 0;
//}
//实现strstr函数
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//char* str_str( char* arr1, const char* arr2)
//{
//	char* p = NULL;
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	while (*arr1)
//	{
//		char* ptr = arr1;
//		
//		int j = 0;
//		for (j = 0; (*(arr2 + j)!='\0')&&(*(arr1+j)!='\0'); j++)
//		{
//			if (*(arr1 + j) != *(arr2 + j))
//			{
//				break;
//			}
//		}
//		if (*(arr2+j) == '\0')
//		{
//			p = ptr;
//			break;
//		}
//		arr1++;
//	}
//	return p;
//}
//int main()
//{
//	char arr1[] = "Iamaboy";
//	char arr2[] = "boy";
//	char* p= str_str(arr1, arr2);
//	if (p == NULL)
//	{
//		printf("%s中没找到%s\n",arr1,arr2);
//	}
//	else
//	{
//		printf("%s中找到了%s！ \n地址为%p\n ", arr1, arr2, p);
//	}
//	system("pause");
//	return 0;
//}

//实现strchr函数
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//char* my_strchr(const char* arr, char a)
//{
//	assert(arr != NULL);
//	while (*arr)
//	{
//		if (*arr == a)
//		{
//			return (char*)arr;
//		}
//		arr++;
//		 
//	}
//	return NULL;
//}
//
//int main()
//{
//	char a = 0;
//	char arr[] = "abcjydusf";
//	char* p = NULL;
//	printf("请输入一个字符：");
//	scanf("%c", &a);
//	
//	p=my_strchr(arr, a);
//	if (NULL == p)
//	{
//		printf("字符串%s中不存在字符%c！\n", arr, a);
//	}
//	else
//	{
//		printf("字符串%s存在字符%c，第一次出现地址为%p\n",arr,a,p);
//	}
//	system("pause");
//	return 0;
//}

//内存拷贝函数
//#include<stdio.h>
//#include<stdlib.h>
//void* my_memcpy(void* dest, const void *src, size_t n)

//	char* p1 = (char*)dest;
//	char* p2 = (char*)src;
//	while (n--)
//	{
//		*p1 = *p2;
//		p1++;//{
//		p2++;
//	}
//	return dest;
//}
//int main()
//{
//	char arr1[] = "I am a boy";
//	char arr2[] = "hehe";
//	my_memcpy(arr1,arr2, 4*sizeof(arr2));
//	printf("%s", arr1);
//	system("pause");
//	return 0;
//}
//

//内存移动
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void* my_memmove(void* dest, const void *src, size_t n)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* p1 = (char*)dest;
	char* p2 = (char*)src;
	while (n--)
	{
		if (dest < src)
		{
			*p1 = *p2;
			p1++;
			p2++;
		}
		else
		{
			*(p1 + n) = *(p2 + n);
		}
		
	}
	return dest;
}
int main()
{
	char str1[] = "12345678";
	char str2[] = "456789";
	my_memmove(str1+2,str1+3,3);
	printf("%s",str1);
	system("pause");
	return 0;
}