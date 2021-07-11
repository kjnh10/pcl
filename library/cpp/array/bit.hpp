#pragma once
#include "../header.hpp"

//%snippet.set('bit')%

template <typename T = ll>
struct bit {  //{{{
    int n;
    vector<T> dat;
    vector<T> raw;

    bit(int _n = 0) {  //{{{
        n = _n;
        dat = vector<T>(n);
        raw = vector<T>(n);
    }  //}}}

    bit(vector<T> a) {  // {{{
        n = (int)a.size();
        dat = vector<T>(n);
        raw = vector<T>(n);
        for (int i = 0; i < n; i++) {
            add(i, a[i]);
            raw[i] = a[i];
        }
    }  //}}}

    T operator[](int i) { return query(i, i+1); }

    T _rsum(int i) {  //{{{ [0, i]
        T s = 0;
        while (i >= 0) {
            s += dat[i];
            i = (i & (i + 1)) - 1;
        }
        return s;
    }  //}}}

    T query(int l, int r) {  //{{{  [l, r)
        if (l > r - 1) return 0;
        return _rsum(r - 1) - _rsum(l - 1);
    }  //}}}

    void add(int i, T x) {  //{{{
        raw[i] += x;
        while (i < n) {
            dat[i] += x;
            i |= i + 1;
        }
    }  //}}}

    int lower_bound(T x) {  // a[0]+...+a[ret] >= x{{{
        int ret = -1;
        int k = 1;
        while (2 * k <= n) k <<= 1;
        for (; k > 0; k >>= 1) {
            if (ret + k < n && dat[ret + k] < x) {
                x -= dat[ret + k];
                ret += k;
            }
        }
        return ret + 1;
    }  //}}}

    #if defined(PCM) || defined(LOCAL)
    friend ostream& operator<<(ostream& os, bit<T>& b) {  //{{{
        os << endl << "  raw:" << b.raw << endl;
        vector<T> acum;
        rep(i, b.n) { acum.pb(b.query(i, i+1)); }
        os << "  acm:" << acum << endl;
        return os;
    }  //}}}
    #endif
};     //}}}

//%snippet.end()%
