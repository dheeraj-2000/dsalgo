vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
if(!A) return ans;

queue<TreeNode*> q;

q.push(A);

while(!q.empty()){
    
    TreeNode* curr = q.front();
    q.pop();
    ans.push_back(curr->val);
    if(curr->right)
    {
        q.push(curr->right);
    }
    if(curr->left)
    {
       q.push(curr->left);    
    }
}

reverse(ans.begin(),ans.end());

return ans; 
}
