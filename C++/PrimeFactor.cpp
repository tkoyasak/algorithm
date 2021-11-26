#include <bits/stdc++.h>
using namespace std;

map<int, int> prime_factor(int n) {
  map<int, int> res;

  int m = ceil(sqrt(n));
  for (int i = 2; i <= m; ++i) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
    if (i > n) break;
  }
  if (n > 1) res[n]++;

  return res;
}
