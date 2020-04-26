---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :warning: library/cpp/debug/dump.hpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#dbefae66adc6b6e178b4020d7ee0c756">library/cpp/debug</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/cpp/debug/dump.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 09:08:25+09:00




## Depends on

* :warning: <a href="prettyprint.hpp.html">library/cpp/debug/prettyprint.hpp</a>
* :heavy_check_mark: <a href="../header.hpp.html">library/cpp/header.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

// http://www.creativ.xyz/dump-cpp-652
using namespace std;
#include <bits/stdc++.h>

#include "../header.hpp"

#define DUMPOUT cerr  // where to dump. cout or cerr

namespace dump_macro {
stack<vector<string>> varnames;
stack<int> varidx;
}  // namespace dump_macro

#define dump(...)                                                            \
    {                                                                        \
        dump_macro::varnames.push([](string s) -> vector<string> {           \
            int n = s.size();                                                \
            vector<string> res;                                              \
            string tmp = "";                                                 \
            int parlevel = 0;                                                \
            for (int i = 0; i < n; i++) {                                    \
                if (s[i] == '(') parlevel++;                                 \
                if (s[i] == ')') parlevel--;                                 \
                if (s[i] == ' ') continue;                                   \
                if (s[i] == ',' && parlevel == 0) {                          \
                    res.push_back(tmp);                                      \
                    tmp = "";                                                \
                } else {                                                     \
                    tmp += s[i];                                             \
                }                                                            \
            }                                                                \
            res.push_back(tmp);                                              \
            return res;                                                      \
        }(#__VA_ARGS__));                                                    \
        dump_macro::varidx.push(0);                                          \
        dump_func(__VA_ARGS__);                                              \
        DUMPOUT << "in [" << __LINE__ << ":" << __FUNCTION__ << "]" << endl; \
        dump_macro::varnames.pop();                                          \
        dump_macro::varidx.pop();                                            \
    }

#define dump_1d(x, n)                                                     \
    {                                                                     \
        DUMPOUT << "  " << #x << "[" << #n << "]"                         \
                << ":=> {";                                               \
        rep(i, n) { DUMPOUT << x[i] << (((i) == (n - 1)) ? "}" : ", "); } \
        DUMPOUT << " in [" << __LINE__ << "]" << endl;                    \
    }

#define dump_2d(x, n, m)                                      \
    {                                                         \
        DUMPOUT << "  " << #x << "[" << #n << "]"             \
                << "[" << #m << "]"                           \
                << ":=> \n";                                  \
        rep(i, n) rep(j, m) {                                 \
            DUMPOUT << ((j == 0) ? "     |" : " ") << x[i][j] \
                    << (((j) == (m - 1)) ? "|\n" : " ");      \
        }                                                     \
        DUMPOUT << "  in [" << __LINE__ << "]" << endl;       \
    }

void dump_func() {}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail) {
    DUMPOUT << dump_macro::varnames.top()[dump_macro::varidx.top()] << ":"
            << head;
    if (sizeof...(Tail) == 0) {
        DUMPOUT << " ";
    } else {
        DUMPOUT << ", ";
    }
    ++dump_macro::varidx.top();
    dump_func(std::move(tail)...);
}

#include "prettyprint.hpp"

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "library/cpp/debug/dump.hpp"

// http://www.creativ.xyz/dump-cpp-652
using namespace std;
#include <bits/stdc++.h>

#line 2 "library/cpp/header.hpp"

// template version 2.0
using namespace std;
#line 6 "library/cpp/header.hpp"

// varibable settings
#define int long long
const int INF = 1e18;

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define _rrep(i, n) rrepi(i, 0, n)
#define rrepi(i, a, b) for (int i = (int)((b)-1); i >= (int)(a); --i)
#define r_rep(...) _overload3(__VA_ARGS__, rrepi, _rrep, )(__VA_ARGS__)
#define each(i, a) for (auto &&i : a)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(...) make_tuple(__VA_ARGS__)
#define ub upper_bound
#define lb lower_bound
#define lpos(A, x) (lower_bound(all(A), x) - A.begin())
#define upos(A, x) (upper_bound(all(A), x) - A.begin())
template <class T>
inline void chmax(T &a, const T &b) {
    if ((a) < (b)) (a) = (b);
}
template <class T>
inline void chmin(T &a, const T &b) {
    if ((a) > (b)) (a) = (b);
}

#define divceil(a, b) ((a) + (b)-1) / (b)
#define is_in(x, a, b) ((a) <= (x) && (x) < (b))
#define uni(x)    \
    sort(all(x)); \
    x.erase(unique(all(x)), x.end())
#define slice(l, r) substr(l, r - l)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int, int> pii;
typedef tuple<int, int, int> iii;

template <typename T>
using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast {
    Fast() {
        std::cin.tie(0);
        ios::sync_with_stdio(false);
    }
} fast;

#if defined(PCM) || defined(LOCAL)
#else
#define dump(...) ;
#define dump_1d(...) ;
#define dump_2d(...) ;
#define cerrendl ;
#endif
#line 8 "library/cpp/debug/dump.hpp"

#define DUMPOUT cerr  // where to dump. cout or cerr

namespace dump_macro {
stack<vector<string>> varnames;
stack<int> varidx;
}  // namespace dump_macro

#define dump(...)                                                            \
    {                                                                        \
        dump_macro::varnames.push([](string s) -> vector<string> {           \
            int n = s.size();                                                \
            vector<string> res;                                              \
            string tmp = "";                                                 \
            int parlevel = 0;                                                \
            for (int i = 0; i < n; i++) {                                    \
                if (s[i] == '(') parlevel++;                                 \
                if (s[i] == ')') parlevel--;                                 \
                if (s[i] == ' ') continue;                                   \
                if (s[i] == ',' && parlevel == 0) {                          \
                    res.push_back(tmp);                                      \
                    tmp = "";                                                \
                } else {                                                     \
                    tmp += s[i];                                             \
                }                                                            \
            }                                                                \
            res.push_back(tmp);                                              \
            return res;                                                      \
        }(#__VA_ARGS__));                                                    \
        dump_macro::varidx.push(0);                                          \
        dump_func(__VA_ARGS__);                                              \
        DUMPOUT << "in [" << __LINE__ << ":" << __FUNCTION__ << "]" << endl; \
        dump_macro::varnames.pop();                                          \
        dump_macro::varidx.pop();                                            \
    }

#define dump_1d(x, n)                                                     \
    {                                                                     \
        DUMPOUT << "  " << #x << "[" << #n << "]"                         \
                << ":=> {";                                               \
        rep(i, n) { DUMPOUT << x[i] << (((i) == (n - 1)) ? "}" : ", "); } \
        DUMPOUT << " in [" << __LINE__ << "]" << endl;                    \
    }

#define dump_2d(x, n, m)                                      \
    {                                                         \
        DUMPOUT << "  " << #x << "[" << #n << "]"             \
                << "[" << #m << "]"                           \
                << ":=> \n";                                  \
        rep(i, n) rep(j, m) {                                 \
            DUMPOUT << ((j == 0) ? "     |" : " ") << x[i][j] \
                    << (((j) == (m - 1)) ? "|\n" : " ");      \
        }                                                     \
        DUMPOUT << "  in [" << __LINE__ << "]" << endl;       \
    }

void dump_func() {}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail) {
    DUMPOUT << dump_macro::varnames.top()[dump_macro::varidx.top()] << ":"
            << head;
    if (sizeof...(Tail) == 0) {
        DUMPOUT << " ";
    } else {
        DUMPOUT << ", ";
    }
    ++dump_macro::varidx.top();
    dump_func(std::move(tail)...);
}

#line 1 "library/cpp/debug/prettyprint.hpp"
//          Copyright Louis Delacroix 2010 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// A pretty printing library for C++
//
// Usage:
// Include this header, and operator<< will "just work".

#ifndef H_PRETTY_PRINT
#define H_PRETTY_PRINT

#line 24 "library/cpp/debug/prettyprint.hpp"

namespace pretty_print {
namespace detail {
// SFINAE type trait to detect whether T::const_iterator exists.

struct sfinae_base {
    using yes = char;
    using no = yes[2];
};

template <typename T>
struct has_const_iterator : private sfinae_base {
   private:
    template <typename C>
    static yes &test(typename C::const_iterator *);
    template <typename C>
    static no &test(...);

   public:
    static const bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
    using type = T;
};

template <typename T>
struct has_begin_end : private sfinae_base {
   private:
    template <typename C>
    static yes &f(
        typename std::enable_if<std::is_same<
            decltype(static_cast<typename C::const_iterator (C::*)() const>(
                &C::begin)),
            typename C::const_iterator (C::*)() const>::value>::type *);

    template <typename C>
    static no &f(...);

    template <typename C>
    static yes &
    g(typename std::enable_if<
        std::is_same<decltype(static_cast<typename C::const_iterator (C::*)()
                                              const>(&C::end)),
                     typename C::const_iterator (C::*)() const>::value,
        void>::type *);

    template <typename C>
    static no &g(...);

   public:
    static bool const beg_value = sizeof(f<T>(nullptr)) == sizeof(yes);
    static bool const end_value = sizeof(g<T>(nullptr)) == sizeof(yes);
};

}  // namespace detail

// Holds the delimiter values for a specific character type

template <typename TChar>
struct delimiters_values {
    using char_type = TChar;
    const char_type *prefix;
    const char_type *delimiter;
    const char_type *postfix;
};

// Defines the delimiter values for a specific container and character type

template <typename T, typename TChar>
struct delimiters {
    using type = delimiters_values<TChar>;
    static const type values;
};

// Functor to print containers. You can use this directly if you want
// to specificy a non-default delimiters type. The printing logic can
// be customized by specializing the nested template.

template <typename T, typename TChar = char,
          typename TCharTraits = ::std::char_traits<TChar>,
          typename TDelimiters = delimiters<T, TChar>>
struct print_container_helper {
    using delimiters_type = TDelimiters;
    using ostream_type = std::basic_ostream<TChar, TCharTraits>;

    template <typename U>
    struct printer {
        static void print_body(const U &c, ostream_type &stream) {
            using std::begin;
            using std::end;

            auto it = begin(c);
            const auto the_end = end(c);

            if (it != the_end) {
                for (;;) {
                    stream << *it;

                    if (++it == the_end) break;

                    if (delimiters_type::values.delimiter != NULL)
                        stream << delimiters_type::values.delimiter;
                }
            }
        }
    };

    print_container_helper(const T &container) : container_(container) {}

    inline void operator()(ostream_type &stream) const {
        if (delimiters_type::values.prefix != NULL)
            stream << delimiters_type::values.prefix;

        printer<T>::print_body(container_, stream);

        if (delimiters_type::values.postfix != NULL)
            stream << delimiters_type::values.postfix;
    }

   private:
    const T &container_;
};

// Specialization for pairs

template <typename T, typename TChar, typename TCharTraits,
          typename TDelimiters>
template <typename T1, typename T2>
struct print_container_helper<T, TChar, TCharTraits,
                              TDelimiters>::printer<std::pair<T1, T2>> {
    using ostream_type =
        typename print_container_helper<T, TChar, TCharTraits,
                                        TDelimiters>::ostream_type;

    static void print_body(const std::pair<T1, T2> &c, ostream_type &stream) {
        stream << c.first;
        if (print_container_helper<T, TChar, TCharTraits,
                                   TDelimiters>::delimiters_type::values
                .delimiter != NULL)
            stream
                << print_container_helper<T, TChar, TCharTraits,
                                          TDelimiters>::delimiters_type::values
                       .delimiter;
        stream << c.second;
    }
};

// Specialization for tuples

template <typename T, typename TChar, typename TCharTraits,
          typename TDelimiters>
template <typename... Args>
struct print_container_helper<T, TChar, TCharTraits,
                              TDelimiters>::printer<std::tuple<Args...>> {
    using ostream_type =
        typename print_container_helper<T, TChar, TCharTraits,
                                        TDelimiters>::ostream_type;
    using element_type = std::tuple<Args...>;

    template <std::size_t I>
    struct Int {};

    static void print_body(const element_type &c, ostream_type &stream) {
        tuple_print(c, stream, Int<0>());
    }

    static void tuple_print(const element_type &, ostream_type &,
                            Int<sizeof...(Args)>) {}

    static void tuple_print(
        const element_type &c, ostream_type &stream,
        typename std::conditional<sizeof...(Args) != 0, Int<0>,
                                  std::nullptr_t>::type) {
        stream << std::get<0>(c);
        tuple_print(c, stream, Int<1>());
    }

    template <std::size_t N>
    static void tuple_print(const element_type &c, ostream_type &stream,
                            Int<N>) {
        if (print_container_helper<T, TChar, TCharTraits,
                                   TDelimiters>::delimiters_type::values
                .delimiter != NULL)
            stream
                << print_container_helper<T, TChar, TCharTraits,
                                          TDelimiters>::delimiters_type::values
                       .delimiter;

        stream << std::get<N>(c);

        tuple_print(c, stream, Int<N + 1>());
    }
};

// Prints a print_container_helper to the specified stream.

template <typename T, typename TChar, typename TCharTraits,
          typename TDelimiters>
inline std::basic_ostream<TChar, TCharTraits> &operator<<(
    std::basic_ostream<TChar, TCharTraits> &stream,
    const print_container_helper<T, TChar, TCharTraits, TDelimiters> &helper) {
    helper(stream);
    return stream;
}

// Basic is_container template; specialize to derive from std::true_type for all
// desired container types

template <typename T>
struct is_container
    : public std::integral_constant<bool,
                                    detail::has_const_iterator<T>::value &&
                                        detail::has_begin_end<T>::beg_value &&
                                        detail::has_begin_end<T>::end_value> {};

template <typename T, std::size_t N>
struct is_container<T[N]> : std::true_type {};

template <std::size_t N>
struct is_container<char[N]> : std::false_type {};

template <typename T>
struct is_container<std::valarray<T>> : std::true_type {};

template <typename T1, typename T2>
struct is_container<std::pair<T1, T2>> : std::true_type {};

template <typename... Args>
struct is_container<std::tuple<Args...>> : std::true_type {};

// Default delimiters

template <typename T>
struct delimiters<T, char> {
    static const delimiters_values<char> values;
};
template <typename T>
const delimiters_values<char> delimiters<T, char>::values = {"[", ", ", "]"};
template <typename T>
struct delimiters<T, wchar_t> {
    static const delimiters_values<wchar_t> values;
};
template <typename T>
const delimiters_values<wchar_t> delimiters<T, wchar_t>::values = {L"[", L", ",
                                                                   L"]"};

// Delimiters for (multi)set and unordered_(multi)set

template <typename T, typename TComp, typename TAllocator>
struct delimiters<::std::set<T, TComp, TAllocator>, char> {
    static const delimiters_values<char> values;
};

template <typename T, typename TComp, typename TAllocator>
const delimiters_values<char>
    delimiters<::std::set<T, TComp, TAllocator>, char>::values = {"{", ", ",
                                                                  "}"};

template <typename T, typename TComp, typename TAllocator>
struct delimiters<::std::set<T, TComp, TAllocator>, wchar_t> {
    static const delimiters_values<wchar_t> values;
};

template <typename T, typename TComp, typename TAllocator>
const delimiters_values<wchar_t>
    delimiters<::std::set<T, TComp, TAllocator>, wchar_t>::values = {
        L"{", L", ", L"}"};

template <typename T, typename TComp, typename TAllocator>
struct delimiters<::std::multiset<T, TComp, TAllocator>, char> {
    static const delimiters_values<char> values;
};

template <typename T, typename TComp, typename TAllocator>
const delimiters_values<char>
    delimiters<::std::multiset<T, TComp, TAllocator>, char>::values = {
        "{", ", ", "}"};

template <typename T, typename TComp, typename TAllocator>
struct delimiters<::std::multiset<T, TComp, TAllocator>, wchar_t> {
    static const delimiters_values<wchar_t> values;
};

template <typename T, typename TComp, typename TAllocator>
const delimiters_values<wchar_t>
    delimiters<::std::multiset<T, TComp, TAllocator>, wchar_t>::values = {
        L"{", L", ", L"}"};

template <typename T, typename THash, typename TEqual, typename TAllocator>
struct delimiters<::std::unordered_set<T, THash, TEqual, TAllocator>, char> {
    static const delimiters_values<char> values;
};

template <typename T, typename THash, typename TEqual, typename TAllocator>
const delimiters_values<char> delimiters<
    ::std::unordered_set<T, THash, TEqual, TAllocator>, char>::values = {
    "{", ", ", "}"};

template <typename T, typename THash, typename TEqual, typename TAllocator>
struct delimiters<::std::unordered_set<T, THash, TEqual, TAllocator>, wchar_t> {
    static const delimiters_values<wchar_t> values;
};

template <typename T, typename THash, typename TEqual, typename TAllocator>
const delimiters_values<wchar_t> delimiters<
    ::std::unordered_set<T, THash, TEqual, TAllocator>, wchar_t>::values = {
    L"{", L", ", L"}"};

template <typename T, typename THash, typename TEqual, typename TAllocator>
struct delimiters<::std::unordered_multiset<T, THash, TEqual, TAllocator>,
                  char> {
    static const delimiters_values<char> values;
};

template <typename T, typename THash, typename TEqual, typename TAllocator>
const delimiters_values<char> delimiters<
    ::std::unordered_multiset<T, THash, TEqual, TAllocator>, char>::values = {
    "{", ", ", "}"};

template <typename T, typename THash, typename TEqual, typename TAllocator>
struct delimiters<::std::unordered_multiset<T, THash, TEqual, TAllocator>,
                  wchar_t> {
    static const delimiters_values<wchar_t> values;
};

template <typename T, typename THash, typename TEqual, typename TAllocator>
const delimiters_values<wchar_t>
    delimiters<::std::unordered_multiset<T, THash, TEqual, TAllocator>,
               wchar_t>::values = {L"{", L", ", L"}"};

// Delimiters for pair and tuple

template <typename T1, typename T2>
struct delimiters<std::pair<T1, T2>, char> {
    static const delimiters_values<char> values;
};
template <typename T1, typename T2>
const delimiters_values<char> delimiters<std::pair<T1, T2>, char>::values = {
    "(", ", ", ")"};
template <typename T1, typename T2>
struct delimiters<::std::pair<T1, T2>, wchar_t> {
    static const delimiters_values<wchar_t> values;
};
template <typename T1, typename T2>
const delimiters_values<wchar_t>
    delimiters<::std::pair<T1, T2>, wchar_t>::values = {L"(", L", ", L")"};

template <typename... Args>
struct delimiters<std::tuple<Args...>, char> {
    static const delimiters_values<char> values;
};
template <typename... Args>
const delimiters_values<char> delimiters<std::tuple<Args...>, char>::values = {
    "(", ", ", ")"};
template <typename... Args>
struct delimiters<::std::tuple<Args...>, wchar_t> {
    static const delimiters_values<wchar_t> values;
};
template <typename... Args>
const delimiters_values<wchar_t>
    delimiters<::std::tuple<Args...>, wchar_t>::values = {L"(", L", ", L")"};

// Type-erasing helper class for easy use of custom delimiters.
// Requires TCharTraits = std::char_traits<TChar> and TChar = char or wchar_t,
// and MyDelims needs to be defined for TChar. Usage: "cout <<
// pretty_print::custom_delims<MyDelims>(x)".

struct custom_delims_base {
    virtual ~custom_delims_base() {}
    virtual std::ostream &stream(::std::ostream &) = 0;
    virtual std::wostream &stream(::std::wostream &) = 0;
};

template <typename T, typename Delims>
struct custom_delims_wrapper : custom_delims_base {
    custom_delims_wrapper(const T &t_) : t(t_) {}

    std::ostream &stream(std::ostream &s) {
        return s << print_container_helper<T, char, std::char_traits<char>,
                                           Delims>(t);
    }

    std::wostream &stream(std::wostream &s) {
        return s << print_container_helper<T, wchar_t,
                                           std::char_traits<wchar_t>, Delims>(
                   t);
    }

   private:
    const T &t;
};

template <typename Delims>
struct custom_delims {
    template <typename Container>
    custom_delims(const Container &c)
        : base(new custom_delims_wrapper<Container, Delims>(c)) {}

    std::unique_ptr<custom_delims_base> base;
};

template <typename TChar, typename TCharTraits, typename Delims>
inline std::basic_ostream<TChar, TCharTraits> &operator<<(
    std::basic_ostream<TChar, TCharTraits> &s, const custom_delims<Delims> &p) {
    return p.base->stream(s);
}

// A wrapper for a C-style array given as pointer-plus-size.
// Usage: std::cout << pretty_print_array(arr, n) << std::endl;

template <typename T>
struct array_wrapper_n {
    typedef const T *const_iterator;
    typedef T value_type;

    array_wrapper_n(const T *const a, size_t n) : _array(a), _n(n) {}
    inline const_iterator begin() const { return _array; }
    inline const_iterator end() const { return _array + _n; }

   private:
    const T *const _array;
    size_t _n;
};

// A wrapper for hash-table based containers that offer local iterators to each
// bucket. Usage: std::cout << bucket_print(m, 4) << std::endl;  (Prints bucket
// 5 of container m.)

template <typename T>
struct bucket_print_wrapper {
    typedef typename T::const_local_iterator const_iterator;
    typedef typename T::size_type size_type;

    const_iterator begin() const { return m_map.cbegin(n); }

    const_iterator end() const { return m_map.cend(n); }

    bucket_print_wrapper(const T &m, size_type bucket) : m_map(m), n(bucket) {}

   private:
    const T &m_map;
    const size_type n;
};

}  // namespace pretty_print

// Global accessor functions for the convenience wrappers

template <typename T>
inline pretty_print::array_wrapper_n<T> pretty_print_array(const T *const a,
                                                           size_t n) {
    return pretty_print::array_wrapper_n<T>(a, n);
}

template <typename T>
pretty_print::bucket_print_wrapper<T> bucket_print(const T &m,
                                                   typename T::size_type n) {
    return pretty_print::bucket_print_wrapper<T>(m, n);
}

// Main magic entry point: An overload snuck into namespace std.
// Can we do better?

namespace std {
// Prints a container to the stream using default delimiters

template <typename T, typename TChar, typename TCharTraits>
inline typename enable_if<::pretty_print::is_container<T>::value,
                          basic_ostream<TChar, TCharTraits> &>::type
operator<<(basic_ostream<TChar, TCharTraits> &stream, const T &container) {
    return stream
           << ::pretty_print::print_container_helper<T, TChar, TCharTraits>(
                  container);
}
}  // namespace std

#endif  // H_PRETTY_PRINT
#line 79 "library/cpp/debug/dump.hpp"

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

