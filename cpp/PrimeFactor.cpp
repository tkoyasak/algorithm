#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, int>> prime_factor(ll n) {
  vector<pair<ll, int>> res;

  for (ll i = 2; i * i <= n; ++i) {
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
