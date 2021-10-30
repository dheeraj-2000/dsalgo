#include<iostream>
#include<vector>
using namespace std;

vector<string> ch = {"","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

void solve(string ip, string op, int ind, vector<string>& ans) {
    if(ip[0] == '0') return;

    if(ind >= ip.length()) {
        ans.push_back(op);
        return;
    }

    int tmp1 = ip[ind] - '0';
    string op1 = op + ch[tmp1];
    solve(ip,op1,ind+1,ans);

    if(ip[ind] != '0') {
        string op1 = op + ip[ind];
        if(ip[ind] - '0' > 2 and ip[ind+1] == '0') {
            return;
        }
        else {
            int tmp2 = tmp1;
            tmp2 = tmp2*10 + (ip[ind+1] - '0');

            if(tmp2 <= 26) {
                string op2 = op + ch[tmp2];
                solve(ip,op2,ind+2,ans);
            }
        }
    }

}

int main() {
    string str;
    cin >> str;

    vector<string> ans;

    solve(str,"",0,ans);

    for(auto s : ans) cout<<s<<"\n";

    return 0;
}