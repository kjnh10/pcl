#include "../../../../problem_template/codes/header.hpp"

//%snippet.set('Pos')%
struct Pos{
  int x,y;
  Pos(int _x, int _y) : x(_x), y(_y){
  }
  Pos() {
    x = 0; y = 0;
  }
  bool in(int a, int b, int c, int d){ // x in [a, b) && y in [c, d)
    if (a<=x && x<b && c<=y && y<d) return true;
    else return false;
  }

  bool operator<(const Pos &r) const { return (x!=r.x ? x<r.x : y<r.y); }
  bool operator>(const Pos &r) const { return (x!=r.x ? x>r.x : y>r.y); }
  bool operator==(const Pos &r) const { return (x==r.x && y==r.y); }

  friend ostream& operator<<(ostream& stream, Pos p){
    stream << "(" << p.x <<  "," << p.y << ")";
    return stream;
  }
};
//%snippet.config({'alias':'pos'})%
//%snippet.end%
