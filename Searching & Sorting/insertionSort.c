#include <stdio.h>

// Complexity: O(N^2)
void insertionSort(int n, int arr[]) {
  int pos;
  for (int i = 0; i < n; i++) {
    pos = i;
    while (pos > 0 && (arr[pos] < arr[pos - 1])) {
      int temp = arr[pos];
      arr[pos] = arr[pos - 1];
      arr[pos - 1] = temp;
      pos--;
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  insertionSort(n, arr);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;  
}
