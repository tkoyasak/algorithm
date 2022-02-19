#include <bits/stdc++.h>
using namespace std;

vector<pair<long, int>> prime_factor(long n) {
  vector<pair<long, int>> res;

  for (long i = 2; i * i <= n; ++i) {
    int exp = 0;
    while (n % i == 0) {
      n /= i;
      exp++;
    }
    if (exp) res.emplace_back(i, exp);
  }
  if (n > 1) res.emplace_back(n, 1);

  return res;
}
