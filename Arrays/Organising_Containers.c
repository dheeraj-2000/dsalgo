// This problem develops your basic concepts about rows & columns of multidimensional arrays, how are they organised.
// Good use of  variable flag indicator.
// Learn the Use of break statement, nested if else loops.
// Keep Learning!

#include<stdio.h>
int main()
{
    int q, n, i, j, k, flag = 0;
    scanf("%d",&q);
    for(k = 0;k < q;k++)
    {
        scanf("%d",&n);
        int a[n][n], space[n], ball[n];
        for(i = 0;i < n;i++)
        {
            space[i] = 0;
            ball[i] = 0;
        }
        for(i = 0;i < n;i++)
        {
            for(j = 0;j < n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i = 0;i < n;i++)
        {
            for(j = 0;j < n;j++)
            {
                space[i] += a[i][j]; //row wise no. of type of balls to store space.
                ball[i] += a[j][i]; //column wise type of balls.
            }
        }
        for(i = 0;i < n;i++)
        {
            for(j = 0;j < n;j++)
            {
                if(space[i] == ball[j])
                {
                    space[i] = NULL;
                    ball[j] = NULL;
                    flag = 1;
                    break;
                }
                else 
                {
                    flag = -1;
                }
            }
            if(flag == -1)
            {
                break;
            }
        }
        if(flag == -1)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("Possible\n");
        }
    }
    return 0;
}