/*
�����⣺�������˻���25 �֣�
��дһ�����򣬼���һ���޷���������unsigned  int���İ������˻�������һ
���޷������� x ��˵�����İ������˻�������������ģ���� x ��һ����λ����
��ô���İ������˻�����������������Ļ���x �İ������˻��͵������ĸ�λ��
0 ������������õ����Ǹ������İ������˻���
���磬4018224312 �İ������˻����� 8�����Ǿ������µļ�������������
�ģ�
4018224312->4*1*8*2*2*4*3*1*2->3072
3072->3*7*2->42
42->4*2->8
�������룺
4018224312
���������
8
*/
#include <stdio.h>
unsigned alpha(unsigned original)
{
	unsigned a=original, b=0, t=1;
	if(a<10)return a;
	while(a!=0)
	{
		b=a%10;
		a=a/10;
		t=t*(b==0?1:b);
	}
	return alpha(t);
}
int main()
{
	unsigned n;
	scanf("%d", &n);
	printf("%d", alpha(n));
	return 0;
}