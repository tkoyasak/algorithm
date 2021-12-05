#include <bits/stdc++.h>
using namespace std;

struct LowLink {
  vector<int> aps;
  vector<pair<int, int>> brs;

  vector<int> seen, ord, low;
  void dfs(const vector<vector<int>>& g, int v, int p = -1) {
    static int time = 0;
    int children = 0;
    bool is_ap = false;

    seen[v] = 1;
    low[v] = ord[v] = time++;
    for (auto c : g[v]) {
      if (seen[c]) {
        if (c != p) low[v] = min(low[v], ord[c]);
        continue;
      }
      dfs(g, c, v);
      low[v] = min(low[v], low[c]);
      if (low[c] > ord[v]) brs.emplace_back(v, c);
      if (low[c] >= ord[v]) is_ap = true;
      children++;
    }
    if ((p == -1 && children > 1) || (p != -1 && is_ap)) aps.emplace_back(v);
  }

  void solve(const vector<vector<int>>& g) {
    int n = g.size();

    seen.assign(n, 0); ord.assign(n, 0); low.assign(n, 0);
    aps.clear(); brs.clear();
    for (int i = 0; i < n; ++i) {
      if (!seen[i]) dfs(g, i);
    }
  }
};

int main(void) {
  int v, e; cin >> v >> e;
  vector<vector<int>> g(v);
  for (int i = 0; i < e; ++i) {
    int a, b; cin >> a >> b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  LowLink ll;
  ll.solve(g);
}
