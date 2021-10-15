#include<iostream>
using namespace std;
void wave_print(int rows, int columns, int **arr){
    for(int column=0;column<columns;column++){
        if(column%2==0){
            for(int row=0;row<rows;row++){
                cout<<arr[row][column]<<" ";
            }
        }
        else{
            for(int row=rows-1;row>=0;row--){
                cout<<arr[row][column]<<" ";
            }
        }
    }
}
int main(){
    int rows,columns;
    cin>>rows>>columns;
    int **arr;
    arr=new int *[rows];
    for(int i=0;i<rows;i++){
        arr[i]=new int[columns];
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Matrix is"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Wave print is"<<endl;
    wave_print(rows,columns,arr);
}