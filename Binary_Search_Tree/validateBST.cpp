// Link : https://leetcode.com/problems/validate-binary-search-tree/
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
    
    bool isBST(TreeNode* root, TreeNode* low, TreeNode* high){
    
        if(!root) return true;
        // conditions that nullify BST definition.
        if( (low && root->val<=low->val) || (high && root->val>=high->val)) 
            return false;
        
        bool isLeft = isBST(root->left, low, root );
        bool isRight = isBST(root->right, root, high);
        // returning values by checking if both left and right subtree are valid BSTs or not
        return (isLeft && isRight);
    }
    // function to check tree rooted at A is a valid BST or not
    bool isValidBST(TreeNode* A) {
        if(!A) return 1;
    
        TreeNode *low = NULL, *high = NULL;

        return isBST(A, low, high);
    }
};
