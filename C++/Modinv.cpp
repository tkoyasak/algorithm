#include <bits/stdc++.h>
using namespace std;

long modinv(long a, long m) {
  long b = m, u = 1, v = 0;

  while (b) {
    long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;

  return u;
}
