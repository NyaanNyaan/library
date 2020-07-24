// Suffix Array
//verify https://judge.yosupo.jp/submission/240
struct SuffixArray{
  int _size;
  vector<int> sa;
  string &s;
  SuffixArray(string &str):_size(str.size()) , s(str) {
    // うしさんのO( N logN )の実装
    s.push_back(0);
    sa.resize(s.size());
    iota(begin(sa), end(sa), 0);
    sort(begin(sa), end(sa), [&](int a, int b) {
      return s[a] == s[b] ? a > b : s[a] < s[b];
    });
    vector< int > classes(s.size()), c(s.begin(), s.end()), cnt(s.size());
    for(int len = 1; len < (int)s.size(); len <<= 1) {
      for(int i = 0; i < (int)s.size(); i++) {
        if(i > 0 && c[sa[i - 1]] == c[sa[i]] && sa[i - 1] + len < (int)s.size() && c[sa[i - 1] + len / 2] == c[sa[i] + len / 2]) {
          classes[sa[i]] = classes[sa[i - 1]];
        } else {
          classes[sa[i]] = i;
        }
      }
      iota(begin(cnt), end(cnt), 0);
      copy(begin(sa), end(sa), begin(c));
      for(int i = 0; i < (int)s.size(); i++) {
        int s1 = c[i] - len;
        if(s1 >= 0) sa[cnt[classes[s1]]++] = s1;
      }
      classes.swap(c);
    }
    s.pop_back();
  }
  // デバッグ用に実装
  void output() {
    cout << "SA\tidx\tstr" << endl;
    for(int i = 0; i < size(); i++) {
      cout << i << ": \t" << sa[i] << " \t" ;
      if(sa[i] != _size) cout << s.substr(sa[i],_size - sa[i]) << endl;
      else cout << "$" << endl;
    }
    cout << endl;
  }
  // sa.size()と表せると便利なので実装
  int size() const{return _size + 1;}
  // sa[]と表せると便利なのでオーバーロードしておく
  int operator[](int k) const{return sa[k]; }
};

struct LCPArray {
  const SuffixArray &SA;
  vector<int> LCP, rank;
  LCPArray(const SuffixArray &sa) : SA(sa) {
    LCP.resize(SA.size()); rank.resize(SA.size());
    // 初期化　rankはsaの逆関数
    for(int i = 0; i < SA.size(); i++) {
      rank[SA[i]] = i;
    }
    LCP[0] = 0; 
    
    // 構築
    for(int i = 0, h = 0; i < SA.size() - 1 ; i++) {
      int j = SA[rank[i] - 1] ; h ? h-- : h;
      // ここで尺取り法に近い手法を使うことでO(N)でLCPの構築をしている
      while( (i > j ? i : j) + h < SA.size() - 1 && SA.s[i + h] == SA.s[j + h] && ++h );
      LCP[rank[i] - 1] = h;
    }
  }

  // デバッグ用に実装
  void output() {
    cout << "SA\tidx\tLCP\tstr" << endl;
     for(int i = 0 ; i < SA.size() ; i++){
      cout << i << "\t" << SA[i] <<" \t" << LCP[i] << "\t"; 
      if(SA[i] == SA.size() - 1) cout << "$";
      else cout << SA.s.substr(SA[i] , SA.size() - 1 - SA[i]);
      cout << endl;
    }
  }

};

// Sparse Table
template<typename T>
struct SparseTable{
  vector< vector< T > > table;
  vector< int > log_table;

