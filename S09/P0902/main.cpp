/*
�ڶ��⣺�������25�֣�
��һ�����������������Ŀ�У���Ʒ����MC�������ۣ�DJ����������SL���� ��
��һ���ṹ��prut�����Ա��������������ݡ����������ж���һ��prut���͵�
�ṹ�����飬����ÿ��Ԫ�ص�ֵ�����㲢�����������ܽ�
�����ʽ����һ�������������N (N<100)��������ÿһ����һ�������
��Ʒ���ǳ��Ȳ�����100���ַ���������Ϊdouble���ͣ�����Ϊ���͡�
�����ʽ��double���͵��ܽ��������6λС����
�������룺
4
book 12.5 3
pen 2.5 10
computer 3200 1
flower 47 5
���������
3497.500000
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define for_(i,x,y) for(i=x; i<=y; i++)
struct prut
{
	char MC[101];
	double DJ;
	int SL;
};
int main()
{
	prut prut_[100];
	int n;
	scanf("%d", &n);
	int i;
	for_(i, 0, n-1)
	{
		scanf("%s", &prut_[i].MC);
		scanf("%lf", &prut_[i].DJ);
		scanf("%d", &prut_[i].SL);
	}
	//end of input

 	double sum = 0;
	for_(i, 0, n-1)
	{
		sum += prut_[i].DJ * prut_[i].SL;
	}
	printf("%.6lf", sum);
	return 0;
} 
