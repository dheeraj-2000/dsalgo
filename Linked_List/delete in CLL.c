

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

int delete(struct node *p,int index)
{
    struct node *t1=NULL;
    int ele,i;
    if(index==0)
    {
        ele=p->data;
        t1=p;
        while(t1->next!=head)
        {
            t1=t1->next;
        }
        t1->next=p->next;
        head=p->next;
        free(p);
        
    }
    else
    {
        for(i=0;i<index;i++)
        {
            t1=p;
            p=p->next;
        }
        ele=p->data;
        t1->next=p->next;
        free(p);
        if(t1->next==NULL)
            t1->next=head;
    }
    
    return ele;
}

int main()
{   struct node *p;
    int a[]={1,2,3,4,5,6};
    
    p=create(a,6);
    display(p);
    printf("\n");
    printf("%d\n",delete(p,0));
    display(head);
    return 0;
}
