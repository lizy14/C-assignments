/*
第一题：单词复数（25分）
编写一个函数RegularPlural，其功能是实现一个英文单词的复数形式。复数
的规则为：
a)  如果单词末尾为s,x,z,ch或sh，则在后面加es；
b)  如果单词末尾为y，且前一个字母为辅音（除a, e, i, o, u以外的其它情
况），则把y改成ies；
c)  如果是其它情形，一律在后面加s。
编写测试程序，输入一个长度小于20的单词，输出该单词的复数形式。（注：
出自课本第七章第9题）
样例输入：
box
样例输出：
boxes
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char word[25];
void Add_es(char * word)
{
	int len = strlen(word);
	word[len] = 'e';
	word[len+1] = 's';
}
void Add_s(char * word)
{
	int len = strlen(word);
	word[len] = 's';
}
void Add_ies(char * word)
{
	int len = strlen(word);
	word[len-1] = 'i';
	word[len] = 'e';
	word[len+1] = 's';
}
void RegularPlural(char * word)
{
	int len = strlen(word);
	switch(word[len-1])
	{
	case 's':
	case 'x':
	case 'z':
		Add_es(word);
		break;
	case 'h':
		if(len > 1)
		{
			switch(word[len-2])
			{
			case 'c':
			case 's':
				Add_es(word);
				break;
			}
		}
		else
		{
			Add_s(word);
		}
		break;
	case 'y':
		if(len > 1)
		{
			switch(word[len-2])
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				Add_s(word);
				break;
			default:
				Add_ies(word);
				break;
			}
		}
		else
		{
			Add_s(word);
		}
		break;
	default:
		Add_s(word);
	}		



}
int main()
{
	gets(word);
	RegularPlural(word);
	puts(word);
	return 0;
} 
