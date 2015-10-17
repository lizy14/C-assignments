/*
第五题：税率问题（20 分）
1988 年的美国税收制度是最简单的一种制度。它包含 4 种类型，各类型及
其应缴的税如下：
单身  17,850$以内 15%，超过的部分 28%
家主  23,900$以内 15%，超过的部分 28%
已婚  29,750$以内 15%，超过的部分 28%
离异  14,875$以内 15%，超过的部分 28%
假 设 一 个 单 身 公 民 的 收 入 是 20,000$,  则他应交的税为
0.15*17,850+0.28*(20,000-17,850)。编写一个程序，输入公民类型（1 表示单身，
2 表示家主，3 表示已婚，4 表示离异）以及他的收入（double 类型） ，输出他应
交的税。 （注：结果保留 6 位小数）
样例输入：
1 20000
样例输出：
3279.50
*/
#include <stdio.h>
#define rate1 0.15
#define rate2 0.28
int main()
{
	double income, tax=0;
	int type;
	scanf("%d %lf", &type, &income);
	
	double stage1[5];

	//第一档税率上限
	stage1[1]=17850;
	stage1[2]=23900;
	stage1[3]=29750;
	stage1[4]=14875;

	


	if(income > stage1[type])
	{
		tax = stage1[type] * rate1 + (income - stage1[type]) * rate2;
	}
	else
	{
		tax = income * rate1;
	}
	printf("%.6lf", tax);
	
	
	return 0;
}
