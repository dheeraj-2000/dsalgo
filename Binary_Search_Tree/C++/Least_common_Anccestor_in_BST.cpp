
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



//*** function to search node in BST ***//
int ser_node(Node* root, int key)
{
	if(root==NULL)
		return 0;
	else if(root->data==key)
		return 1;
	else if(root->data > key)
		return ser_node(root->left, key);
	else
		return ser_node(root->right, key);
	
}


//*** function to find lowest common ancestor ***//
void find_LCA(Node* root, int a, int b)
{
	if(root==NULL)
		cout<<-1<<" (any one of them or both doesn't exists)";
		
	else if(root->data >a && root->data >b)
		return find_LCA(root->left, a, b);							
		
	else if(root->data<a && root->data)
		return find_LCA(root->right, a, b);							
		
	else
		cout<<root->data;												// if our travesal splits right and left then we print that root->data
		
}


int main() 
{ 
    //create a BST 
    Node *root     = newNode(1); 
    root->left     = newNode(2); 
    root->right     = newNode(3); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
    int A,B;
    cout<<"Enter node1 and node 2"<<endl;
    cin>>A>>B;
    cout<<"LCA of "<<A<<" and "<<B<<" is:- ";
	int p=ser_node(Root,A) + ser_node(Root,B);							//to search whether elements are presents or not
	if(p!=2)
		cout<<-1<<" any one of them or both doesn't exists";
	else
		find_LCA(Root,A,B);												// to find LCA
	cout<<endl<<endl<<endl;
 
    return 0; 
} 