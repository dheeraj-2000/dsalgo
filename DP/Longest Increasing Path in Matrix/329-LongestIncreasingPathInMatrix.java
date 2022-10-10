//Question Link : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/


class Solution {
    int[][] dis = {{1,0},{-1,0},{0,1},{0,-1}};
    public int longestIncreasingPath(int[][] matrix) {
        //base case
        if(matrix.length == 0 ){
            return 0;
        }
        
        int[][] state = new int[matrix.length][matrix[0].length];
        int res = 0;
        
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                res = Math.max(res,dfs(i,j,matrix,state));
            }
        }
    
        return res;
    }
  
    public int dfs(int i, int j, int[][] matrix,int[][] state){
        if(state[i][j] > 0){
            return state[i][j];
        }
        
        int max = 0;
        
        for(int m = 0; m < dis.length; m++){
            if(i + dis[m][0] >= 0 && i + dis[m][0] < matrix.length && j + dis[m][1] >= 0 && j + dis[m][1] < matrix[0].length && matrix[i+dis[m][0]][j+dis[m][1]] > matrix[i][j]){
                max = Math.max(max,dfs(i + dis[m][0],j + dis[m][1],matrix,state));
          }
      }
        
        state[i][j] = 1 + max;
      
        return state[i][j];
    }
}
