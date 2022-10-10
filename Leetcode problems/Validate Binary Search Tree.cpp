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
private: 
    bool chk(TreeNode* node, long l, long r) {
        if(node == NULL) return true;
        
        if(node->val <= l || node->val >= r) return false;
        
        return chk(node->left, l, node->val) && chk(node->right, node->val, r);
    }
public:
    bool isValidBST(TreeNode* root) {
        return chk(root, LLONG_MIN, LLONG_MAX);
    }
};