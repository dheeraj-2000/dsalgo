#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    string s;
    long long int str[26]={0},count=0;
    cin>>s;
    long long int l=s.length();
    for(long long int i=0;i<l;i++){
        str[s[i]-'a']++;
    }
    for(long long int i=0;i<26;i++){
        if(str[i]!=0){
            count++;
        }
    }
    if(count%2==0){
        cout<<"CHAT WITH HER!"<<endl;
    }else{
        cout<<"IGNORE HIM!"<<endl;
    }
    return 0;
}
