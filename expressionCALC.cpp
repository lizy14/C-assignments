/*
表达式计算器
2014年12月
*/

/*测试用例及其正确结果
23+56/(102-100)*((36-24)/(8-6))
191

1+sin(30)
0.012

sin(5+2^(1+1)+log(2*(3+1)))
-0.46028129421884

abs(-5.4432)
5.4432

sqrt(-5)
ERROR

2^1000
1.0715086071863 * 10 ^ 301

100!
9.3326215443944 * 10 ^ 157
*/

/*
代码说明
main函数处理用户设置、输入、输出；
simplify主要实现去括号、数学函数求值算法；
simplify_innermost处理不含括号的最内层表达式。
程序内部以“@5”表示“(-5)”。
*/


//将下面一行注释掉就不输出中间结果了。。。。
#define DEBUGING   

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>



#define for_(i,x,y)    for(i=x; i<=y; i++)   //遍历整数 x to y
#define forarray(i,n)  for(i=0; i<n; i++)    //遍历数组下标，数组长度 n 


#define PI 3.1415926
#define E  2.71828
#define EPSILON 1E-15  //浮点数误差容错
#define MID_STRING_LENGTH 10000 
#define MAX_STRING_LENGTH 65536//允许最大字符串长度


//全局设置
int setting = 0;
int outputDigits = 3;

//角度弧度互化
#define ANGLE_TO_RADIAN PI/180
#define ANGLE  0
#define RADIAN 1
int AngleMode = RADIAN;
#define AngleSwitch (AngleMode == RADIAN? 1 : ANGLE_TO_RADIAN)//转化所乘的因数

//数学函数求值部分
#define cos_(x)  cos(AngleSwitch*x)
#define sin_(x)  sin(AngleSwitch*x)
#define tg_(x)   tan(AngleSwitch*x)
#define ctg_(x)  (1/tan(AngleSwitch*x))
#define abs_(x)  (x>=0? x : -x)
#define sign_(x) (x>0 ? 1 : (x==0 ? 0 : -1))
#define sqrt_(x) sqrt(x)
#define ln_(x)   log(x)
#define sinh_(x) sinh(x)
#define cosh_(x) cosh(x)
#define tanh_(x) tanh(x)
#define coth_(x) (1/tanh(x))

#define COS_  0
#define SIN_  1
#define TG_   2
#define CTG_  3
#define ABS_  4
#define SIGN_ 5
#define SQRT_ 6
#define LN_   7
#define SINH_ 8
#define COSH_ 9
#define TANH_ 10
#define COTH_ 11

//返回函数值, double
double Functions(int name, double x)
{
	switch(name)
	{
	case COS_:
		return cos_(x);
	case SIN_:
		return sin_(x);
	case TG_:
		return tg_(x);
	case CTG_:
		return ctg_(x);
	case ABS_:
		return abs_(x);
	case SIGN_:
		return sign_(x);
	case SQRT_:
		return sqrt_(x);
	case LN_:
		return ln_(x);
	case SINH_:
		return sinh_(x);
	case COSH_:
		return cosh_(x);
	case TANH_:
		return tanh_(x);
	case COTH_:
		return coth_(x);
	default:
		return -1;
	}
}
#define IsInt(x) fabs((floor(x) - x))<EPSILON
//判断定义域。在定义域内 则返回真，否则输出错误信息并返回0。
int InDomain(int name, double x)
{
	int p;
	switch(name)
	{
	case COS_:
		return 1;
	case SIN_:
		return 1;
	case TG_:
		p=(IsInt((x-PI/2)/PI));
		if(!p) puts("tg 定义域非法");
		return (p);
	case CTG_:
		p=(IsInt(x/PI));
		if(!p) puts("ctg 定义域非法");
		return (p);
	case ABS_:
		return 1;
	case SIGN_:
		return 1;
	case SQRT_:
		p=(x>=0);
		if(!p) puts("sqrt 定义域非法");
		return (p);
	case LN_:
		p=(x>0);
		if(!p) puts("ln 定义域非法");
		return (p);
	case SINH_:
		return 1;
	case COSH_:
		return 1;
	case TANH_:
		return 1;
	case COTH_:
		p=(x!=0);
		if(!p) puts("ln 定义域非法");
		return (p);
	default:
		return -1;
	}
}
char functionnames[][5]={"cos","sin","tg","ctg","abs","sign","sqrt","ln","sinh","cosh","tanh","coth"};
#define nfunctions 12
#define lenfunctionname(x) strlen(functionnames[x])

