/* Given a number n, the task is to find out whether this number is smith or not. A Smith Number is a composite number whose sum of 
digits is equal to the sum of digits in its prime factorization.

Input   : n = 666
Output  : YES, it is a smith number
Prime factorization = 2, 3, 3, 37 and
2 + 3 + 3 + (3 + 7) = 6 + 6 + 6 = 18
Therefore, 666 is a smith number

Input  : n = 6
Output : NO, it isn't a smith number
Prime factorization = 2, 3  and 2 + 3 is
not 6. Therefore, 6 is not a smith number

code by iamkakashi
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX  = 10000;
  
vector <int> primes;
  

void sieve()
{
    
    bool marked[MAX/2 + 100] = {0};
  
    
    for (int i=1; i<=(sqrt(MAX)-1)/2; i++)
        for (int j=(i*(i+1))<<1; j<=MAX/2; j=j+2*i+1)
            marked[j] = true;
  
    
    primes.push_back(2);
  
    
    for (int i=1; i<=MAX/2; i++)
        if (marked[i] == false)
            primes.push_back(2*i + 1);
}
bool issmith(int n)
{
    int num = n;
  
   
    int digitsum = 0;
    for (int i = 0; primes[i] <= n/2; i++)
    {
        while (n % primes[i] == 0)
        {
            
            int p = primes[i];
            n = n/p;
            while (p > 0)
            {
                digitsum += (p % 10);
                p = p/10;
            }
        }
    }
  
    
    if (n != 1 && n != num)
    {
        while (n > 0)
        {
            digitsum = digitsum + n%10;
            n = n/10;
        }
    }
  
    
    int sumDigits = 0;
    while (num > 0)
    {
        sumDigits = sumDigits + num % 10;
        num = num /10;
    }
  
   
    return (digitsum == sumDigits);
}

int main(){
    int n;
    cin>>n;
    sieve();
    if(issmith(n)){
        cout<<"YES, it is a smith number"<<endl;
    }
    else{
        cout<<"NO, it isn't a smith number"<<endl;
    }
}