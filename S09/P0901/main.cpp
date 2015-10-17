/*
问题描述
请使用指针的方法来实现如下字符串库函数：
char* strncpy(char *s, char *t, int n);//复制t的前n个字符至s
char* strncat(char * s, char *t, int n);//连接t的前n个字符至s末尾
说明：实现题目中要求的两个函数。在main中用户输入两个字符串s和t（长度均小于1000），以及整数n。
程序第一行输出调用函数strncpy后得到的字符串s，第二行输出调用函数strncat后得到的字符串s。
（提示：需要把输入的字符串s和t进行复制。否则调用strncpy后，字符串s和t的值已经改变，再调用strncat结果会出错。）
样例输入
Abcde
Xyz
2
样例输出
Xy
AbcdeXy
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define for_(i,x,y) for(i=x; i<=y; i++)
char* strncpy(char *s, char *t, int n)
{
	int i;
	for_(i, 0, n-1)
		s[i]=t[i];
	s[n] = 0;
	return s;
}
char* strncat(char * s, char *t, int n)
{
	int lens = strlen(s);
	int i;
	int j = 0;
	for_(i, lens, lens + n - 1)
		s[i] = t[j++];
	s[i] = 0;
	return s;
}
int main()
{
	char s0[1000];
	char t0[1000];
	gets(s0);
	gets(t0);
	int n;
	scanf("%d", &n);
	//end of input
	int i;
	int lens = strlen(s0);
	int lent = strlen(t0);
	char s[1000];
	char t[1000];
	for_(i, 0, lens + 1)
		s[i] = s0[i];
	for_(i, 0, lent + 1)
		t[i] = t0[i];
	puts(strncpy(s, t, n));
	for_(i, 0, lens + 1)
		s[i] = s0[i];
	for_(i, 0, lent + 1)
		t[i] = t0[i];
	puts(strncat(s, t, n));
	return 0;
} 

