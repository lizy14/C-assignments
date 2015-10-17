/*
第一题：随机数排序（25 分）
编写一个程序，用户第一行输入一个整数 seed，作为随机数的种子；第二行
输入两个正整数 min 和 max（1 ≤ min, max ≤ 100 且 max ? min ≥ 4） 。程序生
成 5 个在闭区间[min, max]内的一组不重复的随机整数序列，并对这 5 个数按照
升序排序，输出排序后的结果。
样例输入：
100
3 10
样例输出：
3 5 8 9 10
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, max, min, zzz[5]={0}, i, c;
	double b;
	scanf("%d\n%d %d", &a, &min, &max);
	srand(a);
	i=0;
	do
	{
		b = rand() / (double)(RAND_MAX+1);
		c = min + b * ( max - min +1);
		if(c!=zzz[0]&&c!=zzz[1]&&c!=zzz[2]&&c!=zzz[3]&&c!=zzz[4])
		{
			if(c<zzz[0])
			{
				zzz[4]=zzz[3];
				zzz[3]=zzz[2];
				zzz[2]=zzz[1];
				zzz[1]=zzz[0];
				zzz[0]=c;
			}
			else if(c<zzz[1])
			{
				zzz[4]=zzz[3];
				zzz[3]=zzz[2];
				zzz[2]=zzz[1];
				zzz[1]=c;
			}
			else if(c<zzz[2])
			{
				zzz[4]=zzz[3];
				zzz[3]=zzz[2];
				zzz[2]=c;
			}
			else if(c<zzz[3])
			{
				zzz[4]=zzz[3];
				zzz[3]=c;
			}
			else
			{
				zzz[i]=c;
			}
			i++;
		}
	}
	while(i<=4);
	for(i=0;i<=4;i++)
	{
		printf("%d ", zzz[i]);
	}
	return 0;
}
