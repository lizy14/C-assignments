/*
�����⣺��������������25�֣�
һ��������������Ҷ��ʹ����������������ȫ��ͬ�ģ���������Ϊ����
��������898,1221,15651���ǻ�������
��дһ������������������min��max��Ȼ�����min~max֮���ÿһ��
����������min��max�������������һ������������һ����������ô�Ͱ�����
ӡ������Ҫ�󣬻��������������ж϶�Ҫ�ú�������ʽ��ʵ�֡���ע�����Կα�
�����µ�15�⣩
�������룺
5 100
���������
5 7 11
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define for_(i,x,y) for(i=x; i<=y; i++)
int reverse(int n)
{
	int ans=0;
	int a;
	while(n != 0)
	{
		ans *= 10;
		ans += (n % 10);
		n /=10;
	}

	return ans;

}
int isAround(int n)
{
	return (reverse(n) == n);
}
int isPrime(int n)
{
	int i;
	if(n==1) return 0;
	for_(i, 2, n-1)
	{
		if(n%i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int min, max;
	scanf("%d %d", &min, &max);
	int i;
	for_(i, min, max)
	{
		if(isAround(i) && isPrime(i))
			printf("%d ", i);
	}
	return 0;
} 
