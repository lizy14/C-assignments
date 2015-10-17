/*
第五题：解线性方程组（20 分）
给定线性方程组：Ax=b，编写一个程序，求它的解。其中 A 是一个 n*n 的矩
阵，表示方程组的系数，b 是一个给定的列向量，x 是所求的列向量。你可以在
线性代数书中找到一些线性方程组的解法，其中高斯消元法是一种比较容易编程
的方法。 
程序输入的第一行为一个正整数 n（1 ≤ n ≤ 10），表示矩阵规模；接下来 n
行，每行输入 n 个整数（且每个整数都大于-10，小于 10） ，表示 A 矩阵；最后 n
行，每行一个实数，表示 b 向量。若该线性方程组有解，则输出 n 行，每行一个
实数，表示求得的向量 x；若方程无解，则输出“Error”。（注：结果保留 2 位
小数）
样例输入：
2
1 1
1 -1
100.0
60.0
样例输出：
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
void rowswitch(int p, int q)//第一种初等行变换
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
void rowtimes(int src, int des, double times)//第二种初等行变换
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
	//输入结束


	j=1;	//j是检查各列所用的遍历变量

	for(j=1; j<=n; j++)
	{
		//下面换行使得对角元素非零
		i=j;	//i是交换行所用的遍历变量
		while(a[j][j] == 0)
		{
			if(i==n)errorexit
			i++;
			rowswitch(j,i);
		}

		//下面开始将系数消为零
		i=j+1;	//i是系数消为零所用的遍历变量
		for(i=j+1;i<=n;i++)
		{
			if(a[j][j]!=0)rowtimes(j, i ,-a[i][j]/(double)a[j][j]);
		}

	}//对列的遍历结束

	//高斯消元法结束，下面开始求根

	double ans[11]={0};
	//i是求根的遍历变量
	for(i=n;i>0;i--)
	{
		//j是求和变量
		for(j=i+1;j<=n;j++)
			ans[i] -= ans[j] * a[i][j];
		ans[i]+=b[i];
		ans[i]/=a[i][i];
	}

	//下面输出根
	{
		for(i=1;i<=n;i++)
		{
			printf("%.2lf\n",ans[i]);
		}
	}
	return 0;
}
