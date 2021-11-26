#include <bits/stdc++.h>
using namespace std;

// Sieve of eratosthenes to find prime numbers in range [1,n]
vector<bool> prime_number(int n) {
  vector<bool> res(n + 1, true);

  int m = ceil(sqrt(n));
  for (int i = 2; i <= m; ++i) {
    if (res[i]) {
      for (int j = i * 2; j <= n; j += i)
        res[j] = false;
    }
  }

  return res;
}
