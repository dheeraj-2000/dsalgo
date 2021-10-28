class Solution
{
public:
    void sortColors(vector<int> &nums)
    {

        //1. sort()
        //2. count 0, 1, 2
        //         int n = nums.size();
        //         int zero = 0, one = 0;

        //         for(int i=0;i<n;i++)
        //             if(nums[i] == 0)
        //                 zero++;
        //             else if(nums[i] == 1)
        //                 one++;

        //         int i = 0;
        //         while(zero--)
        //             nums[i++] = 0;

        //         while(one--)
        //             nums[i++] = 1;

        //         while(i<n)
        //             nums[i++] = 2;

        //3. l,mid,r
        int n = nums.size();
        int l = 0, mid = 0, r = n - 1;

        while (mid <= r)
        {
            if (nums[mid] == 0)
            {
                swap(nums[l], nums[mid]);
                mid++, l++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }

            else
            {
                swap(nums[r], nums[mid]);
                r--;
            }
        }
    }
};