#pragma once

template <typename fps>
fps convolution_large(const fps &a, const fps &b) {
  using mint = typename fps::value_type;
  int len = 1LL << __builtin_ctz(mint::get_mod() - 1);
  if (a.empty() || b.empty()) return fps{};
  if ((int)a.size() + (int)b.size() - 1 <= len) return a * b;
  vector<fps> as, bs;
  for (int i = 0; i < (int)a.size(); i += len / 2) {
    fps v{begin(a) + i, begin(a) + min<int>(i + len / 2, a.size())};
    v.resize(len);
    v.ntt();
    as.push_back(v);
  }
  for (int i = 0; i < (int)b.size(); i += len / 2) {
    fps v{begin(b) + i, begin(b) + min<int>(i + len / 2, b.size())};
    v.resize(len);
    v.ntt();
    bs.push_back(v);
  }
  vector<fps> cs(as.size() + bs.size() - 1, fps(len));
  for (int i = 0; i < (int)as.size(); i++) {
    for (int j = 0; j < (int)bs.size(); j++) {
      for (int k = 0; k < len; k++) cs[i + j][k] += as[i][k] * bs[j][k];
    }
  }
  for (auto &v : cs) v.intt();

  fps c(a.size() + b.size() - 1);
  for (int i = 0; i < (int)cs.size(); i++) {
    int offset = len / 2 * i;
    int je = min<int>(len, c.size() - offset);
    for (int j = 0; j < je; j++) c[j + offset] += cs[i][j];
  }
  return c;
}