/*
�����⣺�ʼ����ӣ�25�֣�
��Ϊһ�����羯�죬��������Ǽ��ӵ����ʼ����������Ƿ���һЩ���еĹ�
���ʡ���������Щ�ƻ��ķ��������˻�ı�ĳЩ���ʵ���ĸ˳�����ӱܼ�顣
���дһ�����򣬷������ֵ�����˳��Ĺؼ��ʡ�
��������������У���һ���ǹؼ����б��ڶ����Ǵ����ľ��ӡ������
���Ϊ�ڸþ��������ҵ��ľ���˳������Ĺؼ��ʡ�����ĵ���ȫ��ΪСд����
��֮����һ���ո�ָ���ÿһ�еĵ��ʸ������ޣ�ÿһ�г����Ϊ1000����
������ע�����һ�����йؼ�����ؼ����б��ж������ƥ�䣬�򰴹ؼ����б�
˳�����ƥ��ĵ�һ���ؼ��ʣ�
�������룺
guns mines missiles
aameric ssell snug dan iimsssle ot sit neeemis
���������
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

	//��s0�л�ùؼ����б�
	char keywords[MAX_KEYWORD_NUM][LONGEST_WORD];
	int nkw=0;
	int lkw=0;
	for_(i, 0, ls0) //����s0��ÿһ���ַ�
	{
		if(s0[i]==' ' || s0[i]=='\n' || s0[i]==0)//��������ĩβ
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
	//��ȡ�ùؼ����б�����������keywords[][]�У��������±�Ϊnkw
	
	
	char buffer[1001]={0};


	char w[LONGEST_WORD];
	int lw=0;
	for_(i, 0, ls) //����s��ÿһ���ַ�
	{
		if(s[i]==' ' || s[i]=='\n' || s[i]==0)//��������ĩβ
		{
			//��keyword��Ѱ��ƥ��
			w[lw]=0;
			lw=0;
			sort(w,strlen(w));
			for_(j, 0, nkw)
			{
				char buf[LONGEST_WORD];
				strcpy(buf, keywords[j]);
				sort(buf,strlen(buf));
				if(!strcmp(buf,w))//���ַ������
				{
					//Ҫ�����һ�У����Բ���ֱ��puts(keywords[j])
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
