#include <stdio.h>
#include <stdbool.h>

// Complexity: O(sqrt(N))
bool isPrime(int val) {
  if (val <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= val; i++) {
    if (val % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n = 20;
  printf("%d", isPrime(n));
  return 0;
}
