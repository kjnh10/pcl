#include "../../../math/mint.hpp"
#include "../segment_tree_lazy.hpp"

//%snippet.set('monoid_affin_transformation')%
//%snippet.fold()%
struct monoid_affin_transformation {
    mint a, b;
    monoid_affin_transformation(){};
    monoid_affin_transformation(mint a_, mint b_) : a(a_), b(b_){};
};
monoid_affin_transformation operator+(monoid_affin_transformation x, monoid_affin_transformation y){
    return monoid_affin_transformation(x.a * y.a, x.b * y.a + y.b);
}
bool operator==(monoid_affin_transformation m1, monoid_affin_transformation m2) {
    return m1.a == m2.a && m1.b == m2.b;
}
//%snippet.end()%
