


/*
第三题：一元稀疏多项式加法器（25 分） 

编写一个“一元稀疏多项式加法器”，输入两个一元稀疏多项式，然后对它们
进行加法操作。在具体实现上，要求用线性链表的形式来存储一个多项式，每个
链表结点包括两个成员变量，系数和指数（均为整数）。例如，对于多项式

说明：
a)  每一个链表结点都是根据需要动态创建的；
b)  应采用多函数的形式来实现，至少包含如下的函数，创建链表、加法函
数和打印链表等；
c)  多项式的系数可正可负，但指数肯定是非负数，且按照递增顺序排列。
输入格式：第 1 行是一个整数 M，表示第一个多项式的项数。接下来有 M
行，每行有两个整数 ci 和 ei，ci 表示第 i 项的系数，ei 表示它的指数。接下来的
一行是一个整数 N，表示第二个多项式的项数，再接下来有 N 行，每行也是两个
整数，表示相应项的系数和指数。
输出格式：输出两个多项式相加的结果。第一行是一个整数 K，表示在新生
成的多项式中有多少项，接下来有 K 行，每一行是两个整数，表示相应项的系数
和指数。 （注：输出也要求按指数递增的顺序排列。 ）
样例输入：
4
75 0
30 1
95 8
50 9
3
80 1
25 7
-90 8
样例输出：
5
75 0
110 1
25 7
5 8
50 9
*/







#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
	//#define DEBUG
#define for_(i,x,y) for(i=x; i<=y; i++)
struct node
{
	int coefficient;
	int exponent;
	node *next;
};
void print_list(node *head)
{
	node *p = head;
	while(233)
	{
		if(p == NULL)break;
		printf("%d %d\n", p->coefficient, p->exponent);
		p = p->next;
	}

}
node *addition(node* head1, node* head2, int *n)//n为和的项数
{
	*n = 0;
	
	node *p1 = head1, *p2 = head2, *p, *q, *head;
	p = q = head = NULL;
	while(233)
	{
		if(p1 != NULL && p2 != NULL)
		{
			if(p1->exponent == p2->exponent)
			{
				//添加新元素: p1 + p2
				if(p1->coefficient + p2->coefficient != 0)
				{
					*n = *n + 1;
					p = (node*)malloc(sizeof(node));
					p->exponent = p1->exponent;
					p->coefficient = p1->coefficient + p2->coefficient;
					if(head == NULL)
						head = p, q = p;
					else
						q->next = p, q = p;
				}

				p1 = p1->next, p2 = p2->next;
			}
			else if(p1->exponent > p2->exponent)
			{
				//添加新元素： p2
				*n = *n + 1;
				p = (node*)malloc(sizeof(node));
				p->exponent = p2->exponent;
				p->coefficient = p2->coefficient;
				if(head == NULL)
					head = p, q = p;
				else
					q->next = p, q = p;

				p2 = p2->next;
			}
			else if(p1->exponent < p2->exponent)
			{
				//添加新元素：p1
				*n = *n + 1;
				p = (node*)malloc(sizeof(node));
				p->exponent = p1->exponent;
				p->coefficient = p1->coefficient;
				if(head == NULL)
					head = p, q = p;
				else
					q->next = p, q = p;
				p1 = p1->next;
			}
		}
		else if(p1 == NULL && p2 == NULL)
			break;
		else if(p1 != NULL && p2 == NULL)
		{
			//添加新元素： p1
			*n = *n + 1;
			p = (node*)malloc(sizeof(node));
			p->exponent = p1->exponent;
			p->coefficient = p1->coefficient;
			if(head == NULL)
				head = p, q = p;
			else
				q->next = p, q = p;
			p1 = p1->next;
		}
		else if(p1 == NULL && p2 != NULL)
		{
			//添加新元素：p2
			*n = *n + 1;
			p = (node*)malloc(sizeof(node));
			p->exponent = p2->exponent;
			p->coefficient = p2->coefficient;
			if(head == NULL)
				head = p, q = p;
			else
				q->next = p, q = p;
			p2 = p2->next;
		}

	}
	if(q!=NULL)q->next = NULL;
	return head;
}
int main()
{
	node *head1, *head2;
	int n;
	int i;
	int c, e;
	node *p, *q;
	//下面创建 list1
	i = 0, p = q = head1 = NULL;
	scanf("%d", &n);
	while(233)
	{
		if(i++ >= n) break;
		p = (node*)malloc(sizeof(node));
		scanf("%d %d", &c, &e);
		p->coefficient = c, p->exponent = e;
		if(head1 == NULL)
			head1 = p, q = p;
		else
			q->next = p, q = p;
	}
	if(q != NULL)q->next = NULL;

	//下面创建 list2
	i = 0, p = q = head2 = NULL;
	scanf("%d", &n);
	while(233)
	{
		if(i++ >= n) break;
		p = (node*)malloc(sizeof(node));
		scanf("%d %d", &c, &e);
		p->coefficient = c, p->exponent = e;
		if(head2 == NULL)
			head2 = p, q = p;
		else
			q->next = p, q = p;
	}
	if(q != NULL)q->next = NULL;
	//end of input
#ifdef DEBUG
	puts("list1:");
	print_list(head1);
	puts("list2:");
	print_list(head2);
	puts("list:");
#endif 
	node *ans = addition(head1, head2, &n);
	printf("%d\n",n);
	print_list(ans);
	return 0;
} 