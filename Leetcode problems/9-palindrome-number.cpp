//9. Palindrome Number
//Given an integer x, return true if x is palindrome integer.
//An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

class Solution {
public:
    bool isPalindrome(int x) {
      //copy x into string
        string original_str = std::to_string(x);
      //make a reverse string
        string reverse_str;
      //add chars from x string to reverse str in reverse order
        for(int i=original_str.length()-1; i>=0; i--)
        {
            reverse_str += original_str[i];
        }
      //if strings are equal they are palindrome
        if(original_str == reverse_str)
            return true;
        return false;
    }
};
