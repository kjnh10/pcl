using POS = tuple<int, int, int>;  // update
using COST = int;  // update
using EDGES = map<POS, vector<pair<POS, COST>>>;  // update

PQ<pair<COST, POS>> q;
map<POS, COST> d;
EDGES es;

void add_edge(POS from, POS to, COST cost){
  es[from].emplace_back(mp(to, cost));
}

void init_es(){
}

void dijkstra(){
  init_es();
  init_d();

  q.push(mp(0LL, mp(0,0,1))); // init priority que: putting start node
  while (!q.empty()){
    // 取り出し
    auto cp = q.top(); q.pop();
    auto cost = cp.first;
    auto pos = cp.second;

    if (d.find(pos)==d.end() || cost < d[pos]) {
      d[pos] = cost;
      for (const auto &e:es[pos]){
        auto npos = e.fi;
        auto ncost = cost + e.se;
        q.push(mp(ncost, npos));
      }
    }
  }
}

int main(){

}
