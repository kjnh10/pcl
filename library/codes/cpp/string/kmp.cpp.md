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


# :warning: codes/cpp/string/kmp.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f42fe2b40278a2240b94f3b23e9cd7ad">codes/cpp/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/string/kmp.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-14 15:20:35+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//%snippet.set('kmp')%
// kmp をやるための前計算
vector<int> makeTable(const string& s) {
  int n = s.size();
  vector<int> ret(n+1);
  ret[0] = -1;
  int j = -1;
  for (int i = 0; i < n; i++) {
    while (j >= 0 && s[i] != s[j]) j = ret[j];
    ret[i+1] = ++j;
  }
  return ret;
}

// str の中に word とマッチする場所のリストを返す
// ret のそれぞれの要素 el は, 「str[el] からの文字列が word と一致する」ことを示す
vector<int> kmp(const string& str, const string& word) {
  vector<int> table = makeTable(word), ret;
  int m = 0, i = 0, n = str.size();
  while (m+i < n) {
    if (word[i] == str[m+i]) {
      if (++i == (int)(word.size())) {
        ret.push_back(m);
        m = m+i-table[i];
        i = table[i];
      }
    } else {
      m = m+i-table[i];
      if (i > 0) i = table[i];
    }
  }
  return ret;
}
//%snippet.end()%

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/string/kmp.cpp"
//%snippet.set('kmp')%
// kmp をやるための前計算
vector<int> makeTable(const string& s) {
  int n = s.size();
  vector<int> ret(n+1);
  ret[0] = -1;
  int j = -1;
  for (int i = 0; i < n; i++) {
    while (j >= 0 && s[i] != s[j]) j = ret[j];
    ret[i+1] = ++j;
  }
  return ret;
}

// str の中に word とマッチする場所のリストを返す
// ret のそれぞれの要素 el は, 「str[el] からの文字列が word と一致する」ことを示す
vector<int> kmp(const string& str, const string& word) {
  vector<int> table = makeTable(word), ret;
  int m = 0, i = 0, n = str.size();
  while (m+i < n) {
    if (word[i] == str[m+i]) {
      if (++i == (int)(word.size())) {
        ret.push_back(m);
        m = m+i-table[i];
        i = table[i];
      }
    } else {
      m = m+i-table[i];
      if (i > 0) i = table[i];
    }
  }
  return ret;
}
//%snippet.end()%

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

