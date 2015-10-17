/*
第二题：提货单（25分）
有一份提货单，其数据项目有：商品名（MC）、单价（DJ）、数量（SL）。 定
义一个结构体prut，其成员是上面的三项数据。在主函数中定义一个prut类型的
结构体数组，输入每个元素的值，计算并输出提货单的总金额。
输入格式：第一行是数据项个数N (N<100)，接下来每一行是一个数据项。
商品名是长度不超过100的字符串，单价为double类型，数量为整型。
输出格式：double类型的总金额，结果保留6位小数。
样例输入：
4
book 12.5 3
pen 2.5 10
computer 3200 1
flower 47 5
样例输出：
3497.500000
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define for_(i,x,y) for(i=x; i<=y; i++)
struct prut
{
	char MC[101];
	double DJ;
	int SL;
};
int main()
{
	prut prut_[100];
	int n;
	scanf("%d", &n);
	int i;
	for_(i, 0, n-1)
	{
		scanf("%s", &prut_[i].MC);
		scanf("%lf", &prut_[i].DJ);
		scanf("%d", &prut_[i].SL);
	}
	//end of input

 	double sum = 0;
	for_(i, 0, n-1)
	{
		sum += prut_[i].DJ * prut_[i].SL;
	}
	printf("%.6lf", sum);
	return 0;
} 
