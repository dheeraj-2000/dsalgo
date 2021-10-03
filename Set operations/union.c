/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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

int union_fun(int set_A[],int set_B[],int union_set[])
{
    int i=0,j=0,k=0;
    while((i<limit)&&(j<limit))
    {
        if(set_A[i]<set_B[j])
        {
            union_set[k]=set_A[i];
            i++;
            k++;
        }
        else if(set_A[i]>set_B[j])
        {
            union_set[k]=set_B[j];
            j++;
            k++;
        }
        else 
        {
            union_set[k]=set_A[i];
            i++;
            j++;
            k++;
        }
    }
    if(i==limit)
    {
        while(j<limit)
        {
            union_set[k]=set_B[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<limit)
        {
            union_set[k]=set_A[i];
            i++;
            k++;
        }
    }
    return(k);
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

int main()
{
    int set_A[limit], set_B[limit],union_set[limit*2];
    int n;
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
    n=union_fun(set_A,set_B,union_set);
    printf("\nUnion Set:\n");
    display(union_set,n);
    return 0;
}
