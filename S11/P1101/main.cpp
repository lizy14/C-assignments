//编程实现阿克曼函数（ Ackmann）函数 A(x,y)
//无聊的递归练习
#include <stdio.h>
int Ackmann(int x, int y)
{
	if(x==0) return y+1;
	if(y==0) return Ackmann(x-1, 1);
	return Ackmann(x-1, Ackmann(x,y-1));
}
int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d", Ackmann(x,y));
	return 0;
}