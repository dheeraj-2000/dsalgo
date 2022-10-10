#include<iostream>
#include<string>
#include<vector>
#include <limits.h>
using namespace std;

string LPS(string text)
{
    
    string t="$#";
    for(int i=0;i<text.size();i++)
    {
        t+=text[i];
        t+='#';
    }
    t+='@';
 
    vector<int> p(t.size(),0);
    int mirr,c=0,r=0;
    for(int i=1;i<t.size()-1;i++)
    {
        mirr=2*c-i;
        
        if(i<r)
        {
            p[i]=min(r-i,p[mirr]);
        }
        
        while(t[i+(1+p[i])]==t[i-(1+p[i])])
        p[i]++;
        
        if(i+p[i]>r)
        {
            c=i;
            r=i+p[i];
        }
        
    }
    
    int temp=INT_MIN;
    
    for(int i=0;i<p.size();i++)
    {
        if(p[i]>temp)
        {
            temp=p[i];
            c=i;
            r=p[i]/2;
        }
    }
    
    
    string res="";
    
    for(int i=c-2*r;i<=c+2*r;i++)
    {
        if(t[i]!='#')
        res+=t[i];
    }
    
    return res;
    
}

int main()
{
    
        string s;
        cin>>s;
        cout<< LPS(s) << endl;
    
    return 1;
}