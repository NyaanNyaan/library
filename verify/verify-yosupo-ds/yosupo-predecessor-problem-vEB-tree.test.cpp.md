---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/van_emde_boas_tree.hpp
    title: data-structure/van_emde_boas_tree.hpp
  - icon: ':question:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-predecessor-problem-vEB-tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n//\n\
    #include <array>\n#include <cstring>\n#include <type_traits>\n#include <utility>\n\
    \nusing namespace std;\n\n#line 2 \"data-structure/van_emde_boas_tree.hpp\"\n\n\
    namespace vEB_tree_impl {\nusing u64 = uint64_t;\nstatic constexpr unsigned int\
    \ lgW = 6;\nstatic constexpr unsigned int W = 1u << lgW;\nstatic constexpr int\
    \ inf = 1 << 30;\ninline int ctz(u64 n) { return n ? __builtin_ctzll(n) : -1;\
    \ }\ninline int clz(u64 n) { return n ? 63 - __builtin_clzll(n) : -1; }\n\ntemplate\
    \ <int LOG, class D = void>\nstruct vEB_tree_node {\n  using Chd = vEB_tree_node<(LOG\
    \ >> 1)>;\n\n  Chd map;\n  int mn, mx;\n  static constexpr int shift = (LOG >>\
    \ 1) * lgW;\n  array<Chd, 1 << shift> chd;\n\n  inline int mask(u64 key) const\
    \ { return key & ((1 << shift) - 1); }\n\n  constexpr vEB_tree_node() : mn(inf),\
    \ mx(-1) {}\n\n  void insert(int key) {\n    mn = std::min(mn, key), mx = std::max(mx,\
    \ key);\n    int pos = key >> shift;\n    if (chd[pos].empty()) map.insert(pos);\n\
    \    chd[pos].insert(mask(key));\n  }\n\n  void erase(int key) {\n    int pos\
    \ = key >> shift;\n    chd[pos].erase(mask(key));\n    if (chd[pos].empty()) map.erase(pos);\n\
    \    if (mn == mx) {\n      mn = inf, mx = -1;\n    } else if (mn == key) {\n\
    \      int p = map.min();\n      mn = (p << shift) + chd[p].min();\n    } else\
    \ if (mx == key) {\n      int p = map.max();\n      mx = (p << shift) + chd[p].max();\n\
    \    }\n  }\n\n  bool contain(int key) const {\n    int pos = key >> shift;\n\
    \    return chd[pos].contain(mask(key));\n  }\n\n  inline bool empty() const {\
    \ return mx == -1; }\n  inline int min() const { return mn == inf ? -1 : mn; }\n\
    \  inline int max() const { return mx; }\n\n  int find_next(int key) const {\n\
    \    if (key <= min()) return min();\n    if (max() < key) return -1;\n    int\
    \ pos = key >> shift;\n    if (map.contain(pos) && mask(key) <= chd[pos].max())\
    \ {\n      return (pos << shift) + chd[pos].find_next(mask(key));\n    }\n   \
    \ int nxt = map.find_next(pos + 1);\n    if (nxt == -1) return -1;\n    return\
    \ (nxt << shift) + chd[nxt].min();\n  }\n\n  int find_prev(int key) const {\n\
    \    if (max() < key) return max();\n    if (key <= min()) return -1;\n    int\
    \ pos = key >> shift;\n    if (map.contain(pos) && chd[pos].min() < mask(key))\
    \ {\n      return (pos << shift) + chd[pos].find_prev(mask(key));\n    }\n   \
    \ int nxt = map.find_prev(pos);\n    if (nxt == -1) return -1;\n    return (nxt\
    \ << shift) + chd[nxt].max();\n  }\n};\n\ntemplate <int LOG>\nstruct vEB_tree_node<LOG,\
    \ typename std::enable_if<LOG == 1>::type> {\n  u64 map;\n  vEB_tree_node() :\
    \ map(0) {}\n  inline void insert(int key) { map |= 1ULL << key; }\n  inline void\
    \ erase(int key) { map &= ~(1ULL << key); }\n  inline bool contain(int key) const\
    \ { return (map >> key) & 1; }\n  inline bool empty() const { return map == 0;\
    \ }\n  inline int min() const { return ctz(map); }\n  inline int max() const {\
    \ return clz(map); }\n  int find_next(int key) const { return ctz(map & ~((1ULL\
    \ << key) - 1)); }\n  int find_prev(int key) const { return clz(map & ((1ULL <<\
    \ key) - 1)); }\n};\n\n}  // namespace vEB_tree_impl\n\nusing van_Emde_Boas_tree\
    \ = vEB_tree_impl::vEB_tree_node<4>;\n#line 2 \"misc/fastio.hpp\"\n\n#line 6 \"\
    misc/fastio.hpp\"\n\nusing namespace std;\n\nnamespace fastio {\nstatic constexpr\
    \ int SZ = 1 << 17;\nchar ibuf[SZ], obuf[SZ];\nint pil = 0, pir = 0, por = 0;\n\
    \nstruct Pre {\n  char num[40000];\n  constexpr Pre() : num() {\n    for (int\
    \ i = 0; i < 10000; i++) {\n      int n = i;\n      for (int j = 3; j >= 0; j--)\
    \ {\n        num[i * 4 + j] = n % 10 + '0';\n        n /= 10;\n      }\n    }\n\
    \  }\n} constexpr pre;\n\ninline void load() {\n  memcpy(ibuf, ibuf + pil, pir\
    \ - pil);\n  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);\n\
    \  pil = 0;\n}\ninline void flush() {\n  fwrite(obuf, 1, por, stdout);\n  por\
    \ = 0;\n}\n\ninline void skip_space() {\n  if (pil + 32 > pir) load();\n  while\
    \ (ibuf[pil] <= ' ') pil++;\n}\n\ninline void rd(char& c) {\n  if (pil + 32 >\
    \ pir) load();\n  c = ibuf[pil++];\n}\ntemplate <typename T>\ninline void rd(T&\
    \ x) {\n  if (pil + 32 > pir) load();\n  char c;\n  do c = ibuf[pil++];\n  while\
    \ (c < '-');\n  [[maybe_unused]] bool minus = false;\n  if constexpr (is_signed<T>::value\
    \ == true) {\n    if (c == '-') minus = true, c = ibuf[pil++];\n  }\n  x = 0;\n\
    \  while (c >= '0') {\n    x = x * 10 + (c & 15);\n    c = ibuf[pil++];\n  }\n\
    \  if constexpr (is_signed<T>::value == true) {\n    if (minus) x = -x;\n  }\n\
    }\ninline void rd() {}\ntemplate <typename Head, typename... Tail>\ninline void\
    \ rd(Head& head, Tail&... tail) {\n  rd(head);\n  rd(tail...);\n}\n\ninline void\
    \ wt(char c) {\n  if (por > SZ - 32) flush();\n  obuf[por++] = c;\n}\ninline void\
    \ wt(bool b) { \n  if (por > SZ - 32) flush();\n  obuf[por++] = b ? '1' : '0';\
    \ \n}\ntemplate <typename T>\ninline void wt(T x) {\n  if (por > SZ - 32) flush();\n\
    \  if (!x) {\n    obuf[por++] = '0';\n    return;\n  }\n  if constexpr (is_signed<T>::value\
    \ == true) {\n    if (x < 0) obuf[por++] = '-', x = -x;\n  }\n  int i = 12;\n\
    \  char buf[16];\n  while (x >= 10000) {\n    memcpy(buf + i, pre.num + (x % 10000)\
    \ * 4, 4);\n    x /= 10000;\n    i -= 4;\n  }\n  if (x < 100) {\n    if (x < 10)\
    \ {\n      obuf[por] = '0' + x;\n      ++por;\n    } else {\n      uint32_t q\
    \ = (uint32_t(x) * 205) >> 11;\n      uint32_t r = uint32_t(x) - q * 10;\n   \
    \   obuf[por] = '0' + q;\n      obuf[por + 1] = '0' + r;\n      por += 2;\n  \
    \  }\n  } else {\n    if (x < 1000) {\n      memcpy(obuf + por, pre.num + (x <<\
    \ 2) + 1, 3);\n      por += 3;\n    } else {\n      memcpy(obuf + por, pre.num\
    \ + (x << 2), 4);\n      por += 4;\n    }\n  }\n  memcpy(obuf + por, buf + i +\
    \ 4, 12 - i);\n  por += 12 - i;\n}\n\ninline void wt() {}\ntemplate <typename\
    \ Head, typename... Tail>\ninline void wt(Head&& head, Tail&&... tail) {\n  wt(head);\n\
    \  wt(forward<Tail>(tail)...);\n}\ntemplate <typename... Args>\ninline void wtn(Args&&...\
    \ x) {\n  wt(forward<Args>(x)...);\n  wt('\\n');\n}\n\nstruct Dummy {\n  Dummy()\
    \ { atexit(flush); }\n} dummy;\n\n}  // namespace fastio\nusing fastio::rd;\n\
    using fastio::skip_space;\nusing fastio::wt;\nusing fastio::wtn;\n#line 12 \"\
    verify/verify-yosupo-ds/yosupo-predecessor-problem-vEB-tree.test.cpp\"\n\nvan_Emde_Boas_tree\
    \ vEB;\n\nint main() {\n  unsigned int N, Q;\n  rd(N, Q);\n\n  skip_space();\n\
    \  for (unsigned int i = 0; i < N; i++) {\n    char c;\n    rd(c);\n    if (c\
    \ == '1') vEB.insert(i);\n  }\n\n  while (Q--) {\n    unsigned int c, k;\n   \
    \ rd(c, k);\n    if (c == 0) {\n      vEB.insert(k);\n    } else if (c == 1) {\n\
    \      vEB.erase(k);\n    } else if (c == 2) {\n      wtn(vEB.contain(k));\n \
    \   } else if (c == 3) {\n      wtn(vEB.find_next(k));\n    } else if (c == 4)\
    \ {\n      wtn(vEB.find_prev(k + 1));\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    //\n#include <array>\n#include <cstring>\n#include <type_traits>\n#include <utility>\n\
    \nusing namespace std;\n\n#include \"../../data-structure/van_emde_boas_tree.hpp\"\
    \n#include \"../../misc/fastio.hpp\"\n\nvan_Emde_Boas_tree vEB;\n\nint main()\
    \ {\n  unsigned int N, Q;\n  rd(N, Q);\n\n  skip_space();\n  for (unsigned int\
    \ i = 0; i < N; i++) {\n    char c;\n    rd(c);\n    if (c == '1') vEB.insert(i);\n\
    \  }\n\n  while (Q--) {\n    unsigned int c, k;\n    rd(c, k);\n    if (c == 0)\
    \ {\n      vEB.insert(k);\n    } else if (c == 1) {\n      vEB.erase(k);\n   \
    \ } else if (c == 2) {\n      wtn(vEB.contain(k));\n    } else if (c == 3) {\n\
    \      wtn(vEB.find_next(k));\n    } else if (c == 4) {\n      wtn(vEB.find_prev(k\
    \ + 1));\n    }\n  }\n}"
  dependsOn:
  - data-structure/van_emde_boas_tree.hpp
  - misc/fastio.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-predecessor-problem-vEB-tree.test.cpp
  requiredBy: []
  timestamp: '2021-03-08 15:21:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-predecessor-problem-vEB-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-predecessor-problem-vEB-tree.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-predecessor-problem-vEB-tree.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-predecessor-problem-vEB-tree.test.cpp
---
