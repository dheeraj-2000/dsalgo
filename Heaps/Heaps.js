					//Heaps

function Heap()
{
   let heapArr=[];
}

Heap.prototype.swap=function(index1,index2)
{
   let temp=this.heapArr[index1];
   this.heapArr[index1]=this.heapArr[index2];
   this.heapArr[index2]=temp;
}

Heap.prototype.parentIndex=function(N)
{
   return Math.floor((N-1)/2);
}

Heap.prototype.parent=function(N)
{
   return this.heapArr[this.parentIndex(N)];
}

Heap.prototype.leftChildIndex=function(N)
{
   return (N*2)+1;
}

Heap.prototype.leftChild=function(N)
{
   return this.heapArr[this.leftChildIndex(N)];
}

Heap.prototype.rightChildIndex=function(N)
{
   return (N*2)+2;
}

Heap.prototype.rightChild=function(N)
{
   return this.heapArr[this.rightChildIndex(N)];
}

						//Min-Heap
function MinHeap()
{
   this.heapArr=[];
}

MinHeap.prototype=Object.create(Heap.prototype);

MinHeap.prototype.bubbleUp=function()
{
   let index=this.heapArr.length-1;
   while(this.parent(index) && this.parent(index)>this.heapArr[index])
   {
      this.swap(this.parentIndex(index),index);
      index=this.parentIndex(index);
   }
}

MinHeap.prototype.bubbleDown=function()
{
   let index=0;
   while(this.leftChild(index) && 
	 this.leftChild(index)<this.heapArr[index] || 
	 this.rightChild(index)<this.heapArr[index])
   {
      let small=this.leftChildIndex(index);
      if(this.rightChild(index) && this.leftChild(index)>this.rightChild(index))
         small=this.rightChildIndex(index);
      this.swap(index,small)
      index=small;
   }
}

MinHeap.prototype.add=function(item)
{
   if(this.heapArr.indexOf(item)!=-1)
      return;
   this.heapArr[this.heapArr.length]=item;
   this.bubbleUp();
}

MinHeap.prototype.poll=function()
{
   let element=this.heapArr[0];
   this.heapArr[0]=this.heapArr.pop();
   console.log(element);
   this.bubbleDown();
}

let minHeap=new MinHeap();
[1,1,2,5,4,3,6,8,7].map((v,i)=>minHeap.add(v));
console.log(minHeap);					
minHeap.poll();							//1
minHeap.poll();							//2
minHeap.poll();							//3
minHeap.poll();							//4

							//Max-Heap

function MaxHeap()
{
   this.heapArr=[];
}

MaxHeap.prototype=Object.create(Heap.prototype);

MaxHeap.prototype.bubbleUp=function()
{
   let index=this.heapArr.length-1;
   while(this.parent(index) && this.parent(index)<this.heapArr[index])
   {
      this.swap(this.parentIndex(index),index);
      index=this.parentIndex(index);
   }
}

MaxHeap.prototype.bubbleDown=function()
{
   let index=0;
   while(this.leftChild(index) && 
	 this.leftChild(index)>this.heapArr[index] || 
	 this.rightChild(index)>this.heapArr[index])
   {
      let big=this.leftChildIndex(index);
      if(this.rightChild(index) && this.leftChild(index)<this.rightChild(index))
         big=this.rightChildIndex(index);
      this.swap(index,big)
      index=big;
   }
}

MaxHeap.prototype.add=function(item)
{
   if(this.heapArr.indexOf(item)!=-1)
      return;
   this.heapArr[this.heapArr.length]=item;
   this.bubbleUp();
}

MaxHeap.prototype.poll=function()
{
   let element=this.heapArr[0];
   this.heapArr[0]=this.heapArr.pop();
   console.log(element);
   this.bubbleDown();
}

let maxHeap=new MaxHeap();
[1,2,3,4,4,5,3,6,7].map((v,i)=>maxHeap.add(v));
maxHeap.poll();							//7
maxHeap.poll();							//6
maxHeap.poll();							//5

