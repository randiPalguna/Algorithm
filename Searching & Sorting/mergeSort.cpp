#include <bits/stdc++.h>
using namespace std;

// Complexity: O(N log N)
void combineMergeSort(vector<int> &arr, int aLeft, int aRight, int bLeft, int bRight) {
  int size = bRight - aLeft + 1;
  vector<int> arrTemp(size);
  int tIndex = 0;
  int aIndex = aLeft;
  int bIndex = bLeft;
  while (aIndex <= aRight && bIndex <= bRight) {
    // '<=' will sort in ascending order
    if (arr[aIndex] <= arr[bIndex]) {
      arrTemp[tIndex++] = arr[aIndex++];
    } else {
      arrTemp[tIndex++] = arr[bIndex++];
    }
  }
  while (aIndex <= aRight) {
    arrTemp[tIndex++] = arr[aIndex++];
  }
  while (bIndex <= bRight) {
    arrTemp[tIndex++] = arr[bIndex++];
  }
  for (int i = 0; i < size; i++) {
    arr[aLeft + i] = arrTemp[i];
  }
}

void mergeSort(vector<int> &arr, int left, int right) {
  if (left == right) { // arr is already sorted (1 element)
    return;
  }
  int mid = (left + right) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
  combineMergeSort(arr, left, mid, mid + 1, right);
}

 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n = 10;
  vector<int> arr(n);
  srand(time(0));
  for (int i = 0; i < n; i++) {
    int temp = rand();
    arr[i] = temp;
  }
  // vector 'arr' will sort in ascending order
  mergeSort(arr, 0, n - 1);
  return 0;
}
