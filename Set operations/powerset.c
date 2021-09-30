/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h> 
#include <math.h> 
void display(int set_A[],int x)
{
    
    for(int i=0;i<x;i++)
    {
    printf(" %d ",set_A[i]);
    }
}
void input(int set_A[],int x)
{
    for(int i=0;i<x;i++)
    { 
        printf("\n Enter %d element =",i+1);
        scanf("%d",&set_A[i]);
    }
}
void sort(int set[],int x)
{
    int i,j,temp;
    for(i=0;i<x;i++)
    {
        for(j=i+1;j<x;j++)
        {
            if(set[i]>set[j])
            {
                temp=set[j];
                set[j]=set[i];
               set[i]=temp;
            }
        }
    }
}
void Powerset(int set[], int n) 
{ 

    int m = pow(2, n); 
    int i, j; 
 
    for(i = 0; i< m; i++) 
    { 
        printf("Subset %d = ",i+1);
      for(j = 0; j < n; j++) 
       {
          if(i & (1<<j)) 
            printf("%d ", set[j]); 
       } 
       printf("\n"); 
    } 
} 
int main() 
{ 
    int n;
    printf("Enter the number of element=");
    scanf("%d",&n);
    int set[n];
    printf("Enter the elements of set");
    input(set,n);
    sort(set,n);
    printf("Elements of set are = ");
    display(set,n);
    printf("\n");
    Powerset(set,n);
    
    return 0; 
}