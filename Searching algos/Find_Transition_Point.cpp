//question :-https://practice.geeksforgeeks.org/problems/find-transition-point-1587115620/1#submission

#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    if (arr[0]) {
        return 0;
    }
    // Initialise lower and upper bounds
    int l = 0, u = n - 1;

    while (l <= u) {
        int mid = (l + u) / 2;

 
        if (arr[mid] == 0) 
        {l= mid + 1;
        }
        else if (arr[mid] == 1) {
         
            if (arr[mid - 1] == 0) 
            {return mid;
}
    
            u= mid - 1;
        }
    }
    return -1;
}
