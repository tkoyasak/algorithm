#include <bits/stdc++.h>
using namespace std;

class FloydWarshall {
 private:
  const long INF = 1LL << 60;
  int v;
  vector<vector<long>> d;

 public:
  explicit FloydWarshall(int v) : v(v), d(v, vector<long>(v, INF)) {
    for (int i = 0; i < v; ++i) d[i][i] = 0;
  }

  void add_edge(int from, int to, long cost) {
    d[from][to] = cost;
  }

  void solve(void) {
    for (int k = 0; k < v; ++k)
      for (int i = 0; i < v; ++i)
        for (int j = 0; j < v; ++j)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  }
};
