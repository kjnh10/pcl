template<typename T>
class SegmentTreeBeats{
    int n;
    static const T idm=numeric_limits<T>::min();
    static const T idM=numeric_limits<T>::max(),idl=idM;
    struct Node{
        T Max,Max_second,Min,Min_second,sum,laz_add,laz_val;
        int Max_count,Min_count,len;
        Node():Max(idm),Max_second(idm),Min(idM),Min_second(idM)
            ,laz_add(0),laz_val(idl),len(1){}
    };
    vector<Node> Nodes;
    inline void calc(int k){
        Node &p=Nodes[k];
        Node l=Nodes[(k<<1)+1],r=Nodes[(k<<1)+2];
        p.sum=l.sum+r.sum;
        if (l.Max<r.Max){
            p.Max=r.Max;
            p.Max_count=r.Max_count;
            p.Max_second=max(l.Max,r.Max_second);
        } else if (r.Max<l.Max){
            p.Max=l.Max;
            p.Max_count=l.Max_count;
            p.Max_second=max(l.Max_second,r.Max);
        } else {
            p.Max=l.Max;
            p.Max_count=l.Max_count+r.Max_count;
            p.Max_second=max(l.Max_second,r.Max_second);
        }
        if (l.Min<r.Min){
            p.Min=l.Min;
            p.Min_count=l.Min_count;
            p.Min_second=min(l.Min_second,r.Min);
        } else if (r.Min<l.Min){
            p.Min=r.Min;
            p.Min_count=r.Min_count;
            p.Min_second=min(l.Min,r.Min_second);
        } else {
            p.Min=l.Min;
            p.Min_count=l.Min_count+r.Min_count;
            p.Min_second=min(l.Min_second,r.Min_second);
        }
    }
    inline void update_node_min(int k,T x){
        Node &node=Nodes[k];
        node.sum+=(x-node.Max)*node.Max_count;
        if (node.Max==node.Min) node.Max=node.Min=x;
        else if (node.Max==node.Min_second) node.Max=node.Min_second=x;
        else node.Max=x;
        if (node.laz_val!=idl&&node.laz_val<x) node.laz_val=x;
    }
    inline void update_node_max(int k,T x){
        Node &node=Nodes[k];
        node.sum+=(x-node.Min)*node.Min_count;
        if (node.Min==node.Max) node.Min=node.Max=x;
        else if (node.Min==node.Max_second) node.Min=node.Max_second=x;
        else node.Min=x;
        if (node.laz_val!=idl&&x<node.laz_val) node.laz_val=x;
    }
    inline void update_node_add(int k,T x){
        Node &node=Nodes[k];
        node.Max+=x;
        if (node.Max_second!=idm) node.Max_second+=x;
        node.Min+=x;
        if (node.Min_second!=idM) node.Min_second+=x;
        node.sum+=x*node.len;
        (node.laz_val!=idl?node.laz_val:node.laz_add)+=x;
    }
    inline void update_node_val(int k,T x){
        Node &node=Nodes[k];
        node.Max=x; node.Max_second=idm;
        node.Min=x; node.Min_second=idM;
        node.Max_count=node.Min_count=node.len;
        node.sum=x*node.len;
        node.laz_val=x; node.laz_add=0;
    }
    inline void propagate(int k){
        if (k>=n-1) return;
        Node &node=Nodes[k];
        if (node.laz_val!=idl){
            update_node_val((k<<1)+1,node.laz_val);
            update_node_val((k<<1)+2,node.laz_val);
            node.laz_val=idl; return;
        }
        if (node.laz_add!=0){
            update_node_add((k<<1)+1,node.laz_add);
            update_node_add((k<<1)+2,node.laz_add);
            node.laz_add=0;
        }
        if (node.Max<Nodes[(k<<1)+1].Max) update_node_min((k<<1)+1,node.Max);
        if (node.Max<Nodes[(k<<1)+2].Max) update_node_min((k<<1)+2,node.Max);
        if (Nodes[(k<<1)+1].Min<node.Min) update_node_max((k<<1)+1,node.Min);
        if (Nodes[(k<<1)+2].Min<node.Min) update_node_max((k<<1)+2,node.Min);
    }
    inline void update_min(int a,int b,T x,int k,int l,int r){
        if (b<=l||r<=a||Nodes[k].Max<=x) return;
        if (a<=l&&r<=b&&Nodes[k].Max_second<x){
            update_node_min(k,x); return;
        }
        propagate(k);
        update_min(a,b,x,(k<<1)+1,l,(l+r)>>1);
        update_min(a,b,x,(k<<1)+2,(l+r)>>1,r);
        calc(k);
    }
    inline void update_max(int a,int b,T x,int k,int l,int r){
        if (b<=l||r<=a||x<=Nodes[k].Min) return;
        if (a<=l&&r<=b&&x<Nodes[k].Min_second){
            update_node_max(k,x); return;
        }
        propagate(k);
        update_max(a,b,x,(k<<1)+1,l,(l+r)>>1);
        update_max(a,b,x,(k<<1)+2,(l+r)>>1,r);
        calc(k);
    }
    inline void update_add(int a,int b,T x,int k,int l,int r){
        if (b<=l||r<=a) return;
        if (a<=l&&r<=b){
            update_node_add(k,x); return;
        }
        propagate(k);
        update_add(a,b,x,(k<<1)+1,l,(l+r)>>1);
        update_add(a,b,x,(k<<1)+2,(l+r)>>1,r);
        calc(k);
    }
    inline void update_val(int a,int b,T x,int k,int l,int r){
        if (b<=l||r<=a) return;
        if (a<=l&&r<=b){
            update_node_val(k,x); return;
        }
        propagate(k);
        update_val(a,b,x,(k<<1)+1,l,(l+r)>>1);
        update_val(a,b,x,(k<<1)+2,(l+r)>>1,r);
        calc(k);
    }
    inline T query_min(int a,int b,int k,int l,int r){
        if (b<=l||r<=a) return idM;
        if (a<=l&&r<=b) return Nodes[k].Min;
        propagate(k);
        T vl=query_min(a,b,(k<<1)+1,l,(l+r)>>1);
        T vr=query_min(a,b,(k<<1)+2,(l+r)>>1,r);
        return min(vl,vr);
    }
    inline T query_max(int a,int b,int k,int l,int r){
        if (b<=l||r<=a) return idm;
        if (a<=l&&r<=b) return Nodes[k].Max;
        propagate(k);
        T vl=query_max(a,b,(k<<1)+1,l,(l+r)>>1);
        T vr=query_max(a,b,(k<<1)+2,(l+r)>>1,r);
        return max(vl,vr);
    }
    inline T query_sum(int a,int b,int k,int l,int r){
        if (b<=l||r<=a) return 0;
        if (a<=l&&r<=b) return Nodes[k].sum;
        propagate(k);
        T vl=query_sum(a,b,(k<<1)+1,l,(l+r)>>1);
        T vr=query_sum(a,b,(k<<1)+2,(l+r)>>1,r);
        return vl+vr;
    }
    public:
    SegmentTreeBeats(int n_){init(n_);}
    void init(int n_){
        n=1;
        while(n<n_) n<<=1;
        Nodes.resize(n<<1);
    }
    void build(const vector<T> &v){
        for (int i=0;i<v.size();++i){
            Nodes[i+n-1].Max=Nodes[i+n-1].Min=Nodes[i+n-1].sum=v[i];
            Nodes[i+n-1].Max_count=Nodes[i+n-1].Min_count=Nodes[i+n-1].len=1;
        }
        for (int i=n-2;i>=0;--i){
            calc(i);
            Nodes[i].len=Nodes[(i<<1)+1].len+Nodes[(i<<1)+2].len;
        }
    }
    void update_min(int a,int b,T x){update_min(a,b,x,0,0,n);}
    void update_max(int a,int b,T x){update_max(a,b,x,0,0,n);}
    void update_add(int a,int b,T x){update_add(a,b,x,0,0,n);}
    void update_val(int a,int b,T x){update_val(a,b,x,0,0,n);}
    T query_min(int a,int b){return query_min(a,b,0,0,n);}
    T query_max(int a,int b){return query_max(a,b,0,0,n);}
    T query_sum(int a,int b){return query_sum(a,b,0,0,n);}
    T operator[](int i){return query_sum(i,i+1);}
};

int solve() {
    ll n,Q;cin>>n>>Q;

    vl a(n); rep(i, n) a[i] = n-1;
    SegmentTreeBeats<long long> seg_y(n);
    SegmentTreeBeats<long long> seg_t(n);
    seg_y.build(a);
    seg_t.build(a);

    ll ans = (n-2) * (n-2);
    rep(q, Q){
        int ty;cin>>ty;
        ll x;cin>>x;
        x--;
        if (ty == 1){
            // put (1, x)
            ll bel = seg_y.query_sum(x, x+1);
            ans -= bel - 0 - 1;
            seg_t.update_min(0, bel, x);
        }
        if (ty == 2){
            // put (x, 1)
            ll bel = seg_t.query_sum(x, x+1);
            ans -= bel - 0 - 1;
            seg_y.update_min(0, bel, x);
        }
        dump(ans);
    }
    cout << ans << endl;

    return 0; 
}


int main(){/*{{{*/
    solve();
    check_input();
    return 0;
}/*}}}*/
