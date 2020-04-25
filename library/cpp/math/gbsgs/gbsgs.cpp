#include "../../header.hpp"
#include "../mint.hpp"
// %snippet.set('generalized_baybe_step_giant_step')%
// %snippet.config({'alias':'gbsgs'})%
// %snippet.include('mint')%

int bsgs(int a, int b){ //{{{
  // find x s.t a^x = b in (mod)

  if (b>=mod) return -1;
  if (1%mod==b) return 0;

  int h = (int)sqrt(mod)+1; // h s.t x = p*h-r (0<=r<h and 0<=p<=h)

  unordered_map<int, vector<int>> rs; // rs[v]: vector of r s.t b*a^r==v
  mint bar = b;
  rep(r, 0, h){
    rs[bar.x].pb(r);
    bar *= a;
  }
  bool looped = false;
  each(el, rs) if (sz(el.second)>1) looped = true;

  mint ah = mint(a).pow(h);
  rep(p, 1, h+1){
    int aph = ah.pow(p).x;
    if (rs.find(aph)!=rs.end()){
      reverse(all(rs[aph]));
      each(r, rs[aph]){
        if ((p*h-r)>=0 && mint(a).pow(p*h-r)==b) return p*h-r;
      }
    }
    if (looped) return -1;
  }

  return -1;
} //}}}

// %snippet.end()%

signed main(){
  int a,b,p;cin>>a>>b>>p;
  mod = p;
  cout << bsgs(a, b) << endl;
  return 0;
}
