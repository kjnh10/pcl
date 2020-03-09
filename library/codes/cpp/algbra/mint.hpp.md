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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :warning: codes/cpp/algbra/mint.hpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#23a23c125caf8741d8c92b2934bce27d">codes/cpp/algbra</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/algbra/mint.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 23:30:07+09:00




## Depends on

* :heavy_check_mark: <a href="../template.hpp.html">codes/cpp/template.hpp</a>


## Required by

* :warning: <a href="bsgs/bsgs.cpp.html">codes/cpp/algbra/bsgs/bsgs.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../template.hpp"

//%snippet.set('mint')%
int mod = 1e9+7;
struct mint { //{{{
    int x;
    mint(int x=0):x((x%mod+mod)%mod){}

    // ?= operator
    mint& operator+=(const mint a) { (x += a.x) %= mod; return *this; }
    mint& operator-=(const mint a) { (x += mod-a.x) %= mod; return *this; }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }

    mint operator+(const mint a) const { mint res(*this); return res+=a; }
    mint operator-(const mint a) const { mint res(*this); return res-=a; }
    mint operator*(const mint a) const { mint res(*this); return res*=a; }
    mint&operator/=(const mint&rhs){
        if (rhs.x==0) throw runtime_error("mint zero division");
        return *this*=rhs.inv(); 
    }

    mint pow(int n)const{
        mint res(1),x(*this);
        if (n<0){
            n = -n;
            x =(*this).inv();
        }
        while(n){
            if(n&1)res*=x;
            x*=x;
            n>>=1;
        }
        return res;
    }
    mint inv() const{
        if (x==0) throw runtime_error("inv does not exist");
        return pow(mod-2);
    }
    /*mint inv()const{
      int x,y;
      int g=extgcd(v,mod,x,y);
      assert(g==1);
      if(x<0)x+=mod;
      return mint(x);
      }*/
    operator int() const{return x;}
    bool operator<(const mint&r)const{return x<r.x;}
    bool operator==(const mint&r)const{return x==r.x;}
};
istream& operator>>(istream& is, const mint& a) {return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) {return os << a.x;}
//}}}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 68, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 182, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 181, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: codes/cpp/template.hpp: line 48: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

