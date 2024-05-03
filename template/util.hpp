namespace Nyaan {
using ll = long long;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;

template <typename T>
using V = vector<T>;
template <typename T>
using VV = vector<vector<T>>;
using vi = vector<int>;
using vl = vector<long long>;
using vd = V<double>;
using vs = V<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template <typename T, typename U>
struct P : pair<T, U> {
  template <typename... Args>
  P(Args... args) : pair<T, U>(args...) {}

  using pair<T, U>::first;
  using pair<T, U>::second;

  P &operator+=(const P &r) {
    first += r.first;
    second += r.second;
    return *this;
  }
  P &operator-=(const P &r) {
    first -= r.first;
    second -= r.second;
    return *this;
  }
  P &operator*=(const P &r) {
    first *= r.first;
    second *= r.second;
    return *this;
  }
  template <typename S>
  P &operator*=(const S &r) {
    first *= r, second *= r;
    return *this;
  }
  P operator+(const P &r) const { return P(*this) += r; }
  P operator-(const P &r) const { return P(*this) -= r; }
  P operator*(const P &r) const { return P(*this) *= r; }
  template <typename S>
  P operator*(const S &r) const {
    return P(*this) *= r;
  }
  P operator-() const { return P{-first, -second}; }
};

using pl = P<ll, ll>;
using pi = P<int, int>;
using vp = V<pl>;

constexpr int inf = 1001001001;
constexpr long long infLL = 4004004004004004004LL;

template <typename T>
int sz(const T &t) {
  return t.size();
}

template <typename T, typename U>
inline bool amin(T &x, U y) {
  return (y < x) ? (x = y, true) : false;
}
template <typename T, typename U>
inline bool amax(T &x, U y) {
  return (x < y) ? (x = y, true) : false;
}

template <typename T>
inline T Max(const vector<T> &v) {
  return *max_element(begin(v), end(v));
}
template <typename T>
inline T Min(const vector<T> &v) {
  return *min_element(begin(v), end(v));
}
template <typename T>
inline long long Sum(const vector<T> &v) {
  return accumulate(begin(v), end(v), 0LL);
}

template <typename T>
int lb(const vector<T> &v, const T &a) {
  return lower_bound(begin(v), end(v), a) - begin(v);
}
template <typename T>
int ub(const vector<T> &v, const T &a) {
  return upper_bound(begin(v), end(v), a) - begin(v);
}

constexpr long long TEN(int n) {
  long long ret = 1, x = 10;
  for (; n; x *= x, n >>= 1) ret *= (n & 1 ? x : 1);
  return ret;
}

template <typename T, typename U>
pair<T, U> mkp(const T &t, const U &u) {
  return make_pair(t, u);
}

template <typename T>
vector<T> mkrui(const vector<T> &v, bool rev = false) {
  vector<T> ret(v.size() + 1);
  if (rev) {
    for (int i = int(v.size()) - 1; i >= 0; i--) ret[i] = v[i] + ret[i + 1];
  } else {
    for (int i = 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];
  }
  return ret;
};

template <typename T>
vector<T> mkuni(const vector<T> &v) {
  vector<T> ret(v);
  sort(ret.begin(), ret.end());
  ret.erase(unique(ret.begin(), ret.end()), ret.end());
  return ret;
}

template <typename F>
vector<int> mkord(int N, F f) {
  vector<int> ord(N);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), f);
  return ord;
}

template <typename T>
vector<int> mkinv(vector<T> &v) {
  int max_val = *max_element(begin(v), end(v));
  vector<int> inv(max_val + 1, -1);
  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;
  return inv;
}

vector<int> mkiota(int n) {
  vector<int> ret(n);
  iota(begin(ret), end(ret), 0);
  return ret;
}

template <typename T>
T mkrev(const T &v) {
  T w{v};
  reverse(begin(w), end(w));
  return w;
}

template <typename T>
bool nxp(T &v) {
  return next_permutation(begin(v), end(v));
}

// 返り値の型は入力の T に依存
// i 要素目 : [0, a[i])
template <typename T>
vector<vector<T>> product(const vector<T> &a) {
  vector<vector<T>> ret;
  vector<T> v;
  auto dfs = [&](auto rc, int i) -> void {
    if (i == (int)a.size()) {
      ret.push_back(v);
      return;
    }
    for (int j = 0; j < a[i]; j++) v.push_back(j), rc(rc, i + 1), v.pop_back();
  };
  dfs(dfs, 0);
  return ret;
}

// F : function(void(T&)), mod を取る操作
// T : 整数型のときはオーバーフローに注意する
template <typename T>
T Power(T a, long long n, const T &I, const function<void(T &)> &f) {
  T res = I;
  for (; n; f(a = a * a), n >>= 1) {
    if (n & 1) f(res = res * a);
  }
  return res;
}
// T : 整数型のときはオーバーフローに注意する
template <typename T>
T Power(T a, long long n, const T &I = T{1}) {
  return Power(a, n, I, function<void(T &)>{[](T &) -> void {}});
}

template <typename T>
T Rev(const T &v) {
  T res = v;
  reverse(begin(res), end(res));
  return res;
}

template <typename T>
vector<T> Transpose(const vector<T> &v) {
  using U = typename T::value_type;
  if(v.empty()) return {};
  int H = v.size(), W = v[0].size();
  vector res(W, T(H, U{}));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      res[j][i] = v[i][j];
    }
  }
  return res;
}

template <typename T>
vector<T> Rotate(const vector<T> &v, int clockwise = true) {
  using U = typename T::value_type;
  int H = v.size(), W = v[0].size();
  vector res(W, T(H, U{}));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (clockwise) {
        res[W - 1 - j][i] = v[i][j];
      } else {
        res[j][H - 1 - i] = v[i][j];
      }
    }
  }
  return res;
}

}  // namespace Nyaan
