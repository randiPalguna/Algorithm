#include <stdio.h>
#include <string.h>

// Complexity: O(N + M)
void countingSort(int n, int arr[]) {
  int bucket[n + 1]; // if we know exactly the data range or arr[i] is in 0..n
  memset(bucket, 0, sizeof(bucket));
  for (int i = 0; i < n; i++) {
    bucket[arr[i]]++;
  }
  int index = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < bucket[i]; j++) {
      arr[index] = i;
      index++;
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
  countingSort(n, arr);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }  
  return 0;
}
