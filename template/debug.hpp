#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace DebugImpl {

void dump(const char& t) { cerr << t; }

void dump(const string& t) { cerr << t; }

template <typename T>
void dump(const T& t, enable_if_t<is_integral<T>::value>* = nullptr) {
  string res;
  if (t == inf) res = "inf";
  if (is_signed<T>::value && t == -inf) res = "-inf";
  if (sizeof(T) == 8) {
    if (t == infLL) res = "inf";
    if (is_signed<T>::value && t == -infLL) res = "-inf";
  }
  if (res.empty()) res = to_string(t);
  cerr << res;
}

template <typename T, typename U>
void dump(const pair<T, U>&);
template <typename T>
void dump(const pair<T*, int>&);

template <typename T>
void dump(const T& t,
          enable_if_t<!is_void<typename T::iterator>::value>* = nullptr) {
  cerr << "[ ";
  for (auto it = t.begin(); it != t.end();) {
    dump(*it);
    cerr << (++it == t.end() ? " ]" : ", ");
  }
}

template <typename T, typename U>
void dump(const pair<T, U>& t) {
  cerr << "( ";
  dump(t.first);
  cerr << ", ";
  dump(t.second);
  cerr << " )";
}

template <typename T>
void dump(const pair<T*, int>& t) {
  cerr << "[ ";
  for (int i = 0; i < t.second; i++) {
    dump(t.first[i]);
    cerr << (i == t.second - 1 ? " ]" : ", ");
  }
}

void trace() { cerr << endl; }
template <typename Head, typename... Tail>
void trace(Head&& head, Tail&&... tail) {
  cerr << " ";
  dump(head);
  if (sizeof...(tail) != 0) cerr << ",";
  trace(forward<Tail>(tail)...);
}

}  // namespace DebugImpl
using DebugImpl::trace;

/**
 * @brief デバッグ用ダンプ関数
 */
