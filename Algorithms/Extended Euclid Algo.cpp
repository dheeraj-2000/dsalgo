#include <bits/stdc++.h>
using namespace std;

struct triplet {
    int x,y,gcd;
};

triplet extendedEuclid1(int a, int b) {
    if(b == 0) {
        triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        
        return ans;
    }
    
    triplet smallAns = extendedEuclid1(b,a%b);
    
    triplet ans;
    ans.x = smallAns.y;
    ans.y = smallAns.x - floor(a/b)*smallAns.y;
    ans.gcd = smallAns.gcd;
    
    return ans;
}

int extendedEuclid2(int a, int b, int& x, int& y) { // without using struct, and this function will return 
//GCD of a and b but will change the values of x and y at their respective addresses
    
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    int x1,y1;
    int gcd = extendedEuclid2(b ,(a%b) , x1, y1);
    
    x = y1;
    y = x1 - floor(a/b)*y1;
    
    return gcd;
    
}

int main()
{
   int a,b; 
   cin >> a >> b;
   
//   triplet ans = extendedEuclid(a,b);
//   cout<<ans.x<<' '<<ans.y<<' '<<ans.gcd<<"\n";

    int x,y;
    int gcd = extendedEuclid2(a, b, x, y);
    cout<<x<<' '<<y<<' '<<gcd<<"\n";
   
   return 0;
}

/*
While the Euclidean algorithm calculates only the greatest common divisor (GCD) of two integers a and b, 
the extended version also finds a way to represent GCD in terms of a and b, i.e. coefficients x and y for which:
a⋅x+b⋅y=gcd(a,b)

It's important to note, that we can always find such a representation, for instance gcd(55,80)=5
therefore we can represent 5 as a linear combination with the terms 55 and 80: 55⋅3+80⋅(−2)=5

A more general form of that problem is discussed in the article about Linear Diophantine Equations. It will build upon this algorithm.


Algorithm:

We will denote the GCD of a and b with g in this section.
The changes to the original algorithm are very simple. If we recall the algorithm, we can see that the algorithm ends with b=0
and a=g. For these parameters we can easily find coefficients, namely g⋅1+0⋅0=g.
Starting from these coefficients (x,y)=(1,0), we can go backwards up the recursive calls. All we need to do is to figure out how the 
coefficients x and y change during the transition from (a,b) to (b,a%b).

Let us assume we found the coefficients (x1,y1) for (b,a%b): b⋅x1+(amodb)⋅y1=g
and we want to find the pair (x,y) for (a,b): a⋅x+b⋅y=g
We can represent a%b as:
a%b=a−⌊a/b⌋⋅b

Substituting this expression in the coefficient equation of (x1,y1) gives:
g=b⋅x1+(amodb)⋅y1=b⋅x1+(a−⌊ab⌋⋅b)⋅y1
and after rearranging the terms:
g=a⋅y1+b⋅(x1−y1⋅⌊ab⌋)

We found the values of x and y:
{x=y1y=x1−y1⋅⌊ab⌋
*/