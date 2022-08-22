#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../marathon/sa-manager.hpp"
//
using namespace Nyaan;

int N;
int x[110], y[110];

// 状態を持つ型
using state_t = V<i128>;
// スコアを持つ型
using score_t = double;
using pair_t = pair<state_t, score_t>;

// 焼きなましの初期解を入れる関数
pair_t get_init_state() {
  state_t ans;
  score_t score;
  // ans, score に初期解を入れる。
  // 多点焼きなましを行う場合は初期解に多様性が生まれるようにする。
  ans.resize(3, 0);
  rep(i, N) {
    if (rng() & 1) {
      ans[0] |= i128(1) << i, ans[1] += x[i], ans[2] += y[i];
    }
  }
  score = hypot<double, double>(ans[1], ans[2]);

  return {ans, score};
}

//　状態を更新する関数
void update_state(state_t& ans, score_t& score, double th) {
  // 遷移を作る
  // 基本的には以下のように値を複製して遷移先を作っていい
  // (差分更新したい場合は適宜頑張る)
  state_t nxt{ans};
  score_t nxt_score{score};

  int d = rng() % 2 + 1;
  rep(t, d) {
    int i = rng() % N;
    if ((nxt[0] >> i) & 1) {
      nxt[1] -= x[i], nxt[2] -= y[i];
    } else {
      nxt[1] += x[i], nxt[2] += y[i];
    }
    nxt[0] ^= i128(1) << i;
  }
  nxt_score = hypot<double, double>(nxt[1], nxt[2]);

  // スコアの伸びを変数 diff に格納して値を元に遷移を採用するか決める。
  double diff = nxt_score - score;
  if (diff > th) {
    // 遷移を採用して ans, score を更新 or 差分更新する。
    ans = nxt, score = nxt_score;
  } else {
    // (必要があれば)元に戻す。
  }
}

int sa_size = 1;
int endt = 1900;
pair_t sa(Timer& t) {
  SA_manager<state_t, score_t> sa(t, 2000, -2000, endt, sa_size);
  return sa.run<get_init_state, update_state>();
}

int N_circle = 90;
int x_circle[] = {0,       63926,   127540,  190533,  252597,  313431,  372738,
                  430229,  485624,  538653,  589058,  636593,  681026,  722142,
                  759739,  793635,  823665,  849681,  871559,  889190,  902489,
                  911391,  915853,  915853,  911391,  902489,  889190,  871559,
                  849681,  823665,  793635,  759739,  722142,  681026,  636593,
                  589058,  538653,  485624,  430229,  372738,  313431,  252597,
                  190533,  127540,  63926,   0,       -63926,  -127540, -190533,
                  -252597, -313431, -372738, -430229, -485624, -538653, -589058,
                  -636593, -681026, -722142, -759739, -793635, -823665, -849681,
                  -871559, -889190, -902489, -911391, -915853, -915853, -911391,
                  -902489, -889190, -871559, -849681, -823665, -793635, -759739,
                  -722142, -681026, -636593, -589058, -538653, -485624, -430229,
                  -372738, -313431, -252597, -190533, -127540, -63926};
int y_circle[] = {916411,  914179,  907493,  896385,  880911,  861145,  837183,
                  809143,  777161,  741392,  702012,  659211,  613199,  564199,
                  512451,  458205,  401728,  343294,  283187,  221700,  159133,
                  95791,   31982,   -31982,  -95791,  -159133, -221700, -283187,
                  -343294, -401728, -458206, -512451, -564199, -613199, -659211,
                  -702012, -741392, -777161, -809143, -837183, -861145, -880911,
                  -896385, -907493, -914179, -916411, -914179, -907493, -896385,
                  -880911, -861145, -837183, -809143, -777161, -741392, -702012,
                  -659211, -613199, -564199, -512451, -458205, -401728, -343294,
                  -283187, -221700, -159133, -95791,  -31982,  31982,   95791,
                  159133,  221700,  283187,  343294,  401728,  458206,  512451,
                  564199,  613199,  659211,  702012,  741392,  777161,  809143,
                  837183,  861145,  880911,  896385,  907493,  914179};
double ans_circle = 26258581.001626496877294216848735127029515732503186465405;

template <int LOOP_TIME>
void test() {
  Timer timer;
  N = N_circle;
  rep(i, N) {
    x[i] = x_circle[i];
    y[i] = y_circle[i];
  }
  vp kekka;
  for (auto s : vi{10}) {
    sa_size = 10;
    endt = 1900;
    int cnt = 0;
    rep(t, LOOP_TIME) {
      double score = 0;
      timer.reset();
      auto [_, cur] = sa(timer);
      amax(score, cur);
      cerr << "output : " << score << endl;
      cerr << "answer : " << ans_circle << endl;
      cerr << "judge  : ";
      if (abs(score - ans_circle) / ans_circle < 1e-10) {
        cerr << "AC" << endl;
      } else {
        cerr << "WA" << endl;
      }
    }
    kekka.emplace_back(s, cnt);
  }
}

void q() {
  test<1>();
  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

void Nyaan::solve() {
  int T = 1;
  // in(T);
  while (T--) q();
}