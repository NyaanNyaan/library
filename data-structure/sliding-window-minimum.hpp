#pragma once

// return dat | dat[i] := ( answer of range [i - K, i) )
// T : data type
// f : compare function
// K : width of window
template <typename T, typename F>
vector<T> SlideWindowMinimum(vector<T> &v, F f, int K) {
  vector<T> dat;
  int N = v.size();
  dat.resize(N + 1);
  dat[0] = 0;
  deque<int> q;
  for (int i = 0; i < K - 1; i++) {
    while (!q.empty() && (f(v[i], v[q.back()]) == v[i])) q.pop_back();
    q.push_back(i);
    dat[i + 1] = v[q.front()];
  }
  for (int i = K; i < N + 1; i++) {
    T cur = v[i - 1];
    while (!q.empty() && (f(cur, v[q.back()]) == cur)) q.pop_back();
    q.push_back(i - 1);
    dat[i] = v[q.front()];
    if (q.front() == i - K) q.pop_front();
  }
  return dat;
}