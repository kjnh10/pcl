#include "../../../problem_template/codes/header.hpp"

//%snippet.set('slide_min')%
template< typename T >  //{{{
vector<T> slide_min(const vector<T> &v, int k) {
  deque< int > deq;
  vector< T > ret;
  int m = sz(v);
  rep(i, m){
    while(!deq.empty() && v[deq.back()] >= v[i]) {
      deq.pop_back();
    }
    deq.push_back(i);
    if(i - k + 1 >= 0) {
      ret.emplace_back(v[deq.front()]);
      if(deq.front() == i - k + 1) deq.pop_front();
    }
  }
  return ret;  // sz(res) == m-k+1, last index is m-k
}  //}}}
//%snippet.end()%
