#include <bits/stdc++.h>
using namespace std;

template<class T>
int longest_increasing_subsequence(vector<T>& arr, bool is_dup = false) {
  int n = arr.size();
  vector<T> lis;

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
  }

  return lis.size();
}