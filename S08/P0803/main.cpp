/*
�����⣺�ַ���ѹ����25�֣�
��д�����ڳ�����ʵ�ֺ���void strcompress(char *s)����������һ���ַ�
����ֻ����Сд��ĸ�Ϳո��ҳ���С��1000����Ȼ��������µĹ���Ը��ַ�
�����е�ÿһ���ַ�����ѹ����
a)  ������ַ��ǿո��������ַ���
b)  ������ַ��ǵ�1�γ��ֻ��3�γ��ֻ��6�γ��֣��������ַ���
c)  ����ɾ�����ַ���
���磬���û�����occurrence������ѹ�����ַ�c�ĵ�2�γ��ֱ�ɾ����
��1�͵�3�γ����Ա������ַ�r��e�ĵ�2�γ��־���ɾ����������Ľ��
�ڲ�����  �廪��ѧ���ѧԺ������̣�1����ҵ    ��2ҳ  ��3ҳ 
Ϊ��ocurenc��
�������룺
occurrence
���������
ocurenc
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define for_(i,x,y) for(i=x; i<=y; i++)
void strcompress(char s[])
{
	int len=strlen(s);
	int n[128]={0};//Ϊÿ��ASCII�ַ�����һ��������
	int i, j;
	for_(i, 0, len-1)
	{
		n[s[i]]++;
		if(s[i]==' ')continue;
		if(n[s[i]] != 1 && n[s[i]] != 3 && n[s[i]] != 6)
		{
			//ɾ�����ַ�
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
