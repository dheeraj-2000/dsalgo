#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
       void recursive_search(vector<int> &setofNum, int target, int i, int &k, vector<vector<int> >&dict_num, vector<int> &list_num){
        if (target < 0){
            return;
        }else{
            if (target == 0 && list_num.size()==k){
                dict_num.push_back(list_num);
            }else{
                for (int j=i;j<setofNum.size();j++){
                    if (j==0 || setofNum[j] != setofNum[j-1]){
                        list_num.push_back(setofNum[j]);
                        recursive_search(setofNum, target-setofNum[j], j+1, k, dict_num, list_num);
                        list_num.pop_back();
                    }
                }
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> >dict_num;
        vector<int> list_num;
        // vector<int> setofNum(9);
        vector<int> setofNum{1,2,3,4,5,6,7,8,9};

        for (vector<int>::iterator it=setofNum.begin(); it!=setofNum.end(); ++it)

        recursive_search(setofNum, n, 0, k, dict_num, list_num);
        return dict_num;
    }
};


int main(){
      int k, n;
      cin>>n;
      cin>>k;
      Solution dheeraj;
      cout<<dheeraj.combinationSum3(n,k);
}
