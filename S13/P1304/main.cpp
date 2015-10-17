/*
�����⣺ ��ʿѲ�����⣨25 �֣� 
�� N*N �ķ�����ϣ��и���ʿϣ����ĳ������㿪ʼ���ߡ��ա�����ȥ����
���еķ���㣬����ÿ�β����ߵ����������ķ�����ϡ�
˵���� 2*2 �ķ����ϣ����� x ��ֵ������ 0 �� 2������ y ��ֵͬ�������� 0 ��
2�������ʿ����ʼλ���ǣ� 0,0��������û�п��н⡣
�����ʽ��������� 2 �У���һ���� N�� N<5����ֵ���� 2 �а��� 2 ������
�ֱ��ʾ��ʼλ�õ� x �� y ֵ��
�����ʽ�����ֻ��һ��������Ѳ��·�ߵ���������û�п��н⣬����� 0��
�������룺
4
2 2
���������
64
*/

//#define DEBUGING
//#define ONLY_SEARCH_FOR_ONE_SOLUTION

#include <stdio.h>
#ifdef ONLY_SEARCH_FOR_ONE_SOLUTION
#include <stdlib.h>
#endif
#define MAX_N 8 //�����������
#define InRange(x) ((x)>=0 && (x)<=N)
int N;
int cntSolution = 0;
int bVisited[MAX_N+1][MAX_N+1] = {0};
int cntVisited;

//��¼Ѳ�ط���
int seqVisited[MAX_N+1][MAX_N+1] = {0};
int seq = 0;

//��ÿһ��λ�ó�����8�ֿ���
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