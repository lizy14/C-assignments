/*
第二题：计算质数和（25 分）
编写一个程序，由用户输入一个整数 n （n ≤ 2000） ，然后计算出前 n 个质数
的和。例如：如果 n=3 ，那么结果为 2+3+5=10 ；如果 n=7 ，那么结果为
2+3+5+7+11+13+17=58。
样例输入：
7
样例输出：
58
*/ 
#include <stdio.h>
#include <math.h>
int is_prime(int number)
{
	int sqrt_number = sqrt((float) number) + 1;
	int i;
	if(number == 1) return 0;
	if(number == 2) return 1;
	for(i=2; i<=sqrt_number; i++)
	{
		if(number % i ==0) return 0;
	}
	return 1;
}

int main(void)
{
	int max, sum = 0;
	int i;
	int count = 0;
	scanf("%d", &max);
	for(i=1; count <= max; i++, is_prime(i)? count++: 0)
	{
		sum += i * is_prime(i);
	}
	printf("%d", sum);
	return 0;

}
