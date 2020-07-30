
#include "../fps/ntt-friendly-fps.hpp"
#include "../modint/montgomery-modint.hpp"

// 作りかけ
using mint = LazyMontgomeryModInt<1012924417>;
using fps = FormalPowerSeries<mint>;

pair<fps, fps> circular(fps f, int deg = -1) {
  assert(f[0] == mint(0));
  if (deg == -1) deg = (int)f.size();
  fps re({mint(1)}), im({mint(0)});
  for (int i = 1; i < deg; i <<= 1) {
    fps dre = re.diff();
    fps dim = im.diff();
    fps fhypot = (re * re + im * im).inv(i << 1);
    fps ere = dre * re + dim * im;
    fps eim = dim * re - dre * im;
    fps logre = (ere * fhypot).pre((i << 1) - 1).integral();
    fps logim = (eim * fhypot).pre((i << 1) - 1).integral();
    fps gre = (-logre) + mint(1);
    fps gim = (-logim) + f.pre(i << 1);
    fps hre = (re * gre - im * gim).pre(i << 1);
    fps him = (re * gim + im * gre).pre(i << 1);
    swap(re, hre);
    swap(im, him);
  }
  return make_pair(re.pre(deg), im.pre(deg));
}

pair<fps, fps> circular_ntt(fps f, int deg = -1) {
  assert(f[0] == mint(0));
  if (deg == -1) deg = (int)f.size();
  fps re({mint(1)}), im({mint(0)});
  for (int i = 1; i < deg; i <<= 1) {
    fps dre = re.diff();
    fps dim = im.diff();
    re.resize(i << 1);
    im.resize(i << 1);
    dre.resize(i << 1);
    dim.resize(i << 1);
    re.ntt();
    im.ntt();
    dre.ntt();
    dim.ntt();
    fps fhypot(i << 1), ere(i << 1), eim(i << 1);
    for (int j = 0; j < 2 * i; j++) {
      fhypot[j] = re[j] * re[j] + im[j] * im[j];
      ere[j] = dre[j] * re[j] + dim[j] * im[j];
      eim[j] = dim[j] * re[j] - dre[j] * im[j];
    }
    fhypot.intt();
    fhypot = fhypot.inv(i << 1);
    fhypot.resize(i << 2);
    fhypot.ntt();
    ere.ntt_doubling();
    eim.ntt_doubling();
    fps logre(i << 2), logim(i << 2);
    for (int j = 0; j < 4 * i; j++) {
      logre[j] = ere[j] * fhypot[j];
      logim[j] = eim[j] * fhypot[j];
    }
    logre.intt();
    logim.intt();
    logre = logre.pre((i << 1) - 1).integral();
    logim = logim.pre((i << 1) - 1).integral();
    fps gre = (-logre) + mint(1);
    fps gim = (-logim) + f.pre(i << 1);
    gre.resize(i << 2);
    gim.resize(i << 2);
    gre.ntt();
    gim.ntt();
    re.ntt_doubling();
    im.ntt_doubling();
    fps hre(i << 2), him(i << 2);
    for (int j = 0; j < 4 * i; j++) {
      hre[j] = re[j] * gre[j] - im[j] * gim[j];
      him[j] = re[j] * gim[j] + im[j] * gre[j];
    }
    hre.intt();
    him.intt();
    hre = hre.pre(i << 1);
    him = him.pre(i << 1);
    swap(re, hre);
    swap(im, him);
  }
  return make_pair(re.pre(deg), im.pre(deg));
}