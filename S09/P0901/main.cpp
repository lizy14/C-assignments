/*
��������
��ʹ��ָ��ķ�����ʵ�������ַ����⺯����
char* strncpy(char *s, char *t, int n);//����t��ǰn���ַ���s
char* strncat(char * s, char *t, int n);//����t��ǰn���ַ���sĩβ
˵����ʵ����Ŀ��Ҫ���������������main���û����������ַ���s��t�����Ⱦ�С��1000�����Լ�����n��
�����һ��������ú���strncpy��õ����ַ���s���ڶ���������ú���strncat��õ����ַ���s��
����ʾ����Ҫ��������ַ���s��t���и��ơ��������strncpy���ַ���s��t��ֵ�Ѿ��ı䣬�ٵ���strncat����������
��������
Abcde
Xyz
2
�������
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

