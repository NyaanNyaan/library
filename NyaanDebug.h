#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void _cout(const T &c) {
  cerr << c;
}

void _cout(const int &c) {
  if (c == 1001001001)
    cerr << "inf";
  else if (c == -1001001001)
    cerr << "-inf";
  else
    cerr << c;
}

void _cout(const unsigned int &c) {
  if (c == 1001001001)
    cerr << "inf";
  else
    cerr << c;
}

void _cout(const long long &c) {
  if (c == 1001001001 || c == (1LL << 61) - 1)
    cerr << "inf";
  else if (c == -1001001001 || c == -((1LL << 61) - 1))
    cerr << "-inf";
  else
    cerr << c;
}

void _cout(const unsigned long long &c) {
  if (c == 1001001001 || c == (1LL << 61) - 1)
    cerr << "inf";
  else
    cerr << c;
}

template <typename T, typename U>
void _cout(const pair<T, U> &p) {
  cerr << "{ ";
  _cout(p.fi);
  cerr << ", ";
  _cout(p.se);
  cerr << " } ";
}

template <typename T>
void _cout(const vector<T> &v) {
  int s = v.size();
  cerr << "{ ";
  for (int i = 0; i < s; i++) {
    cerr << (i ? ", " : "");
    _cout(v[i]);
  }
  cerr << " } ";
}

template <typename T>
void _cout(const vector<vector<T> > &v) {
  cerr << "[ ";
  for (const auto &x : v) {
    cerr << endl;
    _cout(x);
    cerr << ", ";
  }
  cerr << endl << " ] ";
}

void dbg_out() { cerr << endl; }
template <typename T, class... U>
void dbg_out(const T &t, const U &... u) {
  _cout(t);
  if (sizeof...(u)) cerr << ", ";
  dbg_out(u...);
}

template <typename T>
void array_out(const T &v, int s) {
  cerr << "{ ";
  for (int i = 0; i < s; i++) {
    cerr << (i ? ", " : "");
    _cout(v[i]);
  }
  cerr << " } " << endl;
}

template <typename T>
void array_out(const T &v, int H, int W) {
  cerr << "[ ";
  for (int i = 0; i < H; i++) {
    cerr << (i ? ", " : "");
    array_out(v[i], W);
  }
  cerr << " ] " << endl;
}

#ifndef SRM
void exec(promise<int> p) {
  try {
    solve();
  } catch (...) {
    p.set_value(1);
  }
  p.set_value(0);
}

clock_t start_debug;
int main() {
  cerr << "Program is running..." << endl;
  start_debug = clock();
  promise<int> p;
  future<int> f = p.get_future();
  auto print_time =
      +[]() { cerr << "time : " << clock() - start_debug << " ms" << endl; };
  atexit(print_time);
  thread t(exec, move(p));
  future_status result = f.wait_for(chrono::seconds(30000));
  if (result == future_status::timeout) {
    cerr << "Time Limit Exceeded" << endl;
  }
  t.detach();
}
#endif
