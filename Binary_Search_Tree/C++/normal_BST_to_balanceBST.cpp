/*
    Author-Yogesh kansal
*/

#include<bits/stdc++.h> 
using namespace std;

struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 

Node *newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return (temp); 
} 


//*** function to print inorderBST ***//
void printInorder(Node* node) 
{ 
	if (node == NULL) 
		return; 
			
	printInorder(node->left); 
	
	cout<<node->data<<" "; 

	printInorder(node->right); 

}

//*** to re-create a balanced BST from a given BST ***//
Node* Bal_BST(vector<int>& B, int low, int high)
{
	if(low<=high) 
	{
		
		int mid=(low+high)/2;
			
		Node* root=newNode(B[mid]);
		root->left = Bal_BST(B,low,mid-1);
		root->right = Bal_BST(B,mid+1,high);
		return root;		
	}
	else
		return NULL;
}

//*** function to print inorderBST ***//
void getInorder(Node* root, vector<int>& a) 
{ 
	if (root == NULL) 
		return; 
			
	getInorder(root->left,a); 
	
	a.push_back(root->data);

	getInorder(root->right,a); 
	

} 

  
int main() 
{ 
    //create a BST 
    Node *root     = newNode(1); 
    root->left     = newNode(2); 
    root->right     = newNode(3); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
    
    vector <int> temp;
	getInorder(root,temp);												//to get elements in sorted order using inorder travesal
	Node* New_root=NULL;
	New_root = Bal_BST(temp,0,n-1);										//creating Balance BST
	
	cout<<"Inorder trvesal of Balanced BST:- ";
	printInorder(New_root);												//print inorder
	cout<<endl<<endl;
    return 0; 
} 