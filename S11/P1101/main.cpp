//���ʵ�ְ����������� Ackmann������ A(x,y)
//���ĵĵݹ���ϰ
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