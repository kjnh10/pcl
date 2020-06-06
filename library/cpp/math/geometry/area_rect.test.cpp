#define PROBLEM "https://yukicoder.me/problems/no/1074"
#include "area_rect.hpp"

AreaRect M[4];

int N;
int X1,X2,Y1,Y2;

int main() {
	cin>>N;
	ll pre = 0;
	rep(i, N) {
		cin>>X1>>Y1>>X2>>Y2;
		M[0].add(-X1,-Y1);
		M[1].add(-X1,Y2);
		M[2].add(X2,-Y1);
		M[3].add(X2,Y2);
		ll sum = M[0].sum+M[1].sum+M[2].sum+M[3].sum;
		cout << sum-pre << endl;
		pre = sum;
	}
    return 0;
}
