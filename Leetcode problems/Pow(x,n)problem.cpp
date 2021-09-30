//Link to problem:https://leetcode.com/problems/powx-n/
class Solution {
    
    double pow(double x,int n){
        if(n==0){
            return 1;
        }
        double temp=pow(x,n/2);
        if(n%2==0){
            return temp*temp;
        }
        else{
            return x*temp*temp;
        }
    }
    
public:
    double myPow(double x, int n) {
        if(n<0){
            return 1/pow(x,n);
        }else{
          return pow(x,n);   
        }
       
    }
};