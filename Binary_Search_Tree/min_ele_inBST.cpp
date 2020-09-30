
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


int minValue(Node* root)
{
    // Code here
    if(root==NULL)
        return -1;
    
    
    while(root->left!=NULL)
        root=root->left;
        
    return root->data;
        
}


int main() 
{ 
    //create a BST 
    Node *root     = newNode(1); 
    root->left     = newNode(2); 
    root->right     = newNode(3); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
    
    cout <<"min element in BST is" "<< minValue(root); 
    return 0; 
} 