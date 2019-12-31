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


# :warning: codes/cpp/graph/kruskal.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3ec2d728d77befc78f832b5911706770">codes/cpp/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/graph/kruskal.cpp">View this file on GitHub</a>
    - Last commit date: 2019-09-14 21:41:36+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
// %snippet.set('kruskal')%
// {{{
template<typename T>
struct Kruskal{
  
  struct edge{
    int from,to;
    T cost;
    int used;
    edge(){}
    edge(int from,int to,T cost):
      from(from),to(to),cost(cost),used(0){}
    bool operator<(const edge& e) const{
      return cost<e.cost;
    }
  };

  int n;
  vector<int> p,r;
  vector<edge> edges;

  Kruskal(){}
  Kruskal(int n):n(n){}

  void init(int n){
    r.assign(n,1);
    p.resize(n);
    iota(p.begin(),p.end(),0);
  }
  
  int find(int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }

  bool same(int x,int y){
    return find(x)==find(y);
  }

  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
  }

  void add_edge(int u,int v,T c){
    edges.emplace_back(u,v,c);
  }
  
  T build(){
    sort(edges.begin(),edges.end());
    init(n);
    T res=0;
    for(auto &e:edges){
      if(!same(e.from,e.to)){
        res+=e.cost;
        unite(e.from,e.to);
        e.used=1;
      }
    }
    return res;
  }
};
// int main(){
//   int V,E;
//   scanf("%d %d",&V,&E);
//   Kruskal<int> ksk(V);
//   for(int i=0;i<E;i++){
//     int a,b,c;
//     scanf("%d %d %d",&a,&b,&c);
//     ksk.add_edge(a,b,c);
//   }
//   printf("%d\n",ksk.build());
//   return 0;
// }
//}}}
//%snippet.end()%
//END CUT HERE

int main(){
  int V,E;
  scanf("%d %d",&V,&E);
  Kruskal<int> ksk(V);
  for(int i=0;i<E;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    ksk.add_edge(a,b,c);
  }
  printf("%d\n",ksk.build());
  return 0;
}

/*
  verified on 2018/10/22
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/graph/kruskal.cpp"
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
// %snippet.set('kruskal')%
// {{{
template<typename T>
struct Kruskal{
  
  struct edge{
    int from,to;
    T cost;
    int used;
    edge(){}
    edge(int from,int to,T cost):
      from(from),to(to),cost(cost),used(0){}
    bool operator<(const edge& e) const{
      return cost<e.cost;
    }
  };

  int n;
  vector<int> p,r;
  vector<edge> edges;

  Kruskal(){}
  Kruskal(int n):n(n){}

  void init(int n){
    r.assign(n,1);
    p.resize(n);
    iota(p.begin(),p.end(),0);
  }
  
  int find(int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }

  bool same(int x,int y){
    return find(x)==find(y);
  }

  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
  }

  void add_edge(int u,int v,T c){
    edges.emplace_back(u,v,c);
  }
  
  T build(){
    sort(edges.begin(),edges.end());
    init(n);
    T res=0;
    for(auto &e:edges){
      if(!same(e.from,e.to)){
        res+=e.cost;
        unite(e.from,e.to);
        e.used=1;
      }
    }
    return res;
  }
};
// int main(){
//   int V,E;
//   scanf("%d %d",&V,&E);
//   Kruskal<int> ksk(V);
//   for(int i=0;i<E;i++){
//     int a,b,c;
//     scanf("%d %d %d",&a,&b,&c);
//     ksk.add_edge(a,b,c);
//   }
//   printf("%d\n",ksk.build());
//   return 0;
// }
//}}}
//%snippet.end()%
//END CUT HERE

int main(){
  int V,E;
  scanf("%d %d",&V,&E);
  Kruskal<int> ksk(V);
  for(int i=0;i<E;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    ksk.add_edge(a,b,c);
  }
  printf("%d\n",ksk.build());
  return 0;
}

/*
  verified on 2018/10/22
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
*/

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

