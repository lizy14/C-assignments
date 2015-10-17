/*
第三题： 最大乘积问题（25 分） 
假设有一个长度为 N 的数字串（长度不超过 10），要求将 K 个乘号（“ *”）
插入到这个数字串中，从而把它分成 K+1 个部分。请找出一种分法，使得这 K+1
个部分的乘积能够最大。例如，假设有一个数字串 312，当 N=3,K=1 时，会有两
种分法，即 3*12=36 和 31*2=62，显然符合题目要求的结果是 31*2=62。
说明：
a) 乘号不能加在数字串的最前面或最末尾
b) 也不应有两个或两个以上的乘号相邻
c) 6<=N<=10， 1<=K<=6。
程序的输入共有两行，第一行是两个整数 N 和 K，第二行是一个长度为 N 的
数字串。 程序的输出只有一行，即所求得大的最大乘积。不用考虑数据溢出，最
大乘积的值在整型 int 的取值范围之内。
样例输入：
3 1
312
样例输出：
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
int bSign[MAX_NUM] = {0};     //记录原字符串中下标为 i, i+1 的字符中间是否插入乘号
int cntSign;                  //乘号计数
char str[MAX_NUM] = {0};      //存储输入字串




int main()
{
#ifdef DEBUGING
	while(233)
	{
#endif
		scanf("%d %d %s", &N, &k, str);
		//主要代码开始
 		iMax = 0;
 		TrySign(0);
 		printf("%d\n",iMax);
		//主要代码结束
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


//根据str和bSign求乘积的值
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


//供调试所用，按可读形式输出表达式
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

//在str下标pos和pos+1之间插入chr，允许pos==-1
void InsertChar(char* str, int pos, char chr)
{
	int len=strlen(str);
	int i;
	for(i=len; i>pos; i--)
		str[i+1]=str[i];
	str[pos+1]=chr;
}