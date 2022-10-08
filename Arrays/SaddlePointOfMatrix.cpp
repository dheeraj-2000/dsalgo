#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the size of matrix :";
    int a;
    cin >> a;
    int matrix[a][a];
    cout << "Enter Elements of the matrix :"
         << "\n";
    for (int i = 0; i < a; i++)

    {
        for (int j = 0; j < a; j++)
        {
            cout << "Enter element at " << i << "," << j << " position :";
            cin >> matrix[i][j];
        }
    }
    cout << "\n";
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    int s = 0;
    for (int i = 0; i < a; i++)
    {
        int min = matrix[i][0];
        int column = 0;
        for (int j = 0; j < a; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                column = j;
            }
        }
        int k;
        for (k = 0; k < a; k++)
        {
            if (min < matrix[k][column])
            {
                break;
            }
        }
        if (k == a)
        {
            cout << "The value of saddle point is " << min;
            s = s + 1;
        }
    }
    if (s == 0)
    {
        cout << "No saddle point found";
    }
}
