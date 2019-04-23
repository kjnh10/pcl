//%snippet.set('bit')%
template<typename T=int>
struct BIT {
  public:
    vector<T> data;  // 1-index

    // constructor
    BIT(vector<T> v){  // v: 0-index vector
      data = vector<T>(sz(v)+1);
      rep(i, 1, sz(v)) add(i+1, v[i]);
    }
    BIT(int n){
      data = vector<T>(n+1);
    }
    //------------

    T cum(int idx){
      T res = 0;
      for (int i = idx; i > 0; i -= i&-i) res += data[i];
      return res;
    }

    void add(int idx, T x){
      for (int i = idx; i <= (int)data.size(); i += i&-i){
        data[i] += x;
      }
    }

  private:
};
