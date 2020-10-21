#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "sieve.hpp"

bool is_prime_naive(ll n) { /*{{{*/
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
} /*}}}*/

uint64_t rng() {
    static mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<uint64_t>(1, sv.n * 2)(x);
}

void test(ll m){
    // dump(m);

    auto ps = sv.prime_factor(m);
    // dump(ps);

    ll restore = 1;
    each(p, ps){
        if (is_prime_naive(p.first)==false) assert(false);
        rep(i, p.second) restore *= p.first;
    }
    assert(restore == m);
}

int main(){
    assert(sz(sv.prime_factor(1))==0);
    // test(sv.n * sv.n + 1);  // make sure that this will fail

    int num = 100000;
    while(num--){
        ll m = rng();
        test(m);
    }

    cout << "Hello World" << endl;
}
