/*
第三题： 学生信息（25 分） 
编写一个程序， 采用链表对学生信息进行管理。 程序第一行输入学生个数 M，
接下来每一行输入一条学生信息， 每一行输入信息顺序为： 学号、姓名、性别和
成绩； 然后输入一个整数 N，表示 N 条删除指令，指令格式为“ del 序号”，例
如：“ del 1”表示删除成绩为第 1 名的学生信息。
输出时， 按照学生成绩从高到低输出剩余学生的信息，每个学生信息为一行，
输出信息顺序为： 学号、姓名、性别和成绩， 若学生成绩相同， 输出时按照学号
升序排序输出。
注意： 若学生成绩一样则他们的排名相同，删除时同时删除。 例如： 如果有
3 个学生 A B C， 成绩分别为： 80 90 90，则 B C 名次都为 1， A 名次为 3， 执行
指令“ del 1” 时，把 B C 的信息都删除。

样例输入：
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
样例输出：
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
				head = p->next, flag = 0; // 删除的是首结点
			else
				q->next = p->next, flag = 1; // 删除的是中间结点
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
int list_length (node *head) // 链表长度
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