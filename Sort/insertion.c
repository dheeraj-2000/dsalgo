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



// Another Code for Insertion Sort in C

#include <stdio.h>
int main() {
  int n, array[100], i, j, temp, flag = 0;
  printf("Enter how many numbers you want to sort:\n");
  scanf("%d", &n);
  printf("Enter %d numbers:\n", n);
  for (i = 0; i < n; i++)
    scanf("%d", &array[i]);
  for (i = 1; i <= n - 1; i++) {
    temp = array[i];
    for (j = i - 1; j >= 0; j--) {
      if (array[j] > temp) {
        array[j + 1] = array[j];
        flag = 1;
      } else
        break;
    }
    if (flag)
      array[j + 1] = temp;
  }
  printf("Sorted list in ascending order:\n");
  for (i = 0; i <= n - 1; i++) {
    printf("%d\n", array[i]);
  }
  return 0;
}
