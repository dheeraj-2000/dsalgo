/*
    Author-Yogesh kansal
*/

#include<bits/stdc++.h> 
using namespace std;

struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 

Node *newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return (temp); 
} 



//*** function for level order travesal(BFS) ***//
void printLevelOrder(Node* root)
{
	queue< Node* > Queue;
	Queue.push(root);
	Node* temp=NULL;
	
	while(!Queue.empty())
	{
		temp=Queue.front();
		  Queue.pop();
		
		cout<<temp->data<<" ";												//while iterating we are storing all child at 1 lower level
																			
		if(temp->left!=NULL)												//of a node i=from left to right 		
			Queue.push(temp->left);
		if(temp->right!=NULL)
			Queue.push(temp->right);
	}
}


int main()
{
	
    //create a BST 
    Node *root     = newNode(1); 
    root->left     = newNode(2); 
    root->right     = newNode(3); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
		
	cout<<endl;
	
	
	cout<<"level Order Travesal of BST:- ";
	printLevelOrder(root);													//print indrder
	cout<<endl<<endl;
}