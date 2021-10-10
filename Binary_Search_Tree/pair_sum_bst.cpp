
// Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.

// Sample Input:
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 15

// Sample Output:
// 5 10
// 6 9

#include <iostream>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int>* convertStruct(BinaryTreeNode<int>* root){
    
    if(root == NULL){
        vector<int>* arr = new vector<int>;
        return arr;
    }
    
    if(!root->left && !root->right){
        vector<int>* arr = new vector<int>;
        arr->push_back(root->data);
        return arr;
    }
    
    vector<int>* leftArr = convertStruct(root->left);
    vector<int>* rightArr = convertStruct(root->right);
    
    for(int i = 0; i < rightArr->size(); i++){
        leftArr->push_back(rightArr->at(i));
    }
    
    leftArr->push_back(root->data);
    
    return leftArr;
    
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    
    vector<int>* arr = convertStruct(root);
    
    sort(arr->begin(), arr->end());
    
    int i = 0, j = arr->size() - 1;
    
    int currSum;
    
    while(i<j){
        currSum = arr->at(i) + arr->at(j);
        if(currSum > sum)
            j--;
        else if(currSum < sum)
            i++;
        else if(currSum == sum){
            cout<<arr->at(i)<<" "<<arr->at(j)<<endl;
            i++;
            j--;
        }
    }
    
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}