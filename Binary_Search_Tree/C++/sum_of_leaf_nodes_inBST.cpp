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
  
int sumOfLeafNodes(Node *r ){
     //Your code here 
     if(r==NULL)
        return 0;
    if(r->left==NULL&& r->right==NULL)
        return r->data;
        
    return sumOfLeafNodes(r->left)+sumOfLeafNodes(r->right);
        
}

int main() 
{ 
    //create a BST 
    Node *root     = newNode(1); 
    root->left     = newNode(2); 
    root->right     = newNode(3); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
    
    cout <<"sum of all leaf nodes is: "<< sumOfLeafNodes(root); 
    return 0; 
} 