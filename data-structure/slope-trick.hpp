#pragma once

struct SlopeTrick {
  using ll = long long;
  ll lazx, mn;
  priority_queue<ll> L;
  priority_queue<ll, vector<ll>, greater<>> R;

  SlopeTrick() : lazx(0), mn(0) {}

  pair<ll, ll> get_min() {
    ll x = L.empty() ? R.empty() ? 0 : R.top() : L.top();
    return {x + lazx, mn};
  }

  // f(x) <- f(x - a)
  void shift_x(ll a) { lazx += a; }
  // f(x) <- f(x) + a
  void shift_y(ll a) { mn += a; }

  /**
   * add (x-a)_+
   *           /
   *          /
   *   _____ /
   */
  void add_xma(ll a) {
    a -= lazx;
    if (!L.empty()) mn += max(0LL, L.top() - a);
    L.push(a);
    R.push(L.top());
    L.pop();
  }

  /**
   * add (a-x)_+
   *   \
   *    \
   *     \_____
   */
  void add_amx(ll a) {
    a -= lazx;
    if (!R.empty()) mn += max(0LL, R.top() - a);
    R.push(a);
    L.push(R.top());
    R.pop();
  }

  void add_abs_xma(ll a) { add_xma(a), add_amx(a); }

  //  \_/ -> \__
  void accum_min_right() {
    decltype(R) dummy;
    swap(dummy, R);
  }

  // \_/ -> __/
  void accum_min_left() {
    decltype(L) dummy;
    swap(dummy, L);
  }
};