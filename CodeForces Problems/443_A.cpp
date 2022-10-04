#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,s1;
    std::getline(std::cin, s);
    for(int i=0; i<s.length(); i++){
        int flag=1;
        for(int j=i+1; j<s.length(); j++){
            if(s[i]==s[j]){
                flag=0;
            }
        }
        if(flag==1){
            s1+=s[i];
        }
    }
    if(s1.length()<=4){
        cout<<s1.length()-2<<endl;
    }
    else{
        cout<<s1.length()-4<<endl;
    }


    return 0;
}