#include <bits/stdc++.h>
using namespace std;

// Sieve of eratosthenes to find prime numbers in range [1,n]
vector<int> prime_number(int n) {
  vector<int> res;
  vector<bool> is_prime(n + 1, true);

  for (int i = 2; i <= ceil(sqrt(n)); ++i) {
    if (is_prime[i]) {
      for (int j = i * 2; j <= n; j += i)
        is_prime[j] = false;
    }
  }
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i])
      res.push_back(i);
  }

  return res;
}
