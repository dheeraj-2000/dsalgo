class Solution {
    public int lengthOfLIS(int[] nums) {
        int l=nums.length;
        if(l==1)
            return 1;
        if(l==2)
            if(nums[0]<nums[1])
                return 2;
            else
                return 1;
        int dp[] = new int[l];
        int i,j;
        //Since base case is 1 for individual considerations
        for(i=0;i<l;i++)
            dp[i]=1;
        /*
        For each element starting from index 1, consider subarrays till that from 0. Check for each element if it follows the rule
        (NOTE: similar approach for non-decreasing,Decreasing etc). If yes look for max of the current value or the new appended value
        */
        for(i=1;i<l;i++)
        {
            for(j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=Math.max(dp[j]+1,dp[i]);
                }
            }
            /*for(int k: dp)
                System.out.print(k);
            System.out.println();*/
        }
        /*
        Time complexity is O(n^2)
        Space complexity is O(n)
        */
        return Arrays.stream(dp).max().getAsInt();
        
    }
}
