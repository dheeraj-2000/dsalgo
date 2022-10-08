#include<stdio.h>
int main()
{
int n, temp, i, j, a[30];
printf("Enter how many numbers you want to sort: "); 
scanf("%d",&n);
printf("\nEnter %d numbers:\n",n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<=n-1; i++)
{
for(j=0;j<n-i-1; j++)
{
if(a[j]>a[j+1])
{
temp=a[j+1];
a[j+1]=a[j];
a[j]=temp;
}
}
}
printf("\nSorted elements: ");
for(i=0;i<n;i++)
{
printf(" %d",a[i]);
}
return 0;
}
