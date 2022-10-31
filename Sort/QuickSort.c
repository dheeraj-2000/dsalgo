#include<stdio.h>
#include<time.h>
#include<stdlib.h>

// void sort(int a[],int n)
// {

// }
 void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);

        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);

    swap(&A[l], &A[j]);
    return j;
}
void QuickSort(int A[], int l, int h)
{
    int j;

    if (l < h)
    {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}





void display(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

void reverse(int a[],int n)
{   int temp;
     for(int i=0;i<=n/2;i++)
     {
        temp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1] = temp;
     }
}


int main()
{  int n;srand(time(0));
clock_t start,end;
  printf("enter the size of the array");
  scanf("%d",&n);
  int a[n];
  printf("the array elements before sort \n");
  

    for(int i=0;i<n;i++)
    {
        a[i]=(rand()%60) + 1;  
    }

   // display(a,n);
    printf("\nafter sorting \n");
    start=clock();
    QuickSort(a,0,n);

    // display(a,n);
     end=clock();
    double total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("total time :%fs\n",total);


   start=clock();
    QuickSort(a,0,n);

     //display(a,n);
     end=clock();
    total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("total time :%fs\n",total);


    reverse(a,n);
    //display(a,n);

start=clock();
    QuickSort(a,0,n);

    // display(a,n);
     end=clock();
    total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("total time :%fs\n",total);

    //display(a,n);

  

}
