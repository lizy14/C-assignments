//��¥ʱһ��������һ��̨�ף�Ҳ�����߶�������
//��̨�ס����дһ���ݹ���򣬼��㹲�ж����ֲ�ͬ���߷���
#include <stdio.h>
int ways(int n)
{
	if(n==1 || n==0) return 1;
	if(n<0) return 0;
	return ways(n-1)+ways(n-2)+ways(n-3);
}
int main()
{
	int n; scanf("%d", &n);
	printf("%d", ways(n));
	return 0;
}