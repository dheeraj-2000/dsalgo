#include <stdio.h>
int main(void) {
  int i, low, mid, high, n, key, array[100];
  printf("\nEnter number of elements: ");
  scanf("%d", &n);
  printf("\nEnter %d numbers in ascending order: \n", n);
  for (i = 0; i < n; i++)
    scanf("%d", &array[i]);
  printf("\nEnter the number to find from list: ");
  scanf("%d", &key);
  low = 0;
  high = n - 1;
  mid = (low + high) / 2;

  while (low <= high) {
    if (array[mid] < key)
      low = mid + 1;
    else if (array[mid] == key) {
      printf("\n%d found at location %d", key, mid + 1);
      break;
    } else
      high = mid - 1;
    mid = (low + high) / 2;
  }
  if (low > high)
    printf("\nNot found!\n%d is not present in the list", key);
  return 0;
}
