#include <bits/stdc++.h>
using namespace std;

struct FloydWarshall {
  const int64_t INF = 1LL << 60;
  vector<vector<int64_t>> d;

  explicit FloydWarshall(int v) : d(v, vector<int64_t>(v, INF)) {
    for (int i = 0; i < v; i++) d[i][i] = 0;
  }

  void add_edge(int from, int to, int64_t w) {
    d[from][to] = w;
  }

  void solve(void) {
    int v = d.size();

    for (int k = 0; k < v; ++k) {
      for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
  }
};
