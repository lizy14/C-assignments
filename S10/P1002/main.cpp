/*

�ڶ��⣺�����󽻣�25 �֣�
������������ list1 �� list2�����������е�Ԫ�ض���������˳�����У���û��
�ظ���Ԫ�ء���дһ������ Node* Intersect(Node* head1, Node* head2)������ head1
�� head2 �ֱ��� list1 �� list2 ��ͷָ�룬����һ�������� list ��ͷָ�룬 list �� list1
�� list2 �Ľ�������Ҳ������˳�����С�
��д main �������Ըú�������ȷ�ԡ�������� 4 �У���һ���� list1 ��Ԫ��
�������ڶ����� list1 �е�Ԫ�أ��������� list2 ��Ԫ�ظ������� 4 ���� list2 �е�
Ԫ�أ���������� list �е�Ԫ�ء�
�������룺
6
1 2 3 4 5 6
5
2 4 6 8 10
���������
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
			//�����Ԫ��x
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
	
	//���洴�� list1
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

	


	//���洴�� list2
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