//%snippet.set('syakutori')%
//%snippet.config({'abbr':'syakutori-hou-[l,r)', 'indent':True})%
  int res = 0;
  int sum = 0;

  auto isok=[&](int r){ // [l, r] e.g [l, r+1) is ok?
    if (sum + s[r-1]<=k) return true;
    else               return false;
  };

  int r = 0;
  for (int l=0; l<n; ++l) {
    while (r<n && isok(r+1)) {
      sum += s[r];
      ++r;
    }
    chmax(res, (r-l));

    // leftをincrementする準備
    if (r==l) ++r;  // l,rが同時に動くのでsumは変動しない。
    else sum -= s[l];
  }
//%snippet.end()%
