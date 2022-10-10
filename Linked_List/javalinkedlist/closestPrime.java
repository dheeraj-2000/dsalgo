//This code is about finding the Distance between the user given input number and its closest prime numner.
// Example: distance between the number 16 and its closest prime number 17 is 1.So input will be 16 output will be 1.
//similary distance between the number 23 and its closest prime number 23 is 0.So input will be 23 output will be 0.


//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class closestPrime
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int N = Integer.parseInt(br.readLine().trim());
            Solution ob = new Solution();
            int ans = ob.NthTerm(N);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    //here n is number user inputs
    public boolean isPrime(int n)
        {
            if (n <= 1)
                return false;
     
            // Check if n=2 or n=3
            if (n == 2 || n == 3)
                return true;
     
            // Check whether n is divisible by 2 or 3
            if (n % 2 == 0 || n % 3 == 0)
                return false;
     
            // Check from 5 to square root of n
            // Iterate i by (i+6)
            for (int i = 5; i <= Math.sqrt(n); i = i + 6){
                if (n % i == 0 || n % (i + 2) == 0)
                    return false;
            }
            return true;
        }
    public int NthTerm(int N)
    {
        // code here
        int minDiff=0;
        //to check if given number is 1 or not
        if(N==1){
            minDiff=1;
            return minDiff;
        } 
        //to check if given number is prime or not then diff is 0
        if(isPrime(N)){
            minDiff=0;
            return minDiff;
        }
        //two variables 
        //a) lowerPrime to traverse to N-1,N-2,N-3....numbers 
        //b) higherPrime to traverse to N+1,N+2,N+3....numbers 
        int lowerPrime=N;
        int higherPrime=N;
        
        // !isPrime to reach the closest prime
        //stop the while loop as soon as a prime number is encountered
        while(!isPrime(higherPrime)){
            higherPrime++;
        }
        while(!isPrime(lowerPrime) && lowerPrime>0){
            lowerPrime--;
        }
        //check the min difference using Math.min and subtracting the lowerPrime from N
        //and subtracting N from higherPrime
        minDiff=Math.min((N-lowerPrime),(higherPrime-N));
        
        return minDiff;
    }
    
}