#pragma once

long long MaximalRectangle(vector<long long> buf) {
  int N = buf.size();
  buf.push_back(0);
  using P = pair<long long, long long>;
  stack<P> st;
  long long mx = 0;
  for (int i = 0; i <= N; i++) {
    P rect{buf[i], i};
    if (st.empty() or st.top().first < rect.first) {
      st.push(rect);
    } else {
      int j = i;
      while (!st.empty() and st.top().first >= rect.first) {
        P pre = st.top();
        st.pop();
        mx = max(mx, pre.first * (i - pre.second));
        j = pre.second;
      }
      rect.second = j;
      st.push(rect);
    }
  }
  return mx;
}

/**
 * @brief 最大長方形
 * @docs docs/dp/maximal-rectangle.md
 */
