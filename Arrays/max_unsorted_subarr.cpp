#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


vector<int> solve(vector<int> &a) {
    if(a.size()==0) return {-1};
        vector<int> v=a;
        sort(v.begin(),v.end());

        int i=0,l=-1,r=-1;

        while(i<a.size()){
            if(a[i]!=v[i]){
                l=i;
                break;
            }
            i++;
        }

        i=a.size()-1;

        while(i>=0){
            if(a[i]!=v[i]){
                r=i;
                break;
            }
            i--;
        }

        if(l==-1) return {-1};
        return {l,r};
}



// vector<int> solve(vector<int> &v){
//
//       int front_index, back_index, i,j,result1,result2;
//       for(i=0; i<v.size()-1; i++){
//             if(v[i] > v[i+1]){
//                   front_index=i;
//                   break;}
//       }
//
//       for(j=v.size()-1; j>0; j--){
//             if(v[j-1] > v[j]){
//                   back_index=j;
//                   break;}
//       }
//
//
//       int max_in_subar = *max_element(v[front_index], v[back_index]);
//       int min_in_subar = *min_element(v[front_index], v[back_index]);
//       for(i=0; i<=front_index; i++){
//             if(v[i] > min_in_subar)
//                 result1 =  i;
//       }
//
//       for(i=v.size()-1; i>=back_index; i--){
//             if(v[i] < max_in_subar)
//                 result2 =  i;
//       }
//
//       return {result1, result2};
//
// }


//
// int main(){
//       int n, input;
//       cin>>n;
//       vector<int> v(n);
//       for(int i=0; i<n; i++){
//             cin>>input;
//             v.push_back(input);
//       }
//
//
//       solve(v);
//       for(auto i: v){
//             cout<<i;
//       }
// }
