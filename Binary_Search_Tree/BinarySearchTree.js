						            //Binary Search Tree

function BSTNode(value)
{
	this.value=value;
	this.left=null;
	this.right=null;
}

function BinarySearchTree()
{
	this._root=null;
}

BinarySearchTree.prototype.insert=function(value)
{
   let node=new BSTNode(value);
   if(!this._root)
	this._root=node;
   else
   {
     let currentNode=this._root;
     while(true)
     {
        if(currentNode.value>node.value)
        {
	   if(!currentNode.left)
	   {    
	     currentNode.left=node;
	     break;
	   }
	   currentNode=currentNode.left;
        }
	else if(node.value>currentNode.value)
	{
	   if(!currentNode.right)
	   {
	    currentNode.right=node;
	    break;
	   }
           currentNode=currentNode.right;
        }
        else
	   break;
    }
   }
}

BinarySearchTree.prototype.deletion=function(value)
{
   function findRightTreeMin(root)
   {
      while(root.left)
         root=root.left;	//loops till leftmost node is reached
      return root;
   }

   function recursiveDeletion(root,value)
   {
	   
      if(!root)
	return null;
      else if(value<root.value)
      {
	 root.left=recursiveDeletion(root.left,value);
      }
      else if(value>root.value)
      {
	 root.right=recursiveDeletion(root.right,value);
      }
      else
      {
	 if(!root.left && !root.right)
	      return null;
	 else if(!root.left)
	      return root.right;
	 else if(!root.right)
	      return root.left;
	 else
	 {
	   let temp=findRightTreeMin(root.right);
	   root.value=temp.value;
	   root.right=recursiveDeletion(root.right,temp.value);
	 }
      }
      return root;
   }
   recursiveDeletion(this._root,value);
}

BinarySearchTree.prototype.search=function(value)
{
  let currentNode=this._root;
  while(currentNode)
  {
     if(value<currentNode.value)
        currentNode=currentNode.left;
     else if(value>currentNode.value)
	currentNode=currentNode.right;
     else
	return (console.log("Found"));
  }
  console.log("Not Found");
}

let BST=new BinarySearchTree();
BST.insert(10);
BST.insert(4);
BST.insert(21);
BST.insert(5);
BST.insert(50);
BST.insert(3);
BST.insert(11);
BST.insert(40);
BST.insert(70);
BST.deletion(21);
BST.search(21);                        //Not Found
BST.search(4);                         //Found
console.log(BST);

							//In-order Traversal
BinarySearchTree.prototype.inOrder=function()
{
   function traverser(node)
   {
      if(!node)
         return;
      traverser(node.left);
      console.log(node.value);
      traverser(node.right);
   }
   traverser(this._root);
}
							//Pre-Order Traversal
BinarySearchTree.prototype.preOrder=function()
{
   function preOrderTraversal(node)
   {
      if(!node)
         return;
      console.log(node.value);
      preOrderTraversal(node.left);
      preOrderTraversal(node.right);
   }
   preOrderTraversal(this._root);
}

							//Post-order traversal

BinarySearchTree.prototype.postOrder=function()
{
   function postOrderTraversal(node)
   {
      if(!node)
	return;
      postOrderTraversal(node.right);
      postOrderTraversal(node.left);
      console.log(node.value);
   }
   postOrderTraversal(this._root);
}
							//Level-order traversal
BinarySearchTree.prototype.levelOrder=function()
{
   function levelOrderTraversal(node)
   {
      let Q=[];
      Q.push(node);
      while(Q.length)
      {
         node=Q.shift();
	 console.log(node.value);
	 if(node.left)
	   Q.push(node.left)
	 if(node.right)
	   Q.push(node.right);
      }
   }
   levelOrderTraversal(this._root);
}

let traversalBST=new BinarySearchTree();
let nodeValues=[20,14,4,17,29,24,31,7,3];
nodeValues.map((val,i)=>traversalBST.insert(val));

traversalBST.preOrder();		// [20,14,4,3,7,17,29,24,31]
traversalBST.inOrder();	        // [3,4,7,14,17,20,24,29,31]
traversalBST.postOrder();		// [3,7,4,17,14,24,31,29,20]
traversalBST.levelOrder();		// [20,14,29,4,17,24,31,3,7]
