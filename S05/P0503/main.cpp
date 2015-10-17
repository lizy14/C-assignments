/*
第三题：单词个数统计（20 分）
编写一个程序，输入一个句子，然后统计出这个句子当中不同的单词个数。
例如，对于句子“one little two little three  little boys”，总共有 5 个不同的单词，
one, little, two, three, boys。
说明：
a)  由于句子当中包含有空格，所以应该用 gets 函数来输入这个句子。
b)  输入的句子当中只包含英文字符和空格，单词之间用一个空格隔开。
c)  不用考虑单词的大小写，假设输入的都是小写字符。
d)  句子长度不超过 100 个字符
样例输入：
one little two little three little boys
样例输出：
5
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
long long int power26(int letter,int times)//返回 char * 26^int
{
	long long int temp=1;
	int i;
	for(i=0; i<=times-1; i++)
	{
		temp *= 26;
	}
	return letter * temp;
}
int getlettervalue(char letter)
{
	if(letter>='a' && letter<='z')letter -= 32;
	letter -= 64;
	return letter;
}
long long int getstrvalue(char * str, int length)
{
	int i;
	long long int sum=0;
	for(i=0;i<length;i++)
	{
		if(str[i]=='\0') return sum;
		sum += power26(getlettervalue(str[i]), i);
	}
	return sum;
}
int main()
{
	char str[102]={0};
	gets(str);
	long long int currentword;
	int memorized_words[52]={0};
	int memorized_words_count=0;
	int most, lastspace=-1, length = strlen(str);
	int i, i2;
	int notexist;
	for(i=1; i<=length; i++)
	{   
		if(str[i]=='\0' || str[i]==' ' || str[i]=='\n' )
		{
			
			currentword = getstrvalue(&str[lastspace+1], i-lastspace-1);
			
			//下面检查 currentword 是否存在于 memorized_words[] 中
			notexist=1;
			for(i2=1; i2<=memorized_words_count; i2++)
			{
				notexist *= ((currentword - memorized_words[i2])==0 ? 0 : 1);
				//如果出现 0，即已存在， notexist 变成 0

			}
			if(notexist)
			{
				memorized_words_count ++;
				memorized_words[memorized_words_count] = currentword;
			}

			lastspace = i;
		}
	}
	printf("%d", memorized_words_count);

	return 0;
}
