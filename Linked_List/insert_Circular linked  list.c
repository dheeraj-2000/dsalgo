

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
struct node *head=NULL;

struct node* create(int a[],int n)
{
  struct node *t,*newnode;
  int i;
  newnode=(struct node*)malloc(sizeof(struct node)); 
  head=newnode;
  newnode->data=a[0];
  newnode->next=head;
  t=head;
  
  for(i=1;i<n;i++)
  {
      newnode=(struct node*)malloc(sizeof(struct node));
      newnode->data=a[i];
      t->next=newnode;
      t=t->next;
      newnode->next=head; 
  }
  return head;
}

void display(struct node *p)
{
    while(p->next!=head)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d",p->data);
}

int length(struct node *p)
{int len=0;
    while(p->next!=head)
    {
        len++;
        p=p->next;
    }
    
    return ++len;
}

void insert(struct node *p,int index,int x)
{
  struct node *t,*newnode;
  int i;
  t=p;
  newnode=(struct node*)malloc(sizeof(struct node)); 
  newnode->data=x;
  newnode->next=NULL;
    
    while(t->next!=head)
    {
        t=t->next;
    }
    if(index==0)
    {
        newnode->next=p;
        p=newnode;
        t->next=p;
        head=p;
    }
    else
    {
        for(i=1;i<index;i++)
        {
            p=p->next;
        }
        newnode->next=p->next;
        p->next=newnode;
    }
    display(head);
}

int main()
{   struct node *p;
    int a[]={1,2,3,4,5,6};
    
    p=create(a,6);
    display(p);
    
    printf("\nafter insert\n");
    
    insert(p,6,9);
    return 0;
}
