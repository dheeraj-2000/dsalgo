#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll countcows(vector<ll> a,ll b)
{
    ll index=0,co=1;
    for(ll i=1;i<a.size();i++)
    {
        if((a[index]+b)<=a[i])
        {
            index=i;
            co++;
        }
    }
    return co;
}
int main()
{

    ll t=-1;
    cin>>t;
while(t--)
{ ll n,c,co=0,ans=0,start,finish;
cin>>n>>c;

   vector<ll> v(n);
   for(ll i=0;i<n;i++)
   {
       cin>>v[i];
   }
   sort(v.begin(),v.end());
start=v[0];
finish=v[n-1];
  while(start<=finish)
  {
      ll mid=(start+finish)/2;
      co=countcows(v,mid);

      if(co>=c)
      {start=mid+1;
      ans=mid;
      }
      else
        finish=mid-1;
  }
  cout<<ans<<"\n";
}

return 0;
}
