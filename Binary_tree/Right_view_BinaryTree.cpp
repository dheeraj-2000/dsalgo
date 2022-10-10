
/*
     Problem Statement : Given a binary tree of integers. Return an array of integers representing 
     the right view of the Binary tree.
     Right view of a Binary Tree is a set of nodes visible when the tree is visited from Right side.
     Example :

        1 
      /  \
     2   3
    /
   4
   Ans : [ 1  3  4 ]
   Reason : Look binary tree from right side,we can only see 1,3 and 4.

*/
#include <bits/stdc++.h>
using namespace std;


struct TreeNode  //structure of Tree Node
{
	int val; //data that contains each Tree Node
	struct TreeNode *left, *right;
	TreeNode(int data)
	{
		this->val = data;
		left = right = NULL;
	}
};

 int height(TreeNode* root)  //To Find height of the tree
 {
     if(!root) return -1;
     else return 1 + max(height(root->left) , height(root->right));
 }

 void RightView(TreeNode* root,vector<int> &ans,vector<int> &level_vis,int i) 
 {
     if(!root) return;  
     //If level i is not visited, Make it visited and push value of node into ans vector 
     if(level_vis[i]==0) 
     {
         ans.push_back(root->val);
         level_vis[i]=1;
     }
     //Go for visiting right side of the tree
     RightView(root->right,ans,level_vis,i+1);
     //Go for visiting left side of the tree,if right side not exist.
     RightView(root->left,ans,level_vis,i+1);
 }
vector<int> Right_View(TreeNode* root) 
{
   vector<int> ans;
   int h = height(root);//height of the tree
   vector<int> level_vis(h+1,0); // Total levels = h
   RightView(root,ans,level_vis,0); //Function to find RightView of tree
   return ans;
}

int main()
{
/* Example Tree : 
        1 
      /  \
     2   3
    /
   4

*/
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    vector<int> ans = Right_View(root);
    
    for(auto it:ans)
    cout<<it<<" ";
    
}
