/*
第二题：字符串表达式（25分）
编写程序，在程序中实现字符串表达式求解函数int expression(char* s)。程 序
输入为一个字符串表达式，输出为该函数返回的结果。输入的表达式中只包含加
法和减法，以等号‘=’结束，长度不超过100，并且最少有一项，所有运算均在
整数范围之内。
样例输入：
2+2345+913-3=
样例输出：
3257
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//宏定义
#define for_(i,x,y) for(i=x; i<=y; i++)//可以少按很多次键盘，节约时间！
#define chartoint(x) (x - '0') //提高可读性，可重复使用！

int expression(char* s)
{
	int val = 0;
	int i;
	int len=strlen(s);
	int op = 1;  //上一个运算符
	int num = 0; //待运算数
	for_(i, 0, len - 1)
	{
		switch(s[i])
		{
		case '=':
			val += op*num;
			break;
		case '+':
			val += op*num;
			num = 0;
			op = +1;
			break;
		case '-':
			val += op*num;
			num = 0;
			op = -1;
			break;
		default:
			num *= 10;
			num += chartoint(s[i]);
		}
	}
	return val;
}
int main()
{
	char s[102];
	gets(s);
	printf("%d", expression(s));
	return 0;
} 