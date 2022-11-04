---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: random_graph/gen.hpp
    title: random_graph/gen.hpp
  - icon: ':warning:'
    path: random_graph/graph.hpp
    title: random_graph/graph.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://xoshiro.di.unimi.it/splitmix64.c
    - http://xoshiro.di.unimi.it/xoshiro256starstar.c
    - https://cpprefjp.github.io/reference/algorithm/shuffle.html)
    - https://github.com/yosupo06/library-checker-problems/blob/master/common/random.h
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ random_graph/random.hpp: line 4: #pragma once found in a non-first line\n"
  code: "// This software includes the work that is distributed in the Apache License\
    \ 2.0.\n// https://github.com/yosupo06/library-checker-problems/blob/master/common/random.h\n\
    \n#pragma once\n\n#include <algorithm>\n#include <array>\n#include <cassert>\n\
    #include <cstdint>\n#include <numeric>\n#include <random>\n#include <set>\n\n\
    struct Random {\n  private:\n    // Use xoshiro256**\n    // References: http://xoshiro.di.unimi.it/xoshiro256starstar.c\n\
    \    static uint64_t rotl(const uint64_t x, int k) {\n        return (x << k)\
    \ | (x >> (64 - k));\n    }\n\n    std::array<uint64_t, 4> s;\n\n    uint64_t\
    \ next() {\n        const uint64_t result_starstar = rotl(s[1] * 5, 7) * 9;\n\n\
    \        const uint64_t t = s[1] << 17;\n\n        s[2] ^= s[0];\n        s[3]\
    \ ^= s[1];\n        s[1] ^= s[2];\n        s[0] ^= s[3];\n\n        s[2] ^= t;\n\
    \n        s[3] = rotl(s[3], 45);\n\n        return result_starstar;\n    }\n\n\
    \    // random choice from [0, upper]\n    uint64_t next(uint64_t upper) {\n \
    \       if (!(upper & (upper + 1))) {\n            // b = 00..0011..11\n     \
    \       return next() & upper;\n        }\n        int lg = 63 - __builtin_clzll(upper);\n\
    \        uint64_t mask = (lg == 63) ? ~0ULL : (1ULL << (lg + 1)) - 1;\n      \
    \  while (true) {\n            uint64_t r = next() & mask;\n            if (r\
    \ <= upper)\n                return r;\n        }\n    }\n\n  public:\n    Random(uint64_t\
    \ seed = 0) {\n        // Use splitmix64\n        // Reference: http://xoshiro.di.unimi.it/splitmix64.c\n\
    \        for (int i = 0; i < 4; i++) {\n            uint64_t z = (seed += 0x9e3779b97f4a7c15);\n\
    \            z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;\n            z = (z ^ (z\
    \ >> 27)) * 0x94d049bb133111eb;\n            s[i] = z ^ (z >> 31);\n        }\n\
    \    }\n\n    // random choice from [lower, upper]\n    template <class T>\n \
    \   T uniform(T lower, T upper) {\n        assert(lower <= upper);\n        return\
    \ T(lower + next(uint64_t(upper - lower)));\n    }\n\n    // random choice from\
    \ false or true\n    bool uniform_bool() { return uniform(0, 1) == 1; }\n\n  \
    \  // random choice from [0.0, 1.0]\n    double uniform01() {\n        uint64_t\
    \ v = next(1ULL << 63);\n        return double(v) / (1ULL << 63);\n    }\n\n \
    \   // random choice non-empty sub-interval from interval [lower, upper)\n   \
    \ // equal: random choice 2 disjoint elements from [lower, upper]\n    template\
    \ <class T>\n    std::pair<T, T> uniform_pair(T lower, T upper) {\n        assert(upper\
    \ - lower >= 1);\n        T a, b;\n        do {\n            a = uniform(lower,\
    \ upper);\n            b = uniform(lower, upper);\n        } while (a == b);\n\
    \        if (a > b) std::swap(a, b);\n        return {a, b};\n    }\n\n    //\
    \ generate random lower string that length = n\n    std::string lower_string(size_t\
    \ n) {\n        std::string res = \"\";\n        for (size_t i = 0; i < n; i++)\
    \ {\n            res += uniform('a', 'z');\n        }\n        return res;\n \
    \   }\n\n    // random shuffle\n    template <class Iter>\n    void shuffle(Iter\
    \ first, Iter last) {\n        if (first == last) return;\n        // Reference\
    \ and edit:\n        // cpprefjp - C++\u65E5\u672C\u8A9E\u30EA\u30D5\u30A1\u30EC\
    \u30F3\u30B9\n        // (https://cpprefjp.github.io/reference/algorithm/shuffle.html)\n\
    \        int len = 1;\n        for (auto it = first + 1; it != last; it++) {\n\
    \            len++;\n            int j = uniform(0, len - 1);\n            if\
    \ (j != len - 1)\n                iter_swap(it, first + j);\n        }\n    }\n\
    \n    // generate random permutation that length = n\n    template <class T>\n\
    \    std::vector<T> perm(size_t n) {\n        std::vector<T> idx(n);\n       \
    \ std::iota(idx.begin(), idx.end(), T(0));\n        shuffle(idx.begin(), idx.end());\n\
    \        return idx;\n    }\n\n    // random choise n elements from [lower, upper]\n\
    \    template <class T>\n    std::vector<T> choice(size_t n, T lower, T upper)\
    \ {\n        assert(T(n) <= upper - lower + 1);\n        std::set<T> res;\n  \
    \      while (res.size() < n) res.insert(uniform(lower, upper));\n        return\
    \ {res.begin(), res.end()};\n    }\n} global_gen;\n"
  dependsOn: []
  isVerificationFile: false
  path: random_graph/random.hpp
  requiredBy:
  - random_graph/gen.hpp
  - random_graph/graph.hpp
  timestamp: '2021-08-10 23:14:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random_graph/random.hpp
layout: document
redirect_from:
- /library/random_graph/random.hpp
- /library/random_graph/random.hpp.html
title: random_graph/random.hpp
---
