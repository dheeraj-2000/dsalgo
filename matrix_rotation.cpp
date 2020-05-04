// Clockwise rotation of matrix by 90 degree
// @dheeraj

#include<bits/stdc++.h>
#define N 3
using namespace std;

int transpos_matrix(int matrix[N][N]){                   // taking transpose of the matrix
      for (int i=0; i<N; i++){
            for (int j=i; j<N; j++){
                  swap(matrix[i][j], matrix[j][i]);
            }
      }
}

int reverse_rows(int matrix[N][N]){                     // reversing the rows element
      for (int i=0; i<N; i++){
            int temp = N-1;
            for (int j=0; j<temp; j++){
                  swap(matrix[i][j], matrix[i][temp]);
                  temp--;
            }
      }

}

int print_matrix(int matrix[N][N]){                    // Printing the matrix
      for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                  cout << matrix[i][j];
            }
            cout << endl;
      }
      cout <<endl;
}

int main(){                                           // Driver function to test above function

      int matrix[N][N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
      cout<< "The given matrix is: " << endl;
      print_matrix( matrix);
      transpos_matrix( matrix);
      reverse_rows( matrix);
      cout<< "Rotated matrix is: " << "\n" << print_matrix( matrix);


}
