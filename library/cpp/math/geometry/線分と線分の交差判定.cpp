#include "../../header.hpp"
#include "p2.hpp"

using P = P2<ll>;

bool is_cross_1(P& a, P& b, P& p1, P& p2){
    // abの両サイドにp1, p2が存在しているか。
    auto f = [&](ll x, ll y){
        return (a.y - b.y) * (x - b.x) - (a.x - b.x) * (y - b.y);
    };
    if (f(p1.x, p1.y) * f(p2.x, p2. y) < 0) return true;
    else return false;
}

bool is_cross(P& a, P& b, P& p1, P& p2){
    // 線分としてクロスしているか
    return is_cross_1(a, b, p1, p2) && is_cross_1(p1, p2, a, b);
}
