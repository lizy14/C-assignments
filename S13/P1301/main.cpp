/*
��һ�⣺ ѭ�����ճ̱����⣨25 �֣� 
������� n=2^k ���˶�ԱҪ��������ѭ��������Ҫ���һ����������Ҫ���
�����ճ̱�
a) ÿ��ѡ�ֱ��������� n-1 ��ѡ�ָ���һ�Ρ�
b) ÿ��ѡ��һ��ֻ����һ�Ρ�
c) ѭ������ n-1 ���ڽ�����
�밴��Ҫ�󽫱����ճ̱���Ƴ��� n �к� n-1 �е�һ���������ʽ������
����ͼ��ʾ���ڱ��еĵ� i �С��� j �д������ i ��ѡ���ڵ� j ����������ѡ
�֡����� 1<=i<=n, 1<=j<n������ n(n <= 512) ����������ճ̱�
�������룺
4
���������
2 3 4
1 4 3
4 1 2
3 2 1
*/



/*
���εݹ顣
����  n �ˣ���ѭ����������n-1������ɡ�
���� 2n �ˣ�ǰn-1�죬��ǰn�˺ͺ�n���ڲ��ֱ���е�ѭ��������n�죬ǰn�˺ͺ�n������������
*/

//ѡ��id��1��ʼ���������ڴ�1��ʼ

#define OUT_PUT_FORMAT "%d "
//#define OUT_PUT_FORMAT "%3d, "
#include <stdio.h>
#define MAX_PLAYER_NUM 512
void Arrange(int nPlayer, int idFirstPlayer, int idFirstDay);
void ArrangeSingleMatch(int idPlayer1, int idPlayer2, int idDate);
int Table[MAX_PLAYER_NUM + 1][MAX_PLAYER_NUM] = {  0};//��һ���±��ʾѡ��id���ڶ����±��ʾ���ڣ���ֵΪ����id


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

//��Ҫ�ݹ麯�������ű�����n��ѡ�֡�n-1�죬���ڴ�idFirstDay��ʼ��ѡ�ִ�idFirstPlayer��ʼ������
void Arrange(int nPlayer, int idFirstPlayer, int idFirstDay)
{
	//�ݹ���ֹ����
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
		for(i=1; i<=nPlayer/2; i++)//��������i�����£�����ƫ������i
		{
			for(j=1; j<=nPlayer/2; j++)  //ǰ���������
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
