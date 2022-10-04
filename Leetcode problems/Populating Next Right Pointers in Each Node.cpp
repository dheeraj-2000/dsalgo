#include<bits/stdc++.h>
/*
Link to question - https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

Question - You are given a perfect binary tree where all leaves are on the same level, and every parent has two children.
The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.


Approach - Perform a level order traversal on the tree, for each node in same level, populate next pointer of a node
with the front node in queue, if the current node is the last node of the level, populate next pointer to NULL.

Time Complexity -> O(n)  ,  where n is number od nodes in tree
*/


class Solution {
public:
    Node* connect(Node* root) {   // method to connect next pointers
    
        if(!root)
            return NULL;
        queue<Node*> q;   // initialise a queue to store nodes
        
        q.push(root);   // push root node in queue
        
        // Perform BFS (Level order Traversal)
        while(!q.empty()){
            int sz = q.size();
            for(int i=1;i<=sz;i++){
                Node *temp = q.front();
                q.pop();
                
                if(i==sz)   // last node of current level
                    temp->next = NULL;
                else {
                    temp->next = q.front(); 
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return root;
    }
};