/*
第一题： 循环赛日程表问题（25 分） 
设你班有 n=2^k 个运动员要进行网球循环赛。现要设计一个满足以下要求的
比赛日程表：
a) 每个选手必须与其它 n-1 个选手各赛一次。
b) 每个选手一天只能赛一次。
c) 循环赛在 n-1 天内结束。
请按此要求将比赛日程表设计成有 n 行和 n-1 列的一个表，表的形式和内容
如下图所示。在表中的第 i 行、第 j 列处填入第 i 个选手在第 j 天所遇到的选
手。其中 1<=i<=n, 1<=j<n。输入 n(n <= 512) ，输出比赛日程表。
样例输入：
4
样例输出：
2 3 4
1 4 3
4 1 2
3 2 1
*/



/*
分治递归。
对于  n 人：单循环赛可以在n-1天内完成。
对于 2n 人：前n-1天，让前n人和后n人内部分别进行单循环赛；后n天，前n人和后n人两两比赛。
*/

//选手id从1开始，比赛日期从1开始

#define OUT_PUT_FORMAT "%d "
//#define OUT_PUT_FORMAT "%3d, "
#include <stdio.h>
#define MAX_PLAYER_NUM 512
void Arrange(int nPlayer, int idFirstPlayer, int idFirstDay);
void ArrangeSingleMatch(int idPlayer1, int idPlayer2, int idDate);
int Table[MAX_PLAYER_NUM + 1][MAX_PLAYER_NUM] = {  0};//第一个下标表示选手id，第二个下标表示日期，数值为对手id


int main()
{
	int n; 
	scanf("%d", &n);
	//n=16384;
	Arrange(n, 1, 1);
	int i, j;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<n; j++)
			printf(OUT_PUT_FORMAT,Table[i][j]);
		putchar('\n');
	}
}

//主要递归函数：安排比赛，n个选手、n-1天，日期从idFirstDay开始，选手从idFirstPlayer开始，均含
void Arrange(int nPlayer, int idFirstPlayer, int idFirstDay)
{
	//递归终止条件
	if(nPlayer == 2)
	{
		Table[idFirstPlayer]  [idFirstDay] = idFirstPlayer+1;
		Table[idFirstPlayer+1][idFirstDay] = idFirstPlayer;
	}
	else
	{
		Arrange(nPlayer/2, idFirstPlayer,           idFirstDay);
		Arrange(nPlayer/2, idFirstPlayer+nPlayer/2, idFirstDay);
		int i, j;
		for(i=1; i<=nPlayer/2; i++)//安排日期i的赛事，当天偏移量是i
		{
			for(j=1; j<=nPlayer/2; j++)  //前半组里的人
			{
				int Date    = idFirstDay   +nPlayer/2 +i -2;
				int Player1 = idFirstPlayer           +j -1;
				int Player2 = idFirstPlayer+nPlayer/2 +j +i -2;
				if(Player2 > idFirstPlayer+nPlayer-1)
					Player2 -= nPlayer/2;

				ArrangeSingleMatch(Player1, Player2, Date);
				
			}

			
		}
	}


}

void ArrangeSingleMatch(int idPlayer1, int idPlayer2, int idDate)
{
	Table[idPlayer1][idDate]=idPlayer2;
	Table[idPlayer2][idDate]=idPlayer1;
}
