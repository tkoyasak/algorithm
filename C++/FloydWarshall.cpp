#include <bits/stdc++.h>
using namespace std;

class FloydWarshall {
 private:
  const long INF = 1LL << 60;
  int v;
  vector<vector<long>> dp;

 public:
  explicit FloydWarshall(int v) : v(v), dp(v, vector<long>(v, INF)) {
    for (int i = 0; i < v; ++i) dp[i][i] = 0;
  }

  void add_edge(int from, int to, long cost) {
    dp[from][to] = cost;
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

  vector<vector<long>> get_path(void) {
    return dp;
  }
};
