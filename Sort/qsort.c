#include <stdio.h>
typedef long  long int ll;
void swap(ll *x, ll *y)
{
    ll temp = *x;
    *x = *y;
    *y = temp;
}
ll qpartition(ll A[], ll low, ll high)
{
    ll p = low; //pivot
    ll i = low, j = high;
    do
    {
        do
        {

            i++;
        } while (A[i] <= A[p]);

        do
        {
            j--;
        } while (A[j] > A[p]);

        if (i < j)
            swap(&A[i], &A[j]);

    } while (i < j);

    swap(&A[j], &A[p]);
    return j;
}

void quickSort(ll A[], ll low, ll high)
{
    ll p;
    if (low < high)
    {
        p = qpartition(A, low, high);
        quickSort(A, low, p);
        quickSort(A, p + 1, high);
    }
}
