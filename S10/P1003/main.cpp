


/*
�����⣺һԪϡ�����ʽ�ӷ�����25 �֣� 

��дһ����һԪϡ�����ʽ�ӷ���������������һԪϡ�����ʽ��Ȼ�������
���мӷ��������ھ���ʵ���ϣ�Ҫ���������������ʽ���洢һ������ʽ��ÿ��
���������������Ա������ϵ����ָ������Ϊ�����������磬���ڶ���ʽ

˵����
a)  ÿһ�������㶼�Ǹ�����Ҫ��̬�����ģ�
b)  Ӧ���öຯ������ʽ��ʵ�֣����ٰ������µĺ��������������ӷ���
���ʹ�ӡ����ȣ�
c)  ����ʽ��ϵ�������ɸ�����ָ���϶��ǷǸ������Ұ��յ���˳�����С�
�����ʽ���� 1 ����һ������ M����ʾ��һ������ʽ���������������� M
�У�ÿ������������ ci �� ei��ci ��ʾ�� i ���ϵ����ei ��ʾ����ָ������������
һ����һ������ N����ʾ�ڶ�������ʽ���������ٽ������� N �У�ÿ��Ҳ������
��������ʾ��Ӧ���ϵ����ָ����
�����ʽ�������������ʽ��ӵĽ������һ����һ������ K����ʾ������
�ɵĶ���ʽ���ж������������ K �У�ÿһ����������������ʾ��Ӧ���ϵ��
��ָ���� ��ע�����ҲҪ��ָ��������˳�����С� ��
�������룺
4
75 0
30 1
95 8
50 9
3
80 1
25 7
-90 8
���������
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
node *addition(node* head1, node* head2, int *n)//nΪ�͵�����
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
				//�����Ԫ��: p1 + p2
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
				//�����Ԫ�أ� p2
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
				//�����Ԫ�أ�p1
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
			//�����Ԫ�أ� p1
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
			//�����Ԫ�أ�p2
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
	//���洴�� list1
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

	//���洴�� list2
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