  SparseTable(const vector< T > &v) {
    int b = 0;
    while((1 << b) <= (int)v.size()) ++b;
    table.assign(b, vector< T >(1 << b));
    for(int i = 0; i < (int)v.size(); i++) {
      table[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= (1 << b); j++) {
        table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
    log_table.resize(v.size() + 1);
    for(int i = 2; i < (int)log_table.size(); i++) {
      log_table[i] = log_table[i >> 1] + 1;
    }
  }

  // 区間 [l , r) の最小値を返す
  inline T query(int l, int r) {
    int b = log_table[r - l];
    return min(table[b][l], table[b][r - (1 << b)]);
  }
};

// 文字列検索 検索 O(M + logN) メモリO(N logN)
// verify
// https://onlinejudge.u-aizu.ac.jp/status/users/NyaanNyaan/submissions/1/ALDS1_14_D/judge/3874273/C++14
// https://atcoder.jp/contests/abc135/submissions/7574225
// https://judge.yosupo.jp/submission/241
// https://atcoder.jp/contests/abc141/submissions/7577295
struct StringSearch{
  string &s;
  const SuffixArray &sa;
  const LCPArray &lcp;
  SparseTable<int> sparse;
  StringSearch(LCPArray &lcp)
    : s(lcp.SA.s) , sa(lcp.SA) , lcp(lcp) , sparse(lcp.LCP){ }

 // 文字列sの[i , N)と[j , N)の共通接頭辞の長さを求める
  int ArbitaryLCP(int i , int j){
    if(i == j) return (int)(s.size()) - i;
    return sparse.query(
      min(lcp.rank[i] , lcp.rank[j]) , 
      max(lcp.rank[i] , lcp.rank[j])  
    );
  }

  pair<int,int> comp(const string &t  , int len , int si , int ti = 0){
    int sn = (int)s.size() , tn = (int) t.size();
    si += len , ti += len;
    while(si < sn && ti < tn){
      if(s[si] != t[ti]) return make_pair( s[si]<t[ti] , ti);
      si++ , ti++;
    }
    return make_pair( (si>=sn && ti<tn) , ti);
  }  

  pair<int,int> find_range(int left , int med , int right , int len){
    {
      int ng = left - 1, ok = med;
      while(ng + 1 < ok){
        int cur = (ng + ok) / 2;
        if(sparse.query(cur , med) >= len) ok = cur;
        else ng = cur;
      }
      left = ok;
    }
    {
      int ok = med , ng = right + 1;
      while(ok + 1 < ng){
        int cur = (ng + ok) / 2;
        if(sparse.query(med, cur) >= len) ok = cur;
        else ng = cur;
      }
      right = ok;
    }
    return make_pair(left , right);
  }

  // 全ての出現範囲をSA上の[left , right]の範囲で返す
  // 存在しない場合は-1を返す
  pair<int,int> find(string &t){
    // 条件を満たす[left , right]を見つける
    // sa[0]は空文字列なので left = 1 とする
    // lenは既に一致している文字列の長さ
    int left = 1 , right = sa.size() - 1 , med = left;
    int leftlen = 0 , rightlen = 0 , tlen = t.size();
    pair<int,int> ret;
    while(left + 1 < right){
      med = (left + right) / 2;

      int corres_len = max(
        min(leftlen , sparse.query(left , med)) ,
        min(rightlen, sparse.query(med , right))
      );
      if(corres_len < max(leftlen , rightlen)){
        if(leftlen < rightlen) 
          left = med , leftlen = corres_len;
        else
          right= med ,rightlen = corres_len;
        continue;
      }
      ret = comp(t , corres_len , sa[med]);
      //trc(left,med,right,ret);
      if(ret.second == tlen)
        return find_range(left,med,right,tlen);
      if(ret.first == 0)
        right = med , rightlen = ret.second;
      else
        left = med , leftlen = ret.second;
    }
    if(sa.size() <= 3){
      if(comp(t,0,sa[left]).second==tlen) return find_range(left,left,right,tlen);
      if(comp(t,0,sa[right]).second==tlen) return find_range(left,right,right,tlen);
      return make_pair(-1,-1);
    }
    med = left + right - med;
    ret = comp(t , min(leftlen,rightlen) , sa[med]);
    //trc(left,med,right,ret);
    if(ret.second == tlen)
      return find_range(left,med,right,tlen);
    return make_pair(-1,-1);
  }
};

// Suffix Arrayの使い方(メモリを食うので必要なものだけ使う)
// 参照があるのでstringを削除などしないこと
/*
  SuffixArray sa(S);
  LCPArray lcp(sa);
  StringSearch search(lcp);
*/