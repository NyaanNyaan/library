## Nim Product

$$a \oplus b =\mathrm{mex}(\lbrace a' \oplus b \mid a'<a \rbrace\cup\lbrace a \oplus b' \mid b'<b \rbrace)$$

$$a \otimes b =\mathrm{mex}(\lbrace a' \otimes b \oplus a \otimes b' \oplus a' \otimes b' \mid a'<a,b'<b \rbrace)$$

と置いたとき、$a\otimes b\ (a,b<2^{64})$を高速に計算するライブラリ。

[Wikipedia](https://en.wikipedia.org/wiki/Nimber) [kyopro_friendsさんによる資料](https://drive.google.com/file/d/16g1tfSHUU4NXNTDgaD8FSA1WB4FtJCyV/edit)
