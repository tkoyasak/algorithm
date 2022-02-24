#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>
class Lis {
 public:
  vector<T> lis, sz;

  Lis(vector<T>& arr, bool is_dup = false) {
    for(auto x : arr) {
      if (lis.size() == 0) lis.emplace_back(x);
      else {
        if (is_dup) {
          if (x >= lis.back()) lis.emplace_back(x);
          else *upper_bound(lis.begin(), lis.end(), x) = x;
        }
        else {
          if (x > lis.back()) lis.emplace_back(x);
          else *lower_bound(lis.begin(), lis.end(), x) = x;
        }
      }
      sz.emplace_back(lis.size());
    }
  }
};
