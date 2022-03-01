#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class FloydWarshall {
 private:
  const ll INF = 1LL << 60;
  int v;
 public:
  vector<vector<ll>> dp;

 public:
  explicit FloydWarshall(int v) : v(v), dp(v, vector<ll>(v, INF)) {
    for (int i = 0; i < v; ++i) dp[i][i] = 0;
  }

  void solve(void) {
    for (int k = 0; k < v; ++k) {
      for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
          if (dp[i][k] == INF || dp[k][j] == INF) continue;
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }
  }

  bool negative(void) {
    for (int i = 0; i < v; ++i)
      if (dp[i][i] < 0) return true;
    return false;
  }
};
