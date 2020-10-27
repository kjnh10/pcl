#pragma once
#include "../../header.hpp"

//%snippet.set('shifter')%

struct shifter{
    ll n, min_v;
    shifter(ll _min_v, ll _max_v): min_v(_min_v){
        n = _max_v - min_v;
    }
    ll operator()(ll x) { return x - min_v; }
    ll unshift(ll sx) { return sx + min_v; }
};
// How to use
    // auto sh = shifter(-10000, 10000);
    // vl x(sh.n);
    // x[sh(-3)];

//%snippet.end()%
