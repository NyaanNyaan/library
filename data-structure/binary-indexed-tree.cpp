template <typename T>
struct BinaryIndexedTree {
  int N;
  int max_2beki;
  vector<T> data;

  BinaryIndexedTree(int size) {
    N = ++size;
    data.assign(N, 0);
    max_2beki = 1;
    while (max_2beki * 2 <= N) max_2beki *= 2;
  }

  // get sum of [0,k]
  T sum(int k) {
    if (k < 0) return 0;  // return 0 if k < 0
    T ret = 0;
    for (++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  // getsum of [l,r]
  inline T sum(int l, int r) { return sum(r) - sum(l - 1); }

  // get value of k
  inline T operator[](int k) { return sum(k) - sum(k - 1); }

  // data[k] += x
  void add(int k, T x) {
    for (++k; k < N; k += k & -k) data[k] += x;
  }

  // range add x to [l,r]
  void imos(int l, int r, T x) {
    add(l, x);
    add(r + 1, -x);
  }

  // minimize i s.t. sum(i) >= w
  int lower_bound(T w) {
    if (w <= 0) return 0;
    int x = 0;
    for (int k = max_2beki; k > 0; k /= 2) {
      if (x + k <= N - 1 && data[x + k] < w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }

  // minimize i s.t. sum(i) > w
  int upper_bound(T w) {
    if (w < 0) return 0;
    int x = 0;
    for (int k = max_2beki; k > 0; k /= 2) {
      if (x + k <= N - 1 && data[x + k] <= w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }
};