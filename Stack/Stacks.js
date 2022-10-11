//Stacks
	function Stack(arr_)
	{
	 this.arr=[];
	 if(arr_)
	   this.arr=arr_;
	}
	
	Stack.prototype.isEmpty=function()
	{
	  return(Boolean(!(this.arr.length)));
	}
	Stack.prototype.getBuffer=function()
	{
	  return (this.arr.slice());
	}
 
	Stack.prototype.push=function(value)
	{
	  this.arr.push(value);
	}
	Stack.prototype.peek=function()
	{
	  return(console.log(this.arr[this.arr.length-1]));
	}
	
	Stack.prototype.pop=function()
	{
	  return(this.arr.pop());
	}
	function Access(stack,n)
	{
	  let bufferStack=new Stack(stack.getBuffer());
	  while(--n!=0)
		bufferStack.pop();
	  return bufferStack.pop();
	}
	function Search(stack,element)
	{
	  let bufferStack=new Stack(stack.getBuffer());
	  while(bufferStack.isEmpty())
	  {
	    if(element==bufferStack.pop())
	    {
	       return true;
	    }
	  }
	  return false;
	}
	let stk=new Stack();
	stk.push(5);			// arr=[5]
	stk.push(6);			// arr=[5,6]
	stk.pop();			// arr=[5]
	stk.push(7);			// arr=[5,7]
	stk.push(8);			// arr=[5,7,8]
	stk.push(9);			// arr=[5,7,8,9]
	stk.push(10);			// arr=[5,7,8,9,10]
	console.log(stk.isEmpty());	// returns false
	console.log(Access(stk,2));	// returns 9
	console.log(Search(stk,21));	// returns false
