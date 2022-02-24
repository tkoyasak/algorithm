#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class FloydWarshall {
 private:
  const ll INF = 1LL << 60;
  int v;
  vector<vector<ll>> dp;

 public:
  explicit FloydWarshall(int v) : v(v), dp(v, vector<ll>(v, INF)) {
    for (int i = 0; i < v; ++i) dp[i][i] = 0;
  }

  void input(int e) {
    for (int i = 0; i < e; ++i) {
      int from, to;
      ll cost;
      cin >> from >> to >> cost;
      dp[from][to] = cost;
    }
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

  void output(void) {
    //
  }

  bool negative(void) {
    for (int i = 0; i < v; ++i)
      if (dp[i][i] < 0) return true;
    return false;
  }
};
