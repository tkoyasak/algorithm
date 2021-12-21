#include <bits/stdc++.h>
using namespace std;

template<int MOD>
class ModInt {
 public:
  long x;
  ModInt(long x = 0) : x((x % MOD + MOD) % MOD) {}

  ModInt& operator+=(const ModInt& other) {
    if ((x += other.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt& operator-=(const ModInt& other) {
    if ((x += MOD - other.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt& operator*=(const ModInt& other) {
    (x *= other.x) %= MOD;
    return *this;
  }
  ModInt& operator/=(const ModInt& other) {
    return *this *= other.inv();
  }

  ModInt operator+(const ModInt& other) const {
    return ModInt(*this) += other;
  }
  ModInt operator-(const ModInt& other) const {
    return ModInt(*this) -= other;
  }
  ModInt operator*(const ModInt& other) const {
    return ModInt(*this) *= other;
  }
  ModInt operator/(const ModInt& other) const {
    return ModInt(*this) /= other;
  }

  bool operator==(const ModInt& other) const {
    return x == other.x;
  }
  bool operator!=(const ModInt& other) const {
    return x != other.x;
  }

  ModInt inv(void) const {
    return pow(MOD - 2);
  }
  ModInt pow(long t) const {
    if (!t) return 1;
    ModInt a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
};

template<int MOD> ostream& operator<<(ostream& os, const ModInt<MOD>& val) {
  return os << val.x;
}

typedef ModInt<1000000007> mint;
