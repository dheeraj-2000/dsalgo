/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CompetitiveCoding;

/**
 *
 * @author taher
 */
class Node  
{ 
    int data; 
    Node left, right; 
   
    Node(int item)  
    { 
        data = item; 
        left = right = null; 
    } 
} 
   
class BinaryTree  
{ 
    Node root; 
   
    // Convert a given tree to a tree where every node contains sum of 
    // values of nodes in left and right subtrees in the original tree 
    int toSumTree(Node node)  
    { 
        if(node == null)
            return 0;
            
        int oldVal = node.data;
        
        node.data = toSumTree(node.left) + toSumTree(node.right);
        
        return node.data + oldVal;
    } 
   
    // A utility function to print inorder traversal of a Binary Tree 
    void printInorder(Node node)  
    { 
        if (node == null) 
            return; 
        printInorder(node.left); 
        System.out.print(node.data + " "); 
        printInorder(node.right); 
    } 
   
    /* Driver function to test above functions */
    public static void main(String args[])  
    { 
        BinaryTree tree = new BinaryTree(); 
   
        /* Constructing tree given in the above figure */
        tree.root = new Node(10); 
        tree.root.left = new Node(-2); 
        tree.root.right = new Node(6); 
        tree.root.left.left = new Node(8); 
        tree.root.left.right = new Node(-4); 
        tree.root.right.left = new Node(7); 
        tree.root.right.right = new Node(5); 
   
        tree.toSumTree(tree.root); 
   
        // Print inorder traversal of the converted tree to test result  
        // of toSumTree() 
        System.out.println("Inorder Traversal of the resultant tree is:"); 
        tree.printInorder(tree.root); 
    } 
} 

