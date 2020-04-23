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


# :warning: codes/cpp/misc/event_sort.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#332ea86b24dcdfe987d2922eb448b5fe">codes/cpp/misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/misc/event_sort.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 12:58:45+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

//%snippet.set('event_sort')%

struct Event {
	Event(int t_, int s_, int e_, int isIn_) : t(t_), s(s_), e(e_), isIn(isIn_) {}
	int t;
	int s, e;
	int isIn;

	bool operator<(const Event& rhs) {
		if (t == rhs.t)
			return isIn < rhs.isIn;

		return t < rhs.t;
	}
};

void event_sort(vector<int>& s, vector<int>& e) {
  // 回収はl, rは掃除するversion
	multiset<int> e_set;
  int n = sz(s);

	vector<Event> events;
	for (int i = 0; i < n; i++) {
		events.emplace_back(s[i], s[i], e[i], 1);
		events.emplace_back(e[i] + 1, s[i], e[i], 0);
	}

	sort(all(events));

	for (int i = 0; i < 2 * n; i++) {
		if (events[i].isIn) {
			e_set.insert(events[i].e);
		}
		else {
			e_set.erase(e_set.find(events[i].e));
		}
	}
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/misc/event_sort.cpp"

//%snippet.set('event_sort')%

struct Event {
	Event(int t_, int s_, int e_, int isIn_) : t(t_), s(s_), e(e_), isIn(isIn_) {}
	int t;
	int s, e;
	int isIn;

	bool operator<(const Event& rhs) {
		if (t == rhs.t)
			return isIn < rhs.isIn;

		return t < rhs.t;
	}
};

void event_sort(vector<int>& s, vector<int>& e) {
  // 回収はl, rは掃除するversion
	multiset<int> e_set;
  int n = sz(s);

	vector<Event> events;
	for (int i = 0; i < n; i++) {
		events.emplace_back(s[i], s[i], e[i], 1);
		events.emplace_back(e[i] + 1, s[i], e[i], 0);
	}

	sort(all(events));

	for (int i = 0; i < 2 * n; i++) {
		if (events[i].isIn) {
			e_set.insert(events[i].e);
		}
		else {
			e_set.erase(e_set.find(events[i].e));
		}
	}
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

