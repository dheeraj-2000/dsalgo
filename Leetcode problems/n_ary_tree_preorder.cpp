//Problem:589 (Easy)
//Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
//https://leetcode.com/problems/n-ary-tree-preorder-traversal/


//RECURSIVE SOLUTION
class Solution {
public:
    
    void pre_recursive(Node* root, vector<int>&v)
    {
        if(!root)return;
        v.push_back(root->val);
        for(auto x: root->children)               
        {
            pre_recursive(x,v);
        }    
    }
    vector<int> preorder(Node* root) {
        vector<int>v;
        pre_recursive(root, v);
        return v;
    } 
}


//ITERATIVE SOLUTION
class Solution {
public:
 
     vector<int> preorder(Node* root) {
        vector<int>v;
        if(!root)return v;
         
         stack<Node*> st;         //using stack
         st.push(root);
         
         while(!st.empty())
         {
             Node* temp = st.top();
             st.pop();
             v.push_back(temp->val);             //adding top of the stack to resultant vector
             
             int size = (temp->children).size();        //getting number of children of a node
             while(size--)
             {
                 st.push(temp->children[size]);         //storing the children in reverse order to get the leftmost at top
             } 
         }
         return v;
    }
};