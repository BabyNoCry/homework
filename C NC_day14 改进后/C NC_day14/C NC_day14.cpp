#define _CRT_SECURE_NO_WARNINGS
//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
//����һ��
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
//		//��һ��λ�õ�������ǰŲ��һ��
//		while (*(cur+1) != '\0')
//		{
//			*cur = *(cur + 1);
//			cur++;
//		}
//		//��һ��λ�õ����ݷ���ĩβ
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
//��������������ת��(����) �磺abcdef k=4
//��һ�Σ���תǰk��Ԫ��  dcbaef 
//�ڶ��Σ���תʣ��Ԫ��	 dcbafe
//�����Σ�������ת	     efabcd
//��������abcdef k=2
//��һ�Σ�������ת  fedcba
//�ڶ��Σ���ת1~2   efdcba
//�����Σ���תʣ��  efabcd
//�ַ�����ת
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
//	//����
//	
//	reverse(str, str + k - 1);
//	reverse(str + k, str + strlen(str)- 1);
//	reverse(str, str + strlen(str) - 1);
//
//void right_rotate(char* str, int k)
//{
//	//����
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
//	//int right = sizeof(arr) / sizeof(arr[0]);//����sizeof��arr��=strlen(arr)+1;
//	//printf("%d\n",right);
//	//printf("%d", strlen(arr));//�ַ��Ĵ�С�볤�Ȳ�ͬ ��С���������ֹ�����ڵ����ַ������������Ȳ�������ֹ����
//	int right = strlen(arr);
//	int a = 0;
//	printf("��������Ҫ�������ַ�������>");
//	scanf("%d", &a);
//	change(arr,right,a);
//	system("pause");
//	return 0;
//}

//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC
//����һ��ÿ��תһ�αȽ�һ��
//��������dest: abcd  roate:cdba
//ǰ�᣺�����ַ���������ͬ��������ֱ��֤�����ǡ���֤�ַ��������㹻������ֹԽ�硣
//��һ����ƴ��dest----->abcdabcd
//�ڶ������ж�roate�ǲ���dest���Ӵ�  �ǵĻ���roate����dest��ת�����������ǣ�ע�⣺�ж��ִ�ʱ��ʹ��strncat ����������ʹ��strcat��
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
//		printf("�ַ���arr1�����ַ���arr2��ת�ĵõ���\n");
//	}
//	else
//	{
//		printf("�ַ���arr1�������ַ���arr2��ת�ĵõ���\n");
//	}
//	system("pause");
//	return 0;
//}