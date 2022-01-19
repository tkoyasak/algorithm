#include <bits/stdc++.h>
using namespace std;

class FloydWarshall {
 private:
  const long INF = 1LL << 60;
  int v, e;
  vector<vector<long>> dp;

 public:
  explicit FloydWarshall(int v, int e) : v(v), e(e), dp(v, vector<long>(v, INF)) {
    for (int i = 0; i < v; ++i) dp[i][i] = 0;
  }

  void input(void) {
    for (int i = 0; i < e; ++i) {
      int from, to;
      long cost;
      cin >> from >> to >> cost;
      dp[from][to] = cost;
    }
  }

  void solve(void) {
    for (int k = 0; k < v; ++k)
      for (int i = 0; i < v; ++i)
        for (int j = 0; j < v; ++j)
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
  }

  bool negative(void) {
    for (int i = 0; i < v; ++i)
      if (dp[i][i] < 0) return true;
    return false;
  }
};
