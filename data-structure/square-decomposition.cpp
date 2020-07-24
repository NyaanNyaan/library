
constexpr int B = 300;

struct block{

  // S 更新用 T 取得用
  using S = long long;
  using T = long long;

  // 各種変数の初期化を忘れない！！！
  block(){

  }

  void build(){

  }

  void update_all(S x){

  }
  
  void update_part(int l,int r, S x){

    build();
  }

  T query_all(){

  }
  
  T query_part(int l,int r){
  
  }

};

// 取得クエリのマージ関数をf、単位元をUNITとする
template <typename F> struct Sqd{
  int N;
  V<block> sq;
  F f;
  block::T UNIT;
  Sqd(int N , F f, block::T UNIT) : N(N) , sq(N / B + 1) , f(f) , UNIT(UNIT) {
    init();
    for(auto &x : sq) x.build();
  }

  void init(){

  }

  // 半開区間[ l , r )に対する更新クエリ
  void update(int l , int r , block::S x){
    if(l / B == r / B) {
      sq[l / B].update_part(l % B , r % B , x);
    }
    else {
      sq[l / B].update_part(l % B , B , x);
      for(int i = l / B + 1 ; i < r / B ; i++) sq[i].update_all(x);
      sq[r / B].update_part(0 , r % B , x);
    }
  }

  // 半開区間[ l , r )に対する取得クエリ
  block::T query(int l,int r){
    if(l / B == r / B)
      return sq[l / B].query_part(l % B , r % B);
    block::T ret = UNIT;
    ret = f( ret , sq[l / B].query_part(l % B , B) );
    for(int i = l / B + 1 ; i < r / B ; i++) 
      ret = f(ret , sq[i].query_all() );
    ret = f( ret , sq[r / B].query_part(0 , r % B) );
    return ret;
  }

};