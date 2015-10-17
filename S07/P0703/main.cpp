/*
第三题：回文数和质数（25分）
一个数如果从左往右读和从右往左读数字是完全相同的，则称这个数为回文
数，比如898,1221,15651都是回文数。
编写一个程序，输入两个整数min和max，然后对于min~max之间的每一个
整数（包括min和max），如果它既是一个回文数又是一个质数，那么就把它打
印出来。要求，回文数和质数的判断都要用函数的形式来实现。（注：出自课本
第七章第15题）
样例输入：
5 100
样例输出：
5 7 11
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define for_(i,x,y) for(i=x; i<=y; i++)
int reverse(int n)
{
	int ans=0;
	int a;
	while(n != 0)
	{
		ans *= 10;
		ans += (n % 10);
		n /=10;
	}

	return ans;

}
int isAround(int n)
{
	return (reverse(n) == n);
}
int isPrime(int n)
{
	int i;
	if(n==1) return 0;
	for_(i, 2, n-1)
	{
		if(n%i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int min, max;
	scanf("%d %d", &min, &max);
	int i;
	for_(i, min, max)
	{
		if(isAround(i) && isPrime(i))
			printf("%d ", i);
	}
	return 0;
} 
