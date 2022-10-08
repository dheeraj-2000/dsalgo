#include <iostream>
using namespace std;
void uppertriangular(int array[], int n)
{
    int s=0;
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j< n; j++)
       {
         if (i<=j)
         {
            cout<<array[s]<<" ";
            s++;
         }
         else
         {
           cout<<"0"<<" ";
         }
         
       }
       cout<<"\n";
    }
}
void lowertriangular(int array[], int n)
{
    int s=0;
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j< n; j++)
       {
         if (i>=j)
         {
            cout<<array[s]<<" ";
            s++;
         }
         else
         {
            cout<<"0"<<" ";
         }
         
       }
       cout<<"\n";
    }
}
int main()
{
    int n, c;
    cout << "Enter the size of triangular matrix :";
    cin >> n;
    int s = (n*(n + 1))/2;
    int array[s];
    cout << "Enter the elements present : " << '\n';
    for (int i = 0; i < s; i++)
    {
        cin >> array[i];
    }
    while (c != 3)
    {
        cout << "\n"
             << "1. Print upper triangular "
             << "\n";
        cout << "2. Print lower triangular "
             << "\n";
        cout << "3. Exit"
             << "\n";
        cout << "Enter choice :";
        cin >> c;
        if (c == 1)
        {
            uppertriangular(array, n);
        }
        else if (c == 2)
        {
            lowertriangular(array, n);
        }
    }
    return 0;
}
