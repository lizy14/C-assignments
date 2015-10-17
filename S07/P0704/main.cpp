/*
第四题：集合运算（25分）
输入两个整数集合A、B，求出他们的交集、并集以及B在A中的余集。交
集、并集和余集的计算都要求写成一个单独的函数。
输入第一行为一个正整数n，表示集合A中的元素个数；第二行有n个按从
小到大的顺序输入且互不相同的整数，表示集合A中的元素；第三行为一个正整
数m，表示集合B中的元素个数；第四行有m个按从小到大的顺序输入且互不相
同的整数，表示集合B中的元素；集合中的所有元素均为int范围内的整数，
1≤n,m≤1000。
输出第一行按从小到大的顺序输出A、B交集中的所有元素；第二行按从小
到大的顺序输出A、B并集中的所有元素；第三行按从小到大的顺序输出B在A
中的余集中的所有元素。
样例输入：
5
1 2 3 4 5
5
2 4 6 8 10
样例输出：
2 4
1 2 3 4 5 6 8 10
1 3 5
*/

#define for_(i,x,y) for(i=x; i<=y; i++)
#define bool_(x) (x==0? 0:1)
#include <stdio.h>

void sort(int* a,int n)
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
int JIAO(int* Buffer, int* A, int nA, int* B, int nB)//将交集存入Buffer并返回交集的大小
{
	int iA, iB, n=0;
	for_(iA, 0, nA-1)
	{
		for_(iB, 0, nB-1)
		{
			if(A[iA]==B[iB])
			{
				Buffer[n]=A[iA];
				n++;
			}
		}
	}
	sort(Buffer, n);
	return n;
}
int YU(int* Buffer, int* A, int nA, int* B, int nB)
{
	int iA, iB, n=0;


	//遍历A中元素，若不在B中，送入Buffer
	for(iA=0; iA<=nA-1; iA++)
	{
		int notexist=1;
		//判断A[iA]是否在A中
		for(iB=0; iB<=nB-1; iB++)
		{
			notexist *= (A[iA] != B[iB]);
		}
		if(notexist)
		{
			Buffer[n]=A[iA];
			n++;
		}
	}
	sort(Buffer, n);
	return n;
}
int BING(int* Buffer, int* A, int nA, int* B, int nB)
{
	int iA, iB, n=0;
	
	//先将A送入Buffer
	for(iA=0; iA<=nA-1; iA++)
	{
		Buffer[n]=A[iA];
		n++;
	}

	//遍历B中元素，若不在A中，送入Buffer
	for(iB=0; iB<=nB-1; iB++)
	{
		int notexist=1;
		//判断B[iB]是否在A中
		for(iA=0; iA<=nA-1; iA++)
		{
			notexist *= (A[iA] != B[iB]);
		}
		if(notexist)
		{
			Buffer[n]=B[iB];
			n++;
		}
	}
	sort(Buffer, n);
	return n;
}
int main()
{


	int i;
	
	int A[1000];
	int B[1000];
	int nA, nB;
	
	scanf("%d", &nA);
	for_(i, 0, nA-1)
	{
		scanf("%d", &A[i]);
	}
	scanf("%d", &nB);
	for_(i, 0, nB-1)
	{
		scanf("%d", &B[i]);
	}
	//输入结束
	





	int Buffer[1000], nC;
	
	nC = JIAO(Buffer, A, nA, B, nB)-1;
		for_(i, 0, nC)
	{
		printf("%d ", Buffer[i]);
	}
	printf("\n");
	
	nC = BING(Buffer, A, nA, B, nB)-1;
	
	for_(i, 0, nC)
	{
		printf("%d ", Buffer[i]);
	}
	printf("\n");
	
	nC = YU(Buffer, A, nA, B, nB)-1;
	for_(i, 0, nC)
	{
		printf("%d ", Buffer[i]);
	}
	return 0;
}
