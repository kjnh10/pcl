//%snippet.set('tsearch')%
ll l = 0;
ll r = 1000000001;

// ll num = 100;
// while(num--){
while(r-l>2){
    ll d = (r-l)/3;
    ll ml = l + d;
    ll mr = l + 2*d;
    if ((score(ml) < score(mr))){
        r = mr;
    }
    else{
        l = ml;
    }
}
dump(l, r);
ll ans = INF;
rep(i, l, r+1) chmin(ans, score(i));
