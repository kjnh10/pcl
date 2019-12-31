---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: codes/cpp/mint2.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7c19064045d3d46a80d9dc742b659ff9">codes/cpp</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/mint2.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-15 23:20:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/mint2.cpp"
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


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

