#define _CRT_SECURE_NO_WARNINGS
////ģ��strcpy����
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
//	printf("����ǰ��\narr1=%s\narr2=%s", arr1, arr2);
//	str_cpy(arr1, arr2);
//	printf("\n������\narr1=%s\narr2=%s", arr1, arr2);
//	system("pause");
//	return 0;
//}


//ģ��strcat����
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
//	printf("����ǰ��\narr1=%s\narr2=%s\n", arr1, arr2);
//
//	str_cat(arr1, arr2,len);
//	printf("���Ӻ�\narr1=%s\narr2=%s", arr1, arr2);
//	system("pause");
//	return 0;
//

//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ�� 
//��20Ԫ�����Զ�����ˮ��
//���ʵ�֡�
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
//		//��ƿ��
//		i = j + i % 2;
//		
//	}
//	return count;
//	
//}
//int main()
//{
//	int i = 0;
//	printf("�������ж���Ǯ��>");
//	scanf("%d", &i);
//	printf("���ܹ�������%dƿ��ˮ", sum(i));
//	system("pause");
//	return 0;
//}
//1.һ��������ֻ�����������ǳ���һ�Σ� 
//�����������ֶ����������Ρ�
//�ҳ����������֣����ʵ��
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
	int i = 0;//ѭ������
	int ret = 0;
	//��¼����ֵ���Ľ��
	int pos = 0;
	//��¼ret������Ϊ��һ��Ϊ1��λ��
	int x = 0;//��һ��ֵ�����x���õ�1��û����ͬ���ֵ�ֵ
	int y = 0;//����һ��ֵ�����x���õ���1��û����ͬ���ֵ�ֵ
	for (i = 0; i < len; i++)
	{
		ret ^= arr[i];
	}//�����������ֵ���
	for (i = 0; i < 32; i++)
	{
		if (1 == ((ret >> i) & 1))
		{
			pos = i;
			break;
		}
	}//�ҵ�ret������Ϊ��һ��Ϊ1��λ��
	for (i = 0; i < len; i++)
	{
		if (1 == ((arr[i] >> pos) & 1))
		{
			x ^= arr[i];
		}
		else
			y ^= arr[i];
	}//�������
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
