//%snippet.set('bsearch')%
int left = 0;
int right = 1000000001;
auto isright = [&](int x) {
    cerrendl;
    //
    bool ans = (cond ? true : false);
    dump(x, ans);
    return ans;
};
while (right - left > 1) {
    int mid = (right + left) / 2;
    if (isright(mid)) {
        right = mid;
    } else {
        left = mid;
    }
}
dump(right);
