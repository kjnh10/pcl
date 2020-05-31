#include "../../header.hpp"

//%snippet.set('rad')%
template<class T>
long double rad(T d){
    return d * M_PI / 180.0;
}
//%snippet.end%

//%snippet.set('degree')%
//%snippet.config({'alias':'deg'})%
template<class T>
long double deg(T r){
    return r / M_PI * 180.0;
}
//%snippet.end%
