/*Problem Statement:
Leetcode - 538
Given the root of a Binary Search Tree (BST), 
convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

-The left subtree of a node contains only nodes with keys less than the node's key.
-The right subtree of a node contains only nodes with keys greater than the node's key.
-Both the left and right subtrees must also be binary search trees.

Example 1:

Input: root = [0,null,1]
Output: [1,null,1]

Example 2:

Input: root = [1,0,2]
Output: [3,3,2]

Example 3:

Input: root = [3,2,4,1]
Output: [7,9,4,10]

Approach :
Meditate on the fact that the in order traversal of a Binary Search Tree visits all the nodes in a sorted order .

This is because the traversal goes in the order: left node-parent node- right node. 
And as we know, in BST the left node is less than the parent node and the right node is greater than the parent node.

Hence, a sorted increasing order is maintained.

Imagine traversing through "reverse in order" of a BST. 
Then, our traversal will be in the order: right node-parent node- left node. This means the largest valued element will be visited first and then the smaller values.

Hence, a sorted decreasing order is maintained.

We make use of the above trick of reverse inorder by using a static variable "sum". 
As we visit the greater elements, we keep collecting their sum in this variable and then dump that "sum" in place of data of the node.*/

Solution: 

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

//using reverse inorder traversal (Right -> Root -> Left)

class Solution {
    int sum = 0;
    public TreeNode convertBST(TreeNode root) {
        if(root == null){
            return null;
        }
        
        convertBST(root.right);
        
        sum+= root.val;
        root.val = sum;
        
        convertBST(root.left);
        return root;
        
    }
}
