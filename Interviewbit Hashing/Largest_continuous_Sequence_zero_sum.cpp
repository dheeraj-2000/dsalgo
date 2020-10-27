/*Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. 
*/

vector<int> Solution::lszero(vector<int> &arr) {
    
    
    unordered_map<int, int> sumtillnow;  // key: sum till ith index , value: index
    int sum = 0;
    int len =0, maxlen =0;
    int start =-1, end =-1;
    sumtillnow[0] = -1;
    
    for(int i =0; i < arr.size(); i++){
       sum += arr[i];
       if(arr[i] == 0 && maxlen == 0)
         { maxlen = 1;
          start = i;
          end = i;}
        if(sum == 0)
        {
            if(i+1 > maxlen)
            {  maxlen = i+1;
                start = 0;
                end = i;
            }
            
        }
        //if a sum occurs previously in the map i.e  there is a sequence summing upto 0 in the array b/w previous occurence of sum and current occurence 
       if(sumtillnow.find(sum) != sumtillnow.end())  
       {   len = i - sumtillnow[sum];
           if(len > maxlen)
           {   maxlen = len;
               start = sumtillnow[sum]+1 ;
               end  =i;
           }
       }
       else
       sumtillnow[sum] = i;}  // store the index corresponding to its sum
vector<int> v;
if(start == -1 && end == -1)
return v;

    for(int i =start; i <= end; i++)
    v.push_back(arr[i]);
    return v;
    
    
    
}

