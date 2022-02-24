#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<int N>
class Sieve {
 private:
  vector<bool> isprime;
  vector<int> primes, min_factor;

 public:
  Sieve(void) : isprime(N + 1, true), min_factor(N + 1) {
    isprime[0] = isprime[1] = false;
    iota(min_factor.begin(), min_factor.end(), 0);
    for (int i = 2; i <= N; i++) {
      if (!isprime[i]) continue;
      primes.emplace_back(i);
      for (int j = i * 2; j <= N; j += i) {
        isprime[j] = false;
        if (min_factor[j] == j) min_factor[j] = i;
      }
    }
  }

  vector<int> prime_number(void) {
    return primes;
  }

  vector<pair<int, int>> prime_factor(int n) {
    vector<pair<int, int>> res;

    while (n > 1) {
      int prime = min_factor[n], exp = 0;
      while (min_factor[n] == prime) {
        n /= prime;
        exp++;
      }
      res.emplace_back(prime, exp);
    }

    return res;
  }
};
