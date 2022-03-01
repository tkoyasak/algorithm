#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Dijkstra {
 private:
  const ll INF = 1LL << 60;
  int v;
  vector<int> prev;
 public:
  vector<ll> dp;
  vector<vector<pair<int, ll>>> es;

 public:
  explicit Dijkstra(int v) : v(v), es(v) {}

  void solve(int s) {
    dp.assign(v, INF);
    prev.assign(v, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    dp[s] = 0;
    q.emplace(dp[s], s);
    while (!q.empty()) {
      auto [d, cur] = q.top(); q.pop();
      if (dp[cur] < d) continue;
      for (auto u : es[cur]) {
        ll cost = dp[cur] + u.second;
        if (dp[u.first] > cost) {
          dp[u.first] = cost;
          prev[u.first] = cur;
          q.emplace(dp[u.first], u.first);
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
