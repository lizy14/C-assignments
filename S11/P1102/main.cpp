//上楼时一步可以走一级台阶，也可以走二级或三
//级台阶。请编写一个递归程序，计算共有多少种不同的走法？
#include <stdio.h>
int ways(int n)
{
	if(n==1 || n==0) return 1;
	if(n<0) return 0;
	return ways(n-1)+ways(n-2)+ways(n-3);
}
int main()
{
	int n; scanf("%d", &n);
	printf("%d", ways(n));
	return 0;
}