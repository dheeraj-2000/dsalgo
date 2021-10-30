//leetcode
//1342
//Number of Steps to Reduce a Number to Zero



class Solution {
public:
    
    int helper(int num, int count)
    {
        if(num==0)
            return count;
        if(num%2==0)
          return  helper(num/2,count+1);
        
        return helper(num-1,count+1);
    }
    int numberOfSteps(int num) {
       /* int res=0;
        while(num)
        {
            if((num & 1)==0)
               num>>=1;
           
            else
                num-=1;
               
            
         ++res;
                
        }
        return res;
        */
       
       return helper(num,0);
    }
};