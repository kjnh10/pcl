#include "header.hpp"
template<class T=ll> using vec = vector<T>;
struct Fast { Fast() { std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

int solve() {
    int n,q;cin>>n>>q;

    vl a(n);
    rep(_, q){
        int ty;cin>>ty;
        if (ty == 1){
            int l,r,x;cin>>l>>r>>x;
            rep(i, l, r) a[i] += x;
        }
        if (ty == 2){
            int l,r;cin>>l>>r;
            int res = 0;
            rep(i, l, r) res += a[i];
            cout << res << endl;
        }
        if (ty == 3){
            int right = n;
            int l,x;cin>>l>>x;
            int sum = 0;
            rep(i, l, n){
                sum += a[i];
                if (sum >= x){
                    right = i;
                    break;
                }
            }
            cout << right << endl;
        }
        if (ty == 4){
            int left = -1;
            int r,x;cin>>r>>x;
            int sum = 0;
            r_rep(i, 0, r+1){
                sum += a[i];
                if (sum >= x){
                    left = i;
                    break;
                }
            }
            cout << left << endl;
        }
    }
    return 0; 
}


int main(){/*{{{*/
    solve();
    check_input();
    return 0;
}/*}}}*/
