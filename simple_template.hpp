#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
struct IoSetupNya {
  IoSetupNya() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(7);
  }
} iosetupnya;
constexpr long long TEN(int n) { return n ? TEN(n - 1) * 10 : 1; }

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
