#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
      char cons(string constlltn[3][18]){
            for(int i=0;i<18;i++) {
                  if(constlltn[0][i]=='#' && constlltn[1][i]=='#' && constlltn[2][i]=='#')
                        cout<<'#';

                  else if(constlltn[0][i]=='.' && constlltn[1][i]=='.' && constlltn[2][i]=='.'){

                  }

                  else{
                        char first_row1, first_row2, first_row3, second_row1, second_row2, second_row3, third_row1, third_row2, third_row3;
                        int temp = i;
                        first_row1 = constlltn[0][temp];
                        first_row2 = constlltn[0][temp+1];
                        first_row3 = constlltn[0][temp+2];
                        second_row1 = constlltn[1][temp];
                        second_row2 = constlltn[1][temp+1];
                        second_row3 = constlltn[1][temp+2];
                        third_row1 = constlltn[2][temp];
                        third_row2 = constlltn[2][temp+1];
                        third_row3 = constlltn[2][temp+2];

                        if(first_row1=='.' && first_row2=='*' && first_row3=='.' && second_row1=='*' && second_row2=='*' && second_row3=='*' && third_row1=='*' && third_row2=='.' && third_row3=='*'){
                              // cout<<"A";
                              return 'A';
                              i = i + 2;
                        }
                        if(first_row1=='*' && first_row2=='*' && first_row3=='*' && second_row1=='*' && second_row2=='*' && second_row3=='*' && third_row1=='*' && third_row2=='*' && third_row3=='*'){
                              // cout<<"E";
                              return 'E';
                              i = i + 2;
                        }
                        if(first_row1=='*' && first_row2=='*' && first_row3=='*' && second_row1=='.' && second_row2=='*' && second_row3=='.' && third_row1=='*' && third_row2=='*' && third_row3=='*'){

                              // cout<<"I";
                              return 'I';
                              i = i + 2;
                        }
                        if(first_row1=='*' && first_row2=='*' && first_row3=='*' && second_row1=='*' && second_row2=='.' && second_row3=='*' && third_row1=='*' && third_row2=='*' && third_row3=='*'){

                              // cout<<"O";
                              return 'O';
                              i = i + 2;
                        }
                        if(first_row1=='*' && first_row2=='.' && first_row3=='*' && second_row1=='*' && second_row2=='.' && second_row3=='*' && third_row1=='*' && third_row2=='*' && third_row3=='*'){  			  		{
                              // cout<<"U";
                              return 'U';
                              i = i + 2;
                        }
                  }
            }}


      }
};

int main(){
      char constlltn[3][18] =     {{'*' , '.' , '*' , '#' , '*' , '*' , '*' , '#' , '*' , '*' , '*' , '#' , '*' , '*' , '*' , '.' , '*' , '.' },
                                     {'*' , '.' , '*' , '#' , '*' , '.' , '*' , '#' , '.' , '*' , '.' , '#' , '*' , '*' , '*' , '*' , '*' , '*' },
                                     {'*' , '*' , '*' , '#' , '*' , '*' , '*' , '#' , '*' , '*' , '*' , '#' , '*' , '*' , '*' , '*' , '.' , '*' }};

      Solution ob;

      cout << ob.cons(constlltn);
}
