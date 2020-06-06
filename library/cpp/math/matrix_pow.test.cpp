#define PROBLEM "https://yukicoder.me/problems/no/1073"
#include "matrix_pow.hpp"
#include "mint.hpp"

int solve() {
    ll n;cin>>n;

    mat<mint> A(6, vector<mint>(6));
    mint x = mint(1)/6;
    A[0] = {x, x, x, x, x, x};
    A[1] = {1, 0, 0, 0, 0, 0};
    A[2] = {0, 1, 0, 0, 0, 0};
    A[3] = {0, 0, 1, 0, 0, 0};
    A[4] = {0, 0, 0, 1, 0, 0};
    A[5] = {0, 0, 0, 0, 1, 0};

    mat<mint> B(6, vector<mint>(1, 0));
    B[0] = {x};
    B[1] = {1};

    cout << mul(pow(A, n-1), B)[0][0] << endl;

    return 0; 
}


int main(){/*{{{*/
    solve();
    check_input();
    return 0;
}/*}}}*/
