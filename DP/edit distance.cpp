/* 
  A Dynamic Programming based C++ solution to find minimum
  number of operations to convert str1 into str2, or the 
  Edit/Levenshtein Distance between the two strings.
  m and n are the number of characters in str1 and str2 respectively.
  Complexity: time O(mn), space O(mn)

  Obs: since we don't need to keep the whole matrix to do the
  necessary comparisons, the space complexity may still be reduced,
  but the way presented here is an easier approach to understand
*/

#include <iostream>

using namespace std;

// Utility function to find minimum of three numbers 
int min(int x, int y, int z) { 
    return min(min(x, y), z); 
}

int editDist(string str1, string str2, int m, int n) {

    int dp[m+1][n+1];

    // Base cases: when one string is empty (size 0), the only
    // option is to insert/remove all characters of the other
    // string, resulting in a number of operations equivalent
    // to the size of that string
    for (int i=0; i<m; i++)
        dp[i][0] = i; // Remove all characters of str1
    for (int j=0; j<n; j++)
        dp[0][j] = j; // Insert all characters of str2

    // Fill dp[][] (bottom up)
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            // If equal letters, cost is same as previous pair
            if (str1[i-1] == str2[j-1]) 
                dp[i][j] = dp[i-1][j-1];
            // Otherwise get min cost of the possible operations
            // considering the current operation (+1)
            else
                dp[i][j] = 1 + min(dp[i][j-1],    // Insert
                                   dp[i-1][j],    // Remove
                                   dp[i-1][j-1]); // Replace
        }
    }

    return dp[m][n];
}

// Main function for testing
int main() {
    string str1, str2;

    cout << "Enter first string\n";
    cin >> str1;
    cout << "Enter second string\n";
    cin >> str2;

    cout << EditDist(str1, str2, str1.length(), str2.length());
}