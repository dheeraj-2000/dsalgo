/* Author - Rahul Pathak */
/*  Bucket sort assumes that the input is drawn from a uniform distribution and has an
average-case running time of O(n).
*/

/* Bucket sort divides the interval [0,1) into n equal-sized subintervals, or buckets,
    and then distributes the n input numbers into the buckets. Since the inputs are uniformly
    and independently distributed over [0,1), we do not expect many numbers
    to fall into each bucket. To produce the output, we simply sort the numbers in each
    bucket and then go through the buckets in order, listing the elements in each. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<float> &A)
{
    vector<float> buckets[A.size()];
    // Putting each element into appropriate bucket
    for (int i = 0; i < A.size(); i++)
    {
        int bucketIndex = A[i] * A.size();
        buckets[bucketIndex].push_back(A[i]);
    }
    // Sorting elements in each bucket
    for (int i = 0; i < A.size(); i++)
        sort(buckets[i].begin(), buckets[i].end());
    int i = 0;
    // Concatenating all the sorted buckets
    for (int j = 0; j < A.size(); j++)
        for (int b = 0; b < buckets[j].size(); b++)
        {
            A[i] = buckets[j][b];
            i++;
        }
}

int main()
{
    vector<float> A = {0.23, 0.2, 0.43, 0.32, 0.128, 0.513, 0.135, 0.16, 0.17, 0.1};
    bucketSort(A);
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << ' ';
    cout << endl;
    return 0;
}