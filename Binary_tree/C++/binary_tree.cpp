#include<bits/stdc++.h>
using namespace std;
class Node{
public:
      int data;
      Node* left;
      Node* right;
};

Node* createnode(int data){
      Node* newnode   = new Node();
      newnode -> data = data;
      newnode -> left = NULL;
      newnode -> right = NULL;

      return newnode;
}

Node* insert(Node* root , int data)
{
      if(root == NULL)
                  return createnode(data);
      else if(data < root->data)
                  root->left = insert(root->left , data);
      else if(data > root->data)
                  root->right = insert(root->right , data);
      else
                  return root;
}

void inorder(Node*root)
{
      if(root!=NULL)
      {
            inorder(root->left);
            cout<<root->data<<endl;
            inorder(root->right);


      }
}

int main(){
      int n;
      cin>>n;
      n--;
      int first_val;
       Node* root = NULL;
      cin>>first_val;
      root = insert(root,first_val);
      int input;
      while(n--){
            cin>>input;
            insert(root,input);
      }
      cout<<endl;
      cout<<"PRINT INORDER TRAVERSAL"<<endl;
      inorder(root);
}