char ops[] = {'(', ')', '+', '-', '*', '/', '^', '!'};
#define nops 8 

char digits[]={'0','1','2','3','4','5','6','7','8','9','.','@'};
#define ndigits 12


//错误代码
#define ERROR -1
#define NOT_FOUND -1

//参数传递
#define FULL_LENGTH -1

//函数声明


int Simplify(char* expression);
int SimplifyInnermost(char*buffer, char*innermost_expression);
void MultiplyBigInt(char* s1, char* s2, char* result);
void Plus(char* s1, char* s2, char* result);
int Division(char* s1, char* s2, char* result);
void Power(char* s1, char* s2, char* result);

int InnermostParentheses(char* expression);
int MatchingParentheses(char* expression, int left);
int UnexpectRightParentheses(char* expression);
#define ParenthesesMatch(x) (CountCharInString(x,'(', FULL_LENGTH) == CountCharInString(x,')',FULL_LENGTH))

void HighlightCharInString(char* str, int chr);
void OutputResult(char* expression, int outputDigits);


//字符串处理函数
void strcpyEx(char* des, char* src, int left, int right);
int FindCharInString(char* str, char chr);
int CountCharInString(char* str, char chr, int length);
void InsertChar(char* str, int pos, char chr);
void RemoveChar(char* str, int chr);
void StringReplace(char* src, char* des, int start, int end);

int FindOp(char* expression);
int IsOp(char chr);
int FindFunctionName(char* expression, int end);
#define chartoint(x) (x - '0')
#define inttochar(x) (x + '0')

#define max(x,y) (x>=y? x: y)
#define min(x,y) (x>=y? y: x)

void StartPrompt()
{
	puts("欢迎使用表达式计算器。\n");
}
void SettingPrompt()
{
	puts("  输入 r 设置为弧度制，输入 a 设置为角度制，");
	puts("  输入一个 0~15 的整数设置输出的小数位数。");
	puts("  输入 exit 退出设置。");
}
void InputPrompt()
{
	puts("请输入一个表达式，回车结束。");
	puts("  输入 exit 退出程序。");
	puts("  输入 setting 进入设置。");
	printf("当前设定为：");
	printf((AngleMode==ANGLE? "角度制": "弧度制"));
	printf("，输出 %d 位小数。\n", outputDigits);
}


