#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void maxheapify(int *, int, int);

int* buildmaxheap(int *, int);
void main()
{
    int i, t, n;
	int *a = calloc(MAX, sizeof(int));
    int *m = calloc(MAX, sizeof(int));
    printf("Enter number of elements \n");
    scanf("%d", &n);
    printf("Enter the numbers in array\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    m = buildmaxheap(a, n);
    printf("The heap is\n");
    for (t = 0; t < n; t++) {
        printf("%d\n", m[t]);
    }
}
int* buildmaxheap(int a[], int n)
{
    int heapsize = n;
    int j;
    for (j = n/2; j >= 0; j--) {
        maxheapify(a, j, heapsize);
    }
    return a;
}
void maxheapify(int a[], int i, int heapsize)
{
    int temp, largest, left, right, k;
    left = (2*i+1);
    right = ((2*i)+2);
    if (left >= heapsize)
        return;
    else {
        if (left < (heapsize) && a[left] > a[i]) 
            largest = left;
        else
            largest = i;
        if (right < (heapsize) && a[right] > a[largest])  
            largest = right;
        if (largest != i) {
            temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;
            maxheapify(a, largest, heapsize);
        }
    }
}
