#pragma once

#include "../graph/biconnected-components.hpp"

// aux : block cut tree
// id(V) : new id of node V
// is_arti(V) : return if V is articulation
template <typename G>
struct BlockCutTree {
  const G& g;
  BiConnectedComponents<G> bcc;
  vector<vector<int>> aux;
  vector<int> idar, idcc;

  BlockCutTree(const G& _g) : g(_g), bcc(g) { build(); }

  void build() {
    auto ar = bcc.articulation;
    idar.resize(g.size(), -1);
    idcc.resize(g.size(), -1);
    for (int i = 0; i < (int)ar.size(); i++) idar[ar[i]] = i;

    aux.resize(ar.size() + bcc.bc.size());
    vector<int> last(g.size(), -1);
    for (int i = 0; i < (int)bcc.bc.size(); i++) {
      vector<int> st;
      for (auto& [u, v] : bcc.bc[i]) st.push_back(u), st.push_back(v);
      for (auto& u : st) {
        if (idar[u] == -1) idcc[u] = i + ar.size();
        else if(last[u] != i){
          add(i + ar.size(), idar[u]);
          last[u] = i;
        }
      }
    }
  }

  vector<int>& operator[](int i) { return aux[i]; }

  int size() const { return aux.size(); }

  int id(int i) { return idar[i] == -1 ? idcc[i] : idar[i]; }

  bool is_arti(int i) { return idar[i] != -1; }

  int arti() const { return bcc.articulation.size(); }

 private:
  void add(int i, int j) {
    if (i == -1 or j == -1) return;
    aux[i].push_back(j);
    aux[j].push_back(i);
  };
};

/**
 * @brief Block Cut Tree
 */
