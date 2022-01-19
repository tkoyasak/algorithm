#include <bits/stdc++.h>
using namespace std;

class Edge {
 public:
  int from, to;
  long cost;
  explicit Edge(int from, int to, long cost) : from(from), to(to), cost(cost) {}
};

class BellmanFord {
 private:
  const long INF = 1LL << 60;
  int v, e;
  vector<long> dp;
  vector<Edge> es;

 public:
  explicit BellmanFord(int v, int e) : v(v), e(e), dp(v, INF) {}

  void input(void) {
    for (int i = 0; i < e; ++i) {
      int from, to;
      long cost;
      cin >> from >> to >> cost;
      es.emplace_back(from, to, cost);
    }
  }

  bool solve(int s, int v, int e) {
    dp[s] = 0;
    for (int i = 0; i < v; ++i) {
      for (auto u : es) {
        if (dp[u.from] == INF) continue;
        if (dp[u.to] > dp[u.from] + u.cost) {
          dp[u.to] = dp[u.from] + u.cost;
          if (i == v - 1) return true;
        }
      }
    }
    return true;
  }
};
