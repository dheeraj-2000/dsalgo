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


//*** function to print inorderBST ***//
void printInorder(Node* node) 
{ 
	if (node == NULL) 
		return; 
			
	printInorder(node->left); 
	
	cout<<node->data<<" "; 

	printInorder(node->right); 

}


Node *constructTree (int a[], int size)
{
//code here
    Node* root=NULL;
    if(size==0)
        return root;
    
    root=new Node(a[size-1]);
    
    for(int i=size-2;i>=0;i--) {
        Node *temp=root,*pre=NULL;
        while(temp!=NULL) {
            pre=temp;
            if(temp->data>a[i])
                temp=temp->left;
                
            else if(temp->data<a[i])
                temp=temp->right;
            
        }
        if(pre->data>a[i])
            pre->left = new Node(a[i]);
        else
            pre->right=new Node(a[i]);
        
        
    }
    return root;
}

int main()
{
	int n,i;
	cout<<"Enter number of nodes:- ";
	cin>>n;
	cout<<endl;
	
	int a[n];
	cout<<"Enter values of n nodes:- ";
	for(i=0;i<n;i++)
		cin>>a[i];
	
		
	cout<<endl;
	
	Node* root=NULL;
	root=constructTree(a,n);
	
	
	cout<<"InOrder Travesal of BST:- ";
	printInorder(root);													//print indrder
	cout<<endl<<endl;
}