/*
�����⣺ ���˻����⣨25 �֣� 
������һ������Ϊ N �����ִ������Ȳ����� 10����Ҫ�� K ���˺ţ��� *����
���뵽������ִ��У��Ӷ������ֳ� K+1 �����֡����ҳ�һ�ַַ���ʹ���� K+1
�����ֵĳ˻��ܹ�������磬������һ�����ִ� 312���� N=3,K=1 ʱ��������
�ַַ����� 3*12=36 �� 31*2=62����Ȼ������ĿҪ��Ľ���� 31*2=62��
˵����
a) �˺Ų��ܼ������ִ�����ǰ�����ĩβ
b) Ҳ��Ӧ���������������ϵĳ˺�����
c) 6<=N<=10�� 1<=K<=6��
��������빲�����У���һ������������ N �� K���ڶ�����һ������Ϊ N ��
���ִ��� ��������ֻ��һ�У�������ô�����˻������ÿ��������������
��˻���ֵ������ int ��ȡֵ��Χ֮�ڡ�
�������룺
3 1
312
���������
62
*/

//#define DEBUGING

#include <string.h>
#include <stdio.h>

#define chartoint(x) ((x)-'0')

#define MAX_NUM 20

void TrySign(int iPosBegin);
void GetSolution(void);
int Multiply(void);
void InsertChar(char* str, int pos, char chr);
void PrintExpression(void);

int k, N, iMax;
int bSign[MAX_NUM] = {0};     //��¼ԭ�ַ������±�Ϊ i, i+1 ���ַ��м��Ƿ����˺�
int cntSign;                  //�˺ż���
char str[MAX_NUM] = {0};      //�洢�����ִ�




int main()
{
#ifdef DEBUGING
	while(233)
	{
#endif
		scanf("%d %d %s", &N, &k, str);
		//��Ҫ���뿪ʼ
 		iMax = 0;
 		TrySign(0);
 		printf("%d\n",iMax);
		//��Ҫ�������
#ifdef DEBUGING
	}
#endif
	return 0;
} 

void TrySign(int iPosBegin)
{
	int i;
	for(i=0; i<=1; i++)
	{
		if(i == 1)
		{
			if(cntSign >= k)continue;
			cntSign ++;
			bSign[iPosBegin] = 1;
		}
		
		if(cntSign == k)
			GetSolution();
		else if (iPosBegin < N-2)
			TrySign(iPosBegin+1);
		//trace back
		if(i == 1)
		{
			cntSign --;
			bSign[iPosBegin] = 0;
		}
		
	}

}




void GetSolution(void)
{
	int iTemp;
	iTemp = Multiply();
	if(iTemp>iMax)
		iMax = iTemp;
#ifdef DEBUGING
	PrintExpression();
	printf("=%d\n", iTemp);
#endif
}


//����str��bSign��˻���ֵ
int Multiply(void)
{
	int i;
	int iProduct = 1;
	int iCurrent = 0;
	for(i=0; i<N; i++)
	{
		{
			iCurrent *= 10;
			iCurrent += chartoint(str[i]);
		}
		if(bSign[i] || str[i+1] == '\0')
		{
			iProduct *= iCurrent;
			iCurrent = 0;
		}
	}
	return iProduct;
}


//���������ã����ɶ���ʽ������ʽ
void PrintExpression(void)
{
	char buffer[MAX_NUM *2];
	strcpy(buffer, str);
	int i;
	for(i=N; i>=0; i--)
		if(bSign[i])
			InsertChar(buffer, i,'*');
	printf(buffer);
}

//��str�±�pos��pos+1֮�����chr������pos==-1
void InsertChar(char* str, int pos, char chr)
{
	int len=strlen(str);
	int i;
	for(i=len; i>pos; i--)
		str[i+1]=str[i];
	str[pos+1]=chr;
}