int main()
{
	StartPrompt();
	InputPrompt();
	while (233)
	{
		putchar('\n');
		char expression[MAX_STRING_LENGTH];
		//输入 
		{
			char buffer[MAX_STRING_LENGTH];	
			printf((setting? "setting>>": ">>"));
			gets(buffer);
			
			
			if(setting)
			{
				if(!strcmp(buffer, "exit"))
				{
					setting  = 0;
					puts("您已退出设置。\n");
					InputPrompt();
					continue;
				}
				switch(buffer[0])
				{
				case 'r':
					AngleMode = RADIAN;
					puts("已设置为 弧度制。");
					continue;
				case 'a':
					AngleMode = ANGLE;
					puts("已设置为 角度制。");
					continue;
				}
				int n;
				if(sscanf(buffer, "%d", &n))
					if(n>=0 && n <= 15)
					{
						outputDigits=n;
						printf("已设置为 输出小数点后 %d 位。\n", n);
						continue;
					}
	
				puts("设置格式不正确");
				continue;

			}

			if(!strcmp(buffer, "exit")) return 0;
			if(!strcmp(buffer, "setting"))
			{
				setting = 1;
				puts("您已进入设置。");
				SettingPrompt();
				continue;
			}
			int retUnexpectRightParentheses = UnexpectRightParentheses(buffer);
			if(retUnexpectRightParentheses != NOT_FOUND)
			{
				printf("输入不合法：发现无法匹配的 ')'\n", retUnexpectRightParentheses);
				HighlightCharInString(buffer, retUnexpectRightParentheses);
				putchar('\n');
				continue;
			}
			if(!ParenthesesMatch(buffer))
			{
				puts("输入不合法：丢失 ')'");
				continue;
			}
			strcpy(expression, buffer);
		}
		//输入结束

		
		//主要代码开始
		
		if(Simplify(expression) == 0)
		{
			//输出计算结果
			OutputResult(expression,outputDigits);
			puts(expression);
			FILE *file=fopen("output.txt","a");
			if(file==NULL)
				puts("无法打开 output.txt 进行写入。");
			else
			{
				fputs(expression, file);
				fputs("\n", file);
				puts("计算结果已写入 output.txt。");
				fclose(file);
			}
		}
		else
		{
			printf("出现错误，计算已中止。结果为： %s\n", expression);
		}
		//主要代码结束 

AskForAnotherInput:
		
		;
	}
	return 0;
} 


//主要函数，在expression上直接修改，正常则返回0，否则输出错误信息并返回ERROR
//本函数主要处理去括号
int Simplify(char* expression)
{
	char last_expression[MAX_STRING_LENGTH]; last_expression[0]=0;
	while(FindOp(expression))
	{
		//查找最右的'('和对应的')'，取出其中部分innermost_expression
		int leftParentheses  = InnermostParentheses(expression);
		int rightParentheses = MatchingParentheses(expression, leftParentheses);
		if(leftParentheses  == NOT_FOUND) leftParentheses=-1;//如果考虑NOT_FOUND就是-1，这句确实没什么用。。
		if(rightParentheses == NOT_FOUND) rightParentheses=strlen(expression);
		//紧跟括号的减号不算运算符
		
		char innermost_expression[MAX_STRING_LENGTH];
		strcpyEx(innermost_expression, expression, leftParentheses+1, rightParentheses-1);
		
		//判断里面有没有运算符
		if(FindOp(innermost_expression))
		{	//里面有运算符：算出数值
			char buffer[MAX_STRING_LENGTH];	
			if(SimplifyInnermost(buffer, innermost_expression) == 0)
				StringReplace(buffer,expression,leftParentheses+1, rightParentheses-1);
			else
				return ERROR;
		}
		else
		{	//里面已经没有运算符了
			//向前查找函数名
			int name = FindFunctionName(expression, leftParentheses-1);
			if(name==NOT_FOUND)
			{	//未找到函数名
				//替换“(-”为“(@”
				if(innermost_expression[0]=='-')
					innermost_expression[0]='@';
				//删去括号
				if(leftParentheses != -1)
				{
					RemoveChar(expression, rightParentheses);
					RemoveChar(expression, leftParentheses);
				}
			}
			else
			{	//找到函数名
				double x; 
				if(innermost_expression[0]=='@')
					innermost_expression[0]='-';
				sscanf(innermost_expression, "%lf", &x);
				if(!InDomain(name, x))return ERROR;
				char buffer[MAX_STRING_LENGTH];
				sprintf(buffer, "(%.16lf)", Functions(name, x));//程序内部取函数值16位小数
				StringReplace(buffer, expression, leftParentheses-lenfunctionname(name), rightParentheses);
				
			}
		}

		//本轮循环结束
		if(!strcmp(last_expression, expression))//进入死循环
		{
			puts("未知错误，请检查输入是否合法");
			printf("得到结果为 %s", expression);
			return ERROR;
		}
		strcpy(last_expression, expression);
		#ifdef DEBUGING
			puts(expression);
		#endif
	}
	return 0;
}

