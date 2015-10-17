/*
第三题：字符串压缩（25分）
编写程序，在程序中实现函数void strcompress(char *s)。程序输入一个字符
串（只包含小写字母和空格，且长度小于1000），然后采用如下的规则对该字符
串当中的每一个字符进行压缩：
a)  如果该字符是空格，则保留该字符。
b)  如果该字符是第1次出现或第3次出现或第6次出现，则保留该字符。
c)  否则，删除该字符。
例如，若用户输入occurrence，经过压缩后，字符c的第2次出现被删除，
第1和第3次出现仍保留；字符r和e的第2次出现均被删除，因此最后的结果
内部资料  清华大学软件学院软件工程（1）作业    第2页  共3页 
为：ocurenc。
样例输入：
occurrence
样例输出：
ocurenc
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define for_(i,x,y) for(i=x; i<=y; i++)
void strcompress(char s[])
{
	int len=strlen(s);
	int n[128]={0};//为每个ASCII字符分配一个计数器
	int i, j;
	for_(i, 0, len-1)
	{
		n[s[i]]++;
		if(s[i]==' ')continue;
		if(n[s[i]] != 1 && n[s[i]] != 3 && n[s[i]] != 6)
		{
			//删除该字符
			for_(j, i, len-1)
			{
				s[j] = s[j+1];
			}
			len--;
			i--;
		}
	}
	s[len] = 0;
}
int main()
{
	char s[102];
	gets(s);
	strcompress(s);
	puts(s);
	return 0;
} 
