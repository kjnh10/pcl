#pragma once
#include "../header.hpp"

//%snippet.set('matrix_pow')%
//%snippet.fold()%

template <class value = ll>
using mat = vector<vector<value>>;

template <class T>
mat<T> mul(const mat<T>& A, const mat<T>& B) {
    mat<T> res(A.size(), vector<T>(B[0].size()));
    rep(i, A.size()) {
        rep(j, B[0].size()) {
            rep(k, B.size()) {
                res[i][j] = (res[i][j] + A[i][k] * B[k][j]);
            }
        }
    }
    return res;
}

template <class T>
mat<T> pow(mat<T> A, ll n) {
    mat<T> B(A.size(), vector<T>(A.size()));
    rep(i, A.size()) {
        B[i][i] = 1;  // E
    }
    while (n > 0) {
        if (n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

//%snippet.end()%
