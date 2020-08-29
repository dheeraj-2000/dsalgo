#include<bits/stdc++.h>
using namespace std;
int main(){
      // int num,y1;
  	// cin>>num;
  	// char constlltn[3][num];
      char constlltn[3][18] =     {{'*' , '.' , '*' , '#' , '*' , '*' , '*' , '#' , '*' , '*' , '*' , '#' , '*' , '*' , '*' , '.' , '*' , '.' },
                                     {'*' , '.' , '*' , '#' , '*' , '.' , '*' , '#' , '.' , '*' , '.' , '#' , '*' , '*' , '*' , '*' , '*' , '*' },
                                     {'*' , '*' , '*' , '#' , '*' , '*' , '*' , '#' , '*' , '*' , '*' , '#' , '*' , '*' , '*' , '*' , '.' , '*' }};

  	// for(int i=0; i<3; i++){
  	//   	for(int j=0; j<num; j++) {
  	//     	      cin>>constlltn[i][j];
      //       }
  	// }

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
      			cout<<"A";
      		  	i = i + 2;
      		}
                  if(first_row1=='*' && first_row2=='*' && first_row3=='*' && second_row1=='*' && second_row2=='*' && second_row3=='*' && third_row1=='*' && third_row2=='*' && third_row3=='*'){
      		  	cout<<"E";
      		  	i = i + 2;
      		}
                  if(first_row1=='*' && first_row2=='*' && first_row3=='*' && second_row1=='.' && second_row2=='*' && second_row3=='.' && third_row1=='*' && third_row2=='*' && third_row3=='*'){

      		  	cout<<"I";
      		  	i = i + 2;
      		}
                  if(first_row1=='*' && first_row2=='*' && first_row3=='*' && second_row1=='*' && second_row2=='.' && second_row3=='*' && third_row1=='*' && third_row2=='*' && third_row3=='*'){

      		  	cout<<"O";
      		  	i = i + 2;
      		}
                  if(first_row1=='*' && first_row2=='.' && first_row3=='*' && second_row1=='*' && second_row2=='.' && second_row3=='*' && third_row1=='*' && third_row2=='*' && third_row3=='*'){  			  		{
      		  	cout<<"U";
      		  	i = i + 2;
    	            }
            }
  	}}
}

//
// *, ., *, #, *, *, *, #, *, *, *, #, *, *, *, ., *, .,
// *, ., *, #, *, ., *, #, ., *, ., #, *, *, *, *, *, *,
// *, *, *, #, *, *, *, #, *, *, *, #, *, *, *, *, ., *,
