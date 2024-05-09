#include <stdio.h>

// euclid GCF (FPB) algorithm
// Complexity: O(log(min(a,b))
int gcf(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcf(b, a % b);
  }
}

// LCM (KPK) algorithm
// Complexity: O(1)
int lcm(int a, int b, int gcf) {
  return a * b / gcf;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  printf("%d\n", gcf(n, m));
  printf("%d\n", lcm(n, m, gcf(n, m)));
  return 0;
}
