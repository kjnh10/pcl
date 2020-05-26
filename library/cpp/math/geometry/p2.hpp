#include "../../header.hpp"

//%snippet.set('P2')%
//%snippet.config({'alias':'pos'})%
//%snippet.config({'alias':'point'})%
//%snippet.config({'alias':'pair'})%

template<class T=ll>/*{{{*/
struct P2 {
    T x, y;
    P2(T _x, T _y) : x(_x), y(_y) {}
    P2() {
        x = 0;
        y = 0;
    }
    bool operator<(const P2 &r) const {
        return (x != r.x ? x < r.x : y < r.y);
    }
    bool operator>(const P2 &r) const {
        return (x != r.x ? x > r.x : y > r.y);
    }
    bool operator==(const P2 &r) const { return (x == r.x && y == r.y); }

    friend ostream &operator<<(ostream &stream, P2 p) {
        stream << "(" << p.x << "," << p.y << ")";
        return stream;
    }

    P2 operator-() const {  // 単項演算子
        return P2(-x, -y);
    }

    P2& operator+=(const P2<T>& r){
        x += r.x;
        y += r.y;
        return *this;
    }
    P2& operator-=(const P2<T>& r){
        x -= r.x;
        y -= r.y;
        return *this;
    }
    P2& operator+=(const T& r){
        x += r;
        y += r;
        return *this;
    }
    P2& operator-=(const T& r){
        x -= r;
        y -= r;
        return *this;
    }
    P2& operator*=(const P2<T>& r){
        x *= r.x;
        y *= r.y;
        return *this;
    }
    P2& operator/=(const P2<T>& r){
        x /= r.x;
        y /= r.y;
        return *this;
    }
    P2& operator*=(const T& r){
        x *= r;
        y *= r;
        return *this;
    }
    P2& operator/=(const T& r){
        x /= r;
        y /= r;
        return *this;
    }

    template<class U>
    P2 operator+(const U& r) const {
        P2 res(*this);
        return res += r;
    }
    template<class U>
    P2 operator-(const U& r) const {
        P2 res(*this);
        return res -= r;
    }

    template<class U>
    P2 operator*(const U& r) const {
        P2 res(*this);
        return res *= r;
    }
    template<class U>
    P2 operator/(const U& r) const {
        P2 res(*this);
        return res /= r;
    }


    bool in(T a, T b, T c, T d) {  // x in [a, b) && y in [c, d)
        if (a <= x && x < b && c <= y && y < d) return true;
        else return false;
    }

};/*}}}*/
using P = P2<ll>;

//%snippet.end%
