//%snippet.set('syakutori')%
//%snippet.config({'abbr':'syakutori-hou-[l,r)', 'indent':True})%
  int res = 0;
  int sum = 0;
  int r = 0;
  for (int l=0; l<n; ++l) {
    auto isok=[&](){ // [l, r] e.g [l, r+1) is ok?
      if (sum + s[r]<=k) return true;
      else return false;
    };
    while (r<n && isok()) {
      sum += s[r];
      ++r;
    }
    chmax(res, (r-l));

    // 枝刈り（not needed）
    if (r==n) break;

    // leftをincrementする準備
    if (r==l) ++r;  // l,rが同時に動くのでsumは変動しない。
    else sum -= s[l];
  }
//%snippet.end()%
