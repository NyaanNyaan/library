#### テンプレート

```
// max-plus semiring
/**/
using U = long long;
U ID0 = -4e18;
U ID1 = 0;
auto Add = [](U a, U b) -> U { return max(a, b); };
auto Mul = [](U a, U b) -> U { return a + b; };
//*/

// min-plus semiring
/**
using U = long long;
U ID0 = 4e18;
U ID1 = 0;
auto Add = [](U a, U b) -> U { return min(a, b); };
auto Mul = [](U a, U b) -> U { return a + b; };
//*/

// xor-and semiring
/**
using U = unsigned long long;
constexpr U ID0 = 0;
constexpr U ID1 = U(-1);
auto Add = [](U a, U b) -> U { return a ^ b; };
auto Mul = [](U a, U b) -> U { return a & b; };
//*/

template <typename T, typename F, typename G>
T semiring<T, F, G>::id0 = ID0;
template <typename T, typename F, typename G>
T semiring<T, F, G>::id1 = ID1;
template <typename T, typename F, typename G>
F semiring<T, F, G>::add = Add;
template <typename T, typename F, typename G>
G semiring<T, F, G>::mul = Mul;
using rig = semiring<U, decltype(Add), decltype(Mul)>;
template <int N>
using mat = Mat<U, decltype(Add), decltype(Mul), N>;

```