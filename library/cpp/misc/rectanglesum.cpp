#include <bits/stdc++.h>
using namespace std;

//%snippet.set('RectangleSum')%

template <typename T>
struct RectangleSum {
  vector<vector<T>> sum;
  T GetSum(int left, int right, int top, int bottom) { //[left, right], [top, bottom]{{{
    T res = sum[bottom][right];
    if (left > 0) res -= sum[bottom][left - 1];
    if (top > 0) res -= sum[top - 1][right];
    if (left > 0 && top > 0) res += sum[top - 1][left - 1];
    return res;
  }/*}}}*/

  RectangleSum(const vector<vector<T>> &s) {/*{{{*/
    int h = s.size();
    int w = s[0].size();
    sum.resize(h);
    for (int i = 0; i < h; i ++) sum[i].resize(w, 0);
    for (int y = 0; y < h; y ++) {
      for (int x = 0; x < w; x ++) {
        sum[y][x] = s[y][x];
        if (y > 0) sum[y][x] += sum[y - 1][x];
        if (x > 0) sum[y][x] += sum[y][x - 1];
        if (y > 0 && x > 0) sum[y][x] -= sum[y - 1][x - 1];
      }
    }
  }/*}}}*/
};

//%snippet.end()%
