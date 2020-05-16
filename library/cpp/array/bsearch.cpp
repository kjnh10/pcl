//%snippet.set('bsearch')%
ll left = 0;
ll right = 1000000001;
auto isright = [&](ll x) {
    cerrendl;
    //
    bool ans = (cond ? true : false);
    dump(x, ans);
    return ans;
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
