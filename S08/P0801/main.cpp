/*

第一题：合并排序数组（25分）
编写程序，在程序中实现 void merge(int *a,   int *b , int m, int n, int *result)函
数，该函数合并两个递增排序的整数数组a和b（a、b数组的长度都不超过10）。
函数第一、二个参数分别表示数组a和b，第三个参数m表示数组a长度，第四
个参数n表示b数组长度，最后一个参数result表示a、b数组合并后的数组。
该程序第一行输入一个正整数m，表示a数组的长度，第二行输入数组a的
各个值（以空格隔开）；第三行输入一个正整数n，表示b数组的长度，第四行输
入b数组的各个值（以空格隔开）。程序输出数组a和b合并后的递增序列。
样例输入：
3
4 8 20
4
1 2 5 8
样例输出：
1 2 4 5 8 8 20
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define for_(i,x,y) for(i=x; i<=y; i++)
void sort(int a[], int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp; 
			} 
		} 
	} 
}
void merge(int *a, int *b, int m, int n, int *result)
{
	int i;
	for_(i, 0, m-1)
	{
		result[i] = a[i];
	}
	for_(i, 0, n-1)
	{
		result[m+i] = b[i];
	}
	sort(result, m+n);
}
int main()
{
	int m, n, a[20],b[20],result[20];
	int i;
	scanf("%d", &m);
	for_(i, 0, m-1)
	{
		scanf("%d", a+i);
	}
	scanf("%d", &n);
	for_(i, 0, n-1)
	{
		scanf("%d", b+i);
	}
	//end of input
	merge(a,b,m,n,result);
	for_(i, 0, m+n-1)
	{
		printf("%d ", result[i]);
	}
	return 0;
} 