/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
     return  helper(root,LONG_MAX,LONG_MIN);
    }
 bool   helper(TreeNode* root,long int mx,long int mn)
    {if(root==NULL )
            return true;
        if(root->val>=mx or root->val<=mn)
            return false;
     return helper(root->left,root->val,mn) and  helper(root->right,mx,root->val); 
    }
};
