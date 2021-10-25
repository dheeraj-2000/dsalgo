/*
Problem Statement:
Given n wines in a row, with integers denoting the cost of each wine respectively.
Each year you can sell the first or the last wine in the row.
Let the initial profits from the wines be P1, P2, P3…Pn.
In the Yth year, the profit from the ith wine will be Y*P[i].
The goal is to calculate the maximum profit that can be earned by selling all the wines.
*/
#include <iostream>
using namespace std;

int wines_recursive(int arr[], int n, int start, int end)
{
	// base case
	if (start > end)
	{
		return 0;
	}
	// recursive case
	int year = n + start - end;
	return max(arr[start] * (year) + wines_recursive(arr, n , start + 1, end),
	           arr[end] * (year) + wines_recursive(arr, n, start, end - 1));
}

int wines_memo(int arr[], int n, int start, int end, int memo[][100])
{
	// base case
	if (start > end)
	{
		return 0;
	}
	if (memo[start][end] != -1)
	{
		return memo[start][end];
	}
	// recursive case
	int year = n + start - end;
	return memo[start][end] = max(arr[start] * (year) + wines_recursive(arr, n , start + 1, end),
	                              arr[end] * (year) + wines_recursive(arr, n, start, end - 1));
}


int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int memo[100][100];

	memset(memo, -1, 100 * 100 );
	cout << wines_memo(arr, n, 0, n - 1, memo) << endl;
	return 0;
}