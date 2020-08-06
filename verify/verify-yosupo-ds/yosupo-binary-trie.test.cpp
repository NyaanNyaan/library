#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../../competitive-template.hpp"
#include "../../data-structure/binary-trie.hpp"

void solve() {
  ini(Q);
  BinaryTrie<int, 30> trie;
  rep(_, Q) {
    ini(c, x);
    if (c == 0) {
      if (trie.find(x).first == 0) {
        trie.add(x);
      }
    } else if (c == 1) {
      if (trie.find(x).first != 0) {
        trie.del(x);
      }
    } else {
      trie.operate_xor(x);
      out(trie.min_element().first);
      trie.operate_xor(x);
    }
  }
}