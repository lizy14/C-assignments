/*
��һ�⣺����ƽ���ͣ�25 �֣�
��дһ�������������������� min �� max��min �϶�С�ڻ���� max ��
max �� 1000����Ȼ���������������֮����������������� min �� max����ƽ��
�͡����磬�����û�������� 2 �� 5���������Ϊ:2
2
+3
2
+4
2
+5
2
=54�� ��ע������
�α������µ� 8 �⣩
�������룺
2 5
���������
54
*/
#include <stdio.h>
int main(void)
{
	int min, max, sum = 0;
	scanf("%d %d", &min, &max);
	for(; min <= max; min++)
	{
		sum += min * min;
	}
	printf("%d", sum);
	return 0;

}