//判断chr是否是运算符（即：是否不存在于数组digits[]中）
int IsOp(char chr)
{
	int i;
	forarray(i, ndigits)
		if(digits[i]==chr) return 0;
	return 1;
}

//将整数x转化为字符串存入buffer
void inttostring(char* Buffer, int x)
{
	int temp = x;
	int l = 0;
	while(233)
	{
		temp /= 10;
		l++;
		if(temp==0)break;		
	}

	temp = x;
	int i = 0;
	while(233)
	{
		Buffer[l-1-i] = inttochar(temp % 10);
		temp /= 10;
		i++;
		if(temp==0)break;	
	}
	Buffer[l] = 0;
}

//处理不含括号的innermost_expression，送给buffer，正常则返回0，否则输出错误信息并返回ERROR
int SimplifyInnermost(char* buffer, char*innermost_expression)
{
	strcpy(buffer, innermost_expression);
	char last_buffer[65535];
	last_buffer[0]=0;
	while(FindOp(buffer))
	{
		int op;
		int len=strlen(buffer);
		if(!FindOp(buffer+1))
			if(buffer[0]=='-')
			{
				buffer[0]='@';
				return 0;
			}

		//处理阶乘
		if(((op = FindCharInString(buffer, '!'))!=NOT_FOUND )
			|| ((op = FindCharInString(buffer, '！'))!=NOT_FOUND))
		{
			int i;
			for(i=op; i>0; i--)
				if(IsOp(buffer[i-1]))break;
			if(i==op){puts("输入不合法");return ERROR;}
			if(buffer[op+1]=='!'){puts("输入不合法，不支持 '!!' ");return ERROR;}
			if(buffer[i]=='@')
			{
				puts("无法对负数计算阶乘");
				return ERROR;
			}
			int max;
			{
				char temp[MID_STRING_LENGTH];
				strcpyEx(temp, buffer, i, op-1);
				if(sscanf(temp,"%d", &max) == 0)
				{
					puts("阶乘定义域非法");
					return ERROR;
				}
				if(FindCharInString(temp, '.') != NOT_FOUND)
				{
					puts("无法对小数计算阶乘");
					return ERROR;
				}
			}
			char buffer1[MAX_STRING_LENGTH]="1";
			int j;
			for_(j, 1, max)
			{
				char buffer2[MAX_STRING_LENGTH];
				inttostring(buffer2, j);
				MultiplyBigInt(buffer1, buffer2, buffer1);
			}
			StringReplace(buffer1,buffer,i, op);
			goto nextLoop;
		}
		
		//处理^
		if((op = FindCharInString(buffer, '^')) != NOT_FOUND)
		{
			int i;
			int j;
			for(i=op; i>0; i--)
				if(IsOp(buffer[i-1]))break;
			for(j=op; j<len-1; j++)
				if(IsOp(buffer[j+1]))break;
			if(i==op || j==op){puts("输入不合法");return ERROR;}
			//乘方定义域判定
			if(buffer[i]=='@');//底数是负数！
			{
				;
			}
			char m1[MID_STRING_LENGTH], m2[MID_STRING_LENGTH], buffer1[2*MID_STRING_LENGTH];
			strcpyEx(m1, buffer, i, op-1);
			if(m1[0]=='@') m1[0]='-';
			strcpyEx(m2, buffer, op+1, j);
			if(m2[0]=='@') m2[0]='-';
			Power(m1, m2, buffer1);
			OutputResult(buffer1,16);
			if(buffer1[0]=='-') buffer1[0]='@';
			StringReplace(buffer1, buffer, i, j);

			goto nextLoop;
		}
		
		//处理乘除
		
		int op1 = FindCharInString(buffer, '*');
		int op2 = FindCharInString(buffer, '/');
		if(op1 != NOT_FOUND || op2 != NOT_FOUND)
		{
			//同级运算找最左一个运算符
			if(op1 == NOT_FOUND)
				op = op2;
			else if(op2 == NOT_FOUND)
				op = op1;
			else
				op=min(op1, op2);
			
		//处理*
		if((buffer[op]=='*'))
		{
			int i;
			int j;
			for(i=op; i>0; i--)
				if(IsOp(buffer[i-1]))break;
			for(j=op; j<len-1; j++)
				if(IsOp(buffer[j+1]))break;
			if(i==op || j==op){puts("输入不合法");return ERROR;}
			char m1[MID_STRING_LENGTH], m2[MID_STRING_LENGTH], buffer1[2*MID_STRING_LENGTH];
			
			//看看有没有负号
			int sgn=1;
			if(buffer[i]!='@')

				strcpyEx(m1,buffer,i,op-1);
			else
			{
				sgn *= -1;
				strcpyEx(m1,buffer,i+1,op-1);
			}
			if(buffer[op+1]!='@')
				strcpyEx(m2,buffer,op+1,j);
			else
			{	
				sgn *= -1;
				strcpyEx(m2,buffer,op+2,j);
			}

			//从m1,m2中取出小数点并记录小数位数
			int dm1=0, dm2=0;//小数位数
			int retFindCharInString;
			if((retFindCharInString = FindCharInString(m1,'.')) != NOT_FOUND)
			{
				dm1 = strlen(m1) - retFindCharInString - 1;
				RemoveChar(m1, retFindCharInString);
			}

			if((retFindCharInString = FindCharInString(m2,'.')) != NOT_FOUND)
			{
				dm2 = strlen(m2) - retFindCharInString - 1;
				RemoveChar(m2, retFindCharInString);
			}

			//调用大整数乘法计算
			if(sgn == -1)
			{
				MultiplyBigInt(m1,m2,buffer1+1);
				buffer1[0]='@';
			}
			else
				MultiplyBigInt(m1,m2,buffer1);

			//把小数点放回buffer1
			if(dm1+dm2)
				len = strlen(buffer1);
				InsertChar(buffer1, len - dm1 - dm2 - 1, '.');
			StringReplace(buffer1, buffer, i, j);

			goto nextLoop;
		}


		//处理'/'
		if((buffer[op]=='/'))
		{
			int i;
			int j;
			for(i=op; i>0; i--)
				if(IsOp(buffer[i-1]))break;
			for(j=op; j<len-1; j++)
				if(IsOp(buffer[j+1]))break;
			if(i==op || j==op){puts("输入不合法");return ERROR;}
			char m1[MID_STRING_LENGTH], m2[MID_STRING_LENGTH], buffer1[MID_STRING_LENGTH];
			strcpyEx(m1, buffer, i, op-1);
			if(m1[0]=='@') m1[0]='-';
			strcpyEx(m2, buffer, op+1, j);
			if(m2[0]=='@') m2[0]='-';
			if(Division(m1, m2, buffer1)==ERROR) return ERROR;
			OutputResult(buffer1,16);
			if(buffer1[0]=='-') buffer1[0]='@';
			StringReplace(buffer1, buffer, i, j);

			goto nextLoop;
		}
		}



		//处理加减
		op1 = FindCharInString(buffer, '+');
		op2 = FindCharInString(buffer, '-');
		if(op1 != NOT_FOUND || op2 != NOT_FOUND)


		{
			if(op1 == NOT_FOUND)
				op = op2;
			else if(op2 == NOT_FOUND)
				op = op1;
			else
				op=min(op1, op2);
		//处理+
		if(buffer[op]=='+')
		{
			int i;
			int j;
			for(i=op; i>0; i--)
				if(IsOp(buffer[i-1]))break;
			for(j=op; j<len-1; j++)
				if(IsOp(buffer[j+1]))break;
			if(i==op || j==op){puts("输入不合法");return ERROR;}
			char m1[MID_STRING_LENGTH], m2[MID_STRING_LENGTH], buffer1[MID_STRING_LENGTH];
			strcpyEx(m1, buffer, i, op-1);
			if(m1[0]=='@') m1[0]='-';
			strcpyEx(m2, buffer, op+1, j);
			if(m2[0]=='@') m2[0]='-';
			Plus(m1, m2, buffer1);
			OutputResult(buffer1,16);
			if(buffer1[0]=='-') buffer1[0]='@';
			StringReplace(buffer1, buffer, i, j);

			goto nextLoop;
		}


		//处理-
		if(buffer[op]=='-')
		{
			int i;
			int j;
			for(i=op; i>0; i--)
				if(IsOp(buffer[i-1]))break;
			for(j=op; j<len-1; j++)
				if(IsOp(buffer[j+1]))break;
			if(i==op || j==op){puts("输入不合法");return ERROR;}
			char m1[MID_STRING_LENGTH], m2[MID_STRING_LENGTH], buffer1[MID_STRING_LENGTH];
			strcpyEx(m1, buffer, i, op-1);
			if(m1[0]=='@') m1[0]='-';
			strcpyEx(m2, buffer, op+1, j);
			if(m2[0]=='@')
				RemoveChar(m2, 0);
			else
				InsertChar(m2,-1,'-');
			Plus(m1, m2, buffer1);
			OutputResult(buffer1,16);
			if(buffer1[0]=='-') buffer1[0]='@';
			StringReplace(buffer1, buffer, i, j);

			goto nextLoop;
		}
		}

		
nextLoop:
		;
		#ifdef DEBUGING
			printf("最内层 (%s) %s\n",innermost_expression, buffer);
		#endif
		if(!strcmp(buffer, last_buffer))
		{
			puts("未知错误，请检查输入是否合法");
			return ERROR;
		}
		strcpy(last_buffer,buffer);
	}
	return 0;
}


