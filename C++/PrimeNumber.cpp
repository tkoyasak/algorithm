#include <bits/stdc++.h>
using namespace std;

vector<bool> prime_number(int n) {
  vector<bool> res(n + 1, true);

  res[0] = res[1] = false;
  int m = ceil(sqrt(n));
  for (int i = 2; i <= m; ++i) {
    if (res[i]) {
      for (int j = i * 2; j <= n; j += i)
        res[j] = false;
    }
  }

  return res;
}
