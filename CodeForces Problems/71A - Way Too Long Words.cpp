#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    while(n--) {
        string str;
        cin>>str;
        int size = str.length();
        if(size>10) {
            int i=1;
            while(str[i] != '\0')
                i++;
            cout<<str[0]<<i-2<<str[size-1]<<endl;
        } else {
            cout<<str<<endl;
        }
    }
    
    return 0;
}