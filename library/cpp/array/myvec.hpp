#pragma once
#include "../header.hpp"

//%snippet.set('pyvec')%
//%snippet.config({'alias':'vector_neg'})%
//%snippet.fold()%
template <class T>
struct pyvec {
    vector<T> v;
    pyvec(){}
    pyvec(int n_){ v = vector<T>(n_); }
    pyvec(int n_, T x){ v = vector<T>(n_, x); }
    T& operator[](int i){
        if (i>=0) return v[i];
        else return v[(int)v.size()+i];
    }
    auto begin(){ return v.begin(); }
    auto end(){ return v.end(); }
    auto push_back(){ return v.push_back(); }
    auto emplace_back(){ return v.emplace_back(); }
    auto size() const { return v.size(); }
    auto clear() { v.clear(); }
    auto resize(int x) { v.resize(x); }
    auto back() {this[-1];}
};
template<class T>
ostream& operator<<(ostream& os, const pyvec<T>& a) {
    os << a.v; return os; 
}
template<class T=ll> using vec = pyvec<T>;
//%snippet.end()%


//%snippet.set('asvector')%
//%snippet.fold()%
// acumulative sum vector 
template<typename T=ll>
struct asvector {
    vector<T> v; //accumulative sum
    vector<T> cum; //accumulative sum
    asvector(){};
    asvector(int n_){ v = vector<T>(n_); }
    asvector(int n_, T x){ v = vector<T>(n_, x); }
    T& operator[](int i){
        if (i>=0) return v[i];
        else return v[(int)v.size()+i];
    }
    auto begin(){ return v.begin(); }
    auto end(){ return v.end(); }
    auto push_back(){ return v.push_back(); }
    auto emplace_back(){ return v.emplace_back(); }
    auto size() const { return v.size(); }
    auto clear() { v.clear(); }
    auto resize(int x) { v.resize(x); }
    auto back() {this[-1];}

    void build() {
        cum.resize(sz(v));
        rep(i, 1, sz(v)) cum[i]+=cum[i-1];
    }

    T sum(int l, int r) {  // return sum of [l, r) of data.  {{{
        l = max(0, l);
        r = min(r, sz(cum));
        if (l<r) return cum[r-1] - (l-1>=0 ? cum[l-1] : 0);
        else     return 0;
    } // }}}

    friend ostream& operator<<(ostream &os, asvector<T>& as){//{{{
        os << as.v; return os;
    } //}}}
};
//


// TODO
// neg shifter vec
