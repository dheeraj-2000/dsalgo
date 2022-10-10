/*
	Given an array build a height balanced binary tree
	Input:
	Size of an array(n)
	Array
	Output:
	Height Balanced binary tree(BFS)
*/

#include <iostream>
#include <queue>
#include<utility>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

Node* buildTree()
{
	int data;
	cin >> data;
	if (data == -1)
	{
		return NULL;
	}

	Node * root = new Node(data);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void printPre(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	// Root
	cout << root->data << " ";
	// Left
	printPre(root->left);
	// Right
	printPre(root->right);
}

void printIn(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	// Left
	printIn(root->left);
	// Root
	cout << root->data << " ";
	// Right
	printIn(root->right);
}

void printPost(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	// Left
	printPost(root->left);
	// Right
	printPost(root->right);
	// Root
	cout << root->data << " ";
}

//Approach:
// If node is NULL return 0
// else return max of (left subtree height and right subtree height) + 1
int height(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	return max(height(root->left), height(root->right)) + 1;
}



void tree_bfs_with_newline(Node *root)
{
	queue<Node*> Q;
	Q.push(root);
	// Change of level after root
	Q.push(NULL);
	while (!Q.empty())
	{
		Node* node = Q.front();
		Q.pop();
		// if node is NULL go to next line
		if (node == NULL)
		{
			cout << endl;
			// If Q is not empty then level is changed
			if (!Q.empty())
			{
				Q.push(NULL);
			}
		}
		else
		{
			cout << node->data << " ";
			if (node->left != NULL)
			{
				Q.push(node->left);
			}
			if (node->right != NULL)
			{
				Q.push(node->right);
			}
		}
	}
	return ;
}

Node* buildHeightBalancedHelper(int *arr, int start, int end)
{
	// 0 elements in an array
	if (start > end)
	{
		return NULL;
	}
	// create a node
	// insert mid element into it
	// call recursively on start to mid-1 and mid+1 to end
	int mid = start + (end - start) / 2;
	Node *new_node = new Node(arr[mid]);
	new_node->left = buildHeightBalancedHelper(arr, start, mid - 1);
	new_node->right = buildHeightBalancedHelper(arr, mid + 1, end);
	return new_node;
}

Node* buildHeightBalanced(int *arr, int n)
{
	return buildHeightBalancedHelper(arr, 0, n - 1);
}

int main(int argc, char const *argv[])
{

	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	Node *root = buildHeightBalanced(arr, n);
	tree_bfs_with_newline(root);
	return 0;
}