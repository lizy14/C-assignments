/*
�����⣺�������㣨25�֣�
����������������A��B��������ǵĽ����������Լ�B��A�е��༯����
�����������༯�ļ��㶼Ҫ��д��һ�������ĺ�����
�����һ��Ϊһ��������n����ʾ����A�е�Ԫ�ظ������ڶ�����n������
С�����˳�������һ�����ͬ����������ʾ����A�е�Ԫ�أ�������Ϊһ������
��m����ʾ����B�е�Ԫ�ظ�������������m������С�����˳�������һ�����
ͬ����������ʾ����B�е�Ԫ�أ������е�����Ԫ�ؾ�Ϊint��Χ�ڵ�������
1��n,m��1000��
�����һ�а���С�����˳�����A��B�����е�����Ԫ�أ��ڶ��а���С
�����˳�����A��B�����е�����Ԫ�أ������а���С�����˳�����B��A
�е��༯�е�����Ԫ�ء�
�������룺
5
1 2 3 4 5
5
2 4 6 8 10
���������
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
int JIAO(int* Buffer, int* A, int nA, int* B, int nB)//����������Buffer�����ؽ����Ĵ�С
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


	//����A��Ԫ�أ�������B�У�����Buffer
	for(iA=0; iA<=nA-1; iA++)
	{
		int notexist=1;
		//�ж�A[iA]�Ƿ���A��
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
	
	//�Ƚ�A����Buffer
	for(iA=0; iA<=nA-1; iA++)
	{
		Buffer[n]=A[iA];
		n++;
	}

	//����B��Ԫ�أ�������A�У�����Buffer
	for(iB=0; iB<=nB-1; iB++)
	{
		int notexist=1;
		//�ж�B[iB]�Ƿ���A��
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
	//�������
	





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
