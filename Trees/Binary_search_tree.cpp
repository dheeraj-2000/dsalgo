#include<iostream>
using namespace std;

struct node{
    int data;
node *left;
node *right;
};

node* makenewnode(int data){
   node* newnode=new node();
   newnode->data=data;
   newnode->left=newnode->right=NULL;
   return newnode;
}

node* insert(node* root,int data){
if(root==NULL){
    root=makenewnode(data);
    return root;
}
else if(data<= root->data){
    root->left=insert(root->left,data);
}
else{
    root->right=insert(root->right,data);
}
return root;

}

bool search(node*root,int data){
  if(root==NULL) 
  return false;
 else if(root->data==data)
  return true;  
  else if(data<=root->data)
  return search(root->left,data);
  else 
  return search(root->right,data);
}

int main(){
    int n;
node *head;
head=NULL;

head=insert(head,10);
head=insert(head,20);
head=insert(head,30);
head=insert(head,40);

cout<<"enter a number "<<endl;
cin>>n;
if(search(head,n)==true){
    cout<<"element found"<<endl;
}
else
cout<<"not found"<<endl;

    return 0;
}
