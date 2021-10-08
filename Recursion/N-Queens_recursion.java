/*Problem Statement:
1. You are given a number n, the size of a chess board.
2. You are required to place n number of queens in the n * n cells of board such that no queen can kill another.
Note - Queens kill at distance in all 8 directions
3. Complete the body of printNQueens function - without changing signature - to calculate and print all safe configurations of n-queens. 
Use sample input and output to get more idea.

Sample Input
4
Sample Output
0-1, 1-3, 2-0, 3-2, .
0-2, 1-0, 2-3, 3-1, .
*/

/*Approach :

We have to keep in mind the following 4 conditions:

1. No 2 Queens can be in the same row
2. No 2 Queens can be in the same column
3. No 2 Queens can be in the left diagonal
4. No 2 Queens can be in the right diagonal
Since,

No 2 queens can be in the same row
There are n queens and n rows
It implies that each row will contain exactly one queen.

Thus, we will consider taking a decision for a given row at a given depth of recursion tree, i.e. we will try to place a queen in the ith row at the ith height/level of the recursive tree. 
(We will place the queen in 1st row at first level, 2nd row at second level and so on).

But, what will be the decisions to take at ith level (for the ith row). It will be to place the queen in which column. 
In the ith row, we will try to place the queen in any of the columns.

Till now, we have discovered:

Level (node in recursion tree) corresponds to choosing a row in grid
Decision (edge in recursion tree) corresponds to choosing a column in the given row.
But, how is writing conditions for nodes different from edges? We will try to learn the concept of node-pre, node-post, edge-pre, and edge-post, using the following code snippet:

In the recursion tree, we will find the correct spots of node-pre, node-post, edge-pre and edge-post.

Node-pre will be the statement in the starting of the for loop (for taking decisions/edges), node-post will be the statement after the end of the for loop.
Edge-pre is the statement before calling for the next level/depth, and similarly edge-post is the statement after returning from the next level/depth.
We need to try for all columns in a given row, but will all the columns give valid configuration?

No, until now, we have fulfilled the first condition for valid configuration, i.e. no 2 queens in the same row. But to check the remaining three conditions, 
we need to keep track of all the queens which we have placed so far, and apply some logic to check whether we can place them in the current column for the given row or not.

Hence, we need to check whether the column in which we are trying to place the queen is occupied by any of the queens in the previous rows or not. 
And similarly for the left diagonal and the right diagonal.

We will mark the cell in which the queen is placed by 1 before going to the next level, i.e. in the edge-pre statement. 
But after returning from the next level, we must remember to remove the queen from that cell back, i.e. make the cell empty (= 0) in the edge-post statement.

Edge - Pre statement is chess[row][col] = 1;
Edge - Post statement is chess[row][col] = 0;
We will make a recursive call only if the current column represents valid configuration (satisfy conditions 2,3 and 4). 
Similar to rows, since there are n columns and no 2 queens can be placed in the same column, hence there must be exactly 1 queen in each column, 
and same goes for left diagonal and right diagonal as well.

Let us write the code to check if the current cell holds conditions 2, 3 and 4 as well or not.

We will check for all cells along the following 3 directions to check if there is any queen already placed or not (chess[i][j] = 1) or not. 
We will run three loops, one for each path/direction and return false if any of the cell is occupied else return true.

Now, the only condition left is the base case?

It will occur when we are able to place queens in all the rows, i.e. the current row becomes greater than the number of rows of the table. 
Hence we will print the current configuration and return.
*/



import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        
        int[][] chess = new int[n][n];
        printNQueens(chess,"",0);
    }

    public static void printNQueens(int[][] chess, String qsf, int row) {
        if(row==chess.length)
        {
            System.out.println(qsf+".");
            return;
        }
        
        for(int col=0;col<chess.length;col++){
            if(isItaSafePlaceForTheQueen(chess,row,col)==true){
                chess[row][col] = 1;
                printNQueens(chess, qsf+row+"-"+col+", ", row+1);
                chess[row][col] = 0;
            }
            
        }
    }
    
    public static boolean isItaSafePlaceForTheQueen(int[][]chess,int row, int col){
        for(int i=row-1,j=col ; i>=0;i--){
            if(chess[i][j]==1){
                return false;
            }
        }
        
        for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--){
            if(chess[i][j]==1){
                return false;
            }
        }
        
        for(int i=row-1,j=col+1; i>=0 && j<chess.length; i--,j++){
            if(chess[i][j]==1){
                return false;
            }
        }
        
        return true;
    }
}
