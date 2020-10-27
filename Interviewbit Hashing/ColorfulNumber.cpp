/* A number can be broken into different contiguous sub - subsequence parts.Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different int Solution(int num) */


//Cpp soln 

int Solution::colorful(int num)
{
    
        if (num == NULL)
            return 0;

        int product = 1;
        vector<int> digits;
        while (num > 0)
        {
            digits.insert(digits.begin(), num % 10);  //vector stores digits of the number
            num /= 10;
        }
        int product_of_digits = 1;
        unordered_set<int> present;
        for (int i = 0; i < digits.size(); i++)
        {
            product_of_digits = 1;
            for (int j = i; j < digits.size(); j++)
            {
                product_of_digits *= digits[j];  // product of digits in continuous subsequence
                if (present.find(product_of_digits) != present.end())
                    return 0;
                present.insert(product_of_digits);
            }
        }
        return 1;
    }
    