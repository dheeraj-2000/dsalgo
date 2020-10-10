// INVERT A BINARY TREE ( MIRROR IMAGE OF A BINARY TREE )

/*        The input tree is,    
                 8 
                / \ 
              2    10 
             / \ 
            1   5

    Inverted tree is,
        8 
       / \ 
      10   2 
         / \ 
        5   1

    i.e. a mirror image (or) inversion of a binary tree is a binary tree
        with left and right children of all non-leaf nodes interchanged.
        */
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

struct Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

//      1.--------------------- ITERATIVE APPROACH ------------------
/*  This algorithm does a level order traversal of the tree.
    Left and right children of each non-leaf node at a particular level are swapped.
    The above step is repeated for the next level.
    
    To perform level order traversal we use a queue.  */

/* Time Complexity: O(n), n = number of nodes
   Space Complexity: O(n), n = number of nodes */

void invertTreeIterative(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *currentNode = Q.front(), *temp;
        Q.pop();

        // Swap left and right subtrees of the current node
        temp = currentNode->left;
        currentNode->left = currentNode->right;
        currentNode->right = temp;

        if (currentNode->left)
            Q.push(currentNode->left);
        if (currentNode->right)
            Q.push(currentNode->right);
    }
}

//      2.--------------------- RECURSIVE APPROACH ------------------
/*  The algorithm is recursive and very intuitive.
       We traverse through the tree and swap the left and right children of each node recursively.
       1. Call the invertTreeRecursive function on the left subtree
       2. Call the invertTreeRecursive function on the right subtree.
       3. Swap the left and right children of the current node.  */

/* Time Complexity: O(n), n = number of nodes
       Space Complexity: O(h), h = height of tree */

void invertTreeRecursive(Node *treeNode)
{
    if (treeNode == NULL) // Base case checks if the node is a leaf node
        return;
    Node *temp;

    // Calling invertTreeRecursive on both subtrees recursively
    invertTreeRecursive(treeNode->left);
    invertTreeRecursive(treeNode->right);

    // Swapping the left and right children of the current node.
    temp = treeNode->left;
    treeNode->left = treeNode->right;
    treeNode->right = temp;
}

// Print the tree nodes in inorder fashion
void printTree(Node *treeNode)
{
    if (treeNode == NULL)
        return;
    printTree(treeNode->left);
    cout << treeNode->data << ' ';
    printTree(treeNode->right);
}

int main()
{
    Node *root1 = newNode(8);
    root1->left = newNode(2);
    root1->left->left = newNode(1);
    root1->left->right = newNode(5);
    root1->right = newNode(10);

    Node *root2 = newNode(8);
    root2->left = newNode(2);
    root2->left->left = newNode(1);
    root2->left->right = newNode(5);
    root2->right = newNode(10);

    cout << "Inorder traversal of original tree: " << endl;
    printTree(root1);
    invertTreeIterative(root1);
    invertTreeRecursive(root2);
    cout << '\n'
         << "Inorder traversal of iteratively inverted tree: " << endl;
    printTree(root1);

    cout << '\n'
         << "Inorder traversal of recursively inverted tree: " << endl;
    printTree(root2);
    return 0;
}

/* Output:
    Inorder traversal of original tree: 
    1 2 5 8 10 
    Inorder traversal of iteratively inverted tree: 
    10 8 5 2 1 
    Inorder traversal of recursively inverted tree: 
    10 8 5 2 1 
    */