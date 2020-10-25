#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int d)
    {
        data=d;left=NULL,right=NULL;
    }
};
//Accepts the old root node and returns the new root node
node* insert_in_bst(node* root,int data){
    //base case
    if(root==NULL){
        return new node(data);
        //when we create data using data using new then it automatically returns the address
    }
    //rec casse
    if(data<=root->data){
        root->left=insert_in_bst(root->left,data);
    }
    else{
        root->right=insert_in_bst(root->right,data);
    }
    return root;
}
node* buildtree(){
    
    int d;
    cin>>d;
    
    node* root=NULL;
    while(d!=-1){
        root=insert_in_bst(root,d);
        cin>>d;
    }
    return root;
    
}

class linkedlist{
    public:
    node* head;
    node* tail;
};
linkedlist flatten(node* root){
    linkedlist l;
    //this case is only possible when tree is empty
    if(root==NULL){
        l.head=l.tail=NULL;
        return l;
    }
    //this is the case of leaf node
    if(root->left==NULL && root->right==NULL){
        l.head=l.tail=root;
        return l;
    }
    //left is not NULL
    if(root->left!=NULL && root->right==NULL){
        linkedlist leftll=flatten(root->left);
        leftll.tail->right=root;
        
        l.head=leftll.head;
        l.tail=root;
        return l;
    }
    //right side not null
    if(root->left==NULL && root->right!=NULL){
        linkedlist rightll=flatten(root->right);
        root->right=rightll.head;
        
        l.head=root;
        l.tail=rightll.tail;
        return l;
    }
    //both side not NULL
    linkedlist leftll= flatten(root->left);
    linkedlist rightll=flatten(root->right);
    
    leftll.tail->right=root;
    root->right=rightll.head;
    
    l.head=leftll.head;
    l.tail=rightll.tail;
    return l;
}
int main() 
{
	node* root=buildtree();
    linkedlist l=flatten(root);
    node* temp=l.head;
    
    while(temp!=NULL){
        cout<<temp->data<<" --> ";
        temp=temp->right;
    }
    cout<<endl;
}
