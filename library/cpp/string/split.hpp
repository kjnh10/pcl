#include "../header.hpp"

//%snippet.set('split')%
//%snippet.fold()%

vector<string> split(const string& s){
    ll n = sz(s);
    vector<string> res = {""};
    rep(i, n){
        if (s[i]==' '){ res.push_back(""); }
        else{ res.back() += s[i]; }
    }
    return res;
}

//%snippet.end()%
