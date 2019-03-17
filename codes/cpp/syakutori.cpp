int r = 0;
for (int l=0; l<n; ++l) {
  while (r<n-1 && isok(r+1)) {
    ++r;
    // sum += a[r];
  }

  // if (isok(now))  // l==rでダメなやつも流れてくる場合があるので。
  res += (r-l+1);  // 更新

  // sum -= a[l];  // prepare move l
  if (r<n-1 && r==l){
    ++r;
    // sum += a[r];
  }

}
