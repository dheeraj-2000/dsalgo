#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {

        int num1, num2;

        size_t start1 = 0;
        size_t pos1 = version1.find(".", start1);

        size_t start2 = 0;
        size_t pos2 = version2.find(".", start2);

        // Initialze nums if they don't have dots
        if (pos1 == string::npos)
            num1 = stoi(version1);
        if (pos2 == string::npos)
            num2 = stoi(version2);

        // We loop till we reach the end to both strings
        while (pos1 != string::npos || pos2 != string::npos)
        {
            // If the end of a string is not reached, compare the numbers
            // If end is reached, indicated by start becoming string::npos
            if (pos1 != string::npos)
            {
                num1 = stoi(version1.substr(start1, pos1 - start1));
            }

            if (pos2 != string::npos)
            {
                num2 = stoi(version2.substr(start2, pos2 - start2));
            }

            if (start1 == version1.length() - 1)
                num1 = stoi(version1.substr(start1, version1.length() - start1));
            if (start2 == version2.length() - 1)
                num2 = stoi(version2.substr(start2, version2.length() - start2));

            // Compare the numbers
            // If num1 < num2 => version1 is lesser than version2
            if (num1 < num2)
                return -1;
            else if (num1 > num2)
                return 1;
            else
            {
                // If numbers are equal, we move forward

                // If end of a string is reached, make the default digit for it 0 as any number greater than
                // it from now in the other string would mean that that string has a higher version number
                if (pos1 == string::npos)
                {
                    num1 = 0;
                    start1 = string::npos;
                }
                // If end is not reached, we move forward
                if (pos1 != string::npos)
                {
                    start1 = pos1 + 1;
                    pos1 = version1.find(".", start1);
                }

                if (pos2 == string::npos)
                {
                    num2 = 0;
                    start2 = string::npos;
                }
                if (pos2 != string::npos)
                {
                    start2 = pos2 + 1;
                    pos2 = version2.find(".", start2);
                }
            }
        }

        // We come out of the loop only when we reach the end of both strings
        // We can find out which string we ended with last by checking start  variable
        size_t curr;
        string str;

        if (start1 == string::npos)
        {
            curr = start2;
            str = version2;
        }
        else if (start2 == string::npos)
        {
            curr = start1;
            str = version1;
        }
        else
        {
            // If neither of the start variables are string::npos, it means that the versions are of the
            // same length, and that we just have to compare the last digits
            int n1 = stoi(version1.substr(start1, version1.length() - start1));
            int n2 = stoi(version2.substr(start2, version2.length() - start2));

            if (n1 > n2)
                return 1;
            else if (n1 < n2)
                return -1;
            else
                return 0;
        }

        // If they have different lengths, then compare the last digit of the longer version
        // with 0, as the only reason we reached till here is because the previous digits were
        // all equal
        int n = stoi(str.substr(curr, str.length() - curr));

        if (n)
        {
            if (curr == start1)
                return 1;
            else
                return -1;
        }

        return 0;
    }
};