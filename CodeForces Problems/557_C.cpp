#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
using namespace std;
 
int n;
struct node {
    int x;
    int y;
} q[1001000];
int v[201];
int minn;
int small;
 
bool cmp(node a,node b) {
    return a.x > b.x;
}
 
int main() {
    while(scanf("%d",&n)!=EOF) {
            memset(v,0,sizeof(v));
        for(int i=0; i<n; i++) {
            scanf("%d",&q[i].x);
        }
        for(int i=0; i<n; i++) {
            scanf("%d",&q[i].y);
            v[q[i].y]++;
        }
        if(n == 2 && q[0].x!=q[1].x)
        {
            printf("%d\n",min(q[0].y,q[1].y));
            continue;
        }
        sort(q,q+n,cmp);
        minn = 99999999;
        int cnt = 1;
        int sum = 0;
        int ans = 0;
        int pn = n;
        small = 0;
        v[q[0].y]--;
        ans = q[0].y;
        for(int i=1; i<n; i++) {
            if(q[i].x == q[i-1].x) {
                v[q[i].y]--;
                ans += q[i].y;
                cnt++;
            } else {
                pn -= cnt;
                int num = pn - cnt + 1;
                if(num>0) {
                    for(int j=1; j<=201; j++) {
                        if(v[j]>=num) {
                            small += num * j;
                            num = 0;
                            break;
                        } else {
                            small += v[j]*j;
                            num -= v[j];
                        }
                    }
                }
                small += sum;
                minn = min(small,minn);
                cnt = 1;
                sum += ans;
                ans = q[i].y;
                v[q[i].y]--;
                small = 0;
            }
        }
        minn = min(minn,sum);
        printf("%d\n",minn);
    }
    return 0;
}