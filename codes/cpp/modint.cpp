template<unsigned MOD>
class ModInt {
public:
  unsigned x;
  ModInt(): x(0) { }
  ModInt(signed y) : x(y >= 0 ? y % MOD : MOD - (-y) % MOD) {}
  unsigned get() const { return x; }

  // 逆数
  ModInt inv() const {
    ll a = 1, p = x, e = MOD-2;
    while(e > 0) {
      if(e%2 == 0) {p = (p*p) % MOD; e /= 2;}
      else {a = (a*p) % MOD; e--;}
    }
    a %= MOD;
    return ModInt(a);
  }
  // e乗
  ModInt pow(ll e) {
    ll a = 1, p = x;
    while(e > 0) {
      if(e%2 == 0) {p = (p*p) % MOD; e /= 2;}
      else {a = (a*p) % MOD; e--;}
    }
    a %= MOD;
    return ModInt(a);
  }
  // 2のx乗
  ModInt pow2() {
    ll a = 1, p = 2, e = x;
    while(e > 0) {
      if(e%2 == 0) {p = (p*p) % MOD; e /= 2;}
      else {a = (a*p) % MOD; e--;}
    }
    a %= MOD;
    return ModInt(a);
  }

  // Comparators
  bool operator <(ModInt b) { return x < b.x; }
  bool operator >(ModInt b) { return x > b.x; }
  bool operator<=(ModInt b) { return x <= b.x; }
  bool operator>=(ModInt b) { return x >= b.x; }
  bool operator!=(ModInt b) { return x != b.x; }
  bool operator==(ModInt b) { return x == b.x; }

  // increment, decrement
  ModInt operator++() { x++; return *this; }
  ModInt operator--() { x--; return *this; }

  // Basic Operations
  ModInt &operator+=(ModInt that) {
    x = ((ll)x+that.x)%MOD;
    return *this;
  }
  ModInt &operator-=(ModInt that) {
    x = ((((ll)x-that.x)%MOD)+MOD)%MOD;
    return *this;
  }
  ModInt &operator*=(ModInt that) {
    x = (ll)x * that.x % MOD;
    return *this;
  }
  // O(log(mod))かかるので注意
  ModInt &operator/=(ModInt that) {
    x = (ll)x * that.inv() % MOD;
    return *this;
  }
  ModInt &operator%=(ModInt that) {
    x = (ll)x % that.x;
    return *this;
  }
  ModInt operator+(ModInt that)const{return ModInt(*this) += that;}
  ModInt operator-(ModInt that)const{return ModInt(*this) -= that;}
  ModInt operator*(ModInt that)const{return ModInt(*this) *= that;}
  ModInt operator/(ModInt that)const{return ModInt(*this) /= that;}
  ModInt operator%(ModInt that)const{return ModInt(*this) %= that;}
};
typedef ModInt<1000000007> mint;

// tourist mod calc{{{
const int md = (int) 1e9 + 7;
inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}
inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}
inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}
inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}
//}}}
