#include <bits/stdc++.h>
using namespace std;

template<typename T, int N>
class Combination {
 private:
  vector<T> fac, inv;

 public:
  Combination(void) : fac(N, 1), inv(N, 1) {
    for (int i = 1; i < N; ++i)
      fac[i] = fac[i - 1] * i;
    inv[N - 1] = T(1) / fac[N - 1];
    for (int i = N - 2; i >= 1; --i)
      inv[i] = inv[i + 1] * T(i + 1);
  }

  T npk(int n, int k) {
    if (k < 0 || n < k) return T(0);
    return fac[n] * inv[n - k];
  }

  T nck(int n, int k) {
    if (k < 0 || n < k) return T(0);
    return fac[n] * inv[n - k] * inv[k];
  }

  T nhk(int n, int k) {
    if (n == 0 && k == 0) return T(1);
    if (n <= 0 || k < 0) return T(0);
    return nck(n + k - 1, k);
  }
};
