/** 
 * Binary Tree ZigZag Order Tree Traversal
 * Given the root of a binary tree, return the zigzag level order traversal of its node value.
 * (i.e from left to right then right to left for the next level and then alternate between).
 *  Approach used: Use of two queues
 * Keep all the nodes of one level in one queue and enqueue all the nodes of next level in another 
 * queue and level wise append the nodes in a list.
*/
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode *getLeft()
    {
        return this->left;
    }
    TreeNode *getRight()
    {
        return this->right;
    }
    int getVal()
    {
        return val;
    }
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrderTraversal(TreeNode *root)
    {
        vector<vector<int>> sol;
        if (root == NULL)
        {
            return sol;
        }
        queue<TreeNode *> q1, q2;
        vector<int> res;
        bool leftToRight = false;
        res.push_back(root->getVal());
        sol.push_back(res);
        q1.push(root);
        while (!q1.empty())
        {
            TreeNode *top = q1.front();
            q1.pop();
            if (top->getLeft() != NULL)
            {
                q2.push(top->getLeft());
            }
            if (top->getRight() != NULL)
            {
                q2.push(top->getRight());
            }
            if (q1.empty())
            {
                res.clear();
                while (!q2.empty())
                {
                    TreeNode *front = q2.front();
                    q2.pop();
                    res.push_back(front->getVal());
                    q1.push(front);
                }
                if (res.size() > 0)
                {
                    if (!leftToRight)
                    {
                        reverse(res.begin(), res.end());
                    }
                    sol.push_back(res);
                    leftToRight = !leftToRight;
                }
            }
        }
        return sol;
    }
};