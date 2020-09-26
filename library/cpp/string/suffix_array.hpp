#include "../header.hpp"
#include "../array/segtree/segment_tree.hpp"
#include "../array/sparse_table.hpp"

//%snippet.set('suffix_array')%
//%snippet.config({'alias':'sa'})%
//%snippet.include('segment_tree')%
//%snippet.include('sparse_table')%
//%snippet.fold()%

struct suffix_array { 
    vector<int> a;
    vector<int> pos;   // pos[j]: j位のsumffixはどこから始まるか
    vector<int> rank;  // rank[i]: s[i:]は何位か
    // pos = rank^-1
    vector<int> lcp_array;           // lcp_arry[j]: s[pos[j]:]とs[pos[j]+1:]のlcp
    SegmentTree<int> _seg_lcp_array;
    int n;
    string s;

    // constructor{{{
    suffix_array() {}
    suffix_array(vector<int>& a) : a(a), n(a.size()) { _build(); }
    suffix_array(string& s_): s(s_) {
        n = s.size();
        a.resize(n);
        rep(i, n) a[i] = s[i];
        _build();
    } /*}}}*/

    void _build() { /*{{{*/
        _build_order();
        _build_lcp_array();
    } /*}}}*/

    void _build_order() { /*{{{*/
        pos.resize(n);
        iota(all(pos), 0);
        rank = a;  // aでそのままスコア化

        for (int k = 1; k < n; k *= 2) {
            // kでのrankが生成されている前提で2*kでのrankを生成する

            auto _comp = [&](int l, int r) {
                auto left = mp(rank[l], (l + k < n ? rank[l + k] : -1));
                auto right = mp(rank[r], (r + k < n ? rank[r + k] : -1));
                return left < right;
            };
            sort(all(pos), _comp);

            vector<int> next_rank(n);
            next_rank[pos[0]] = 0;
            int r = 0;
            rep(i, 1, n) {
                if (_comp(pos[i - 1], pos[i])) r++;
                next_rank[pos[i]] = r;
            }
            rank = next_rank;
        }
    } /*}}}*/

    void _build_lcp_array() { /*{{{*/
        lcp_array.resize(n);
        int con = 1;
        rep(l, 0, n) {
            if (rank[l] + 1 == n) {
                lcp_array[rank[l]] = -1;
                con = 1;
                continue;
            }

            if (con > 0) con--;
            int r = pos[rank[l] + 1];
            while (l + con < n && r + con < n && a[l + con] == a[r + con]) {
                con++;
            }
            lcp_array[rank[l]] = con;
        }

        auto mymin = [](auto a, auto b) { return min(a, b); };
        _seg_lcp_array = SegmentTree<int>(lcp_array, mymin, 1e9);
        // sparse_lcp_array = SparseTable<int>(lcp_array);
    } /*}}}*/

    int lcp(int i, int j) {  // longest cummon prefix length between s[i:] and s[j:]{{{
        if (rank[i]<rank[j])   return _seg_lcp_array.query(rank[i], rank[j]);
        else                   return _seg_lcp_array.query(rank[j], rank[i]);
        // if (rank[i] < rank[j]) return sparse_lcp_array.get(rank[i], rank[j]);
        // else                   return sparse_lcp_array.get(rank[j], rank[i]);
    } /*}}}*/

    #if defined(PCM) || defined(LOCAL)/*{{{*/
    friend ostream& operator<<(ostream& os, suffix_array& sa) {
        os << endl;
        rep(j_th, sa.n){
            int i = sa.pos[j_th];
            os << right << setw(4);
            os << j_th << ":" << sa.s.substr(i, sa.n-i) << endl;
        }
        return os;
    }
    #endif/*}}}*/
};    
// how to use
    // string s;cin>>s;
    // ll n = sz(s);
    // suffix_array sa(s);
    // dump(sa);
    // dump(sa.lcp_array);
    // sa.pos[j]  : j位のsuffixはどこから始まるか
    // sa.rank[i] : s[i:]は何位か
    // sa.lcp_arry[j] : return lcp(s[pos[j]:], s[pos[j+1]:])
    // sa.lcp(i, j) :   return lcp(s[i:], s[j:])

//%snippet.end()%
