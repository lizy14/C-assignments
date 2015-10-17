/*
�����⣺�����Է����飨20 �֣�
�������Է����飺Ax=b����дһ�����������Ľ⡣���� A ��һ�� n*n �ľ�
�󣬱�ʾ�������ϵ����b ��һ����������������x ����������������������
���Դ��������ҵ�һЩ���Է�����Ľⷨ�����и�˹��Ԫ����һ�ֱȽ����ױ��
�ķ����� 
��������ĵ�һ��Ϊһ�������� n��1 �� n �� 10������ʾ�����ģ�������� n
�У�ÿ������ n ����������ÿ������������-10��С�� 10�� ����ʾ A ������� n
�У�ÿ��һ��ʵ������ʾ b �������������Է������н⣬����� n �У�ÿ��һ��
ʵ������ʾ��õ����� x���������޽⣬�������Error������ע��������� 2 λ
С����
�������룺
2
1 1
1 -1
100.0
60.0
���������
80.00
20.00
*/
#include <stdio.h>
#define errorexit {printf("Error");return 0;}
double a[11][11]={0};
double b[11]={0};
int n;
void printmatrix()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%-8.2lf",a[i][j]);
		}
		printf("%-8.2lf\n",b[i]);
	}
	printf("\n\n");
}
void rowswitch(int p, int q)//��һ�ֳ����б任
{
	int i;
	double temp;
	for(i=1;i<=n;i++)
	{
		temp = a[p][i];
		a[p][i] = a[q][i];
		a[q][i] = temp;
	}
	temp = b[p];
	b[p] = b[q];
	b[q] = temp;
}
void rowtimes(int src, int des, double times)//�ڶ��ֳ����б任
{
	int i;
	for(i=1;i<=n;i++)
	{
		a[des][i]=a[des][i]+a[src][i]*times;
	}
	b[des]=b[des]+b[src]*times;
}
int main()
{
	scanf("%d", &n);
	int i,j;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lf",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lf",&b[i]);
	}
	//�������


	j=1;	//j�Ǽ��������õı�������

	for(j=1; j<=n; j++)
	{
		//���滻��ʹ�öԽ�Ԫ�ط���
		i=j;	//i�ǽ��������õı�������
		while(a[j][j] == 0)
		{
			if(i==n)errorexit
			i++;
			rowswitch(j,i);
		}

		//���濪ʼ��ϵ����Ϊ��
		i=j+1;	//i��ϵ����Ϊ�����õı�������
		for(i=j+1;i<=n;i++)
		{
			if(a[j][j]!=0)rowtimes(j, i ,-a[i][j]/(double)a[j][j]);
		}

	}//���еı�������

	//��˹��Ԫ�����������濪ʼ���

	double ans[11]={0};
	//i������ı�������
	for(i=n;i>0;i--)
	{
		//j����ͱ���
		for(j=i+1;j<=n;j++)
			ans[i] -= ans[j] * a[i][j];
		ans[i]+=b[i];
		ans[i]/=a[i][i];
	}

	//���������
	{
		for(i=1;i<=n;i++)
		{
			printf("%.2lf\n",ans[i]);
		}
	}
	return 0;
}
