#include <stdio.h>

// Complexity: O(N^2)
void selectionSort(int n, int arr[]) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  selectionSort(n, arr);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;  
}
