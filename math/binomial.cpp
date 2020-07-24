vector<long long> fac,finv,inv;
void cominit(int MAX) {
  MAX++;
  fac.resize(MAX , 0);
  finv.resize(MAX , 0);
  inv.resize(MAX , 0);
  fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
// nCk combination 
inline long long COM(int n,int k){
  if(n < k || k < 0 || n < 0) return 0;
  else return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// nPk permutation
inline long long PER(int n,int k){
  if (n < k || k < 0 || n < 0) return 0;
  else return (fac[n] * finv[n - k]) % MOD;
}
// nHk homogeneous polynomial
inline long long HGP(int n,int k){
  if(n == 0 && k == 0) return 1; // depending on problem?
  else if(n < 1 || k < 0) return 0;
  else return fac[n + k - 1] * (finv[k] * finv[n - 1] % MOD) % MOD;
}