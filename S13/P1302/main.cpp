/*
第二题： 鱼的采购问题（25 分） 
小张是一家餐馆的采购人员，一天他去市场上买鱼。在鱼摊上总共有 N 条鱼，
每条鱼的重量为 ti。出于成本考虑，小张最多只能买 T 公斤的鱼，而为了携带方
便，他又希望买的鱼的条数越少越好。所以他必须从这 N 条鱼当中选择若干条，
使得这些鱼的总重量 L 尽可能地大（ L<=T），并且在此前提下，鱼的条数又尽可
能地少。
参数限制： 0<N<=30，表示鱼的总数； 0<T<=20000，表示小张最多能够买的
鱼的总重量； ti 是一个正整数，表示第 i 条鱼的重量。
输入格式：第一行是两个整数 N 和 T，接下来有 N 行，每一行是一个整数
ti，表示第 i 条鱼的重量。
输出格式：第一行是一个整数 K，表示买回家的鱼的数量，接下来有 K 行，
每一行是一个整数，表示一条鱼的重量。若有多个解，输出任意一个解即可。
样例输入：
5 35
7 8 9 10 11
样例输出：
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