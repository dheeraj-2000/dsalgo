#include <stdio.h>
void input(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void cartesian(int a[],int b[],int m,int n)
{
	int i,j;
 for(i=0;i<n;i++)
 {
 	for(j=0;j<n;j++)
 	{
 		printf("(%d ,%d)\n",a[i],b[j]);
	 }
 }
}
void main()
{
	int m,n;
	printf("Enter the number of elemeants in first array= ");
	scanf("%d",&m);
	printf("Enter the number of elements in second array= ");
	scanf("%d",&n);
	int a[m],b[n];
	printf("Enter elements in first array ");
	input(a,m);
	printf("Enter elements in second array");
	input(b,n);
	printf("Cartesian Product");
	cartesian(a,b,m,n);
}
