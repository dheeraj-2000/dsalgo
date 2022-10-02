// stack implementation using linkedlist
// a linkedlist insertion and deletion from head -> makes it a stack . LIFO T.C best case O(1)
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
// global head, in our case , the top
struct Node* top=NULL;

void print(){
	struct Node *traverse = top;
	while(traverse!=NULL){
		printf("%d ",traverse->data);
		traverse = traverse->next; // iterate
	}
	printf("\n");
}

void Push(int x){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = NULL;
	if(top==NULL){
		top = newNode;
		print();
		return;
	}
	// link fix with first node
	newNode->next = top;
	top = newNode;
	printf("Stack after insertion : \n");
	print();
}

void Pop(){
	if(top == NULL){
		printf("Stack is empty!!\n");
		return ;
	}
	struct Node *temp = top->next;  // one node skipped i.e., deleted
	top->next = NULL;
	top = temp;
	printf("Stack after deletion: \n");
	print();
}

void emptyCheck(){
	if(top == NULL) printf("True \n");
	else printf("False\n");
}

int main(){
	top = NULL;
	int choice;
	userChoice:
	printf("Enter 1 for push, 2 for pop, 3 for emptyCheck : ");
	scanf("%d",&choice);
	// switch statement
	switch(choice){
		case 1:
			int value;
			printf("Enter the value for insertion : ");
			scanf("%d",&value);
			Push(value);
			break;
		case 2:
			Pop();
			break;
		case 3:
			emptyCheck();
			break;
		default: 
				printf("Wrong choice!");

	}
	goto userChoice;
	return 1;
}