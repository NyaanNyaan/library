#pragma once

#include <algorithm>
#include <limits>
#include <utility>
using namespace std;

namespace RadixSortImpl {
constexpr int b = 8;
constexpr int powb = 1 << b;
constexpr int mask = powb - 1;

int cnt0[powb];
int cnt1[powb];
int cnt2[powb];
int cnt3[powb];

template <typename T>
void radix_sort(int N, T* p) {
  static_assert(sizeof(T) == 4 or sizeof(T) == 8);
  if (!N) return;
  if (N <= 64) {
    sort(p, p + N);
    return;
  }
  static T* tmp = nullptr;
  static int tmp_size = 0;
  if (!tmp or tmp_size < N) {
    if (tmp) delete[] tmp;
    tmp_size = 1;
    while (tmp_size < N) tmp_size *= 2;
    tmp = new T[tmp_size];
  }

  memset(cnt0, 0, sizeof(cnt0));
  memset(cnt1, 0, sizeof(cnt1));
  memset(cnt2, 0, sizeof(cnt2));
  memset(cnt3, 0, sizeof(cnt3));
  for (int i = 0; i < N; i++) {
    cnt0[p[i] & mask]++;
    cnt1[(p[i] >> b) & mask]++;
    cnt2[(p[i] >> b * 2) & mask]++;
    cnt3[(p[i] >> b * 3) & mask]++;
  }
  for (int i = 0; i < powb - 1; i++) {
    cnt0[i + 1] += cnt0[i];
    cnt1[i + 1] += cnt1[i];
    cnt2[i + 1] += cnt2[i];
    cnt3[i + 1] += cnt3[i];
  }
  for (int i = N; i--;) tmp[--cnt0[p[i] & mask]] = p[i];
  for (int i = N; i--;) p[--cnt1[tmp[i] >> b & mask]] = tmp[i];
  for (int i = N; i--;) tmp[--cnt2[p[i] >> b * 2 & mask]] = p[i];
  for (int i = N; i--;) p[--cnt3[tmp[i] >> b * 3 & mask]] = tmp[i];

  if constexpr (sizeof(T) == 8) {
    memset(cnt0, 0, sizeof(cnt0));
    for (int i = 0; i < N; i++) cnt0[p[i] >> b * 4 & mask]++;
    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];
    for (int i = N; i--;) tmp[--cnt0[p[i] >> b * 4 & mask]] = p[i];
    memset(cnt0, 0, sizeof(cnt0));
    for (int i = 0; i < N; i++) cnt0[tmp[i] >> b * 5 & mask]++;
    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];
    for (int i = N; i--;) p[--cnt0[tmp[i] >> b * 5 & mask]] = tmp[i];
    memset(cnt0, 0, sizeof(cnt0));
    for (int i = 0; i < N; i++) cnt0[p[i] >> b * 6 & mask]++;
    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];
    for (int i = N; i--;) tmp[--cnt0[p[i] >> b * 6 & mask]] = p[i];
    memset(cnt0, 0, sizeof(cnt0));
    for (int i = 0; i < N; i++) cnt0[tmp[i] >> b * 7 & mask]++;
    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];
    for (int i = N; i--;) p[--cnt0[tmp[i] >> b * 7 & mask]] = tmp[i];
  }
  if constexpr (is_signed<T>::value) {
    int i = N;
    while (i and p[i - 1] < 0) i--;
    rotate(p, p + i, p + N);
  }
}

// N 10^7 int :  90 ms
// N 10^7 ll  : 220 ms
template <typename T>
void radix_sort(vector<T>& v) {
  radix_sort(v.size(), v.data());
}

// first の順にソート, second は不問
template <typename T, typename U>
void radix_sort_compare_first(int N, pair<T, U>* p) {
  static_assert(sizeof(T) == 4 or sizeof(T) == 8);

  if (!N) return;
  if (N <= 64) {
    stable_sort(p, p + N, [](const pair<T, U>& s, const pair<T, U>& t) {
      return s.first < t.first;
    });
    return;
  }
  static pair<T, U>* tmp = nullptr;
  static int tmp_size = 0;
  if (!tmp or tmp_size < N) {
    if (tmp) delete[] tmp;
    tmp_size = 1;
    while (tmp_size < N) tmp_size *= 2;
    tmp = new pair<T, U>[tmp_size];
  }

  memset(cnt0, 0, sizeof(cnt0));
  for (int i = 0; i < N; i++) cnt0[p[i].first & mask]++;
  for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];
  for (int i = N; i--;) tmp[--cnt0[p[i].first & mask]] = p[i];
  memset(cnt0, 0, sizeof(cnt0));
  for (int i = 0; i < N; i++) cnt0[tmp[i].first >> b & mask]++;
  for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];
  for (int i = N; i--;) p[--cnt0[tmp[i].first >> b & mask]] = tmp[i];
  memset(cnt0, 0, sizeof(cnt0));
  for (int i = 0; i < N; i++) cnt0[p[i].first >> b * 2 & mask]++;
  for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];
  for (int i = N; i--;) tmp[--cnt0[p[i].first >> b * 2 & mask]] = p[i];
  memset(cnt0, 0, sizeof(cnt0));
  for (int i = 0; i < N; i++) cnt0[tmp[i].first >> b * 3 & mask]++;
  for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];
  for (int i = N; i--;) p[--cnt0[tmp[i].first >> b * 3 & mask]] = tmp[i];

  if constexpr (sizeof(T) == 8) {
    memset(cnt0, 0, sizeof(cnt0));
    for (int i = 0; i < N; i++) cnt0[p[i].first >> b * 4 & mask]++;
    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];
    for (int i = N; i--;) tmp[--cnt0[p[i].first >> b * 4 & mask]] = p[i];
    memset(cnt0, 0, sizeof(cnt0));
    for (int i = 0; i < N; i++) cnt0[tmp[i].first >> b * 5 & mask]++;
    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];
    for (int i = N; i--;) p[--cnt0[tmp[i].first >> b * 5 & mask]] = tmp[i];
    memset(cnt0, 0, sizeof(cnt0));
    for (int i = 0; i < N; i++) cnt0[p[i].first >> b * 6 & mask]++;
    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];
    for (int i = N; i--;) tmp[--cnt0[p[i].first >> b * 6 & mask]] = p[i];
    memset(cnt0, 0, sizeof(cnt0));
    for (int i = 0; i < N; i++) cnt0[tmp[i].first >> b * 7 & mask]++;
    for (int i = 0; i < powb - 1; i++) cnt0[i + 1] += cnt0[i];
    for (int i = N; i--;) p[--cnt0[tmp[i].first >> b * 7 & mask]] = tmp[i];
  }

  if constexpr (is_signed<T>::value) {
    int i = N;
    while (i and p[i - 1].first < 0) i--;
    rotate(p, p + i, p + N);
  }
}

// first の順にソート, second は不問
// N 10^7 int : 130 ms
// N 10^7 ll  : 370 ms
template <typename T, typename U>
void radix_sort_compare_first(vector<pair<T, U>>& v) {
  radix_sort_compare_first(v.size(), v.data());
}

}  // namespace RadixSortImpl

using RadixSortImpl::radix_sort;
using RadixSortImpl::radix_sort_compare_first;

/*
  @brief radix sort
*/
