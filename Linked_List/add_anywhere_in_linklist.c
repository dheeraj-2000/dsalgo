#include <stdio.h>
#include <stdlib.h>
 struct node{
			int data;
			struct node *next;
			}*head,*end,*ptr1,*ptr2;
 void addInEnd();
 void addInBegining();
 void addInBetween();
 void display(); 
 void main()
	{
		head=end=NULL;
		int ch = 0;
		do{
			printf("\n\n\t\t\t MENU");
			printf("\n\n\t 1. Add a node in the end of the list");
			printf("\n\t 2. Add a node in the begining of the list");
			printf("\n\t 3. Add a node at a specific location");
			printf("\n\t 4. Display list");
			printf("\n\t 5. Exit");
			printf("\n\n\t Enter your choice :\t");
			scanf("%d", &ch);
			switch(ch){
				case 1: addInEnd();
						break;
				case 2: addInBegining();
						break;
				case 3: addInBetween();
						break;
				case 4: display();
						break;
				case 5: return;
				default: printf("\n\n\t WRONG CHOICE!!!!");
				}
			}while(1);
	}
 void addInEnd()
	{struct node* temp;
temp=(struct node*)malloc(sizeof(struct node));
		if(!head)
			{
			end=temp;
			head=end;
			}
		else
			end->next=temp;
		printf("\n\n\t Enter the data:\t");
		scanf("%d", &temp->data);
		if(head==end)
			return;
		end=end->next;
	}
 void addInBegining()
	{
		ptr1=(struct node*)malloc(sizeof(struct node));
		printf("\n\n\t Enter the data :\t");
		scanf("%d", &ptr1->data);
		ptr1->next=head;
		head=ptr1;
		if(!end)
			end=ptr1;
	}
 void addInBetween()
	{
		int d,flag = 0;
		printf("\n\n\t Enter the data after which new data is to be inserted :\t");
		scanf("%d", &d);
		ptr1=head;
		while(ptr1){
			if(ptr1->data == d){
				if(ptr1->next == NULL)
					addInEnd();
				else{
					ptr2=(struct node*)malloc(sizeof(struct node));
					printf("\n\n\t Enter the data to be put after the node with data %d :\t", d);
					scanf("%d",&ptr2->data);
					ptr2->next= ptr1->next;
					ptr1->next=ptr2;
					}				
				flag++;
				}
			ptr1=ptr1->next;
			}
		if(flag==0)
			printf("\n\t Element not found\n");
	}
 void display()
	{
		ptr1 = head;
		while(ptr1){
			printf("%d\t", ptr1->data);
			ptr1 = ptr1->next;
			}
	}
