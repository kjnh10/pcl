
//%snippet.set('event_sort')%

struct Event {
    Event(int t_, int s_, int e_, int isIn_)
        : t(t_), s(s_), e(e_), isIn(isIn_) {}
    int t;
    int s, e;
    int isIn;

    bool operator<(const Event& rhs) {
        if (t == rhs.t) return isIn < rhs.isIn;

        return t < rhs.t;
    }
};

void event_sort(vector<int>& s, vector<int>& e) {
    // 回収はl, rは掃除するversion
    multiset<int> e_set;
    int n = sz(s);

    vector<Event> events;
    for (int i = 0; i < n; i++) {
        events.emplace_back(s[i], s[i], e[i], 1);
        events.emplace_back(e[i] + 1, s[i], e[i], 0);
    }

    sort(all(events));

    for (int i = 0; i < 2 * n; i++) {
        if (events[i].isIn) {
            e_set.insert(events[i].e);
        } else {
            e_set.erase(e_set.find(events[i].e));
        }
    }
}
