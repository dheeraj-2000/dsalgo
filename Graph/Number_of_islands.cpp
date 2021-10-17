
// C++ Program to count islands in boolean 2D matrix
#include <bits/stdc++.h>
using namespace std;

#define ROW 5
#define COL 5


int isSafe(int M[][COL], int row, int col,
           bool visited[][COL])
{
    
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]);
}


void DFS(int M[][COL], int row, int col,
         bool visited[][COL])
{
    // These arrays are used to get
    // row and column numbers of 8
    // neighbours of a given cell
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    // Mark this cell as visited
    visited[row][col] = true;

    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited))
            DFS(M, row + rowNbr[k], col + colNbr[k], visited);
}


int countIslands(int M[][COL])
{
    
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    
    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)

            // If a cell with value 1 is not
            if (M[i][j] && !visited[i][j]) {
                // visited yet, then new island found
                // Visit all cells in this island.
                DFS(M, i, j, visited);

                // and increment island count
                ++count;
            }

    return count;
}

// Driver code
int main()
{
    int M[][COL] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 } };

    cout << "Number of islands is: " << countIslands(M);

    return 0;
}


