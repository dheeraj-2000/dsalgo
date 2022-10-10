#include<stdio.h>
void main()
{
int i,j,n;
  
printf("Enter no of elements in array\n");
  
scanf("%d",&n);
  
//declaring integer array
int int_array[n];
  
printf("Enter the numbers in array\n");
  
for(i=0;i<n;i++)
{
      scanf("%d", &int_array[i]);
  
  if(i == n-1)
  {
       for(int j = 0; j < n; j++)
       {
            printf("%d", int_array[i]);
       }
  }
  
}
  
  

}
