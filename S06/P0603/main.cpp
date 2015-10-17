/*
�����⣺����ѭ����25 �֣�
��дһ����������һ�� 4 λ��������������ɸ����ĸ�λ�����������У�
�γ�һ���������һ����С����֮�����������ȥ��С�����õ�һ���µ�������
������һ������ 1000����Ȼ���������µ����������ظ��������裬ֱ��������
����ֵ���ٷ����仯��
���磬�����û������������Ϊ 1001����ô�������γɵ������Ϊ 1100����
С��Ϊ 11������µ�������Ϊ 1089������ 1089�������γɵ������Ϊ 9810����
С��Ϊ 189������µ�������Ϊ 9621��9621 �������Ϊ 9621����С��Ϊ 1269��
���Ϊ 8352,��8352 �������Ϊ 8532����С��Ϊ 2358�����Ϊ 6174��6174 ����
����Ϊ 7641����С��Ϊ 1467�������Ϊ 6174����˳�������� ��ע�� ���Կα���
���µ� 22 �⣩
�������룺
1001
���������
6174
*/

#include <stdio.h>
//{4,3,2,1} -> 4321 ������
int power10(int position)
{
	int val[4]={1000,100,10,1};
	return val[position];
}
//{4,3,2,1} -> 4321
int digstoval(int * digits)
{
	int i;
	int sum=0;
	for(i=0; i<4; i++)
		sum += digits[i] * power10(i);
	return sum;
}
//4321 -> {4,3,2,1}
void valtodigs(int val, int * digits)
{
	int i;
	for(i=3; i>=0; i--)
	{
		digits[i] = val % 10;
		val /= 10;
	}
}
//ð�ݷ�����������
void sort(int * a)
{
	int n = 4;
	{
		int i,j,temp;
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]>a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp; 
				} 
			} 
		} 
	}
}
//��ָ�뽻������������ֵ
void exchange(int * val1, int * val2)
{
	int temp;
	temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}
//��ת����sort��ϣ����н�������
void reverse(int * digits)
{
	exchange(&digits[1],&digits[2]);
	exchange(&digits[0],&digits[3]);
}
//��������һ������������һ������
int diff(int val)
{
	//�� 4321 ת���� {4,3,2,1} ������������
	int digits[4];
	valtodigs(val, digits);

	int max, min;
	sort(digits);
	min = digstoval(digits);
	reverse(digits);
	max = digstoval(digits);
	return max - min;
}

int main()
{
	int original;
	scanf("%d", &original);
	//�������

	int last = original, current;
	while(1)
	{
		current = diff(last);
		if(current==last)
		{
			printf("%d", current);
			return 0;
		}
		last = current;
	}
	return 0;
}
