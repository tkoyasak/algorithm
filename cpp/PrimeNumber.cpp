#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> prime_number(ll n) {
  vector<bool> res(n + 1, true);

  res[0] = res[1] = false;
  ll m = ceil(sqrt(n));
  for (ll i = 2; i <= m; ++i) {
    if (res[i]) {
      for (ll j = i * 2; j <= n; j += i)
        res[j] = false;
    }
  }

  return res;
}
