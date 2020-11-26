## Cartesian Tree

#### 概要

数列$(a_n)$が与えられたとき、区間$[0,n)$に対して次の操作を再帰的に繰り返すことで得られる二分木をCartesian Treeと呼ぶ。
- 区間$[l,r)$が与えられたとき、$i \in [l,r)$のうちa_iが最小の$i$(複数ある場合は$i$が最も小さい点)を$m$と置く。
- 頂点$m$を根、区間$[l,m)$から得られる二分木を左の子、区間$[m+1,r)$から得られる二分木を右の子とした木を返す。

Cartesian Treeの構築にかかる時間計算量は直感的には$\mathrm{O}(n \log n)$だが、実はstackを利用することで$\mathrm{O}(n)$での構築が可能である。

Cartesian Treeの長所として「頂点$(u,v)$のLCAが区間$[u,v]$の最小値に対応する」という点があり、前計算$\mathrm{O}(n)$-クエリ$\mathrm{O}(1)$のRMQなどに利用されている。

参考：[EXPREP(codechef)](https://www.codechef.com/JULY20A/problems/EXPREP)　SAを計算して手に入れたLCP配列から構築したCartesian TreeをHLDecしてRSQ+RAQを載せることで解くことが出来る。(想定解はSuffix AutomatonとDSU on TreeとRSQ+RAQらしいが…)

#### 使い方

- `CartesianTree(a)` : 配列$a$に対して`{`グラフ`,`根`}`を返す。
