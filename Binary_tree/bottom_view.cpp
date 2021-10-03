#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};


vector <int> bottomView(Node *root)
{
     vector<int> v;
     v.push_back(0);
    if(root == NULL)
    return v;
    v.pop_back();
  queue<pair<Node*,int>>q;
  q.push(make_pair(root,0));
  int vd = 0;
  int count_size = 0;
  map<int,int> m;
  while(!q.empty())
  {
      count_size = q.size();
      while(count_size)
      {
          pair<Node*,int> temp = q.front();
          q.pop();
          vd = temp.second;
          Node *node =  temp.first;
          m[vd] = node -> data;
          if(node -> left)
          q.push(make_pair(node -> left , vd - 1));
          if(node -> right)
          q.push(make_pair(node -> right , vd + 1));
          count_size--;
      }
  }
 
  auto it = m.begin();
  while(it != m.end())
  {
      v.push_back(it -> second);
      it++;
  }
  return v;
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--) // t is for testcases
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}





