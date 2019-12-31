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


# :warning: codes/cpp/string/rollinghash.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f42fe2b40278a2240b94f3b23e9cd7ad">codes/cpp/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/string/rollinghash.cpp">View this file on GitHub</a>
    - Last commit date: 2019-09-30 18:04:35+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct RollingHash{
    vector<int64_t> hash;
    vector<int64_t> base_pow;
    int64_t base, mod;
    static const int64_t DEFAULT_BASE = 1009, DEFAULT_MOD = 1e9+7;

    RollingHash(string S="", int64_t base=DEFAULT_BASE, int64_t mod=DEFAULT_MOD):base(base), mod(mod){
        if(S.size() > 0) initialize(S);
    }

    void initialize(string& S){
        int N = S.size();
        vector<int> s(N);
        for(int i=0; i<N; i++) s[i] = S[i];
        initialize(s);
    }

    void initialize(vector<int>& S){
        int len = S.size();
        hash.resize(len+1);
        base_pow.resize(len+1);
        hash[0] = 0;
        base_pow[0] = 1;
        for(int i=1; i<=len; i++){
            hash[i] = (hash[i-1] * base + S[i-1]) % mod;
            base_pow[i] = base_pow[i-1] * base % mod;
        }
    }

    // 0-indexed, [a, b)
    int64_t between(int a, int b){
        return (mod + hash[b] - hash[a] * base_pow[b-a] % mod) % mod;
    }
};

int main(){
    int N;
    string S;
    cin >> N >> S;
    int ok = 0, ng = N/2+1;
    RollingHash rh1(S, 1007, 1e9+7);

    while(ng-ok>1){
        int len = (ng+ok)/2;
        set<int64_t> val;
        vector<int64_t> v(N);
        bool success = false;
        for(int i=0; i+len<=N; i++){
            if(i >= len) val.insert(v[i-len]);
            v[i] = rh1.between(i, i+len);
            if(val.count(v[i])){
                success = true;
                break;
            }
        }
        (success ? ok : ng) = len;
    }
    cout << ok << endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/string/rollinghash.cpp"
struct RollingHash{
    vector<int64_t> hash;
    vector<int64_t> base_pow;
    int64_t base, mod;
    static const int64_t DEFAULT_BASE = 1009, DEFAULT_MOD = 1e9+7;

    RollingHash(string S="", int64_t base=DEFAULT_BASE, int64_t mod=DEFAULT_MOD):base(base), mod(mod){
        if(S.size() > 0) initialize(S);
    }

    void initialize(string& S){
        int N = S.size();
        vector<int> s(N);
        for(int i=0; i<N; i++) s[i] = S[i];
        initialize(s);
    }

    void initialize(vector<int>& S){
        int len = S.size();
        hash.resize(len+1);
        base_pow.resize(len+1);
        hash[0] = 0;
        base_pow[0] = 1;
        for(int i=1; i<=len; i++){
            hash[i] = (hash[i-1] * base + S[i-1]) % mod;
            base_pow[i] = base_pow[i-1] * base % mod;
        }
    }

    // 0-indexed, [a, b)
    int64_t between(int a, int b){
        return (mod + hash[b] - hash[a] * base_pow[b-a] % mod) % mod;
    }
};

int main(){
    int N;
    string S;
    cin >> N >> S;
    int ok = 0, ng = N/2+1;
    RollingHash rh1(S, 1007, 1e9+7);

    while(ng-ok>1){
        int len = (ng+ok)/2;
        set<int64_t> val;
        vector<int64_t> v(N);
        bool success = false;
        for(int i=0; i+len<=N; i++){
            if(i >= len) val.insert(v[i-len]);
            v[i] = rh1.between(i, i+len);
            if(val.count(v[i])){
                success = true;
                break;
            }
        }
        (success ? ok : ng) = len;
    }
    cout << ok << endl;
    return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

