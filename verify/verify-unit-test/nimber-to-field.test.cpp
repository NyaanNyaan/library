#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../math/nimber-to-field.hpp"
#include "../../math/nimber.hpp"
#include "../../math/sweep.hpp"

using namespace Nyaan;

void Nyaan::solve() {
  using nim = Nimber16;
  using u16 = uint16_t;
  nim proot = NimberImpl::c16.proot;
  vector<u16> ntf{0x0001u, 0x8ff5u, 0x6cbfu, 0xa5beu, 0x761au, 0x8238u,
                  0x4f08u, 0x95acu, 0xf340u, 0x1336u, 0x7d5eu, 0x86e7u,
                  0x3a47u, 0xe796u, 0xb7c3u, 0x0008u};
  NimberToField<nim> mp(proot);
  rep(i, 16) {
    assert(ntf[i] == mp.nimber2field(1 << i));
    assert(mp.field2nimber(1 << i) == proot.pow(i));
  }
  nim p16 = proot.pow(16);
  u16 f16 = mp.nimber2field(p16);
  unsigned ppoly = (unsigned(1) << 16) ^ f16;
  assert(ppoly == NimberImpl::c16.ppoly);

  {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
  }
}
