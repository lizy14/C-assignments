/*
�����⣺ ѧ����Ϣ��25 �֣� 
��дһ������ ���������ѧ����Ϣ���й��� �����һ������ѧ������ M��
������ÿһ������һ��ѧ����Ϣ�� ÿһ��������Ϣ˳��Ϊ�� ѧ�š��������Ա��
�ɼ��� Ȼ������һ������ N����ʾ N ��ɾ��ָ�ָ���ʽΪ�� del ��š�����
�磺�� del 1����ʾɾ���ɼ�Ϊ�� 1 ����ѧ����Ϣ��
���ʱ�� ����ѧ���ɼ��Ӹߵ������ʣ��ѧ������Ϣ��ÿ��ѧ����ϢΪһ�У�
�����Ϣ˳��Ϊ�� ѧ�š��������Ա�ͳɼ��� ��ѧ���ɼ���ͬ�� ���ʱ����ѧ��
�������������
ע�⣺ ��ѧ���ɼ�һ�������ǵ�������ͬ��ɾ��ʱͬʱɾ���� ���磺 �����
3 ��ѧ�� A B C�� �ɼ��ֱ�Ϊ�� 80 90 90���� B C ���ζ�Ϊ 1�� A ����Ϊ 3�� ִ��
ָ� del 1�� ʱ���� B C ����Ϣ��ɾ����

�������룺
7
2012008001 alice male 87
2012008002 bob male 93
2012008007 luce female 78
2012008004 jone male 87
2012008005 lily female 95
2012008006 jack male 81
2012008003 jim female 78
2
del 3
del 5
���������
2012008005 lily female 95
2012008002 bob male 93
2012008003 jim female 78
2012008007 luce female 78
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node
{
	unsigned int ID;
	char name[20];
	char gender[20];
	int  score;
	int  rank;
	node *next;
};
node * delete_rank_from_list(node *head, int rank)
{

	node *p, *q; 
	if(head == NULL) return NULL;
	
	q = p = head; 
	
	while(233)
	{
		if(p == NULL) break;
		
		if(p->rank == rank)
		{
			int flag;
			if(p == head)
				head = p->next, flag = 0; // ɾ�������׽��
			else
				q->next = p->next, flag = 1; // ɾ�������м���
			free(p);
			if(flag)
				p=q->next;
			else
				p=head;
		}
		else
			q = p, p = p->next;
	}
	return head;
}
int list_length (node *head) // ������
{
	node *p = head;
	if (p == NULL) return 0;
	int n = 0;
	while(p) {
		n++;
		p = p->next;
	}
	return n;
}
void list_data_copy (node *Dst, node *Src)
{
	strcpy(Dst->name, Src->name);
	strcpy(Dst->gender, Src->gender);
	Dst->ID = Src->ID;
	Dst->score = Src->score;
}
void printlist(node *head)
{
	node *p = head;
	while(233)
	{
		if(p==NULL)break;
		printf("%u %s %s %d\n", p->ID, p->name, p->gender, p->score);
		p = p->next;
	}
	return;
}
node *list_sort (node *head)
{
	int i, j, n;
	node *p, temp;
	n = list_length (head); 
	if(head == NULL || head->next == NULL)
		return head;
	for(j = 1; j < n; j++) 
	{
		p = head;
		for(i = 0; i < n - j; i++) 
		{
			if(p->score < p->next->score) 
			{ 
				list_data_copy (&temp, p);
				list_data_copy (p, p->next);
				list_data_copy (p->next, &temp);
			}
			else if
				((p->score == p->next->score) &&
				 (p->ID > p->next->ID))
			{
				list_data_copy (&temp, p);
				list_data_copy (p, p->next);
				list_data_copy (p->next, &temp);
			}
			p = p->next;
		}
	}
	return head;
}
node *list_rank (node *head)
{
	node *p = head;
	int last_score = -1;
	int last_rank = 1;
	int last_total = 1;
	while(233)
	{
		if(p==NULL) break;

		if(last_score != p->score) 
			last_rank = last_total;

		p->rank = last_rank;
		last_score = p->score;
		last_total ++;

		p=p->next;
	}
	return head;
}
int main()
{
	
	node *p, *q, *head;
	int n, i;

	head = p = q = NULL;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		p=(node*)malloc(sizeof(node));
		scanf("%u %s %s %d", &p->ID, &p->name, &p->gender, &p->score);
		if(head == NULL)
			head = p, q = p;
		else
			q->next = p, q = p;
	}
	if(q!=NULL) q->next = NULL;
	//end of creating student list
		
	head=list_sort(head);
	head=list_rank(head);
	//end of ranking
	
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		char cmd_string[4];
		int cmd_rank;
		scanf("%s %d", cmd_string, &cmd_rank);
		if(!strcmp(cmd_string,"del"))
			head=delete_rank_from_list(head, cmd_rank);
	}
	
	printlist(head);
	return 0;	
}