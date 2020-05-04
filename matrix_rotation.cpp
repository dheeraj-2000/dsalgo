#include<bits/stdc++.h>
#define N 3
using namespace std;



int transpos_matrix(int matrix[N][N]){
      for (int i=0; i<N; i++){
            for (int j=i; j<N; j++){
                  swap(matrix[i][j], matrix[j][i]);
            }
      }
}

int reverse_rows(int matrix[N][N]){
      for (int i=0; i<N; i++){
            int temp = N-1;
            for (int j=0; j<temp; j++){
                  swap(matrix[i][j], matrix[i][temp]);
                  temp--;
            }
      }

}

int print_matrix(int matrix[N][N]){
      for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                  cout << matrix[i][j];
            }
            cout << endl;
      }
      cout <<endl;
}

// Driver function to test above function
int main(){
      int matrix[N][N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
      cout<< "The given matrix is: " << endl;
      print_matrix( matrix);
      transpos_matrix( matrix);
      // cout<< "Transpose matrix of the given matrix is: " << endl;
      reverse_rows( matrix);
      cout<< "Rotated matrix is: " << "\n" << print_matrix( matrix);


}
