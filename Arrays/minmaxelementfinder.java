import java.util.*;
import java.lang.*;
import java.io.*;

/*Math.pow() is import using java.lang package*/
class Main
{ 
  
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
    System.out.print("Enter the number :");
    int n = sc.nextInt();
    int []a = new int[n];
    int i=0,temp=0,j=0;
    System.out.print("Enter the array Element :");
    for(i=0;i<n;i++)
  {
    a[i] = sc.nextInt();
  }
  int max=0;
  for(i=0;i<n;i++)
  {
    if(max<a[i])
    {max=a[i];}
  }int min=a[0];
  for(i=0;i<n;i++)
  {
    if(min>a[i])
    {min=a[i];}
  }
    System.out.println("Smallest Element in array :"+min);
		System.out.println("Largest Element in array :"+max);

}}
