//%snippet.set('zip')%
// zip: a = [3, 10, 5, 5, 2]
vector<int> unzipper; // [2, 3, 5, 10]
map<int, int> zipper; // {2:0, 3:2, 5:3, 10:4}
vector<int> zipped; // [2, 4, 3, 3, 0]
auto zip=[&](vector<int> a){ //{{{
	int n = sz(a);
	unzipper = vector<int>(n); zipped = vector<int>(n);
	rep(i, n) { unzipper[i]=a[i]; }
	uni(unzipper);
	rep(i, sz(unzipper)){ zipper[unzipper[i]] = i; }
	rep(i, n){ zipped[i] = zipper[a[i]]; }
	return 0;
}; /// }}}
zip(/*your vector*/);
dump(unzipper); dump(zipper); dump(zipped);
