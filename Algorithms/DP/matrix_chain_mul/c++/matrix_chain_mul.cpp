/**************************************************************************************************

    Name : Ankit Dimri
    code : Matrix Chain Multiplication. Make parenthesization on a matrix Chain to give solution
           of optimal number of multiplicatons by put parentheis.

**************************************************************************************************/

#include <iostream>
#include <vector>
#include <climits>  // for INT_MAX

 // To find the optimal points of parenthesis
 void matrix_mul_optimal_points (std::vector <int>&, std::vector <std::vector <int>>&);
 // To print the solution
 void print (std::vector <std::vector <int>>&, int, int);

 int main(int argc, char const *argv[]) {
     int n;
     std::cout << "\n\n\t Enter the of matrices : ";
     std::cin >> n;
     n++;
     std::vector <int> p (n, 0);
     std::vector <std::vector <int>> s (p.size ()-1, std::vector <int> (p.size ()-1, 0));
     std::cout << "\n\t Enter the dimensions of matrices in series : ";
     for  (int i = 0; i < n; i++)
         std::cin >> p [i];
     matrix_mul_optimal_points (p, s);
     std::cout << "\n\t The result is : ";
     // Print the matrix chain with optimal parenthesization
     print (s, 1, s [0].size ()); // The array is cosidered to start at 1
     std::cout << '\n';
     return 0;
 }

 void matrix_mul_optimal_points (std::vector <int> &p, std::vector <std::vector <int>> &s) {
     std::vector <std::vector <int>> m (p.size ()-1, std::vector <int> (p.size ()-1, 0));
     int n = p.size () - 1, q;
     for (int l = 1; l < n; l++) {
         for (int i = 0; i < n-l; i++) {
             int j = i+l;
             m [i][j] = INT_MAX;
             for (int k = i; k < j; k++) {
                 q = m [i][k] + m [k+1][j] + p [i]*p[k+1]*p[j+1];
                 if (q < m [i][j]) {
                     m [i][j] = q;
                     s [i][j] = k+1;
                 }
             }
         }
     }
     // Uncomment to print the Dynamic table
     /* std::cout << "\n\t m : " << '\n';
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << m [i][j] << '\t';
        std::cout << '\n';
     } */

     // Uncomment to print the table containing the solution of points
     /* std::cout << "\n\t s :" << '\n';
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << s [i][j] << ' ';
        std::cout << '\n';
    } */
 }

 void print (std::vector <std::vector <int>> &s, int i, int j) {
     if (i == j)
        std::cout << "A";
     else {
         std::cout << "(";
         // The array starts at 0 therefore '-1'
         print (s, i, s [i-1][j-1]);
         print (s, s [i-1][j-1] + 1, j);
         std::cout << ")";
     }
 }
