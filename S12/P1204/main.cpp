/*
第四题： 棋盘问题（25 分）
在 N*N（ 1<=N<=5）的棋盘上填入 1,2，…， N*N，共 N*N 个数，使得任意
两个相邻的数之和为素数。例如，当 N=2 时，有：
1 4
2 3
显然，在这种情形下，任意两个相邻的数之和均为素数： 1+2=3, 1+4=5, 4+3=7,
2+3=5。在这里我们约定：左上角的格子里必须放数字 1.
请编写一个程序，输入一个 N， 任意输出一个方案，如果无解，则输出 0。
样例输入：
2
样例输出：
1 4
2 3
*/

#include <stdio.h>

#define N 5 //允许最大输入

typedef int 整型;
typedef void 空类型;
typedef float 浮点;
typedef double 双精度浮点;
#define 如果 if
#define 反之 else
#define 返回 return
#define 计数循环 for
#define 格式化输出 printf
#define 格式化输入 scanf
#define 结构体 struct

#define 小于等于 <=
#define 大于等于 >=
#define 大于 >
#define 小于 <
#define 自增 ++
#define 自减 --
#define 且 &&
#define 取余 %

#define 主函数 main

整型 棋盘[N+1][N+1];
整型 数字已使用[N*N+1]={0,1,0};
整型 位置=1;

结构体{
	整型 x;
	整型 y;
	整型 数字;
}顺序标记[N*N+1];

整型 是素数(整型 m);
整型 查找未用数字(整型 查找起始点,整型 阶数);
整型 符合性检查(整型 x,整型 y);
空类型 填入下一位置(整型 n);
空类型 回溯(整型 n);
空类型 打印棋盘(整型 阶数);

整型 主函数 (){
	整型 i,j,n;
	格式化输入("%d",&n);
	//end of input

	计数循环(i=1;i 小于等于 n;i 自增)
		计数循环(j=1;j 小于等于 n;j 自增)
		棋盘[i][j]=0;
	棋盘[1][1]=1;
	//棋盘初始化结束

	计数循环(i=1;i 小于等于 n;i 自增)
	{
		顺序标记[i].x=1;
		顺序标记[i].y=i;
		顺序标记[i].数字=0;
	}
	顺序标记[1].数字=1;

	计数循环(;i<2*n;i 自增)
	{
		顺序标记[i].x=i-n+1;
		顺序标记[i].y=1;
		顺序标记[i].数字=0;
	}

	如果(n>1)
		计数循环(;i 小于等于 n*n;i 自增)
		{
			顺序标记[i].x=2+(i-2*n)/(n-1);
			顺序标记[i].y=i-2*n+1-(顺序标记[i].x-2)*(n-1)+1;
			顺序标记[i].数字=0;
		}
	//顺序标记[]初始化结束

	整型 符合性标记=1;
	do
	{
		如果(符合性标记)
			如果(位置==n*n)
		{
			打印棋盘(n);
			返回 0;
		}
		反之  填入下一位置(n);
		反之  回溯(n);
		符合性标记=符合性检查(顺序标记[位置].x,顺序标记[位置].y);
	}while(位置 大于等于 1);
	返回 -1;
}

整型 是素数(整型 m)
{
	整型 i;
	如果(m==2)
		返回 1;
	如果(m==1 || m 取余 2==0)
		返回 0;
	计数循环(i=3; i*i 小于等于 m;)
	{
		如果(m 取余 i==0)
			返回 0;
		i+=2;
	}
	返回 1;
}

//如有未用数字，返回编号，否则返回0
整型 查找未用数字(整型 查找起始点,整型 阶数)
{
	整型 j;
	计数循环(j=查找起始点;j 小于等于 阶数 * 阶数;j 自增)
		如果(!数字已使用[j])
		返回 j;
	返回 0;
}

整型 符合性检查(整型 x,整型 y)
{
	如果(x>1 且 !是素数(棋盘[x][y]+棋盘[x-1][y]))
		返回 0;
	如果(y>1 且 !是素数(棋盘[x][y]+棋盘[x][y-1]))
		返回 0;
	返回 1;
}

空类型 填入下一位置(整型 n)
{
	顺序标记[ 自增 位置].数字=查找未用数字(2,n);
	棋盘[顺序标记[位置].x][顺序标记[位置].y]=顺序标记[位置].数字;
	数字已使用[顺序标记[位置].数字]=1;
}

空类型 回溯(整型 n)
{
	整型 j;

	while(位置 大于等于 1 且 (j=查找未用数字(顺序标记[位置].数字+1,n))==0)
		数字已使用[顺序标记[位置 自减].数字]=0;
	如果(位置<1)
	{
		格式化输出("0");
		返回;
	}
	//重置该可行位置
	数字已使用[顺序标记[位置].数字]=0;
	顺序标记[位置].数字=j;
	棋盘[顺序标记[位置].x][顺序标记[位置].y]=顺序标记[位置].数字;
	数字已使用[j]=1;
}

空类型 打印棋盘(整型 阶数)
{
	整型 甲,乙;

	计数循环(甲=1;甲 小于等于 阶数;甲 自增){
		计数循环(乙=1;乙 小于等于 阶数;乙 自增)
			格式化输出("%d ",棋盘[甲][乙]);
		格式化输出("\n");
	}
}