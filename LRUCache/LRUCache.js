				//LRU
function LRUNode(key,value)
{
   this.key=key;
   this.value=value;
   this.prev=null;
   this.next=null;
}
function LRUCache(capacity)
{
   this.keys={};                        //A hash table
   this.head=new LRUNode('',null);
   this.tail=new LRUNode('',null);
   this.capacity=capacity;
   this.head.next=this.tail;
   this.tail.prev=this.head;
}
LRUCache.prototype.addNode=function(node)
{
   let realTail=this.tail.prev;
   node.prev=realTail;
   realTail.next=node;
   node.next=this.tail;
   this.tail.prev=node;
}
LRUCache.prototype.delNode=function(node)
{
   let prevNode=node.prev;
   let nextNode=node.next;
   prevNode.next=nextNode;
   nextNode.prev=prevNode;
}
LRUCache.prototype.set=function(key,value)
{
   let node=this.keys[key];
   
   if(node)
      this.delNode(node);
   
   node=new LRUNode(key,value);
   this.keys[key]=node;
   this.addNode(node);
   if(this.capacity<Object.keys(this.keys).length)
   {
      let realHead=this.head.next;
      this.delNode(realHead);
      delete this.keys[realHead.key];
   }
}
LRUCache.prototype.get=function(key)
{
   let node=this.keys[key];
   if(node==undefined)
      return null;
   else
   {
      this.delNode(node);
      this.addNode(node);
      return node.value;
   }
}
let myLRU=new LRUCache(5);
myLRU.set(1,1);				//1
myLRU.set(2,'b');			//1<->b
myLRU.set(3,3);				//1<->b<->3
myLRU.set(4,4);				//1<->b<->3<->4
myLRU.set(5,'e');			//1<->b<->3<->4<->e
myLRU.set(6,'f');			//b<->3<->4<->e<->f
myLRU.set(7,7);				//3<->4<->5<->f<->7
console.log(myLRU);
myLRU.get(4);				//3<->5<->f<->7<->4
myLRU.get(12);

