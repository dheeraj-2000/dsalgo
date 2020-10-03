/* Author - Rahul Pathak */
/*  We assume that each of the n input elements is an integer in the range
    0 to k, for some integer k. When k = O(n) the sort runs in bigTheta(n) time.

    Counting sort determines, for each input element x, the number of elements less
    than x. It uses this information to place element x directly into its position in the
    output array.
*/

#include <iostream>
#include <vector>
using namespace std;

int findMaxElement(vector<int> A)
{
    int maximum = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        maximum = max(maximum, A[i]);
    }
    return maximum;
}
int findMinElement(vector<int> A)
{
    int minimum = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        minimum = min(minimum, A[i]);
    }
    return minimum;
}

void countingSort(vector<int> &A)
{
    int max = findMaxElement(A);
    int min = findMinElement(A);
    // Setting the range allows us to map the smallest element to index 0
    // irrespective of it being negative/positive or zero.
    int range = max - min + 1;
    int count[range] = {0}, temp[A.size()];

    // Storing the frequency of every element at the mapped index
    for (int i = 0; i < A.size(); i++)
        count[A[i] - min]++;

    // Storing the number of elements that occur before the
    // current element in the sorted array
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Placing each element at the correct location
    for (int i = A.size() - 1; i >= 0; i--)
    {
        temp[count[A[i] - min] - 1] = A[i];
        count[A[i] - min]--;
    }

    for (int i = 0; i < A.size(); i++)
        A[i] = temp[i];
    return;
}

int main()
{
    vector<int> A = {23, -2, 43, -32, 8, 13, -5, 16, 17, 1};
    countingSort(A);
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << ' ';
    cout << endl;
    return 0;
}