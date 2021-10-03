#include <stdio.h>
#define limit 5
void input_elements(int set_A[])
{
    for(int i=0;i<limit;i++)
    scanf("%d",&set_A[i]);
}
void display(int set_A[],int x)
{
    for(int i=0;i<x;i++)
    printf(" %d ",set_A[i]);
}
void arraysum(int set_A[],int set_B[],int set_c[],int x,int y)
{
    int j=0;
    for(int i=0;i<x;i++)
    {
        set_c[j]=set_A[i];
        j++;
    }
    for(int i=0;i<y;i++)
    {
        set_c[j]=set_B[i];
        j++;
    }
}
void sort_set(int set[])
{
    int i,j,temp;
    for(i=0;i<limit;i++)
    {
        for(j=i+1;j<limit;j++)
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
int diff_fn(int set_A[],int set_B[],int diff_set1[])
{ 
    int i,j,k=0,c;
    for(i=0;i<limit;i++)
    {
        c=0;
        for(j=0;j<limit;j++)
        {
          if(set_A[i]==set_B[j])  
          {
              c=1;
              break;
          }
        }
        if(c==0)
        {
            diff_set1[k]=set_A[i];
            k++;
        }
    }
    return k;
}
int main()
{
     int set_A[limit],set_B[limit],diff_set1[limit],diff_set2[limit],sdiff_set[2*limit];
    int n,m;
    printf("\nEnter elements of Set A \n");
    input_elements(set_A);
    printf("\nEnter elements of Set B\n");
    input_elements(set_B);
    printf("\nElements of set A :\n");
    display(set_A,limit);
    printf("\nElements of set B:\n");
    display(set_B,limit);
    sort_set(set_A);
    sort_set(set_B);
    n=diff_fn(set_A,set_B,diff_set1);
    m=diff_fn(set_B,set_A,diff_set2);
    arraysum(diff_set1,diff_set2,sdiff_set,n,m);
    sort_set(sdiff_set);
    printf("\nSymmetric Difference set\n");
    display(sdiff_set,n+m);
    return 0;
}