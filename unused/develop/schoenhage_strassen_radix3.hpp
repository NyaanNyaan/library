#pragma once

template <typename R>
struct SchoenHage_Strassen_radix3 {
  struct T {
    R x, y;
    T() : x(), y() {}
    T(const R& _x, const R& _y) : x(_x), y(_y) {}

    T operator+(const R& r) const { return T(x + r.x, y + r.y); }
    T operator-(const R& r) const { return T(x - r.x, y + r.y); }
    T operator*(const R& r) const {
      return T(x * r.x - y * r.y, x * r.y + y * r.x - y * r.y);
    }
    T& operator+=(const R& r) { return *this = *this + r; }
    T& operator-=(const R& r) { return *this = *this - r; }
    T& operator*=(const R& r) { return *this = *this * r; }
    T operator-() const { return T(-x, -y); }
    static T omega() { return T(R(), R::ID1()); }
    static T omega2() { return T(-R::ID1(), -R::ID1()); }
  };

  T* buf = nullptr;

  void cp(T* dst, T* src, int s) { memcpy(dst, src, s * sizeof(T)); }
  void reset(T* dst, int s) { fill(dst, dst + s, T()); }

  // 1 / (x^(2s) + x^s + 1)
  void rot(T* dst, T* src, int s, int d) {
    int s2 = s * 2, s3 = s * 3;
    assert(0 <= d and d < s3);
    reset(dst, s2);
    int i = 0, j = d;
    while (j < s2) {
      dst[j] += src[i];
      i++, j++;
    }
    while (i < s2 && j < s3) {
      dst[j - s] -= src[i];
      dst[j - s2] -= src[i];
      i++, j++;
    }
    while (i < s2) {
      assert(j < s * 5);
      dst[j - s3] -= src[i];
      i++, j++;
    }
  }

  void in_add(T* dst, T* src, int s) {
    for (int i = 0; i < s; i++) dst[i] += src[i];
  }
  void in_sub(T* dst, T* src, int s) {
    for (int i = 0; i < s; i++) dst[i] -= src[i];
  }

  // R[x] / (1+x^(3^m)+x^(2*(3^m))) 上の長さLのFFT
  void fft(T* a,int l,int m) {
    
  }
};