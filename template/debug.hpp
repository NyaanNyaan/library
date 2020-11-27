#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace DebugImpl {

template <typename T, enable_if_t<is_integral<T>::value, nullptr_t> = nullptr>
void print(const T& t) {
  if (t == inf) {
    cerr << "inf";
    return;
  }
  if constexpr (is_signed<T>::value) {
    if (t == -inf) {
      cerr << "-inf";
      return;
    }
  }
  if constexpr (sizeof(T) == 8) {
    if constexpr (is_signed<T>::value) {
      if (t == -infLL) {
        cerr << "-inf";
        return;
      }
    }
    if (t == infLL) {
      cerr << "inf";
      return;
    }
  }
  cerr << t;
  return;
}

template <typename T, enable_if_t<!is_void<typename T::iterator>::value,
                                  nullptr_t> = nullptr>
void print(const T& t) {
  cerr << "{ ";
  for (auto it = t.begin(); it != t.end();) {
    print(*it);
    cerr << (++it == t.end() ? " }" : ", ");
  }
}

void trace() { cerr << endl; }
template <typename Head, typename... Tail>
void trace(Head&& head, Tail&&... tail) {
  print(head);
  if (sizeof...(tail) != 0) cerr << ", ";
  trace(forward<Tail>(tail)...);
}

}  // namespace DebugImpl