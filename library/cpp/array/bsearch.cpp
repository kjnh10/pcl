#include "../header.hpp"

int main(){
    //%snippet.set('bsearch')%
    ll left = 0;
    ll right = 1e9 + 1;
    auto isright = [&](ll x) {
        cerrendl;
        bool is_r = true;

        dump(x, is_r);
        return is_r;
    };
    while (right - left > 1) {
        ll mid = (right + left) / 2;
        if (isright(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    dump(right);
    //%snippet.end()%
}
