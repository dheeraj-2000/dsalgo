#include<bits/stdc++.h>
using namespace std;
#define dec_var ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int t,n,sum,mx,mn;
int main()
{
    dec_var
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        mx=-1;
        mn=7;
        for(int i=0;i<n;i++)
        {
            bool m[n]={0};
            m[i]=1;

            for(int j=i;j<n;j++)
            {
                if(a[i]>a[j])
                m[j]=(m[i] | m[j]);
            }

            for(int j=i;j>=0;j--)
            {
                for(int k=i;k<n;k++)
                {
                    if(a[j]>a[k])
                    {
                        m[j] |=m[k];
                        m[k] |=m[j];
                    }
                }
            }
            sum =0;
            for(int j=0;j<n;j++)
            {
                sum+m[j];
            }
            if(sum>mx)
            mx=sum;
            if(sum<mn)
            mn=sum;
        }
        cout<<mn<<" "<<mx<<endl;
    }
    return 0;
}
