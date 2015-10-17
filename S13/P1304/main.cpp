/*
第四题： 骑士巡回问题（25 分） 
在 N*N 的方格点上，有个骑士希望从某个方格点开始，走“日”字形去遍历
所有的方格点，而且每次不能走到曾经到过的方格点上。
说明： 2*2 的方格上，横轴 x 的值可以是 0 到 2，纵轴 y 的值同样可以是 0 到
2。如果骑士的起始位置是（ 0,0），问题没有可行解。
输入格式：输入包括 2 行，第一行是 N（ N<5）的值，第 2 行包括 2 个数，
分别表示起始位置的 x 和 y 值。
输出格式：输出只有一个整数，巡回路线的条数，若没有可行解，则输出 0。
样例输入：
4
2 2
样例输出：
64
*/

//#define DEBUGING
//#define ONLY_SEARCH_FOR_ONE_SOLUTION

#include <stdio.h>
#ifdef ONLY_SEARCH_FOR_ONE_SOLUTION
#include <stdlib.h>
#endif
#define MAX_N 8 //允许最大输入
#define InRange(x) ((x)>=0 && (x)<=N)
int N;
int cntSolution = 0;
int bVisited[MAX_N+1][MAX_N+1] = {0};
int cntVisited;

//记录巡回方案
int seqVisited[MAX_N+1][MAX_N+1] = {0};
int seq = 0;

//从每一个位置出发，8种可能
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};

void Try(int x, int y);
void FindSolution(void);
int main()
{
	
	//int xSrc=2, ySrc=2;
	//N=4;
	scanf("%d", &N);
	int xSrc, ySrc;

		
	scanf("%d %d", &xSrc, &ySrc);
	//end of input

	bVisited[xSrc][ySrc] = 1;
	cntVisited = 1;
	seqVisited[xSrc][ySrc] = 1;
	seq = 1;
	Try(xSrc, ySrc);
	
	printf("%d", cntSolution);
		
	return 0;
		
}
void FindSolution()
{
	cntSolution ++;
#ifdef DEBUGING
	int x , y;
	printf("Solution ID %d\n", cntSolution);
	for(x=0; x<=N; x++)
	{
		for(y=0; y<=N; y++)
			printf("%4d", seqVisited[x][y]);
		putchar('\n');
	}
	putchar('\n');
#endif
#ifdef ONLY_SEARCH_FOR_ONE_SOLUTION
	exit(0);
#endif

}
void Try(int x, int y)
{
	int i;
	for(i=0; i<8; i++)
	{
		if(!InRange(x+dx[i])) continue;
		if(!InRange(y+dy[i])) continue;
		if(bVisited[x+dx[i]][y+dy[i]]) continue;
		
		bVisited[x+dx[i]][y+dy[i]] = 1;
		cntVisited ++;
		seqVisited[x+dx[i]][y+dy[i]] = ++seq;
		if(cntVisited == (N+1)*(N+1))
			FindSolution();
		else
		{
			if(x==4 && y==3)
			{
				int x6=0;
				x6++;
			}
			Try(x+dx[i], y+dy[i]);
		}
		bVisited[x+dx[i]][y+dy[i]] = 0;
		cntVisited --;
		seqVisited[x+dx[i]][y+dy[i]] =0,  seq--;
	}
}