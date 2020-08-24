#include "../header.hpp"

//%snippet.set('fft')%
template<typename T> class fft {
private:
    using mycomplex = std::complex<T>;
    static void dft(vector<mycomplex>& func, int inverse) {
        int sz = func.size();
        if (sz == 1)return;
        vector<mycomplex> veca, vecb;
        rep(i, sz / 2) {
            veca.push_back(func[2 * i]);
            vecb.push_back(func[2 * i + 1]);
        }
        dft(veca, inverse); dft(vecb, inverse);
        mycomplex now = 1, zeta = polar(1.0, inverse * 2.0 * acos(-1) / sz);
        rep(i, sz) {
            func[i] = veca[i % (sz / 2)] + now * vecb[i % (sz / 2)];
            now *= zeta;
        }
    }
public:
    static vector<double> multiply(vector<T> f, vector<T> g) {
        vector<mycomplex> nf, ng;
        int sz = 1;
        while (sz < f.size() + g.size())sz *= 2;
        nf.resize(sz); ng.resize(sz);
        rep(i, f.size()) {
            nf[i] = f[i];
            ng[i] = g[i];
        }
        dft(nf, 1);
        dft(ng, 1);
        rep(i, sz)nf[i] *= ng[i];
        dft(nf, -1);
        vector<double> res;
        rep(i, sz)res.push_back(nf[i].real() / sz);
        return res;
    }
};
//%snippet.end%
