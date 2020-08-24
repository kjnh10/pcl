#include "../../header.hpp"

//%snippet.set('dist')%
template<class T> T dist(T x1, T y1, T x2, T y2){ return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); }
//%snippet.end%

//%snippet.set('rad')%
template<class T> T rad(T x){ return x * M_PI / 180.0; }
//%snippet.end%

//%snippet.set('degree')%
//%snippet.config({'alias':'deg'})%
template<class T> T deg(T r){ return r / M_PI * 180.0; }
//%snippet.end%
