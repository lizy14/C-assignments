/*
�ڶ��⣺ ��Ĳɹ����⣨25 �֣� 
С����һ�Ҳ͹ݵĲɹ���Ա��һ����ȥ�г������㡣����̯���ܹ��� N ���㣬
ÿ���������Ϊ ti�����ڳɱ����ǣ�С�����ֻ���� T ������㣬��Ϊ��Я����
�㣬����ϣ������������Խ��Խ�á�������������� N ���㵱��ѡ����������
ʹ����Щ��������� L �����ܵش� L<=T���������ڴ�ǰ���£���������־���
�ܵ��١�
�������ƣ� 0<N<=30����ʾ��������� 0<T<=20000����ʾС������ܹ����
����������� ti ��һ������������ʾ�� i �����������
�����ʽ����һ������������ N �� T���������� N �У�ÿһ����һ������
ti����ʾ�� i �����������
�����ʽ����һ����һ������ K����ʾ��ؼҵ������������������ K �У�
ÿһ����һ����������ʾһ��������������ж���⣬�������һ���⼴�ɡ�
�������룺
5 35
7 8 9 10 11
���������
4
7 8 9 11
*/

#include <stdio.h>
int sum = 0;
int sumMax = 0;
#define MAX_NUM 40
int bTaken[MAX_NUM] = {0};
int bTakenAns[MAX_NUM] = {0};
int t[MAX_NUM];
int N;
int T;
int cntItemMin = 0;
int cntItem = 0;
void FindSolution(void);
void TryItem(int iPosBegin);
int main()
{
	scanf("%d %d", &N, &T);
	int i;
	for(i=1; i<=N; i++)
		scanf("%d", &t[i]);
	//end of input
	TryItem(1);
	if(cntItemMin == 0)
	{
		printf("No Solution Found"); 
	}
	else
	{
		printf("%d\n", cntItemMin);
		for(i=1; i<=N; i++)
			if(bTakenAns[i])printf("%d\n", t[i]);
	}
	return 0;
}
void TryItem(int iPosBegin)
{
	int i;
	for(i=1; i<=2; i++)
	{
		if(i==1)
		{
			if(sum + t[iPosBegin] > T) continue;
			bTaken[iPosBegin] = 1;
			sum += t[iPosBegin];
			cntItem ++;
		}
		if(iPosBegin==N)
			FindSolution();
		else
			TryItem(iPosBegin+1);
		if(i==1)
		{
			bTaken[iPosBegin] = 0;
			sum -= t[iPosBegin];
			cntItem --;
		}

	}
}
void FindSolution()
{
	if(
	    ((sum == sumMax) && 
		 (cntItem < cntItemMin || cntItemMin == 0))
		||
		(sum > sumMax)
	  )
	{
		sumMax = sum;
		cntItemMin = cntItem;
		//copy array
		int i;
		for(i=1; i<=N; i++)
			bTakenAns[i] = bTaken[i];
	}
}