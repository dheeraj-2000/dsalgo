class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int one = arr[1] - arr[0];
        int two = arr[2] - arr[1];
        int cd;
        int ans;
        //one > two ? return one: return two;
        if (abs(one)>abs(two))
                 cd=two;

        else
            cd = one;

   /* for(int i=0; i<arr.size();i++){
            if(arr[i]==0)
                ans = arr[0];
            if(arr[i] != arr[0]+i*cd)
                 ans = arr[i-1]+cd;
               }*/

        for (int i=0; i < arr.size ()-1; i++) {
            if(arr[i]==0)
                ans = arr[0];
            if (arr [i+1] - arr [i] == cd)
                continue;
            else {
                ans = arr [i] + cd;
                break;
            }
        }



        return ans;
}

};