//处理正整数s1和s2相乘，支持大整数，结果送入result
void MultiplyBigInt(char* s1, char* s2, char* result)
{
	int i, j;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int val[20 + 2*MID_STRING_LENGTH] = {0};
	int x1[10 +MID_STRING_LENGTH]={0};
	int x2[10 +MID_STRING_LENGTH]={0};

	//"2048" --> {8,4,0,2}
	for_(i, 0, len1 - 1)
		x1[i] = chartoint(s1[len1 -1 - i]);
	for_(i, 0, len2 - 1)
		x2[i] = chartoint(s2[len2 -1 - i]);




	for_(i, 0, len1 - 1)
	{
		for_(j, 0, len2 - 1)
		{
			val[i+j] += x1[i] * x2[j];
		}
	}


	//进位
	for_(i, 0 , 18 +MID_STRING_LENGTH)
	{
		val[i+1] += val[i] / 10;
		val [i] %= 10;
	}



	//数字串转字符串

	int h;//最高位
	for(i = 19 +MID_STRING_LENGTH; i>=0; i--)
	{
		if(val[i] != 0)
		{
			h=i;
			break;
		}
	}
	j = 0;
	for(i = h; i>=0; i--)
	{
		result[j] = inttochar(val[i]);
		j++;		
	}
	result[j] = 0;
	return;
}


