
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


 //*** function to calculate hight of BST ***//
int cal_height(Node* root)
{
	if(root==NULL)
		return 0;
	
	return max(1+cal_height(root->left), 1+cal_height(root->right));		//this will give max hight of a right/left subtree
}

int main() 
{ 
    //create a BST 
    Node *root     = newNode(1); 
    root->left     = newNode(2); 
    root->right     = newNode(3); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
    
    cout <<"hight of bst is: "<< cal_height(root); 
    return 0; 
} 