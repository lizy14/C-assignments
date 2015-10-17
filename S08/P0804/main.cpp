/*
�����⣺�����˷���25�֣�
�������Ƚϴ���������ʱ�����ܻ����������������Ρ�Ϊ�����������
�Բ����ַ����ķ�����ʵ����������֮��ĳ˷���������˵���������ַ�������
ʽ��������������ÿ�������ĳ��Ȳ�����10λ��Ȼ���������˵Ľ���洢��
��һ���ַ������У����Ȳ��ᳬ��20λ������������ַ�����ӡ������
���磬�����û�����Ϊ��9999999999 ��1000000000����������Ϊ��
9999999999000000000��
��д�����ڳ�����ʵ�ֺ��� void multiply(char* s1, char* s2, char* 
result)�����в���s1��s2Ϊ�������������result = s1 * s2��
�������룺
9999999999 1000000000
���������
9999999999000000000
*/

#define _CRT_SECURE_NO_WARNINGS

//#define DEBUGING

#include <stdio.h>
#include <string.h>
#define for_(i,x,y) for(i=x; i<=y; i++)
#define chartoint(x) (x - '0')
#define inttochar(x) (x + '0')
#define ext 0

void multiply(char* s1, char* s2, char* result)
{
	int i, j;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int val[20 + ext + ext] = {0};
	int x1[10 + ext]={0};
	int x2[10 + ext]={0};

	//"2048" --> {8,4,0,2}
	for_(i, 0, len1 - 1)
		x1[i] = chartoint(s1[len1 -1 - i]);
	for_(i, 0, len2 - 1)
		x2[i] = chartoint(s2[len2 -1 - i]);
#ifdef DEBUGING
	for_(i, 0 , 9 + ext)
		printf("%d ", x1[i]);
	putchar('\n');
	for_(i, 0 , 9 + ext)
		printf("%d ", x2[i]);
	putchar('\n');
#endif



	for_(i, 0, len1 - 1)
	{
		for_(j, 0, len2 - 1)
		{
			val[i+j] += x1[i] * x2[j];
		}
	}
#ifdef DEBUGING
	for_(i, 0 , 19 + ext)
		printf("%d ", val[i]);
	putchar('\n');
#endif
	
	//��λ
	for_(i, 0 , 18 + ext)
	{
		val[i+1] += val[i] / 10;
		val [i] %= 10;
	}
#ifdef DEBUGING
	for_(i, 0 , 19 + ext)
		printf("%d ", val[i]);
	putchar('\n');
#endif


	//���ִ�ת�ַ���
	
	int h;//���λ
	for(i = 19 + ext; i>=0; i--)
	{
		if(val[i] != 0)
		{
			h=i;
			break;
		}
	}
	j = 0;
	for(i = h; i>=0; i--)
	{
		result[j] = inttochar(val[i]);
		j++;		
	}
	result[j] = 0;
	return;
}
int main()
{
	char x[11 + ext], y[11 + ext];
	char result[21 + ext + ext];
	scanf("%s %s", x ,y);
	multiply(x, y, result);
	puts(result);
	return 0;
} 