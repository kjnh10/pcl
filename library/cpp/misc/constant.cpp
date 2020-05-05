#include "../header.hpp"

namespace std {
    template<> class numeric_limits<pair<int, int>> {
    public:
       static pair<int, int> max() {return pair<int, int>(100, 100);};
       // One can implement other methods if needed
    };
}

template <class T>
T get_inf(){
    T t; return t;
}

template <>
pair<int, int> get_inf(){
    int inf = numeric_limits<int>().max();
    return make_pair(inf, inf);
}

int main(){
    dump(get_inf<pair<int, int>>());
}
