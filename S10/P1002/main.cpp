/*

第二题：链表求交（25 分）
给定两个链表 list1 和 list2，两个链表中的元素都按递增的顺序排列，且没有
重复的元素。编写一个函数 Node* Intersect(Node* head1, Node* head2)，其中 head1
和 head2 分别是 list1 和 list2 的头指针，返回一个新链表 list 的头指针， list 是 list1
和 list2 的交集，且也按递增顺序排列。
编写 main 函数测试该函数的正确性。输入包括 4 行，第一行是 list1 的元素
个数，第二行是 list1 中的元素，第三行是 list2 的元素个数，第 4 行是 list2 中的
元素；输出新链表 list 中的元素。
样例输入：
6
1 2 3 4 5 6
5
2 4 6 8 10
样例输出：
2 4 6

*/


#define _CRT_SECURE_NO_WARNINGS

//#define DEBUG

#include <stdio.h>

#include <stdlib.h>

#define for_(i,x,y) for(i=x; i<=y; i++)

struct Node
{
	int x;
	Node *next;
};

Node *Intersect(Node *head1, Node *head2)
{
	
	if(head1 == NULL || head2 == NULL)return NULL;

	Node *p1 = head1, *p2 = head2, *p, *q, *head;
	p = q = head = NULL;
	
	while(233)
	{
		if(p1->x == p2->x)
		{
			//添加新元素x
			p = (Node*)malloc(sizeof(Node));
			p->x = p1->x;
			if(head == NULL)
				head = p, q = p;
			else
				q->next = p, q = p;
			p1 = p1->next, p2 = p2->next;
		}
		else if(p1->x > p2->x)
		{
			p2 = p2->next;
		}
		else
		{
			p1 = p1->next;
		}
		if(p1 == NULL || p2 == NULL)break;
	}
	if(q!=NULL)q->next = NULL;
	return head;
}

void print_list(Node *head)
{
	Node *p = head;
	while(233)
	{
		if(p == NULL)break;
		printf("%d ", p->x);
		p = p->next;
	}
	putchar('\n');
}
int main()
{
	int n;
	int i;
	int x;
	Node *p, *q, *head1, *head2;
	
	//下面创建 list1
	i = 0, p = q = head1 = NULL;
	scanf("%d", &n);
	while(233)
	{
		if(i++ >= n) break;
		p = (Node*)malloc(sizeof(Node));
		scanf("%d", &x);
		p->x = x;
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
		p = (Node*)malloc(sizeof(Node));
		scanf("%d", &x);
		p->x = x;
		if(head2 == NULL)
			head2 = p, q = p;
		else
			q->next = p, q = p;
	}
	if(q != NULL)q->next = NULL;

	//end of input

#ifdef DEBUG
	print_list(head1);
	print_list(head2);
#endif

	print_list(Intersect(head1, head2));

	return 0;
} 