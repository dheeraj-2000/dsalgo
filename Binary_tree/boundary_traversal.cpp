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


//main function for print boundary
vector <int> printBoundary(Node *root)
{
   vector<int> v;
   v.push_back(root -> data);
   if(root -> left)
   printLeftBoundary(root -> left, v);
   
   printBoundaryLeaves(root,v);
   if(root -> right)
   printRightBoundary(root -> right, v);
   return v;
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