//处理乘方，在指数是正整数、底数是整数的情况下支持大整数，其他情况调用库函数pow()，double
void Power(char* s1, char* s2, char* result)
{
	if(FindCharInString(s1,'.')==NOT_FOUND 
		&& FindCharInString(s2,'.')==NOT_FOUND
		&& s2[0]!='-')
		//指数是正整数，底数是整数，调用MultiplyBigInt实现支持大整数
	{
		char ans[MAX_STRING_LENGTH]="1";
		int times = atoi(s2);
		int i;
		int sgn=1;
		if( (s1[0]=='-') && (times%2 ==1) ) 
		{
			sgn = -1;
			RemoveChar(s1, 0);
		}
		if( (s1[0]=='-') && (times%2 ==0) )
			RemoveChar(s1, 0);
		for_(i, 1, times)
			MultiplyBigInt(ans, s1, ans);
		if(sgn==-1)
			InsertChar(ans, -1, '@');
		strcpy(result, ans);
	}
	else
	{
		long double x,y;
		sscanf(s1, "%lf", &x);
		sscanf(s2, "%lf", &y);
		sprintf(result, "%.16lf", pow(x,y));
	}
}

//处理加法，目前使用 long long int 和 double，不支持大数；不支持'@'
void Plus(char* s1, char* s2, char* result)
{
	if(FindCharInString(s1,'.')==NOT_FOUND && FindCharInString(s2,'.')==NOT_FOUND)
	//两个都是整数
	{
		//大整数加法未实现，本部分重写
		int k = 0.1;
		long long int x, y;
		sscanf(s1, "%d", &x);
		sscanf(s2, "%d", &y);
		sprintf(result, "%d", x+y);
	}
// 	else if(FindCharInString(s1,'.')==NOT_FOUND)
// 	{
// 		long double y; long long int x;
// 		sscanf(s1, "%lld", &x);
// 		sscanf(s2, "%lf", &y);
// 		sprintf(result, "%.16lf", x+y);
// 	}
// 	else if(FindCharInString(s2,'.')==NOT_FOUND)
// 	{
// 		long double x; long long int y;
// 		sscanf(s1, "%lf", &x);
// 		sscanf(s2, "%lld", &y);
// 		sprintf(result, "%.16lf", x+y);
// 	}
	else
	{
		long double x,y;
		sscanf(s1, "%lf", &x);
		sscanf(s2, "%lf", &y);
		sprintf(result, "%.16lf", x+y);
	}

}

