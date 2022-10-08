#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the rows of matrix :";
    int a, b;
    cin >> a;
    cout << "Enter the columns of matrix :";
    cin >> b;
    int matrix[a][a];
    cout << "Enter Elements of the matrix :"
         << "\n";
    for (int i = 0; i < a; i++)

    {
        for (int j = 0; j < b; j++)
        {
            cout << "Enter element at " << i << "," << j << " position :";
            cin >> matrix[i][j];
        }
    }
    cout << "\n";
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < a; i++)
    {
        int rowsum = 0;
        for (int j = 0; j < b; j++)
        {
            rowsum = rowsum + matrix[i][j];
        }
        cout << "The sum of " << i + 1 << " row of the matrix is " << rowsum << "\n";
    }

    for (int i = 0; i < a; i++)
    {
        int colsum = 0;
        for (int j = 0; j < b; j++)
        {
            colsum = colsum + matrix[j][i];
        }
        cout << "The sum of " << i + 1 << " column of the matrix is " << colsum << "\n";
    }
}
