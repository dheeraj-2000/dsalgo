/*Tic-tac-toe is a game played between two players on a 3×3 grid. In a turn, a player chooses an empty cell and places their symbol on the cell.
The players take alternating turns, where the player with the first turn uses the symbol X and the other player uses the symbol O.
The game continues until there is a row, column, or diagonal containing three of the same symbol (X or O), and the player with that token is declared the winner.
Otherwise if every cell of the grid contains a symbol and nobody won, then the game ends and it is considered a draw.
You are given a tic-tac-toe board A after a certain number of moves, consisting of symbols O, X, and underscore(_).
Underscore signifies an empty cell.
Print
1: if the position is reachable, and the game has drawn or one of the players won.
2: if the position is reachable, and the game will continue for at least one more move.
3: if the position is not reachable.*/
#include<iostream>
using namespace std;
int main()
{
    long long int T;
    cin>>T;
    while(T!=0)
    {
        char a[3][3];
        int xn=0,on=0,dn=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='X')
                xn++;
                if(a[i][j]=='O')
                on++;
                if(a[i][j]=='_')
                dn++;
            }
        }
        
        int x=0,o=0;
        if(((a[0][0]==a[0][1])&&(a[0][0]==a[0][2])&&(a[0][0]=='X'))||((a[1][0]==a[1][1])&&(a[1][0]==a[1][2])&&(a[1][1]=='X'))||
        ((a[2][0]==a[2][1])&&(a[2][0]==a[2][2])&&(a[2][1]=='X'))||((a[0][0]==a[1][0])&&(a[0][0]==a[2][0])&&(a[0][0]=='X'))||
        ((a[0][1]==a[1][1])&&(a[0][1]==a[2][1])&&(a[1][1]=='X'))||((a[0][2]==a[1][2])&&(a[0][2]==a[2][2])&&(a[1][2]=='X'))||
        ((a[0][0]==a[1][1])&&(a[0][0]==a[2][2])&&(a[1][1]=='X'))||((a[0][2]==a[1][1])&&(a[0][2]==a[2][0])&&(a[1][1]=='X')))
        x++;
        if(((a[0][0]==a[0][1])&&(a[0][0]==a[0][2])&&(a[0][0]=='O'))||((a[1][0]==a[1][1])&&(a[1][0]==a[1][2])&&(a[1][1]=='O'))||
        ((a[2][0]==a[2][1])&&(a[2][0]==a[2][2])&&(a[2][1]=='O'))||((a[0][0]==a[1][0])&&(a[0][0]==a[2][0])&&(a[0][0]=='O'))||
        ((a[0][1]==a[1][1])&&(a[0][1]==a[2][1])&&(a[1][1]=='O'))||((a[0][2]==a[1][2])&&(a[0][2]==a[2][2])&&(a[1][2]=='O'))||
        ((a[0][0]==a[1][1])&&(a[0][0]==a[2][2])&&(a[1][1]=='O'))||((a[0][2]==a[1][1])&&(a[0][2]==a[2][0])&&(a[1][1]=='O')))
        o++;
        if(((x==1)&&(xn==(on+1))&&(o==0))||((o==1)&&(xn==on)&&(x==0))||((x==0)&&(o==0)&&(dn==0)&&(xn==(on+1))))
        cout<<"1"<<endl;

        else if(((xn==on)||(xn==(on+1)))&&(dn!=0)&&(x==0)&&(o==0))
        cout<<"2"<<endl;
        
        else
        cout<<"3"<<endl;
        T--;
    }
    return 0;
}