#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Edge {
 public:
  int from, to;
  ll cost;
  explicit Edge(int from, int to, ll cost) : from(from), to(to), cost(cost) {}
};

class BellmanFord {
 private:
  const ll INF = 1LL << 60;
  int v;
 public:
  vector<ll> dp;
  vector<Edge> es;

 public:
  explicit BellmanFord(int v) : v(v) {}

  bool solve(int s, int v) {
    dp.assign(v, INF);
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
