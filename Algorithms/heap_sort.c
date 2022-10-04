#include <stdio.h>  
 
void heapify(int a[], int n, int i)  
{  
    int largest = i; 
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 
    
    // If left child is larger than root  
    if (left < n && a[left] > a[largest])  
        largest = left;  
        
    // If right child is larger than root  
    if (right < n && a[right] > a[largest])  
        largest = right;  
        
    // If root is not largest  
    if (largest != i) {  
        // swap a[i] with a[largest]  
        int temp = a[i];  
        
        a[i] = a[largest];  
        a[largest] = temp;  
          
        heapify(a, n, largest);  
    }  
}  





void heapSort(int a[], int n)  
{  
    for (int i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);  
    
    for (int i = n - 1; i >= 0; i--) {  
       
        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
          
        heapify(a, i, 0);  
    }  
}  

void printArr(int arr[], int n)  
{  
    for (int i = 0; i < n; ++i)  
    {  
        printf("%d", arr[i]);  
        printf(" ");  
    }  
          
}  
int main()  
{  
    int a[] = {55, 9, 21, 42, 28, 16, 19};  
    int n = sizeof(a) / sizeof(a[0]);  
    printf("Before sorting  - \n");  
    printArr(a, n);  
    heapSort(a, n);  
    printf("\nAfter sorting - \n");    
    printArr(a, n);  
    return 0;  
}  
