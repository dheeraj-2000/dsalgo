#include <iostream>

using namespace std;

int main()
{ int n=0,i=0,num=0,max=0,pos=0;
    cout<<"\t\tProgram on Linear Search";
    cout<<"\nEnter the size of array : ";cin>>n;
    int a[n];
    cout<<"Enter the array elements :\n";
    for(i=0;i<n;i++)
    {cin>>a[i];}
    cout<<"Enter the search elemnet :";cin>>num;
    max=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==num)
        {
            max=a[i];;
            pos=i+1;
        }
        
    }
    cout<<"Element :"<<max<<"\nfound at position :"<<pos;
    
        return 0;
    }

  
