/*
第四题：邮件监视（25分）
作为一名网络警察，你的任务是监视电子邮件，看其中是否有一些敏感的关
键词。不过，有些狡猾的犯罪嫌疑人会改变某些单词的字母顺序，以逃避检查。
请编写一个程序，发现这种调整过顺序的关键词。
程序的输入有两行，第一行是关键词列表，第二行是待检查的句子。程序的
输出为在该句子中所找到的经过顺序调整的关键词。输入的单词全部为小写，单
词之间以一个空格分隔，每一行的单词个数不限，每一行长度最长为1000个字
符。（注：如果一个敏感关键词与关键词列表中多个单词匹配，则按关键词列表
顺序输出匹配的第一个关键词）
样例输入：
guns mines missiles
aameric ssell snug dan iimsssle ot sit neeemis
样例输出：
guns missiles
*/

//#define DEBUGING

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define for_(i,x,y) for(i=x; i<=y; i++)
#define LONGEST_WORD 50
#define MAX_KEYWORD_NUM 50
void sort(char a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp; 
			} 
		} 
	} 
}

int main()
{
	char s0[1001], s[1001];
	gets(s0);//keyword
	gets(s);//mail
	//end of input
	
	int ls0=strlen(s0);
	int ls=strlen(s);



	int i;
	int j;

	//从s0中获得关键词列表
	char keywords[MAX_KEYWORD_NUM][LONGEST_WORD];
	int nkw=0;
	int lkw=0;
	for_(i, 0, ls0) //遍历s0中每一个字符
	{
		if(s0[i]==' ' || s0[i]=='\n' || s0[i]==0)//遇到单词末尾
		{
			keywords[nkw][lkw]=0;
			nkw ++;
			lkw=0;
		}
		else
		{
			keywords[nkw][lkw++]=s0[i];
		}
	}
	nkw--;
#ifdef DEBUGING
	for_(i, 0, nkw)
		puts(keywords[i]);
	printf(">> keyword indexing done, nkw = %d\n", nkw);
#endif
	//已取得关键词列表，保存在数组keywords[][]中，外层最大下标为nkw
	
	
	char buffer[1001]={0};


	char w[LONGEST_WORD];
	int lw=0;
	for_(i, 0, ls) //遍历s中每一个字符
	{
		if(s[i]==' ' || s[i]=='\n' || s[i]==0)//遇到单词末尾
		{
			//在keyword中寻找匹配
			w[lw]=0;
			lw=0;
			sort(w,strlen(w));
			for_(j, 0, nkw)
			{
				char buf[LONGEST_WORD];
				strcpy(buf, keywords[j]);
				sort(buf,strlen(buf));
				if(!strcmp(buf,w))//若字符串相等
				{
					//要求输出一行，所以不能直接puts(keywords[j])
					strcat(buffer, keywords[j]);
					strcat(buffer, " ");
					goto finishchar;
				}
			}
			
		}
		else
		{
			w[lw++]=s[i];
		}
		finishchar:
		;
	}
	puts(buffer);
	return 0;
} 
