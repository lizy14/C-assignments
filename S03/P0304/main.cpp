/*
第四题：分数序列（25 分）
有一分数序列
2
1
，
3
2
，
5
3
，
8
5
，
13
8
，
21
13
， …
求出这个数列的前 n 项之和（1 ≤ n ≤ 40） ，例如用户输入的是 6，则计算结
果为: 10.01。 （注：结果保留 2 位小数）
样例输入：
6
样例输出：
10.01
*/
#include <stdio.h>

int main(void)
{
	int max;
	scanf("%d", &max);
	int i;
	int F[40];
	F[0] = 1;
	F[1] = 1;
	for(i = 2; i <= max+1; i++)
	{
		F[i] = F[i-1] + F[i-2];
	}
	float sum = 0;
	for(i = 1; i <= max; i++)
	{
		sum += F[i+1] / (F[i]+0.0);
	}
	printf("%.2f", sum);
	return 0;
}
