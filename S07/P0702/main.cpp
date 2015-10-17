/*
第二题：strcmp函数（25分）
在C语言中，有一个strcmp函数，其功能是比较两个字符串s1和s2。请编
写一个你自己的字符串比较函数my_strcmp，来实现strcmp函数的类似功能。如
果s1=s2，则返回0；否则返回s1 与s2 第一个不同字符的差值（如果s1<s2，该
差值是一个负数；如果s1>s2，该差值是一个正数）。
编写测试程序，输入两个长度小于1000的字符串（可能包含有空格，且长度
不一定相等），然后调用my_strcmp函数来进行比较，并输出返回结果。（注：出
自课本第七章第12题）
样例输入：
aBcDefgf
aacdef
样例输出：
-31
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int my_strcmp(char* s1, char* s2)
{
	int l1=strlen(s1);
	int l2=strlen(s2);
	int i, dif;
	for(i=0; i<(l1>=l2? l1:l2); i++)
	{
		if(dif=s1[i]-s2[i])
			return dif;
	}
	return 0;
}
int main()
{
	char s1[1000]={0};
	char s2[1000]={0};
	gets(s1);
	gets(s2);
	printf("%d",my_strcmp(s1, s2));
	return 0;
} 
