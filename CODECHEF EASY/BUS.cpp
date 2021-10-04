// question :- https://www.codechef.com/START9C/problems/BUS/
#include <bits/stdc++.h>
using namespace std;


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,m,q;
       cin>>n>>m>>q;
       unordered_set<int>us;
       int f=1;
       while(q>0)
       {
           char c;
           int i;
           cin>>c>>i;
           if(f==1)
           {
               if(c=='-')
               {
                   if(us.find(i)!=us.end())
                   {
                       us.erase(i);
                   }
                   else{
                       f=0;
                   }
               }
               else{
                   if((int)us.size()==m)
                   {
                       f=0;
                   }
                   else{
                       us.insert(i);
                   }
               }
           }
           q--;
       }
       if(f==0)
       {
           cout<<"Inconsistent"<<endl;
       }
       else{
           cout<<"Consistent"<<endl;
       }
   }

    return 0;
}
