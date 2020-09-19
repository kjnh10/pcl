---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"library/cpp/misc/event_sort.cpp\"\n\n//%snippet.set('event_sort')%\n\
    \nstruct Event {\n    Event(int t_, int s_, int e_, int isIn_)\n        : t(t_),\
    \ s(s_), e(e_), isIn(isIn_) {}\n    int t;\n    int s, e;\n    int isIn;\n\n \
    \   bool operator<(const Event& rhs) {\n        if (t == rhs.t) return isIn <\
    \ rhs.isIn;\n\n        return t < rhs.t;\n    }\n};\n\nvoid event_sort(vector<int>&\
    \ s, vector<int>& e) {\n    // \u56DE\u53CE\u306Fl, r\u306F\u6383\u9664\u3059\u308B\
    version\n    multiset<int> e_set;\n    int n = sz(s);\n\n    vector<Event> events;\n\
    \    for (int i = 0; i < n; i++) {\n        events.emplace_back(s[i], s[i], e[i],\
    \ 1);\n        events.emplace_back(e[i] + 1, s[i], e[i], 0);\n    }\n\n    sort(all(events));\n\
    \n    for (int i = 0; i < 2 * n; i++) {\n        if (events[i].isIn) {\n     \
    \       e_set.insert(events[i].e);\n        } else {\n            e_set.erase(e_set.find(events[i].e));\n\
    \        }\n    }\n}\n"
  code: "\n//%snippet.set('event_sort')%\n\nstruct Event {\n    Event(int t_, int\
    \ s_, int e_, int isIn_)\n        : t(t_), s(s_), e(e_), isIn(isIn_) {}\n    int\
    \ t;\n    int s, e;\n    int isIn;\n\n    bool operator<(const Event& rhs) {\n\
    \        if (t == rhs.t) return isIn < rhs.isIn;\n\n        return t < rhs.t;\n\
    \    }\n};\n\nvoid event_sort(vector<int>& s, vector<int>& e) {\n    // \u56DE\
    \u53CE\u306Fl, r\u306F\u6383\u9664\u3059\u308Bversion\n    multiset<int> e_set;\n\
    \    int n = sz(s);\n\n    vector<Event> events;\n    for (int i = 0; i < n; i++)\
    \ {\n        events.emplace_back(s[i], s[i], e[i], 1);\n        events.emplace_back(e[i]\
    \ + 1, s[i], e[i], 0);\n    }\n\n    sort(all(events));\n\n    for (int i = 0;\
    \ i < 2 * n; i++) {\n        if (events[i].isIn) {\n            e_set.insert(events[i].e);\n\
    \        } else {\n            e_set.erase(e_set.find(events[i].e));\n       \
    \ }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/misc/event_sort.cpp
  requiredBy: []
  timestamp: '2020-04-26 09:08:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/misc/event_sort.cpp
layout: document
redirect_from:
- /library/library/cpp/misc/event_sort.cpp
- /library/library/cpp/misc/event_sort.cpp.html
title: library/cpp/misc/event_sort.cpp
---
