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


# :warning: codes/cpp/geoemtry/dist_between_line_and_point.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#8616042c429b9b7b0fd5371a59ae7751">codes/cpp/geoemtry</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/geoemtry/dist_between_line_and_point.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-21 02:54:48+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

double dist_line_podouble(double x1, double y1, double x2, double y2, double px, double py){
  double num = abs((py-y1)*(x2-x1) - (y2-y1)*(px-x1));
  double den = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
  return num/den;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/geoemtry/dist_between_line_and_point.cpp"

double dist_line_podouble(double x1, double y1, double x2, double y2, double px, double py){
  double num = abs((py-y1)*(x2-x1) - (y2-y1)*(px-x1));
  double den = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
  return num/den;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

