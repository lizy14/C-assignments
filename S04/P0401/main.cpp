/*
��һ�⣺���������25 �֣�
��дһ�������û���һ������һ������ seed����Ϊ����������ӣ��ڶ���
�������������� min �� max��1 �� min, max �� 100 �� max ? min �� 4�� ��������
�� 5 ���ڱ�����[min, max]�ڵ�һ�鲻�ظ�������������У������� 5 ��������
����������������Ľ����
�������룺
100
3 10
���������
3 5 8 9 10
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, max, min, zzz[5]={0}, i, c;
	double b;
	scanf("%d\n%d %d", &a, &min, &max);
	srand(a);
	i=0;
	do
	{
		b = rand() / (double)(RAND_MAX+1);
		c = min + b * ( max - min +1);
		if(c!=zzz[0]&&c!=zzz[1]&&c!=zzz[2]&&c!=zzz[3]&&c!=zzz[4])
		{
			if(c<zzz[0])
			{
				zzz[4]=zzz[3];
				zzz[3]=zzz[2];
				zzz[2]=zzz[1];
				zzz[1]=zzz[0];
				zzz[0]=c;
			}
			else if(c<zzz[1])
			{
				zzz[4]=zzz[3];
				zzz[3]=zzz[2];
				zzz[2]=zzz[1];
				zzz[1]=c;
			}
			else if(c<zzz[2])
			{
				zzz[4]=zzz[3];
				zzz[3]=zzz[2];
				zzz[2]=c;
			}
			else if(c<zzz[3])
			{
				zzz[4]=zzz[3];
				zzz[3]=c;
			}
			else
			{
				zzz[i]=c;
			}
			i++;
		}
	}
	while(i<=4);
	for(i=0;i<=4;i++)
	{
		printf("%d ", zzz[i]);
	}
	return 0;
}
