void levelorder(TreeNode *root, vector<vector<int> > &ans){
if(root==NULL)
return;
queue<TreeNode *> q;
int level=1;
q.push(root);
while(!q.empty()){
int count=q.size();
vector<int> v;
for(int i=0;i<count;i++){
TreeNode *curr=q.front();
q.pop();
v.push_back(curr->val);
if(curr->left!=NULL)
q.push(curr->left);
if(curr->right!=NULL)
q.push(curr->right);

    }
    if(level%2==0)
        reverse(v.begin(),v.end());
    level++;
    ans.push_back(v);
}
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
vector<vector<int> > ans;
TreeNode *root=A;
levelorder(root,ans);
return ans;
}
