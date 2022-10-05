class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # Length of two given strings
        
        len_1 = len(text1)
        len_2 = len(text2)
        
        # If any of the two strings is empty
        
        if len_1 == 0 or len_2 == 0:
            return 0
        
        else:
            # Logic for Longest Common Subsequence
            dp = [[0 for columns in range(len_2+1)]for rows in range(len_1+1)]
            for row in range(1, len_1+1):
                for column in range(1, len_2+1):
                    if text1[row-1] == text2[column-1]:
                        dp[row][column] = 1+dp[row-1][column-1]
                    else:
                        dp[row][column] = max(dp[row][column-1], dp[row-1][column])
        return (dp[len_1][len_2])