//处理除法，目前使用double，不支持大数，不支持'@'
//出错则打印出错信息并返回ERROR
int Division(char* s1, char* s2, char* result)
{
	if(
		(s2[0]=='0' && s2[1]!='.')||
		(s2[0]=='-' && s2[1]=='0' && s2[2]!='.')
		)
	{
		puts("除数为零");
		return ERROR;
	}
	long double x,y;
	sscanf(s1, "%lf", &x);
	sscanf(s2, "%lf", &y);
	sprintf(result, "%.16lf", x/y);
}

//将des从下标start到end的部分（均含）替换为src
void StringReplace(char* src, char* des, int start, int end)
{
	int lensrc = strlen(src);
	int lendes = strlen(des);
	int lenfield = end - start + 1;
	if(lensrc == lenfield)
	{
		int i;
		forarray(i, lensrc)
			des[start + i] = src[i];
	}
	else if(lensrc > lenfield)
	{
		int i;
		des[lendes-lenfield+lensrc]=0;
		for(i=lendes-lenfield+lensrc-1; i>=start+lensrc-lenfield; i-- )
			des[i]=des[i+lenfield-lensrc];
		
		forarray(i, lensrc)
			des[start + i] = src[i];
	}
	else if(lensrc < lenfield)
	{
		int i;
		forarray(i, lensrc)
			des[start + i] = src[i];
		for_(i, start+lensrc, lendes-lenfield+lensrc-1)
			des[i]=des[i+lenfield-lensrc];
		des[i]=0;
	}
}

//用作递归终止条件
//找到括号或运算符或函数名 则返回真。
int FindOp(char* expression)
{
	int j;
	int sum=0;
	int len = strlen(expression);
	forarray(j, ndigits)
		sum += CountCharInString(expression, digits[j],len);
	return (sum < len);
}


//寻找最内层的'('，返回其下标，未找到返回 NOT_FOUND
int InnermostParentheses(char* expression)
{
	int ret = NOT_FOUND;
	int i;
	int len = strlen(expression);
	forarray(i, len)
		if(expression[i]=='(')ret=i;
	return ret;
}

