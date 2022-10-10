/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans = 0;
// utility function to traverse the BST
void fun(TreeNode* root, int b, int c){
    if(!root) return;
    // incresing the ans variable if current value is in the range [b,c]
    if(root->val >= b && root->val <= c) ans++;
    // traversing both the subtrees.
    fun(root->right, b, c);
    fun(root->left, b,c);
    
}
int solve(TreeNode* A, int B, int C) {
  // initializing the ans variable to 0 before traversal.
    ans = 0;
    fun(A,B,C);
    return ans;
}
