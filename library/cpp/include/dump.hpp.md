---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/cpp/debug/dump.hpp
    title: library/cpp/debug/dump.hpp
  - icon: ':warning:'
    path: library/cpp/debug/prettyprint.hpp
    title: library/cpp/debug/prettyprint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/cpp/debug/dump.hpp\"\n\n// http://www.creativ.xyz/dump-cpp-652\n\
    using namespace std;\n#include <bits/stdc++.h>\n\n#define DUMPOUT cerr  // where\
    \ to dump. cout or cerr\n\n#define cerrendl cerr << endl\n\nnamespace dm {\n \
    \   stack<vector<string>> arg_names;\n    stack<int> varidx;\n    int i;\n   \
    \ int j;\n}  // namespace dm\n\n#define dump(...)                            \
    \                                       \\\n    {                            \
    \                                                   \\\n        dm::arg_names.push(parse_args_names(#__VA_ARGS__));\
    \                         \\\n        dm::varidx.push(0);                    \
    \                                     \\\n        dump_func(__VA_ARGS__);    \
    \                                                 \\\n        DUMPOUT << \"in\
    \ [\" << __LINE__ << \":\" << __FUNCTION__ << \"]\" << endl;        \\\n     \
    \   dm::arg_names.pop();                                                     \
    \   \\\n        dm::varidx.pop();                                            \
    \               \\\n    }\n\n#define dump_1d(x, n)                           \
    \                                    \\\n    {                               \
    \                                                \\\n        DUMPOUT << #x <<\
    \ \"[\" << #n << \"]\"                                           \\\n        \
    \        << \":=> \";                                                        \
    \ \\\n        dump_1d_core(x, n);                                            \
    \             \\\n        DUMPOUT << \"  in [\" << __LINE__ << \":\" << __FUNCTION__\
    \ << \"]\" << endl;      \\\n    }\n\n#define dump_2d(x, n, m)               \
    \                                             \\\n    {                      \
    \                                                         \\\n        DUMPOUT\
    \ << #x << \"[\" << #n << \"]\"                                           \\\n\
    \                << \"[\" << #m << \"]\"                                     \
    \            \\\n                << \":=> \\n\";                             \
    \                           \\\n        dump_2d_core(x, n, m);               \
    \                                       \\\n        DUMPOUT << \"  in [\" << __LINE__\
    \ << \":\" << __FUNCTION__ << \"]\" << endl;      \\\n    }\n\nvoid dump_func()\
    \ {}\ntemplate <class Head, class... Tail>\nvoid dump_func(Head&& head, Tail&&...\
    \ tail) {\n    DUMPOUT << dm::arg_names.top()[dm::varidx.top()] << \":\"\n   \
    \         << head;\n    if (sizeof...(Tail) == 0) {\n        DUMPOUT << \" \"\
    ;\n    } else {\n        DUMPOUT << \", \";\n    }\n    ++dm::varidx.top();\n\
    \    dump_func(std::move(tail)...);\n}\n\ntemplate <class T>\nstring to_string_mod(T\
    \ v) {\n    T inf = numeric_limits<T>::max() / 2.1;\n    if (v == inf) return\
    \ \"inf\";\n    else if (v == -inf) return \"-inf\";\n    else return to_string(v);\n\
    }\n\ntemplate <class T, template <class C> class VEC>\nvoid dump_1d_core(VEC<T>&\
    \ x, int m){\n    vector<int> column_len(m, 2);\n    for(int j = 0; j < m; ++j)\
    \ {\n        int len = to_string_mod(x[j]).size();\n        if (len > column_len[j])\
    \ column_len[j] = len;\n    }\n\n    for(int j = 0; j < m; ++j) {\n        if\
    \ (j == 0) DUMPOUT << \"[\";\n        DUMPOUT << to_string_mod(x[j]);\n      \
    \  DUMPOUT << (j != m-1 ? \", \" : \"]\");\n    }\n}\n\ntemplate <class T, template\
    \ <class C> class VEC>\nvoid dump_2d_core(VEC<VEC<T>>& x, int n, int m){\n   \
    \ vector<int> column_len(m, 2);\n    for(int i = 0; i < n ; ++i) for(int j = 0;\
    \ j < m; ++j) {\n        int len = to_string_mod(x[i][j]).size();\n        if\
    \ (len > column_len[j]) column_len[j] = len;\n    }\n\n    // print header\n \
    \   int header_len = 0;\n    for(int j = 0; j < m ; ++j) {\n        if (j == 0)\
    \ {\n            DUMPOUT << string(7, ' ');\n        }\n        else{\n      \
    \      DUMPOUT << \" \";\n            header_len++;\n        }\n        DUMPOUT\
    \ << setw(column_len[j]) << j;\n        header_len += column_len[j];\n       \
    \ DUMPOUT << (((j) == (m - 1)) ? \"\\n\" : \"\");\n    }\n    DUMPOUT << string(7,\
    \ ' ');\n    DUMPOUT << string(header_len, '-');\n    DUMPOUT << \"\\n\";\n\n\
    \    for(int i = 0; i < n ; ++i) for(int j = 0; j < m; ++j) {\n        if (j ==\
    \ 0) DUMPOUT << setw(5) << i << \" |\";\n        else DUMPOUT << \" \";\n    \
    \    DUMPOUT << setw(column_len[j]) << to_string_mod(x[i][j]);\n        DUMPOUT\
    \ << (((j) == (m - 1)) ? \"|\\n\" : \"\");\n    }\n}\n\n\nvector<string> parse_args_names(string\
    \ s){\n    int n = s.size();\n    vector<string> res;\n    string tmp = \"\";\n\
    \    int parlevel = 0;\n    int angle_level = 0;\n    for (int i = 0; i < n; i++)\
    \ {\n        if (s[i] == '(') parlevel++;\n        if (s[i] == ')') parlevel--;\n\
    \        if (s[i] == '<') angle_level++;\n        if (s[i] == '>') angle_level--;\n\
    \        if (s[i] == ' ') continue;\n        if (s[i] == ',' && parlevel == 0\
    \ && angle_level == 0) {\n            res.push_back(tmp);\n            tmp = \"\
    \";\n        }\n        else {\n            tmp += s[i];\n        }\n    }\n \
    \   res.push_back(tmp);\n    return res;\n}\n\n#line 1 \"library/cpp/debug/prettyprint.hpp\"\
    \n//          Copyright Louis Delacroix 2010 - 2014.\n// Distributed under the\
    \ Boost Software License, Version 1.0.\n//    (See accompanying file LICENSE_1_0.txt\
    \ or copy at\n//          http://www.boost.org/LICENSE_1_0.txt)\n//\n// A pretty\
    \ printing library for C++\n//\n// Usage:\n// Include this header, and operator<<\
    \ will \"just work\".\n\n#ifndef H_PRETTY_PRINT\n#define H_PRETTY_PRINT\n\n#include\
    \ <cstddef>\n#include <iterator>\n#include <memory>\n#include <ostream>\n#include\
    \ <set>\n#include <tuple>\n#include <type_traits>\n#include <unordered_set>\n\
    #include <utility>\n#include <valarray>\n\nnamespace pretty_print {\nnamespace\
    \ detail {\n// SFINAE type trait to detect whether T::const_iterator exists.\n\
    \nstruct sfinae_base {\n    using yes = char;\n    using no = yes[2];\n};\n\n\
    template <typename T>\nstruct has_const_iterator : private sfinae_base {\n   private:\n\
    \    template <typename C>\n    static yes &test(typename C::const_iterator *);\n\
    \    template <typename C>\n    static no &test(...);\n\n   public:\n    static\
    \ const bool value = sizeof(test<T>(nullptr)) == sizeof(yes);\n    using type\
    \ = T;\n};\n\ntemplate <typename T>\nstruct has_begin_end : private sfinae_base\
    \ {\n   private:\n    template <typename C>\n    static yes &f(\n        typename\
    \ std::enable_if<std::is_same<\n            decltype(static_cast<typename C::const_iterator\
    \ (C::*)() const>(\n                &C::begin)),\n            typename C::const_iterator\
    \ (C::*)() const>::value>::type *);\n\n    template <typename C>\n    static no\
    \ &f(...);\n\n    template <typename C>\n    static yes &\n    g(typename std::enable_if<\n\
    \        std::is_same<decltype(static_cast<typename C::const_iterator (C::*)()\n\
    \                                              const>(&C::end)),\n           \
    \          typename C::const_iterator (C::*)() const>::value,\n        void>::type\
    \ *);\n\n    template <typename C>\n    static no &g(...);\n\n   public:\n   \
    \ static bool const beg_value = sizeof(f<T>(nullptr)) == sizeof(yes);\n    static\
    \ bool const end_value = sizeof(g<T>(nullptr)) == sizeof(yes);\n};\n\n}  // namespace\
    \ detail\n\n// Holds the delimiter values for a specific character type\n\ntemplate\
    \ <typename TChar>\nstruct delimiters_values {\n    using char_type = TChar;\n\
    \    const char_type *prefix;\n    const char_type *delimiter;\n    const char_type\
    \ *postfix;\n};\n\n// Defines the delimiter values for a specific container and\
    \ character type\n\ntemplate <typename T, typename TChar>\nstruct delimiters {\n\
    \    using type = delimiters_values<TChar>;\n    static const type values;\n};\n\
    \n// Functor to print containers. You can use this directly if you want\n// to\
    \ specificy a non-default delimiters type. The printing logic can\n// be customized\
    \ by specializing the nested template.\n\ntemplate <typename T, typename TChar\
    \ = char,\n          typename TCharTraits = ::std::char_traits<TChar>,\n     \
    \     typename TDelimiters = delimiters<T, TChar>>\nstruct print_container_helper\
    \ {\n    using delimiters_type = TDelimiters;\n    using ostream_type = std::basic_ostream<TChar,\
    \ TCharTraits>;\n\n    template <typename U>\n    struct printer {\n        static\
    \ void print_body(const U &c, ostream_type &stream) {\n            using std::begin;\n\
    \            using std::end;\n\n            auto it = begin(c);\n            const\
    \ auto the_end = end(c);\n\n            if (it != the_end) {\n               \
    \ for (;;) {\n                    stream << *it;\n\n                    if (++it\
    \ == the_end) break;\n\n                    if (delimiters_type::values.delimiter\
    \ != NULL)\n                        stream << delimiters_type::values.delimiter;\n\
    \                }\n            }\n        }\n    };\n\n    print_container_helper(const\
    \ T &container) : container_(container) {}\n\n    inline void operator()(ostream_type\
    \ &stream) const {\n        if (delimiters_type::values.prefix != NULL)\n    \
    \        stream << delimiters_type::values.prefix;\n\n        printer<T>::print_body(container_,\
    \ stream);\n\n        if (delimiters_type::values.postfix != NULL)\n         \
    \   stream << delimiters_type::values.postfix;\n    }\n\n   private:\n    const\
    \ T &container_;\n};\n\n// Specialization for pairs\n\ntemplate <typename T, typename\
    \ TChar, typename TCharTraits,\n          typename TDelimiters>\ntemplate <typename\
    \ T1, typename T2>\nstruct print_container_helper<T, TChar, TCharTraits,\n   \
    \                           TDelimiters>::printer<std::pair<T1, T2>> {\n    using\
    \ ostream_type =\n        typename print_container_helper<T, TChar, TCharTraits,\n\
    \                                        TDelimiters>::ostream_type;\n\n    static\
    \ void print_body(const std::pair<T1, T2> &c, ostream_type &stream) {\n      \
    \  stream << c.first;\n        if (print_container_helper<T, TChar, TCharTraits,\n\
    \                                   TDelimiters>::delimiters_type::values\n  \
    \              .delimiter != NULL)\n            stream\n                << print_container_helper<T,\
    \ TChar, TCharTraits,\n                                          TDelimiters>::delimiters_type::values\n\
    \                       .delimiter;\n        stream << c.second;\n    }\n};\n\n\
    // Specialization for tuples\n\ntemplate <typename T, typename TChar, typename\
    \ TCharTraits,\n          typename TDelimiters>\ntemplate <typename... Args>\n\
    struct print_container_helper<T, TChar, TCharTraits,\n                       \
    \       TDelimiters>::printer<std::tuple<Args...>> {\n    using ostream_type =\n\
    \        typename print_container_helper<T, TChar, TCharTraits,\n            \
    \                            TDelimiters>::ostream_type;\n    using element_type\
    \ = std::tuple<Args...>;\n\n    template <std::size_t I>\n    struct Int {};\n\
    \n    static void print_body(const element_type &c, ostream_type &stream) {\n\
    \        tuple_print(c, stream, Int<0>());\n    }\n\n    static void tuple_print(const\
    \ element_type &, ostream_type &,\n                            Int<sizeof...(Args)>)\
    \ {}\n\n    static void tuple_print(\n        const element_type &c, ostream_type\
    \ &stream,\n        typename std::conditional<sizeof...(Args) != 0, Int<0>,\n\
    \                                  std::nullptr_t>::type) {\n        stream <<\
    \ std::get<0>(c);\n        tuple_print(c, stream, Int<1>());\n    }\n\n    template\
    \ <std::size_t N>\n    static void tuple_print(const element_type &c, ostream_type\
    \ &stream,\n                            Int<N>) {\n        if (print_container_helper<T,\
    \ TChar, TCharTraits,\n                                   TDelimiters>::delimiters_type::values\n\
    \                .delimiter != NULL)\n            stream\n                << print_container_helper<T,\
    \ TChar, TCharTraits,\n                                          TDelimiters>::delimiters_type::values\n\
    \                       .delimiter;\n\n        stream << std::get<N>(c);\n\n \
    \       tuple_print(c, stream, Int<N + 1>());\n    }\n};\n\n// Prints a print_container_helper\
    \ to the specified stream.\n\ntemplate <typename T, typename TChar, typename TCharTraits,\n\
    \          typename TDelimiters>\ninline std::basic_ostream<TChar, TCharTraits>\
    \ &operator<<(\n    std::basic_ostream<TChar, TCharTraits> &stream,\n    const\
    \ print_container_helper<T, TChar, TCharTraits, TDelimiters> &helper) {\n    helper(stream);\n\
    \    return stream;\n}\n\n// Basic is_container template; specialize to derive\
    \ from std::true_type for all\n// desired container types\n\ntemplate <typename\
    \ T>\nstruct is_container\n    : public std::integral_constant<bool,\n       \
    \                             detail::has_const_iterator<T>::value &&\n      \
    \                                  detail::has_begin_end<T>::beg_value &&\n  \
    \                                      detail::has_begin_end<T>::end_value> {};\n\
    \ntemplate <typename T, std::size_t N>\nstruct is_container<T[N]> : std::true_type\
    \ {};\n\ntemplate <std::size_t N>\nstruct is_container<char[N]> : std::false_type\
    \ {};\n\ntemplate <typename T>\nstruct is_container<std::valarray<T>> : std::true_type\
    \ {};\n\ntemplate <typename T1, typename T2>\nstruct is_container<std::pair<T1,\
    \ T2>> : std::true_type {};\n\ntemplate <typename... Args>\nstruct is_container<std::tuple<Args...>>\
    \ : std::true_type {};\n\n// Default delimiters\n\ntemplate <typename T>\nstruct\
    \ delimiters<T, char> {\n    static const delimiters_values<char> values;\n};\n\
    template <typename T>\nconst delimiters_values<char> delimiters<T, char>::values\
    \ = {\"[\", \", \", \"]\"};\ntemplate <typename T>\nstruct delimiters<T, wchar_t>\
    \ {\n    static const delimiters_values<wchar_t> values;\n};\ntemplate <typename\
    \ T>\nconst delimiters_values<wchar_t> delimiters<T, wchar_t>::values = {L\"[\"\
    , L\", \",\n                                                                 \
    \  L\"]\"};\n\n// Delimiters for (multi)set and unordered_(multi)set\n\ntemplate\
    \ <typename T, typename TComp, typename TAllocator>\nstruct delimiters<::std::set<T,\
    \ TComp, TAllocator>, char> {\n    static const delimiters_values<char> values;\n\
    };\n\ntemplate <typename T, typename TComp, typename TAllocator>\nconst delimiters_values<char>\n\
    \    delimiters<::std::set<T, TComp, TAllocator>, char>::values = {\"{\", \",\
    \ \",\n                                                                  \"}\"\
    };\n\ntemplate <typename T, typename TComp, typename TAllocator>\nstruct delimiters<::std::set<T,\
    \ TComp, TAllocator>, wchar_t> {\n    static const delimiters_values<wchar_t>\
    \ values;\n};\n\ntemplate <typename T, typename TComp, typename TAllocator>\n\
    const delimiters_values<wchar_t>\n    delimiters<::std::set<T, TComp, TAllocator>,\
    \ wchar_t>::values = {\n        L\"{\", L\", \", L\"}\"};\n\ntemplate <typename\
    \ T, typename TComp, typename TAllocator>\nstruct delimiters<::std::multiset<T,\
    \ TComp, TAllocator>, char> {\n    static const delimiters_values<char> values;\n\
    };\n\ntemplate <typename T, typename TComp, typename TAllocator>\nconst delimiters_values<char>\n\
    \    delimiters<::std::multiset<T, TComp, TAllocator>, char>::values = {\n   \
    \     \"{\", \", \", \"}\"};\n\ntemplate <typename T, typename TComp, typename\
    \ TAllocator>\nstruct delimiters<::std::multiset<T, TComp, TAllocator>, wchar_t>\
    \ {\n    static const delimiters_values<wchar_t> values;\n};\n\ntemplate <typename\
    \ T, typename TComp, typename TAllocator>\nconst delimiters_values<wchar_t>\n\
    \    delimiters<::std::multiset<T, TComp, TAllocator>, wchar_t>::values = {\n\
    \        L\"{\", L\", \", L\"}\"};\n\ntemplate <typename T, typename THash, typename\
    \ TEqual, typename TAllocator>\nstruct delimiters<::std::unordered_set<T, THash,\
    \ TEqual, TAllocator>, char> {\n    static const delimiters_values<char> values;\n\
    };\n\ntemplate <typename T, typename THash, typename TEqual, typename TAllocator>\n\
    const delimiters_values<char> delimiters<\n    ::std::unordered_set<T, THash,\
    \ TEqual, TAllocator>, char>::values = {\n    \"{\", \", \", \"}\"};\n\ntemplate\
    \ <typename T, typename THash, typename TEqual, typename TAllocator>\nstruct delimiters<::std::unordered_set<T,\
    \ THash, TEqual, TAllocator>, wchar_t> {\n    static const delimiters_values<wchar_t>\
    \ values;\n};\n\ntemplate <typename T, typename THash, typename TEqual, typename\
    \ TAllocator>\nconst delimiters_values<wchar_t> delimiters<\n    ::std::unordered_set<T,\
    \ THash, TEqual, TAllocator>, wchar_t>::values = {\n    L\"{\", L\", \", L\"}\"\
    };\n\ntemplate <typename T, typename THash, typename TEqual, typename TAllocator>\n\
    struct delimiters<::std::unordered_multiset<T, THash, TEqual, TAllocator>,\n \
    \                 char> {\n    static const delimiters_values<char> values;\n\
    };\n\ntemplate <typename T, typename THash, typename TEqual, typename TAllocator>\n\
    const delimiters_values<char> delimiters<\n    ::std::unordered_multiset<T, THash,\
    \ TEqual, TAllocator>, char>::values = {\n    \"{\", \", \", \"}\"};\n\ntemplate\
    \ <typename T, typename THash, typename TEqual, typename TAllocator>\nstruct delimiters<::std::unordered_multiset<T,\
    \ THash, TEqual, TAllocator>,\n                  wchar_t> {\n    static const\
    \ delimiters_values<wchar_t> values;\n};\n\ntemplate <typename T, typename THash,\
    \ typename TEqual, typename TAllocator>\nconst delimiters_values<wchar_t>\n  \
    \  delimiters<::std::unordered_multiset<T, THash, TEqual, TAllocator>,\n     \
    \          wchar_t>::values = {L\"{\", L\", \", L\"}\"};\n\n// Delimiters for\
    \ pair and tuple\n\ntemplate <typename T1, typename T2>\nstruct delimiters<std::pair<T1,\
    \ T2>, char> {\n    static const delimiters_values<char> values;\n};\ntemplate\
    \ <typename T1, typename T2>\nconst delimiters_values<char> delimiters<std::pair<T1,\
    \ T2>, char>::values = {\n    \"(\", \", \", \")\"};\ntemplate <typename T1, typename\
    \ T2>\nstruct delimiters<::std::pair<T1, T2>, wchar_t> {\n    static const delimiters_values<wchar_t>\
    \ values;\n};\ntemplate <typename T1, typename T2>\nconst delimiters_values<wchar_t>\n\
    \    delimiters<::std::pair<T1, T2>, wchar_t>::values = {L\"(\", L\", \", L\"\
    )\"};\n\ntemplate <typename... Args>\nstruct delimiters<std::tuple<Args...>, char>\
    \ {\n    static const delimiters_values<char> values;\n};\ntemplate <typename...\
    \ Args>\nconst delimiters_values<char> delimiters<std::tuple<Args...>, char>::values\
    \ = {\n    \"(\", \", \", \")\"};\ntemplate <typename... Args>\nstruct delimiters<::std::tuple<Args...>,\
    \ wchar_t> {\n    static const delimiters_values<wchar_t> values;\n};\ntemplate\
    \ <typename... Args>\nconst delimiters_values<wchar_t>\n    delimiters<::std::tuple<Args...>,\
    \ wchar_t>::values = {L\"(\", L\", \", L\")\"};\n\n// Type-erasing helper class\
    \ for easy use of custom delimiters.\n// Requires TCharTraits = std::char_traits<TChar>\
    \ and TChar = char or wchar_t,\n// and MyDelims needs to be defined for TChar.\
    \ Usage: \"cout <<\n// pretty_print::custom_delims<MyDelims>(x)\".\n\nstruct custom_delims_base\
    \ {\n    virtual ~custom_delims_base() {}\n    virtual std::ostream &stream(::std::ostream\
    \ &) = 0;\n    virtual std::wostream &stream(::std::wostream &) = 0;\n};\n\ntemplate\
    \ <typename T, typename Delims>\nstruct custom_delims_wrapper : custom_delims_base\
    \ {\n    custom_delims_wrapper(const T &t_) : t(t_) {}\n\n    std::ostream &stream(std::ostream\
    \ &s) {\n        return s << print_container_helper<T, char, std::char_traits<char>,\n\
    \                                           Delims>(t);\n    }\n\n    std::wostream\
    \ &stream(std::wostream &s) {\n        return s << print_container_helper<T, wchar_t,\n\
    \                                           std::char_traits<wchar_t>, Delims>(\n\
    \                   t);\n    }\n\n   private:\n    const T &t;\n};\n\ntemplate\
    \ <typename Delims>\nstruct custom_delims {\n    template <typename Container>\n\
    \    custom_delims(const Container &c)\n        : base(new custom_delims_wrapper<Container,\
    \ Delims>(c)) {}\n\n    std::unique_ptr<custom_delims_base> base;\n};\n\ntemplate\
    \ <typename TChar, typename TCharTraits, typename Delims>\ninline std::basic_ostream<TChar,\
    \ TCharTraits> &operator<<(\n    std::basic_ostream<TChar, TCharTraits> &s, const\
    \ custom_delims<Delims> &p) {\n    return p.base->stream(s);\n}\n\n// A wrapper\
    \ for a C-style array given as pointer-plus-size.\n// Usage: std::cout << pretty_print_array(arr,\
    \ n) << std::endl;\n\ntemplate <typename T>\nstruct array_wrapper_n {\n    typedef\
    \ const T *const_iterator;\n    typedef T value_type;\n\n    array_wrapper_n(const\
    \ T *const a, size_t n) : _array(a), _n(n) {}\n    inline const_iterator begin()\
    \ const { return _array; }\n    inline const_iterator end() const { return _array\
    \ + _n; }\n\n   private:\n    const T *const _array;\n    size_t _n;\n};\n\n//\
    \ A wrapper for hash-table based containers that offer local iterators to each\n\
    // bucket. Usage: std::cout << bucket_print(m, 4) << std::endl;  (Prints bucket\n\
    // 5 of container m.)\n\ntemplate <typename T>\nstruct bucket_print_wrapper {\n\
    \    typedef typename T::const_local_iterator const_iterator;\n    typedef typename\
    \ T::size_type size_type;\n\n    const_iterator begin() const { return m_map.cbegin(n);\
    \ }\n\n    const_iterator end() const { return m_map.cend(n); }\n\n    bucket_print_wrapper(const\
    \ T &m, size_type bucket) : m_map(m), n(bucket) {}\n\n   private:\n    const T\
    \ &m_map;\n    const size_type n;\n};\n\n}  // namespace pretty_print\n\n// Global\
    \ accessor functions for the convenience wrappers\n\ntemplate <typename T>\ninline\
    \ pretty_print::array_wrapper_n<T> pretty_print_array(const T *const a,\n    \
    \                                                       size_t n) {\n    return\
    \ pretty_print::array_wrapper_n<T>(a, n);\n}\n\ntemplate <typename T>\npretty_print::bucket_print_wrapper<T>\
    \ bucket_print(const T &m,\n                                                 \
    \  typename T::size_type n) {\n    return pretty_print::bucket_print_wrapper<T>(m,\
    \ n);\n}\n\n// Main magic entry point: An overload snuck into namespace std.\n\
    // Can we do better?\n\nnamespace std {\n// Prints a container to the stream using\
    \ default delimiters\n\ntemplate <typename T, typename TChar, typename TCharTraits>\n\
    inline typename enable_if<::pretty_print::is_container<T>::value,\n          \
    \                basic_ostream<TChar, TCharTraits> &>::type\noperator<<(basic_ostream<TChar,\
    \ TCharTraits> &stream, const T &container) {\n    return stream\n           <<\
    \ ::pretty_print::print_container_helper<T, TChar, TCharTraits>(\n           \
    \       container);\n}\n}  // namespace std\n\n#endif  // H_PRETTY_PRINT\n#line\
    \ 2 \"library/cpp/include/dump.hpp\"\n"
  code: '#include "../debug/dump.hpp"'
  dependsOn:
  - library/cpp/debug/dump.hpp
  - library/cpp/debug/prettyprint.hpp
  isVerificationFile: false
  path: library/cpp/include/dump.hpp
  requiredBy: []
  timestamp: '2020-11-09 20:34:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/cpp/include/dump.hpp
layout: document
redirect_from:
- /library/library/cpp/include/dump.hpp
- /library/library/cpp/include/dump.hpp.html
title: library/cpp/include/dump.hpp
---
