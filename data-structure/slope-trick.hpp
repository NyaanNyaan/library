#pragma once

struct SlopeTrick {
 private:
  using ll = long long;
  // x : 座標, c : 傾きの変化量
  struct P {
    ll x, c;
    P(ll _x, ll _c) : x(_x), c(_c) {}
    friend bool operator<(const P& a, const P& b) { return a.x < b.x; }
    friend bool operator>(const P& a, const P& b) { return a.x > b.x; }
  };
  ll addL, addR, min_y;
  priority_queue<P> L;
  priority_queue<P, vector<P>, greater<>> R;
  void pushL(ll x, ll c = 1) { L.emplace(x - addL, c); }
  void pushR(ll x, ll c = 1) { R.emplace(x - addR, c); }
  P getL() { return P{L.top().x + addL, L.top().c}; }
  P getR() { return P{R.top().x + addR, R.top().c}; }
  void popL() { L.pop(); }
  void popR() { R.pop(); }

 public:
  SlopeTrick() : addL(0), addR(0), min_y(0) {}

  void debug() {
    cerr << "addL, addR, min_y : ";
    cerr << addL << ", " << addR << ", " << min_y << endl;

    auto LL{L};
    cerr << "L : ";
    while (!LL.empty()) {
      cerr << "( " << LL.top().x + addL << ", " << LL.top().c << " ), ";
      LL.pop();
    }
    cerr << endl;

    auto RR{R};
    cerr << "R : ";
    while (!RR.empty()) {
      cerr << "( " << RR.top().x + addR << ", " << RR.top().c << " ), ";
      RR.pop();
    }
    cerr << endl;

    cerr << "min : ";
    cerr << "( " << get_min().first << ", " << get_min().second << " )" << endl;
  }

  // return {x, y} s.t. {argmin, min}
  pair<ll, ll> get_min() {
    ll x = L.empty() ? R.empty() ? 0 : getR().x : getL().x;
    return {x, min_y};
  }

  void shift_L(ll a) { addL += a; }
  void shift_R(ll a) { addR += a; }
  // f(x) <- f(x - a)
  void shift_x(ll a) { addL += a, addR += a; }
  // f(x) <- f(x) + a
  void shift_y(ll a) { min_y += a; }

  // add (x-a)_+   _____/
  void add_xma(ll a, ll c = 1) {
    ll used = 0;
    while (used < c && !L.empty()) {
      auto [X, C] = getL();
      if (X <= a) break;
      popL();
      ll tmp = min(c - used, C);
      pushR(X, tmp);
      if (C != tmp) pushL(X, C - tmp);
      min_y += (X - a) * tmp;
      used += tmp;
    }
    if (used) pushL(a, used);
    if (c - used) pushR(a, c - used);
  }

  // add (a-x)_+   \_____
  void add_amx(ll a, ll c = 1) {
    ll used = 0;
    while (used < c && !R.empty()) {
      auto [X, C] = getR();
      if (X >= a) break;
      popR();
      ll tmp = min(c - used, C);
      pushL(X, tmp);
      if (C != tmp) pushR(X, C - tmp);
      min_y += (a - X) * tmp;
      used += tmp;
    }
    if (used) pushR(a, used);
    if (c - used) pushL(a, c - used);
  }

  // add |x-a|     \____/
  void add_abs_xma(ll a, ll c = 1) { add_xma(a, c), add_amx(a, c); }

  //  chmin right side \_/ -> \__
  void chmin_right() { decltype(R){}.swap(R); }
  //  chmin left side  \_/ -> __/
  void chmin_left() { decltype(L){}.swap(L); }

  // destructive merge
  void merge(SlopeTrick& r) {
    if (L.size() + R.size() < r.L.size() + r.R.size()) swap(*this, r);
    while (!r.L.empty()) {
      auto [x, c] = r.getL();
      r.popL();
      add_amx(x, c);
    }
    while (!r.R.empty()) {
      auto [x, c] = r.getR();
      r.popR();
      add_xma(x, c);
    }
    shift_y(r.min_y);
  }

  // eval f(x) O(|L| + |R|) TODO : verify
  ll eval(ll x) {
    ll y = min_y;
    auto LL{L};
    while (!LL.empty()) {
      auto [X, C] = LL.top();
      X += addL;
      if(X < x) break;
      y += (X - x) * C;
      LL.pop();
    }
    auto RR{R};
    while (!RR.empty()) {
      auto [X, C] = RR.top();
      X += addR;
      if(x < X) break;
      y += (x - X) * C;
      RR.pop();
    }
    return y;
  }
};

/**
 * @brief Slope Trick
 */
