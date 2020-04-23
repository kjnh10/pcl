#include "./template.hpp"

//%snippet.set('zip')%

struct zipper{/*{{{*/
    unordered_map<long long, int> zip_map; // [2:0, 3:1, 5:2, 10:3]
    vector<long long> _unzipper; // [2, 3, 5, 10]
    bool _is_build = false;

    zipper(long long inf_value = INF){/*{{{*/
        _unzipper.push_back(-inf_value);
        _unzipper.push_back(inf_value);
    }/*}}}*/
    zipper(vector<long long> a, long long inf_value = INF){/*{{{*/
        int n = sz(a);
        _unzipper = vector<long long>(n);
        rep(i, n) { _unzipper[i]=a[i]; }
        _unzipper.push_back(-inf_value);
        _unzipper.push_back(inf_value);
        build();
    }/*}}}*/
    void add_value(long long lv){/*{{{*/
        _unzipper.push_back(lv);
        _is_build = false;
    }/*}}}*/
    void build(){/*{{{*/
        uni(_unzipper);
        zip_map.clear();
        rep(i, sz(_unzipper)){ zip_map[_unzipper[i]] = i; }
        _is_build = true;
    }/*}}}*/
    int get_zipped(long long lv){/*{{{*/
        if (!_is_build) assert(false);
        return zip_map[lv];
    }/*}}}*/
    vector<int> get_zipped(vector<long long> lvs){/*{{{*/
        if (!_is_build) assert(false);
        int n = sz(lvs);
        vector<int> res(n);
        rep(i, n) res[i] = zip_map[lvs[i]];
        return res;
    }/*}}}*/
    int operator()(long long lv) {/*{{{*/
        if (!_is_build) assert(false);
        return zip_map[lv];
    }/*}}}*/
    long long unzip(int sv) {/*{{{*/
        if (!_is_build) assert(false);
        return _unzipper[sv];
    }/*}}}*/
};
ostream& operator<<(ostream& os, const zipper& zp){/*{{{*/
    os << endl;
    os << "_is_build: " << zp._is_build << endl;
    os << "zip_map:   " << zp.zip_map << endl;
    return os;
}/*}}}*//*}}}*/
// How to use{{{
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
/*}}}*/

//%snippet.end()%


