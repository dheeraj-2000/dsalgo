#include<bits/stdc++.h>
using namespace std;
class Node{
public:
      int data;
      Node* left = NULL;
      Node* right = NULL;
};
Node* add_node(int l){
      Node* new_node = new Node();
      new_node->data = l;
      new_node->left = NULL;
      new_node->right = NULL;
      return new_node;
}

void insert(Node* new_node, int l){
      if(!new_node->left)
            new_node->left = add_node(l);
      if(!new_node->right)
            new_node->right = add_node(l);
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
      int n,l;
      cin>>n;
      n--;
      int fist_val;
      cin>>first_val;
      Node* root = NULL;
      insert(root, first_val);
      while(n--){
            cin>>l;
            insert(root, l);
      }
      cout<<endl;
      cout<<"PRINT INORDER TRAVERSAL"<<endl;
      inorder(root);
}
