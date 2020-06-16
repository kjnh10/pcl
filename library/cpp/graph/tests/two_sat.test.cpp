#define PROBLEM "https://yukicoder.me/problems/no/274"
#include "../two_sat.hpp"

int main() {
    int n,m;cin>>n>>m;
    vector<int> l(n), r(n);
    rep(i, n){
        cin>>l[i]>>r[i];
    }

    two_sat ts(n);

    rep(i, n){
        rep(j, i+1, n){
            if (r[j] < l[i] || r[i] < l[j]) {
            }
            else{
                ts.add_condition(i, 0, j, 0);
                ts.add_condition(i, 1, j, 1);
            }

            if (r[j] < m-1-r[i] || m-1-l[i] < l[j]) {
            }
            else{
                ts.add_condition(i, 0, j, 1);
                ts.add_condition(i, 1, j, 0);
            }
        }
    }
    auto valid = ts.build();
    cout << (valid ? "YES" : "NO") << endl;

    return 0; 
}
