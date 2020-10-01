// C++ program find maximum and minimum element 
#include <bits/stdc++.h> 
using namespace std; 

// A Tree node 
struct Node { 
	int key; 
	struct Node *left, *right; 
}; 

// Utility function to create a new node 
Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return (temp); 
} 


// Function to print a maximum and minimum element 
// in a tree without recursion without stack 
void printMinMax(Node* root) 
{ 
	
	if (root == NULL) 
	{ 
		cout << "Tree is empty"; 
		return; 
	} 
	
	Node* current = root; 
	
	Node* pre; 
	
	// Max variable for storing maximum value	 
	int max_value = INT_MIN; 
	
	// Min variable for storing minimum value	 
	int min_value = INT_MAX; 
	
	
	while (current != NULL) 
	{ 
		// If left child does nor exists 
		if (current->left == NULL) 
		{ 
			max_value = max(max_value, current->key); 
			min_value = min(min_value, current->key); 
			
			current = current->right; 
		} 
		else
		{ 
	
			// Find the inorder predecessor of current 
			pre = current->left; 
			while (pre->right != NULL && pre->right != 
												current) 
				pre = pre->right; 
	
			// Make current as the right child 
			// of its inorder predecessor 
			if (pre->right == NULL) 
			{ 
				pre->right = current; 
				current = current->left; 
			} 
	
			// Revert the changes made in the 'if' part to 
			// restore the original tree i.e., fix the 
			// right child of predecessor 
			else
			{ 
				pre->right = NULL; 
				
				max_value = max(max_value, current->key); 
				min_value = min(min_value, current->key); 
			
				current = current->right; 
			} // End of if condition pre->right == NULL 
			
		} // End of if condition current->left == NULL 
		
	} // End of while 
	
	// Finally print max and min value 
	cout << "Max Value is : " << max_value << endl; 
	cout << "Min Value is : " << min_value << endl; 
} 

// Driver Code 
int main() 
{ 
	/* 15 
	/ \ 
	19 11 
		/ \ 
	25 5 
	/ \ / \ 
	17 3 23 24 

	Let us create Binary Tree as shown 
	above */

	Node* root = newNode(15); 
	root->left = newNode(19); 
	root->right = newNode(11); 

	root->right->left = newNode(25); 
	root->right->right = newNode(5); 

	root->right->left->left = newNode(17); 
	root->right->left->right = newNode(3); 
	root->right->right->left = newNode(23); 
	root->right->right->right = newNode(24); 
	
	// Function call for printing a max 
	// and min element in a tree 
	printMinMax(root); 

	return 0; 
} 
