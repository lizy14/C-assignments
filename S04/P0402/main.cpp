/*
第二题：数列问题（25 分）
编写一个程序，计算以下数列的值。 当用户输入 n （0 ≤ n ≤ 15） 时，程序输
出第 n 个元素的值。
公式略 
样例输入：
7
样例输出：
7953
*/
#include <stdio.h>
int main()
{
	int a[16];
	int n, i;
	scanf("%d", &n);
	a[0]=1;
	a[1]=3;
	for(i=2;i<=n;i++)
	{
		a[i] = 4*a[i-1] -a[i-2];
	}
	printf("%d",a[n]);
	return 0;
}
