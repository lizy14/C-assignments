/*
�����⣺�ɼ�����25�֣�
����һ��ѧ���ṹ������student���� ��4���ֶΣ��������Ա�����ͳɼ���
Ȼ�����������ж���һ���ṹ�����飨���Ȳ�����1000����������ÿ��Ԫ�ص�ֵ��
�ڲ�����  �廪��ѧ���ѧԺ������̣�1����ҵ    ��2ҳ  ��3ҳ 
����ʹ��ð�����򷨽�ѧ�����ճɼ���С�����˳������Ȼ���������Ľ����
�����ʽ����һ����һ������N��N<1000������ʾԪ�ظ�����������N��ÿ
������һ��Ԫ�أ��������Ա��ǳ��Ȳ�����20���ַ���������ͳɼ�������
�͡�
�����ʽ�����ɼ���С�����������Ԫ�أ������ѧ���ɼ���ͬ��ɼ���ͬ
��ͬѧ֮�䱣��ԭ��������˳��
�������룺
3
Alice female 18 98
Bob male 19 90
Miller male 17 92
���������
Bob male 19 90
Miller male 17 92
Alice female 18 98
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define for_(i,x,y) for(i=x; i<=y; i++)

struct student
{
	char name[21];
	char gender[21];
	int age;
	int score;
};

void sort(student student_[],int n)
{
	int i,j;
	student temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(student_[j].score>student_[j+1].score)
			{
				temp=student_[j];
				student_[j]=student_[j+1];
				student_[j+1]=temp; 
			} 
		} 
	} 
}

int main()
{
	student student_[1000];
	int n;
	scanf("%d", &n);
	int i;
	for_(i, 0, n-1)
		scanf("%s %s %d %d", 
		&student_[i].name,
		&student_[i].gender,
		&student_[i].age,
		&student_[i].score);
	//end of input

	sort(student_, n);

	for_(i, 0, n-1)
		printf("%s %s %d %d\n", 
		student_[i].name,
		student_[i].gender,
		student_[i].age,
		student_[i].score);
	return 0;
} 
