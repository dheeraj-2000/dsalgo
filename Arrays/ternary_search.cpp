#include <iostream>
using namespace std;
int ternarySearch(int l, int r, int key, int ar[])

{
    while (r >= l) {

        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (ar[mid1] == key) {
            return mid1;
        }
        if (ar[mid2] == key) {
            return mid2;
        }


        if (key < ar[mid1]) {

            // The key lies in between l and mid1 
            r = mid1 - 1;
        }
        else if (key > ar[mid2]) {

            // The key lies in between mid2 and r 
            l = mid2 + 1;
        }
        else {

            // The key lies in between mid1 and mid2 
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return -1;
}
int main()
{
 int len;
cin>>len;
int ar[len];
for(int i=0;i<len;i++){
        cin>>ar[i];
}
int key;
cin>>key;
int l=0;
int r=len-1;
int p=0;
     p = ternarySearch(l, r, key, ar);

    cout << "Index of "<<key<<" is " << p << endl;
    }

