#include "../../header.hpp"

//%snippet.set('zipper')%

struct zipper {                             /*{{{*/
    // unordered_map<long long, int> zip_map;  // [2:0, 3:1, 5:2, 10:3] debugしづらい
    map<long long, int> zip_map;  // [2:0, 3:1, 5:2, 10:3]
    vector<long long> _unzipper;            // [2, 3, 5, 10]
    bool _is_build = false;
    int n = 0;

    zipper(long long inf_value = INF) { /*{{{*/
        _unzipper.push_back(-inf_value);
        _unzipper.push_back(inf_value);
    }                                                        /*}}}*/
    zipper(vector<long long> a, long long inf_value = INF) { /*{{{*/
        _unzipper = vector<long long>(sz(a));
        rep(i, sz(a)) { _unzipper[i] = a[i]; }
        _unzipper.push_back(-inf_value);
        _unzipper.push_back(inf_value);
        build();
    }                              /*}}}*/
    void add_value(long long lv) { /*{{{*/
        _unzipper.push_back(lv);
        _is_build = false;
    }              /*}}}*/
    void build() { /*{{{*/
        uni(_unzipper);
        zip_map.clear();
        n = sz(_unzipper);
        rep(i, n) { zip_map[_unzipper[i]] = i; }
        _is_build = true;
    }                              /*}}}*/
    vector<int> zip(vector<long long> lvs) { /*{{{*/
        if (!_is_build) assert(false);
        int n = sz(lvs);
        vector<int> res(n);
        rep(i, n) res[i] = zip_map[lvs[i]];
        return res;
    }                              /*}}}*/
    int zip(long long lv) { /*{{{*/
        if (!_is_build) assert(false);
        return zip_map[lv];
    }                                               /*}}}*/
    int operator()(long long lv) { return zip(lv); }

    long long unzip(int sv) { /*{{{*/
        if (!_is_build) assert(false);
        return _unzipper[sv];
    }                              /*}}}*/
    int operator[](int sv) { return unzip(sv); }

    int size() {return n;}

#if defined(PCM) || defined(LOCAL) /*{{{*/
    friend ostream& operator<<(ostream& os, const zipper& zp) {
        os << endl;
        os << "_is_build: " << zp._is_build << endl;
        os << "zip_map:   " << zp.zip_map << endl;
        os << "_unzipper:   " << zp._unzipper << endl;
        return os;
    }
#endif /*}}}*/
};     /*}}}*/
// How to use {{{
// construct
// auto z = zipper(x); // x: vector<long long>;
// auto z = zipper(x, 30*INF);

// auto z = zipper();
// auto z = zipper();
// z.add_value(3);
// z.add_value(5);
// z.add_value(10);
// z.add_value(100000000);
// z.build();

// other method
// z(x[i]); -> zipped x[i]
// z.unzip(z(x[i])) -> x[i];
// z.get_zipped(x) -> zipped x
// }}}

//%snippet.end()%
