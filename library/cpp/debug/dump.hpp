#pragma once

// http://www.creativ.xyz/dump-cpp-652
using namespace std;
#include <bits/stdc++.h>

#define DUMPOUT cerr  // where to dump. cout or cerr

#define cerrendl cerr << endl

namespace dm {
    stack<vector<string>> arg_names;
    stack<int> varidx;
    int i;
    int j;
}  // namespace dm

#define dump(...)                                                                   \
    {                                                                               \
        dm::arg_names.push(parse_args_names(#__VA_ARGS__));                         \
        dm::varidx.push(0);                                                         \
        dump_func(__VA_ARGS__);                                                     \
        DUMPOUT << "in [" << __LINE__ << ":" << __FUNCTION__ << "]" << endl;        \
        dm::arg_names.pop();                                                        \
        dm::varidx.pop();                                                           \
    }

#define dump_1d(x, n)                                                               \
    {                                                                               \
        DUMPOUT << #x << "[" << #n << "]"                                           \
                << ":=> ";                                                         \
        dump_1d_core(x, n);                                                         \
        DUMPOUT << "  in [" << __LINE__ << ":" << __FUNCTION__ << "]" << endl;      \
    }

#define dump_2d(x, n, m)                                                            \
    {                                                                               \
        DUMPOUT << #x << "[" << #n << "]"                                           \
                << "[" << #m << "]"                                                 \
                << ":=> \n";                                                        \
        dump_2d_core(x, n, m);                                                      \
        DUMPOUT << "  in [" << __LINE__ << ":" << __FUNCTION__ << "]" << endl;      \
    }

void dump_func() {}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail) {
    DUMPOUT << dm::arg_names.top()[dm::varidx.top()] << ":"
            << head;
    if (sizeof...(Tail) == 0) {
        DUMPOUT << " ";
    } else {
        DUMPOUT << ", ";
    }
    ++dm::varidx.top();
    dump_func(std::move(tail)...);
}

template <class T>
void print_formatted_int(T v, T inf, int len){
    if (v == inf) {
        DUMPOUT << string(max(len-2, 0), ' ');
        DUMPOUT << "∞ ";
    }
    else if (v == -inf){
        DUMPOUT << string(max(len-3, 0), ' ');
        DUMPOUT << "-∞ ";
    }
    else{
        DUMPOUT << setw(len);
        DUMPOUT << v;
    }
}

template <class T>
void dump_1d_core(const vector<T>& x, int m){
    T inf = numeric_limits<T>::max() / 2.1;

    vector<int> column_len(m, 2);
    for(int j = 0; j < m; ++j) {
        int len = to_string(x[j]).size();
        if (x[j] == inf) len = 2;
        if (x[j] == -inf) len = 3;
        if (len > column_len[j]) column_len[j] = len;
    }

    for(int j = 0; j < m; ++j) {
        if (j == 0) DUMPOUT << "[";
        print_formatted_int(x[j], inf, column_len[j]);
        DUMPOUT << (j != m-1 ? " " : "]");
    }
}

template <class T>
void dump_2d_core(const vector<vector<T>>& x, int n, int m){
    T inf = numeric_limits<T>::max() / 2.1;

    vector<int> column_len(m, 2);
    for(int i = 0; i < n ; ++i) for(int j = 0; j < m; ++j) {
        int len = to_string(x[i][j]).size();
        if (x[i][j] == inf) len = 2;
        if (x[i][j] == -inf) len = 3;
        if (len > column_len[j]) column_len[j] = len;
    }

    // print header
    int header_len = 0;
    for(int j = 0; j < m ; ++j) {
        if (j == 0) {
            DUMPOUT << string(7, ' ');
        }
        else{
            DUMPOUT << " ";
            header_len++;
        }
        DUMPOUT << setw(column_len[j]) << j;
        header_len += column_len[j];
        DUMPOUT << (((j) == (m - 1)) ? "\n" : "");
    }
    DUMPOUT << string(7, ' ');
    DUMPOUT << string(header_len, '-');
    DUMPOUT << "\n";

    for(int i = 0; i < n ; ++i) for(int j = 0; j < m; ++j) {
        if (j == 0) DUMPOUT << setw(5) << i << " |";
        else DUMPOUT << " ";
        print_formatted_int(x[i][j], inf, column_len[j]);
        DUMPOUT << (((j) == (m - 1)) ? "|\n" : "");
    }
}


vector<string> parse_args_names(string s){
    int n = s.size();
    vector<string> res;
    string tmp = "";
    int parlevel = 0;
    int angle_level = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') parlevel++;
        if (s[i] == ')') parlevel--;
        if (s[i] == '<') angle_level++;
        if (s[i] == '>') angle_level--;
        if (s[i] == ' ') continue;
        if (s[i] == ',' && parlevel == 0 && angle_level == 0) {
            res.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += s[i];
        }
    }
    res.push_back(tmp);
    return res;
}

#include "prettyprint.hpp"
