#include <iostream>
using namespace std;
#include <vector>
int main(){
    int n1,n2;
    cin>>n1>>n2;
    vector <int> vect(n1);
    for(int i=0;i<n1;++i){
        cin>>vect[i];
    }
    n2=n2%n1;
    for(int j=n2;j<n1;++j){
        cout<<vect[j]<<" ";
    }
    for(int j=0;j<n2;++j){
        cout<<vect[j]<<" ";
    }
}
