#pragma once
#include "../../header.hpp"

//%snippet.set('AreaRect')%
//%snippet.fold()%

class AreaRect { //(0,0)-(X,Y)の矩形の面積の総和
	map<ll,ll> M;  // 矩形の右端を管理
public:
	ll sum;
	AreaRect() {
		M[0] = 1LL<<60;  // 番兵
		M[1LL<<60] = 0;  // 番兵
		sum = 0;
	}
	void add(ll x, ll y) {
		auto k = M.lower_bound(x);
		if (k->second >= y) return;
		while(true) {
            if (auto p = *prev(M.lower_bound(x)); p.second > y){
                break;
            }
            else{;
                M.erase(p.first);
                sum -= (p.first - prev(M.lower_bound(p.first))->first) * (p.second - M.lower_bound(x)->second);
            }
		}
		sum += (x - prev(M.lower_bound(x))->first) * (y - M.lower_bound(x)->second);
		M[x] = y;
	}
};

//%snippet.end()%
