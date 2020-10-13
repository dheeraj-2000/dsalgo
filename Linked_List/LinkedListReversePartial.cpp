#include<stdlib.h>
#include<stdio.h>

/*
This C code reverse n nodes of a linked list after skipping m nodes in the same linked list

for example if the linked list is given as 1->2->3->4->5->6->7->8

and n = 2, and m = 2

then output will be: 1->2->4->3->5->6->8->7

value of n and m is taken from console.

*/


struct node
{
	int value;
	struct node *next;
};
struct node * insert_node(struct node *s, int x)
{
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	p->value=x;
	p->next = s;
	s = p;
	return (s);
}
	
int count_nodes(struct node *s)
{
	if(s==NULL)
	return 0;
	struct node *q = s;
	int count=0;
	while(q!=NULL)
	{
		count+=1;
		q=q->next;
	}
	return count;
}


struct node *reverse_partial(struct node *s, int n, int m)
{
	if(s==NULL)
	return (s);
	struct node *p = s, *q = NULL;
	int x = m;
	while(p!=NULL && x>0)
	{
		q=p;
		p=p->next;
		x--;
	}
	int a[n]={0};
	int y=n;
	int i=0;
	q=p;
	while(p!=NULL && y>0)
	{

		a[i] = p->value;
		p = p->next;
		i++;
		y--;
	}
	i--;
	
	while(q!=NULL && i>-1)
	{
		q->value = a[i];
		q = q->next;
		i--;
	}
	p=q;
	if(p!=NULL)
	p = reverse_partial(p,n,m);
	
	
	return (s);
	}
void Display(struct node *s)
{
	printf("\n Linked list elements ->");
	struct node *q = s;
	while(q!=NULL)
	{
		printf("%d ",q->value );
		q=q->next;
	}
	
	printf("\n\n");
}

int main()
{
struct node *start;
start=NULL;
int n,m;
printf(" Enter n and m\n");
scanf("%d%d", &n,&m);
int x = 8;
start = insert_node(start , x);
x = 7;
start = insert_node(start , x);
x = 6;
start = insert_node(start , x);
x = 5;
start = insert_node(start , x);
x = 4;
start = insert_node(start , x);
x = 3;
start = insert_node(start , x);
x = 2;
start = insert_node(start , x);
x = 1;

start = insert_node(start , x);
Display(start);
printf("\n");
start = reverse_partial(start,n,m);
Display(start);
printf(" Reversed %d nodes after every %d nodes\n", n, m);
}
