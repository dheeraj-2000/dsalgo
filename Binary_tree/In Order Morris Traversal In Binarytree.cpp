#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
  int val = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;

  TreeNode(int val)
  {
    this->val = val;
  }
};

vector<int> morrisInTraversal(TreeNode* root) {

  vector<int> ans;
  if(!root) return ans;

  TreeNode* curr = root;

  while(curr != NULL) {

    if(curr->left == NULL) {
      ans.push_back(curr->val);
      curr = curr->right;
    }
    else {
      TreeNode* prev = curr->left;
      while(prev->right != NULL && prev->right != curr) {
        prev = prev->right;
      }

      if(prev->right == NULL) {
        prev->right = curr;
        curr = curr->left;
      }

      if(prev->right == curr) {
        ans.push_back(curr->val);
        prev->right = NULL;
        curr = curr->right;
      }

    }
  }

  return ans;

}

// input_section=================================================

TreeNode* createTree(vector<int>& arr, vector<int>& IDX)
{

  if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
  {
    IDX[0]++;
    return nullptr;
  }

  TreeNode* node = new TreeNode(arr[IDX[0]++]);
  node->left = createTree(arr, IDX);
  node->right = createTree(arr, IDX);

  return node;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  vector<int> IDX(1, 0);
  TreeNode* root = createTree(arr, IDX);

  vector<int> ans = morrisInTraversal(root);

  for (int i : ans)
  {
    cout << i << " ";
  }
}

int main()
{
  solve();
  return 0;
}