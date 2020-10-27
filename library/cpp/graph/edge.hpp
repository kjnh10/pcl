#pragma once
#include "../header.hpp"

//%snippet.set('edge')%
//%snippet.fold()%
template<class Cost=ll>
struct Edge {
    int from, to;
    Cost cost;
    int idx;
    Edge(){};
    Edge(int from_, int to_, Cost cost_, int idx_)
        : from(from_), to(to_), cost(cost_), idx(idx_) {}

    friend ostream& operator<<(ostream& os, const Edge& e) {
        // os << "(f:" << e.from << ", t:" << e.to << ", c:" << e.cost << ", i" << e.idx << ")";  // detailed
        os << "(" << e.from << "," << e.to << ")";
        return os;
    }
};
//%snippet.end()%
