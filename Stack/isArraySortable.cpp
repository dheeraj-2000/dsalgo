
/*

Given an array of N distinct elements where elements are between 1 and N both inclusive, check if it is stack-sortable or not. An array A[] is said to be stack sortable if it can be stored in another array B[], using a temporary stack S. The operations that are allowed on array are:

Remove the starting element of array A[] and push it into the stack.
Remove the top element of the stack S and append it to the end of array B.
If all the element of A[] can be moved to B[] by performing these operations such that array B is sorted in ascending order, then array A[] is stack sortable. 
  
  
 */

// C++ implementation of above approach.
#include <bits/stdc++.h>
using namespace std;

// Function to check if A[] is
// Stack Sortable or Not.
bool check(int A[], int N)
{
	// Stack S
	stack<int> S;

	// Pointer to the end value of array B.
	int B_end = 0;

	// Traversing each element of A[] from starting
	// Checking if there is a valid operation
	// that can be performed.
	for (int i = 0; i < N; i++)
	{
		// If the stack is not empty
		if (!S.empty())
		{
			// Top of the Stack.
			int top = S.top();

			// If the top of the stack is
			// Equal to B_end+1, we will pop it
			// And increment B_end by 1.
			while (top == B_end + 1)
			{
				// if current top is equal to
				// B_end+1, we will increment
				// B_end to B_end+1
				B_end = B_end + 1;

				// Pop the top element.
				S.pop();

				// If the stack is empty We cannot
				// further perfom this operation.
				// Therefore break
				if (S.empty())
				{
					break;
				}

				// Current Top
				top = S.top();
			}

			// If stack is empty
			// Push the Current element
			if (S.empty()) {
				S.push(A[i]);
			}
			else
			{
				top = S.top();

				// If the Current element of the array A[]
				// if smaller than the top of the stack
				// We can push it in the Stack.
				if (A[i] < top)
				{
					S.push(A[i]);
				}
				// Else We cannot sort the array
				// Using any valid operations.
				else
				{
					// Not Stack Sortable
					return false;
				}
			}
		}
		else
		{
			// If the stack is empty push the current
			// element in the stack.
			S.push(A[i]);
		}
	}

	// Stack Sortable
	return true;
}

// Driver's Code
int main()
{
	int A[] = { 4, 1, 2, 3 };
	int N = sizeof(A) / sizeof(A[0]);
	check(A, N)? cout<<"YES": cout<<"NO";
	return 0;
}
