#include<bits/stdc++.h>
#define N 3
using namespace std;



int transpos_matrix(int matrix[N][N]){
      for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                  swap(matrix[i][j], matrix[j][i]);
            }
      }
}

int reverse_rows(int matrix[N][N]){
      for (int i=0; i<N; i++){
            for (int j=i; j<N-1; j++){
                  swap(matrix[i][j], matrix[i][j]);
            }
      }

}

int print_matrix(int matrix[N][N]){
      for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                  cout<< '\t' << matrix[i][j];
            }
      }
      cout << "\n";
}

// Driver function to test above function
int main(){
      int matrix[N][N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
      cout<< "The given matrix is: " << print_matrix[N][N];
      transpos_matrix[N][N];
      cout<< "Transpose matrix of the given matrix is: " << print_matrix[N][N];
      reverse_rows[N][N];
      cout<< "Rotated matrix is: " << print_matrix[N][N];
