#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class UnionFind {
 private:
  vector<int> par;

 public:
  explicit UnionFind(int n): par(n, -1) {}

  int root(int x) {
    if (par[x] < 0) return x;
    return par[x] = root(par[x]);
  }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  int size(int x) {
    return -par[root(x)];
  }
};
