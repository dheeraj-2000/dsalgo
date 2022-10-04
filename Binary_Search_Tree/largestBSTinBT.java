/** Reference: https://www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst/
 * Definition for binary tree
 * class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) {
 *      val = x;
 *      left=null;
 *      right=null;
 *     }
 * }
 */
 
class MinMax{
    int min;
    int max;
    boolean isBST;
    int size ;
    
    MinMax(){
        min = Integer.MAX_VALUE;
        max = Integer.MIN_VALUE;
        isBST = true;
        size = 0;
    }
}

public class Solution {
    
    
    private MinMax largest(TreeNode root){
        //if root is null return min as Integer.MAX and max as Integer.MIN 
        if(root == null){
            return new MinMax();
        }
        
        //postorder traversal of tree. First visit left and right then
        //use information of left and right to calculate largest BST.
        MinMax leftMinMax = largest(root.left);
        MinMax rightMinMax =largest(root.right);
        
        MinMax m = new MinMax();
        
        //if either of left or right subtree says its not BST or the data
        //of this node is not greater/equal than max of left and less than min of right
        //then subtree with this node as root will not be BST. 
        //Return false and max size of left and right subtree to parent
        if(leftMinMax.isBST == false || rightMinMax.isBST == false || (leftMinMax.max > root.val || rightMinMax.min <= root.val)){
            m.isBST = false;
            m.size = Math.max(leftMinMax.size, rightMinMax.size);
            return m;
        }
        
        //if we reach this point means subtree with this node as root is BST.
        //Set isBST as true. Then set size as size of left + size of right + 1.
        //Set min and max to be returned to parent.
        m.isBST = true;
        m.size = leftMinMax.size + rightMinMax.size + 1;
     
        //if root.left is null then set root.data as min else
        //take min of left side as min
        m.min = root.left != null ? leftMinMax.min : root.val;
  
        //if root.right is null then set root.data as max else
        //take max of right side as max.
        m.max = root.right != null ? rightMinMax.max : root.val;
   
        return m;
    }
    
    public int solve(TreeNode root) {
        MinMax m = largest(root);
        return m.size;
    }
}
