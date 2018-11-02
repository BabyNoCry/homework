#define _CRT_SECURE_NO_WARNINGS
调整数组使奇数全部都位于偶数前面
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[] = {1,8,9,5,4,6,3,2,0,1,4,5,9,8,1,3,5};
	int tmp = 0;
	int i = 0;
	int left = 0;
	int right =( sizeof(arr) / sizeof(arr[0]))-1;
	int j = right;
	while (left <=right )
	{
		if (arr[left] % 2==0)
		{
			if (arr[right] % 2 == 1)
			{
				tmp = arr[left];
				arr[left] =arr[right];
				arr[right] = tmp;
				left++;
				right--;
			}
			else
			{
				right--;
			}
		}
		else
		{
			left++;
		}
	}
	for (i = 0; i < j; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;

}


杨氏矩阵
折半查找
#include<stdio.h>
#include<stdlib.h>
#define COL 3
#define ROW 3
int judge(int arr[ROW][COL], int a)
{
	int i = 0, j = 0;

	if (a<arr[0][0] || a>arr[ROW][COL])
	{
		return 0;
	}
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (a > arr[i][ROW]||a<arr[i][0])
				break;
			else
			{
				
				int m = COL-1;
				int n = 0;
				int k;
				while (n <= m)
				{
					 k = (m + n) / 2;
					if (a == arr[i][k])
					{
						return 1;
					}
					if (a < arr[i][k])
					{
						m = k-1;
					}
					else
					{
						n = k+1;
					}
					
				}
				
			}
		}
	}
	return 0;
}
int main()
{
	int arr[ROW][COL] = {1,2,3,4,5,6,7,8,9};
	int a = 0;
	scanf("%d", &a);
	if (0 == judge(arr, a))
	{
		printf("%d不存在于该数组中", a);
	}
	else
	{
		printf("%d存在于该数组中", a);
	}
	system("pause");
	return 0;
}