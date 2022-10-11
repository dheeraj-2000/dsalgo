//Queue
	function Queue(arr_)
	{
	  this.arr=[];
	  if(arr_)
	    this.arr=arr_;
	}
	Queue.prototype.getBuffer=function()
	{
	  return this.arr.slice();
	}
	Queue.prototype.isEmpty=function()
	{
	  return (Boolean(!(this.arr.length)));
	}
	Queue.prototype.enque=function(value)
	{
	  this.arr.push(value);
	}
	Queue.prototype.deque=function()
	{
	  return this.arr.shift();
	}
	Queue.prototype.peek=function()
	{
          return this.arr[0];
	}
	function queueNAccess(queue,n)
	{
	  let bufferQueue=new Queue(queue.getBuffer());
	  while(--n!=0)
		bufferQueue.deque();
	  return bufferQueue.deque();
	}
	function queueSearch(queue,element)
	{
	  let bufferQueue=new Queue(queue.getBuffer());
	  while(!(bufferQueue.isEmpty()))
	  {
	    if(element==bufferQueue.deque())
		  return true;
	  }
	  return false;
	}
	let Q=new Queue();
	Q.enque(1);                     // arr=[1]
	Q.enque(2);			 // arr=[1,2]
	Q.enque(3);			 // arr=[1,2,3]
	Q.enque(4);			 // arr=[1,2,3,4]
	Q.enque(5);			 // arr=[1,2,3,4,5]
	Q.enque(6);			 // arr=[1,2,3,4,5,6]
	Q.deque();			 // arr=[2,3,4,5,6]
	console.log(Q.isEmpty());	 // returns false		
	console.log(Q.peek());		 // returns '2'
	console.log(queueSearch(Q,9));  // returns false
	console.log(queueNAccess(Q,2)); // returns '3'
