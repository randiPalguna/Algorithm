#include <stdio.h>

int binarySearch(int n, int arr[], int target) {
  int left = 0;
  int right = n - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (target < arr[mid]) {
      right = mid - 1;
    } else if (target > arr[mid]) {
      left = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[n + 1];
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }

  int target;
  scanf("%d", &target);
  printf("%d", binarySearch(n, arr, target));
  return 0;
}
