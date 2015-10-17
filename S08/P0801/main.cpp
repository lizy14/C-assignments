/*

��һ�⣺�ϲ��������飨25�֣�
��д�����ڳ�����ʵ�� void merge(int *a,   int *b , int m, int n, int *result)��
�����ú����ϲ����������������������a��b��a��b����ĳ��ȶ�������10����
������һ�����������ֱ��ʾ����a��b������������m��ʾ����a���ȣ�����
������n��ʾb���鳤�ȣ����һ������result��ʾa��b����ϲ�������顣
�ó����һ������һ��������m����ʾa����ĳ��ȣ��ڶ�����������a��
����ֵ���Կո������������������һ��������n����ʾb����ĳ��ȣ���������
��b����ĸ���ֵ���Կո�������������������a��b�ϲ���ĵ������С�
�������룺
3
4 8 20
4
1 2 5 8
���������
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