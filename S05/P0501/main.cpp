/*
第一题：字符删除（20 分）
编写一个程序，第一行输入一个字符串 str （长度不超过 20），第二行输入单
独的一个字符 ch。要求程序把字符串 str 当中所有的 ch 字符都删除，从而得到
一个新的字符串，输出新的字符串。
样例输入：
123-45-678
-
样例输出：
12345678
*/ 
#include <stdio.h>
int main()
{
	char str[21]={0}, res[21]={0};
	char ch;
	gets(str);
	ch = getchar();
	int i, count=0;
	for(i=0; i<20; i++)
	{
		if (i+count >= 20) break;
		while (str[i+count] == ch) 
		{
			count++;
			if (i+count >= 20) break;
		}
		if (i+count >= 20) break;
		res[i]=str[i+count];
	}

	puts(res);
	return 0;
}
