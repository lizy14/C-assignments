/*
��һ�⣺���ʸ�����25�֣�
��дһ������RegularPlural���书����ʵ��һ��Ӣ�ĵ��ʵĸ�����ʽ������
�Ĺ���Ϊ��
a)  �������ĩβΪs,x,z,ch��sh�����ں����es��
b)  �������ĩβΪy����ǰһ����ĸΪ��������a, e, i, o, u�����������
���������y�ĳ�ies��
c)  ������������Σ�һ���ں����s��
��д���Գ�������һ������С��20�ĵ��ʣ�����õ��ʵĸ�����ʽ����ע��
���Կα������µ�9�⣩
�������룺
box
���������
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
