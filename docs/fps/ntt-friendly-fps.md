## NTT mod専用の形式的冪級数ライブラリ

modがNTT modの時に高速に動作する実装を行ったFPSライブラリ。(現在はinvとexpのみ実装している。)

#### 概要

形式的冪級数の計算においてニュートン法は多くの関数に使用されるが、定数倍が重いという欠点がある。もしもmodがNTT可能な素数である場合、NTTの巡回畳み込みを利用することで計算を高速化することが出来る。

- $\mathrm{inv}$ ： [latteさんによる資料](https://paper.dropbox.com/doc/fps--Amh2kcXvb96i8w8Hrm4fvNxvAg-EoHXQDZxfduAB8wD1PMBW)

- $\mathrm{exp}$ ： [論文](https://web.archive.org/web/20170809063921/https://www.csd.uwo.ca/~eschost/publications/BoSc09-final.pdf)

他にも$\mathrm{sqrt}$や剰余算なども高速化が可能である。

また、このページでは使用していないが、値を周波数領域で保持したままダブリングを続けたり、長さ$n$の$DFT(f)$を長さ$n$の$\mathrm{FFT}$2回で長さ$2n$の$DFT(f)$に変換するテクニックも高速化に有用である。([一例](https://nyaannyaan.github.io/library/library/fps/kitamasa.hpp.html))
