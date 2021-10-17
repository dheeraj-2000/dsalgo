//Problem: 1448 (Medium)
//https://leetcode.com/problems/count-good-nodes-in-binary-tree/


class Solution {
public:
    
    void goody(TreeNode* root, int mx, int &c)
    {
        if(!root)return;
        if(mx <= root->val)                    //we simply keep the track of the maximum element along the path
        {
            mx=root->val;
            ++c;                                    //increment the result if number is greater or equal to max element
        }
        goody(root->left,mx,c);
        goody(root->right,mx,c);   
    }
    int goodNodes(TreeNode* root) {
        
        int c=0,mx=INT_MIN;
        goody(root,mx,c);
        return c;
    }
};