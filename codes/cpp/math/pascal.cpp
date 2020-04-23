#include "template.hpp"

//%snippet.set('pascal')%

template<class T> vector<vector<T>> pascal(int N){ // {{{
    vector<vector<T>> com(N+1, vector<T>(N+1));
    com[0][0] = 1;
    rep(i, 1, N+1){
        // パスカルの三角形は0-indexdで段を数えるとよい。
        // com[i]を計算。
        rep(j, 0, i+1){
            if (j-1>=0) com[i][j] += com[i-1][j-1];
            com[i][j] += com[i-1][j];
            // com[i][j] /= 2.0;  // probability version
        }
    }
    return com;
} // }}}

//%snippet.end()%
