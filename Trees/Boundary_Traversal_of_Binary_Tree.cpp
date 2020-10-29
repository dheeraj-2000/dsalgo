//Problem Statement: Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root.
//Note: The boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.

/*
  Eg.            20
                /   \
               4     6
              / \   / \
             10  2  1  5
                / \     \
               3   8     9
               
Output: 20 4 10 3 8 1 5 9 
*/   

/*
Approach: We break the problem into 3 parts:
1) Print the left boundary of the Binary Tree in top-down manner
2) Print the leaves from left to right
3) Print the right boundary of the Binary Tree in bottom-up manner
*/

void printLeaves(Node* root){
    if(root==NULL)
        return;

    printLeaves(root->left);

    //print if it is a leaf node
    if(root->left==NULL && root->right==NULL)
        cout<<root->data<<" ";

    printLeaves(root->right);

}

//the leftmost boundary is basically all the leftmost nodes of the Binary Tree
void printLeftBoundary(Node* root){
    if(root==NULL)
        return;

    if(root->left){

        //to ensure top-down manner, first print and then call the function recursively
        cout<<root->data<<" ";
        printLeftBoundary(root->left);
    }
    else if(root->right){
        cout<<root->data<<" ";
        printLeftBoundary(root->right);
    }
}

//the rightmost boundary is basically all the rightmost nodes of the Binary Tree
void printRightBoundary(Node* root){
    if(root==NULL)
        return;

    if(root->right){

        //to ensure bottom-up manner, first call the function recursively and then print
        printRightBoundary(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left){
        printLeftBoundary(root->left);
        cout<<root->data<<" ";
    }
}

//The function where the entire boundary traversal is printed
void printBoundaryOfBinaryTree(Node* root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";

    //Step 1
    printLeftBoundary(root->left);

    //Step 2
    printLeaves(root);

    //Step 3
    printRightBoundary(root->right);

}