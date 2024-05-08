#include <stdio.h>
#include <stdbool.h>
#include <string.h> // memset function

void sieveOfEratosthenes(int n, int primeList[]) {
  int cnt = 0;
  bool eleminated[n + 1];
  memset(eleminated, 0, sizeof(eleminated));

  for (int i = 2; i <= n; i++) {
    if (!eleminated[i]) {
      primeList[cnt++] = i;
      for (int j = i * i; j <= n; j += i) {
        eleminated[j] = 1;
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int primeList[n + 1];
  memset(primeList, 0, sizeof(primeList));

  sieveOfEratosthenes(n, primeList);

  for (int i = 0; primeList[i] != 0; i++) {
    printf("%d ", primeList[i]);
  }
  return 0;
}
