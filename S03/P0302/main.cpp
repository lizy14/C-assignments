/*
�ڶ��⣺���������ͣ�25 �֣�
��дһ���������û�����һ������ n ��n �� 2000�� ��Ȼ������ǰ n ������
�ĺ͡����磺��� n=3 ����ô���Ϊ 2+3+5=10 ����� n=7 ����ô���Ϊ
2+3+5+7+11+13+17=58��
�������룺
7
���������
58
*/ 
#include <stdio.h>
#include <math.h>
int is_prime(int number)
{
	int sqrt_number = sqrt((float) number) + 1;
	int i;
	if(number == 1) return 0;
	if(number == 2) return 1;
	for(i=2; i<=sqrt_number; i++)
	{
		if(number % i ==0) return 0;
	}
	return 1;
}

int main(void)
{
	int max, sum = 0;
	int i;
	int count = 0;
	scanf("%d", &max);
	for(i=1; count <= max; i++, is_prime(i)? count++: 0)
	{
		sum += i * is_prime(i);
	}
	printf("%d", sum);
	return 0;

}
