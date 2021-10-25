#include<stdio.h>
void main()
{
int i,j,n;
printf("Enter no of elements in array\n");
scanf("%d",&n);
int arr[n];
printf("Enter the numbers in array\n");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
for(i=0;i<n;i++)
printf("%d\t",arr[i]);
}
