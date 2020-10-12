#include <iostream>
using namespace std;

// initializing the size of stack 
int n = 10, stack[10], top = -1;

// function for pushing into stack
/*
	if we've reached to n-1 means from 0 to n-1 that means we've no free spaces is stack, which 
	implies the stack is full a.k.a Stack Overflow. Otherwise push into stack.
*/
void push(int value){
	if(top > n-1){
		cout << "Stack Overflow" << endl;
	}
	else{
		top++;
		stack[top] = value;
	}
}

// function for poping from the stack
/*
	if the head or top of the stack is reduced by poping from it, to -1 that means we're done with poping 
	and no other elements in stack is left to pop, which implies the stack is empty a.k.a 
	Stack Underflow. Otherwise pop from stack.
*/
void pop(){
	if(top <= -1){
		cout << "Stack Underflow" << endl;
	}
	else{
		cout << "The popped element is " << stack[top] << endl;
		top--;
	}
}

// function to display the stack elements
/*
	first chack if we've element or not if yes, then start from 0 upto the top and display one by one
*/
void display(){
	if(top >= 0){
		cout << "Stack elements are: ";
		for(int i = 0; i <= top; ++i){
			cout << stack[i] << " ";
		}
		cout << endl;
	}
	else{
		cout << "Stack is empty!" << endl;
	}
}

// the main driver function
int main(){
	
	// choice is the option to enter for specific operation
	// value is the element that we should push into the stack
	int choice, value;
	
	cout << "Enter 1, 2, 3 or 4"
	cout << "1. Push in Stack " << endl;
	cout << "2. Pop from Stack " << endl;
	cout << "3. Display Stack elements " << endl;
	cout << "4. Exit " << endl;

	/*
		- If the user enters 1 we should push into the stack, for this we've to prompt for the element to push.
		and for this call the push function with the value as an argument.
		- If the choice is 2, we should pop from stack and for this call the pop function.
		- If the choice is 3, we should display the stack's elements and for this call the display function.
		- If the choice is 4, we should break out of the loop or say we should exit.
		- If any other choice is entered that is invalid choice and show the warning.
	*/
	do{
		cout << "\nEnter any choice: ";
		cin >> choice;
		switch(choice){
			case 1: {
				cout << "Enter value to be pushed: ";
				cin >> value;
				push(value);
				break;
			}
			case 2: {
				pop();
				break;
			}
			case 3: {
				display();
				break;
			}
			case 4: {
				cout << "Exit" << endl;
				break;
			}
			default: {
				cout << "Invalid choice ;-)" << endl;
				break;
			}
		}
		
	} while(choice != 4);
	
	return 0;
}

