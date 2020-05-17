#include "../../header.hpp"

using C = complex<ld>;
#define X real()
#define Y imag()

const double EPS = 1e-1;

// 2点を与えると, それを通る半径rの円の中央2つを返す
vector<C> f(C a, C b, ld r){
  vector<C> ret;
  
  // a, bの距離が大きすぎると作れない
  {
    ld d = abs(a-b);
    if(d>2*r){
        return {a, b};
    }
  }

  C c = (a+b)/(ld)2.0;

  ld temp = r*r - norm(a-c);
  ld x = sqrt(temp);

  //中央に向かうベクトル
  C d = c-a;
  C e = {-d.Y, d.X}; // 垂直ベクトル
  C f = e / abs(e); // 単位ベクトル

  ret.push_back(c+x*f);
  ret.push_back(c-x*f);

  return ret;
}
