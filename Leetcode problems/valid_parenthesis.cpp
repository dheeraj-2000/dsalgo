#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
      bool isValid(string s) {
            stack<char> st;
            char c;
            for(int i=0; i<s.length(); i++){
                  if(s[i] == '(' ||  s[i] == '{' || s[i] == '['){
                        st.push(s[i]);
                        continue;
                  }

                  if (st.empty())
                        return false;

                  switch (s[i]) {
                        case ')':
                              c = st.top();
                              st.pop();
                              if (c == '}' || c == ']')
                                    return false;
                              break;

                        case '}':
                              c = st.top();
                              st.pop();
                              if (c == ')' || c == ']')
                                    return false;
                              break;

                        case ']':
                              c = st.top();
                              st.pop();
                              if (c == '}' || c == ')')
                                    return false;
                              break;

                  }


            }
            return (st.empty());
    }
};

int main(){
      string str = "{[]}";
      Solution obj;
      cout<<obj.isValid(str);
}
