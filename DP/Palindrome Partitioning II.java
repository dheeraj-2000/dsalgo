class Solution {
    int t[][];
    public int minCut(String str) {
        
        t = new int[2001][2001];
        for(int[]row : t){
            Arrays.fill(row,-1);
        }
        
        return solve(str,0,str.length()-1);
    }
    
    int solve(String str,int i, int j){
        if(i>=j){
            return 0;
        }
        
        if(t[i][j] != -1){
            return t[i][j];
        }
        
        //no partitioning if str is already palindromic        
        if(isPalindromic(str,i,j)==true){ 
            return 0;
        }
        
        int min = Integer.MAX_VALUE;
        
        for(int k = i; k<=j-1;k++){
        
/*An Optimization: We will make the partition only if the string till the partition (till Kth position) is a valid palindrome. Because the question states that all partition must be a valid palindrome. If we dont check this, we will have to perform recursion on the left subproblem too (solve(str, i, k)) and	we will waste a lot of time on subproblems that is not required. Without this the code will give correct answer but TLE on big test cases. */
            
        if(isPalindromic(str, i, k)){
            int partitions = 1+solve(str, k+1, j);
            
            min = Math.min(min, partitions);                
        }
    }
        
        t[i][j] = min;
        return min;
        
    }
    
    boolean isPalindromic(String str, int i, int j){
        if(i==j){
            return true;
        }
        
        
        while(i<j){
            if(str.charAt(i) != str.charAt(j)){
                return false;
            }
            
            i++;
            j--;
        }
        return true;
    }
}