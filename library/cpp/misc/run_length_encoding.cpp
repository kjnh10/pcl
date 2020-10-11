#include "../header.hpp"

//%snippet.set('RLE')%
//%snippet.config({'alias':'run_length_encoding'})%
//%snippet.fold()%
template<class T = vector<int>, class U = int>
vector<pair<U, int>> RLE(const T& v){
    vector<pair<U, int>> res;
    rep(i, sz(v)){
        if (sz(res) == 0 || res.back().first != v[i]) {
            res.emplace_back(v[i], 1);
        }
        else{
            res.back().second++;
        }
    }
    return res;
}
//%snippet.end()%

int main(){
    string s = "100011111110110101011";
    dump(RLE(s));
}
