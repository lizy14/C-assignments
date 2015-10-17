/*
第一题：连续平方和（25 分）
编写一个程序，输入两个正整数 min 和 max（min 肯定小于或等于 max 且
max ≤ 1000），然后计算这两个整数之间的所有整数（包括 min 和 max）的平方
和。例如，假设用户输入的是 2 和 5，则计算结果为:2
2
+3
2
+4
2
+5
2
=54。 （注：引自
课本第五章第 8 题）
样例输入：
2 5
样例输出：
54
*/
#include <stdio.h>
int main(void)
{
	int min, max, sum = 0;
	scanf("%d %d", &min, &max);
	for(; min <= max; min++)
	{
		sum += min * min;
	}
	printf("%d", sum);
	return 0;

}
