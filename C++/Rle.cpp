#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>
vector<pair<int, int>> rl_encoding(T& arr) {
  vector<pair<int, int>> res;

  int m = arr.size(), cnt = 1;
  for (int i = 1; i < m; i++) {
    if (arr[i] == arr[i - 1]) cnt++;
    else res.emplace_back(arr[i - 1], cnt), cnt = 1;
  }
  res.emplace_back(arr[m - 1], cnt);

  return res;
}