//根据'('的下标寻找相对应的')'，返回其下标，未找到返回 NOT_FOUND
int MatchingParentheses(char* expression, int left)
{
	int nLeft = 0, nRight = 0;
	int len = strlen(expression);
	for(int i = left + 1; i < len; i++)
	{
		if(expression[i]=='(')
			nLeft++;
		if(expression[i]==')')
		{
			nRight++;
			if(nRight == nLeft+1)
				return i;
		}
	}
	return NOT_FOUND;
}

//查找不合适的')'，不存在则返回NOT_FOUND，不匹配则返回下标
int UnexpectRightParentheses(char* expression)
{
	int len = strlen(expression);
	int i;
	forarray(i, len)
		if(CountCharInString(expression, '(',i+1) < CountCharInString(expression, ')',i+1)) return i;
	return NOT_FOUND;
}

//字符串中特定字符计数，len传入待检字符串长度
int CountCharInString(char* str, char chr, int len)
{
	if(len == FULL_LENGTH)len = strlen(str);
	int i;
	int count= 0;
	forarray(i, len)
		if(str[i] == chr) count ++;
	return count;
}

//寻找str中第一个字符chr的位置，返回下标，未找到返回NOT_FOUND
int FindCharInString(char* str, char chr)
{
	int len = strlen(str);
	int i;
	forarray(i, len)
		if(str[i] == chr) return i;
	return NOT_FOUND;
}

//传入下标，高亮输出
void HighlightCharInString(char* str, int chr)
{
	int len=strlen(str);
	int i;
	for(i=0; i<chr; i++)
		putchar(str[i]);
	printf("【%c】", str[chr]);
	for(i=chr+1; i<len; i++)
		putchar(str[i]);
}

//在expression中从下标end（含）往前查找函数名，返回函数名下标，未找到返回NOT_FOUND
int FindFunctionName(char* expression, int end)
{

	int i, j, b;
	forarray(i, nfunctions)
	{
		int len=lenfunctionname(i);
		b=1;
		forarray(j, len)
		{
			if(expression[end-len+1+j] != functionnames[i][j]) b=0;
		}
		if(b) return i;
	}
	return NOT_FOUND;
}

//按照给定精度（小数点后outputDigits位，或整数）将expression格式化。
//expression以-或@开始均接受。返回值不以@开始。
void OutputResult(char* expression, int outputDigits)
{
	int len=strlen(expression);
	if(expression[0]=='@')expression[0]='-';
	//寻找小数点	
	int i=-1;
	forarray(i, len)
		if(expression[i]=='.')break;
	if(i==-1) return;

	//检查小数点后是否全是零
	int posPoint = i;
	int allZero = 1;
	for_(i, posPoint + 1, len-1)
		if(expression[i] != '0')allZero = 0;
	
	if(allZero)
	{
		expression[posPoint]=0;
		return;
	}
	else
	{
		//四舍五入采用printf
		int k = 0.1;
		long double temp;
		
		if(outputDigits)
		{
			char stroutputDigits[3];
			inttostring(stroutputDigits, outputDigits);
			char format[7] = "%.*lf";
			StringReplace(stroutputDigits, format, 2,2);
			sscanf(expression, "%lf", &temp);
			sprintf(expression, format, temp);
		}
		else
		{
			sscanf(expression, "%lf", &temp);
			sprintf(expression, "%d", temp);
		}

		//expression[posPoint + outputDigits + 1] = 0;
	}
	

}

//将src下标left到right的部分复制到des
void strcpyEx(char* des, char* src, int left, int right)
{
	int i, j=0;
	for_(i, left, right)
		des[j++]=src[i];
	des[j]=0;
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

//将str中下标pos的字符去掉
void RemoveChar(char* str, int pos)
{
	int len=strlen(str);
	int i;
	for(i=pos; i<len; i++)
		str[i]=str[i+1];
}