struct RollingHash{
    vector<int64_t> hash;
    vector<int64_t> base_pow;
    int64_t base, mod;
    static const int64_t DEFAULT_BASE = 1009, DEFAULT_MOD = 1e9+7;

    RollingHash(string S="", int64_t base=DEFAULT_BASE, int64_t mod=DEFAULT_MOD):base(base), mod(mod){
        if(S.size() > 0) initialize(S);
    }

    void initialize(string& S){
        int N = S.size();
        vector<int> s(N);
        for(int i=0; i<N; i++) s[i] = S[i];
        initialize(s);
    }

    void initialize(vector<int>& S){
        int len = S.size();
        hash.resize(len+1);
        base_pow.resize(len+1);
        hash[0] = 0;
        base_pow[0] = 1;
        for(int i=1; i<=len; i++){
            hash[i] = (hash[i-1] * base + S[i-1]) % mod;
            base_pow[i] = base_pow[i-1] * base % mod;
        }
    }

    // 0-indexed, [a, b)
    int64_t between(int a, int b){
        return (mod + hash[b] - hash[a] * base_pow[b-a] % mod) % mod;
    }
};

int main(){
    int N;
    string S;
    cin >> N >> S;
    int ok = 0, ng = N/2+1;
    RollingHash rh1(S, 1007, 1e9+7);

    while(ng-ok>1){
        int len = (ng+ok)/2;
        set<int64_t> val;
        vector<int64_t> v(N);
        bool success = false;
        for(int i=0; i+len<=N; i++){
            if(i >= len) val.insert(v[i-len]);
            v[i] = rh1.between(i, i+len);
            if(val.count(v[i])){
                success = true;
                break;
            }
        }
        (success ? ok : ng) = len;
    }
    cout << ok << endl;
    return 0;
}
