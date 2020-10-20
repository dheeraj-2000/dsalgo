#include <stdio.h>
#include <stdlib.h>

#define less(a, b) (a<b)
#define exch(a, b) {int t = a; a = b; b = t;}
#define cmpexch(a, b) {if(less(b,a)) exch(a, b);}

void insertion(int *v, int l, int r) {
    for(int i=r; i>l; i--)
        cmpexch(v[i-1], v[i]);

    for(int i=l+2; i<=r; i++) {
        int j = i;
        int tmp = v[j];
        while (less(tmp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = tmp;
    }
}

int main() {
    int *v,n;
    scanf("%d",&n);
    v = malloc(n * sizeof(int));

    for(int i=0; i<n; i++)
      scanf("%d", &v[i]);

    insertion(v, 0, n-1);

    printf("%d", v[0]);
    for(int i=1; i<n; i++)
        printf(" %d", v[i]);
    printf("\n");

    return 0;
}