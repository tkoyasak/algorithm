#include <bits/stdc++.h>
using namespace std;

map<long, int> prime_factor(long n) {
  map<long, int> res;

  for (long i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if (n > 1) res[n]++;

  return res;
}
