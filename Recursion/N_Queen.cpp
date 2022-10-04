#include <bits/stdc++.h>
using namespace std;

bitset<30> d1,d2,col; //to store current status of diagonals and columns
vector<vector<int>> v;
vector<int> ex;

void recurser(int r, int n){
    if(r==n){
       v.push_back(ex);
       return ;
    }

    for(int c=0; c<n; c++){
        if(!col[c] && !d1[r-c+n-1] && !d2[r+c]){
            col[c]=d1[r-c+n-1]=d2[r+c]=1;
            ex[c]=r+1;
            recurser(r+1,n);
            col[c]=d1[r-c+n-1]=d2[r+c]=0; //backtracking
        }
    }
}

vector<vector<int>> nQueens(int n) {
    for(int i=0; i<n; i++)
        ex.push_back(0);
    recurser(0,n);
    sort(v.begin(),v.end());
    return v;
}

int main(){
    int n;
    cout<<"Enter size of the board\n";
    cin>>n;

    vector<vector<int>> ans = nQueens(n);

    cout<<"Valid positions for placing n Queens are:\n";
    for(int i = 0;i < ans.size();i++){
        cout<<"[";
        for(int u: ans[i])
            cout<<u<<" ";
        cout<<"] ";
    }
    cout<<endl;
    return 0;
}
