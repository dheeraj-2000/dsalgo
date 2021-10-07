/*
Problem statement: 
We are given a tree and we need to print it's level order traversal in spiral manner
Example:

           10
         /    \
        20     30
      /   \   /   \
     40   50 60   70
Output: 
Spiral level order traversal is - 10 30 20 40 50 60 70     
*/

#include<bits/stdc++.h>
using namespace std;

//structure for tree nodes
struct treeNode{
   int data;
   struct treeNode *left, *right;
  treeNode(int x)
   {
       data=x;
       left=NULL;
       right=NULL;
   }
};

//Function to add new nodes to tree
struct treeNode* newNode(int val)
{
    struct treeNode* node = new treeNode(val);
    node->left=NULL;
    node->right=NULL;

    return node;
}

//Function to find spiral level order traversal 
vector<vector<int>> spiralTraversal(struct treeNode* root)
{
    vector<vector<int>>res;    //resultant vector
    
    if(root==NULL)     //null check
      return res;
    
    //two stacks to store alternate levels
    stack<treeNode*> s1, s2;
    
    //pushing first level i.e. root node to stack s1
    s1.push(root);
    

    while(!s1.empty() || !s2.empty())
    {
        vector<int>v1, v2;

        //keep pushing node values of current level from s1 to v1
        //Push nodes of next level to s2 
        while(!s1.empty())
        {
            treeNode* temp = s1.top();
            s1.pop();
            v1.push_back(temp->data);
            
            //here we push left node before right node
            if(temp->left)
             s2.push(temp->left);
            if(temp->right)
             s2.push(temp->right);
            
        }
        
        //push current level 'v1' to resultant vector 'res'
        if(!v1.empty())
            res.push_back(v1);
        
        //keep pushing node values of current level from s2 to v2
        //Push nodes of next level to s1
        while(!s2.empty())
        {
            treeNode* temp = s2.top();
            s2.pop();
            v2.push_back(temp->data);
            
            //here we push right node before left node
            if(temp->right)
             s1.push(temp->right);
            if(temp->left)
             s1.push(temp->left);
        }

        //push current level 'v2' to resultant vector 'res'
        if(!v2.empty())
          res.push_back(v2);
    }
    return res;
}


//driver code
int main()
{
    struct treeNode* root = newNode(10);
    
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
    root->right->left = newNode(60);
    root->right->right = newNode(70);

    cout << "Spiral level order traversal of binary tree is \n";
    vector<vector<int>>ans = spiralTraversal(root);

    for(vector<int>it: ans)
    {
        for(auto x: it)
         cout<<x<<" ";
    }
 
    return 0;
}