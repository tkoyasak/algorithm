#include <bits/stdc++.h>
using namespace std;

class Edge {
 public:
  int from, to;
  long cost;
  explicit Edge(int from, int to, long cost) : from(from), to(to), cost(cost) {}
};

class Dijkstra {
 private:
  const long INF = 1LL << 60;
  int v;
  vector<long> dp;
  vector<int> prev;
  vector<vector<Edge>> es;

 public:
  explicit Dijkstra(int v) : v(v), dp(v, INF), prev(v, -1), es(v) {}

  void input(int e) {
    for (int i = 0; i < e; ++i) {
      int from, to;
      long cost;
      cin >> from >> to >> cost;
      es[from].emplace_back(from, to, cost);
    }
  }

  void solve(int s) {
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> q;
    dp[s] = 0;
    q.emplace(dp[s], s);
    while (!q.empty()) {
      auto [cost, cur] = q.top(); q.pop();
      if (dp[cur] < cost) continue;
      for (auto u : es[cur]) {
        if (dp[u.to] > dp[cur] + u.cost) {
          dp[u.to] = dp[cur] + u.cost;
          prev[u.to] = cur;
          q.emplace(dp[u.to], u.to);
        }
      }
    }
  }

  vector<int> get_path(int t) {
    vector<int> path;
    while (t != -1) {
      path.emplace_back(t);
      t = prev[t];
    }
    reverse(path.begin(), path.end());
    return path;
  }
};
