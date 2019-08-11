//%snippet.set('mint2')%
template<unsigned mod>/*{{{*/
class mint {
public:
  unsigned x;
  mint(): x(0) { }
  mint(signed y) : x(y >= 0 ? y % mod : mod - (-y) % mod) {}
  unsigned get() const { return x; }

  // 逆数
  mint inv() const {
    ll a = 1, p = x, e = mod-2;
    while(e > 0) {
      if(e%2 == 0) {p = (p*p) % mod; e /= 2;}
      else {a = (a*p) % mod; e--;}
    }
    a %= mod;
    return mint(a);
  }
  // e乗
  mint pow(ll e) {
    ll a = 1, p = x;
    while(e > 0) {
      if(e%2 == 0) {p = (p*p) % mod; e /= 2;}
      else {a = (a*p) % mod; e--;}
    }
    a %= mod;
    return mint(a);
  }
  // 2のx乗
  mint pow2() {
    ll a = 1, p = 2, e = x;
    while(e > 0) {
      if(e%2 == 0) {p = (p*p) % mod; e /= 2;}
      else {a = (a*p) % mod; e--;}
    }
    a %= mod;
    return mint(a);
  }

  // Comparators
  bool operator <(mint b) { return x < b.x; }
  bool operator >(mint b) { return x > b.x; }
  bool operator<=(mint b) { return x <= b.x; }
  bool operator>=(mint b) { return x >= b.x; }
  bool operator!=(mint b) { return x != b.x; }
  bool operator==(mint b) { return x == b.x; }

  // increment, decrement
  mint operator++() { x++; return *this; }
  mint operator--() { x--; return *this; }

  // Basic Operations
  mint &operator+=(mint that) {
    x = ((ll)x+that.x)%mod;
    return *this;
  }
  mint &operator-=(mint that) {
    x = ((((ll)x-that.x)%mod)+mod)%mod;
    return *this;
  }
  mint &operator*=(mint that) {
    x = (ll)x * that.x % mod;
    return *this;
  }
  // O(log(mod))かかるので注意
  mint &operator/=(mint that) {
    x = (ll)x * that.inv() % mod;
    return *this;
  }
  mint &operator%=(mint that) {
    x = (ll)x % that.x;
    return *this;
  }
  mint operator+(mint that)const{return mint(*this) += that;}
  mint operator-(mint that)const{return mint(*this) -= that;}
  mint operator*(mint that)const{return mint(*this) *= that;}
  mint operator/(mint that)const{return mint(*this) /= that;}
  mint operator%(mint that)const{return mint(*this) %= that;}
};
typedef mint<1000000007> mint;
ostream& operator<<(ostream& os, const mint& a){
  os << a.x;
  return os;
}
/*}}}*/

//%snippet.set('mint')%
int mod = 1e9+7;
struct mint { //逆元などを使いたければmint2{{{
  int x;
  mint(int x=0):x(x%mod){}
  mint& operator+=(const mint a) {
    (x += a.x) %= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    (x += mod-a.x) %= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
};
ostream& operator<<(ostream& os, const mint& a){
  os << a.x;
  return os;
} //}}}
