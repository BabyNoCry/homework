#include<stdio.h>
int find(int arr[], int a,int r)
{
	int le = 0;
	while (le <r)
	{
		int mid = (le + r) / 2;
		if (arr[mid] > a)
		{
			r = mid;
		}
		else if (arr[mid] < a)
		{
			le = mid++;
		}
		else
		{
			return mid;//找到了
		}
	}
	return -1;//没找到
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int le = 0;
	int r = sizeof(arr)/sizeof(arr[0]);
	int i=find(arr, 2, r);
	return 0;
}