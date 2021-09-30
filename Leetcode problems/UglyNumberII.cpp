//Problem Link :https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3380/

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(1, 1);
        // Intiliaze with 1
        n -= 1;
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        int nextNum = 0;
        // Multiply the ugly number with 2,3,5

        while (n--)
        {
            int num2 = dp[index2] * 2;
            int num3 = dp[index3] * 3;
            int num5 = dp[index5] * 5;
            //Minimun to get sorted List
            nextNum = min({num2, num3, num5});

            // Multiply the next ugly number with 2,3,5, thus ensuring that nextNum is also ugly
            if (nextNum == num2)
            {
                index2++;
            }
            if (nextNum == num3)
            {
                index3++;
            }
            if (nextNum == num5)
            {
                index5++;
            }
            dp.push_back(nextNum); //vector dp contains only ugly numbers as it is the previous Ugly number multiplied by either 2, 3 or 5
        }
        return dp.back();//last number of dp is nth Ugly Number
    }
};
