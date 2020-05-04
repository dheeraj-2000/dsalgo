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
      for(int i=0; i<N; i++){
            for(int j=i; j<N-1; j++){
                  swap(matrix[i][j], matrix[i][j])
            }
      }

}

int print_mat(){

}




// Driver function to test above function
int main(){
      int mat[3][3]
