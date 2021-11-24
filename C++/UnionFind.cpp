#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> p;

  UnionFind(int n): p(n, -1) {}

  int find(int x) {
    if (p[x] < 0) return x;
    else return p[x] = find(p[x]);
  }

  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (p[x] > p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return true;
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  int size(int x) {
    return -p[find(x)];
  }
};
