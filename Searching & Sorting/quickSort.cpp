#include <bits/stdc++.h>
using namespace std;

// Complexity in average: O(N log N)
// Worst complexity: O(N^2)
void quickSort(vector<int> &arr, int left, int right) {
  if (left >= right) { // nothing to sort
    return;
  }
  // choosing pivot from the median of {front, mid, arr} arr elements
  int pivot;
  int front = arr[left];
  int mid = arr[(left + right) / 2];
  int rear = arr[right];
  if ((front < mid && front > rear) || (front < rear && front > mid)) {
    pivot = front;
  } else if ((mid < front && mid > rear) || (mid < rear && mid > front)) {
    pivot = mid;
  } else {
    pivot = rear;
  }

  int pLeft = left;
  int pRight = right;
  while (pLeft <= pRight) {
    // '<' will sort in ascending order
    while (arr[pLeft] < pivot) {
      pLeft++;
    }
    // '>' will sort in ascending order
    while (arr[pRight] > pivot) {
      pRight--;
    }
    if (pLeft <= pRight) {
      swap(arr[pLeft], arr[pRight]);
      pLeft++;
      pRight--;
    }
  }
  quickSort(arr, left, pRight);
  quickSort(arr, pLeft, right);
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
  for (auto v : arr) {
    cout << v << " ";
  }
  cout << '\n';
  // sort in ascending order
  quickSort(arr, 0, n - 1);
  for (auto v : arr) {
    cout << v << " ";
  }
  return 0;
}
