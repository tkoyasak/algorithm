#include <bits/stdc++.h>
using namespace std;

class Dijkstra {
 private:
  const long INF = 1LL << 60;
  int v;
  vector<long> dp;
  vector<int> prev;
  vector<vector<pair<int, long>>> es;

 public:
  explicit Dijkstra(int v) : v(v), es(v) {}

  void input(int e) {
    for (int i = 0; i < e; ++i) {
      int from, to;
      long cost;
      cin >> from >> to >> cost;
      es[from].emplace_back(to, cost);
    }
  }

  void solve(int s) {
    dp.assign(v, INF);
    prev.assign(v, -1);
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> q;
    dp[s] = 0;
    q.emplace(dp[s], s);
    while (!q.empty()) {
      auto [d, cur] = q.top(); q.pop();
      if (dp[cur] < d) continue;
      for (auto u : es[cur]) {
        long cost = dp[cur] + u.second;
        if (dp[u.first] > cost) {
          dp[u.first] = cost;
          prev[u.first] = cur;
          q.emplace(dp[u.first], u.first);
        }
      }
    }
  }

  void output(void) {
    // 
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
