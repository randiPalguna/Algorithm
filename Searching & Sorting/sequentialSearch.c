#include <stdio.h>

int sequentialSearch(int n, int arr[], int target) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[n + 1];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int target;
  scanf("%d", &target);

  printf("%d", sequentialSearch(n, arr, target));
  return 0;
}
