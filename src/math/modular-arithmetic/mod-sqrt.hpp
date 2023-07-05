#pragma once

#include "src/cpp-template/header/int-alias.hpp"
#include "src/modular-arithmetic/mod-pow.hpp"

namespace luz {

  // a^{(p-1)/2} == 1 (mod p, p is prime)
  //   iff. a has sqrt on mod p.
  // [!] mod-sqrt is not always unique.
  i64 mod_sqrt(i64 a, i64 p) {
    if (a == 0) return 0;
    if (p == 2) return a;
    if (mod_pow(a, (p - 1) >> 1, p) != 1) return -1;

    i64 b = 1;
    while (mod_pow(b, (p - 1) >> 1, p) == 1) ++b;

    i64 e = 0, m = p - 1;
    while (m % 2 == 0) m >>= 1, ++e;

    i64 x = mod_pow(a, (m - 1) >> 1, p);
    i64 y = a * (x * x % p) % p;
    (x *= a) %= p;
    i64 z = mod_pow(b, m, p);
    while (y != 1) {
      i64 j = 0, t = y;
      while (t != 1) {
        j += 1;
        (t *= t) %= p;
      }
      z = mod_pow(z, i64(1) << (e - j - 1), p);
      (x *= z) %= p;
      (z *= z) %= p;
      (y *= z) %= p;
      e = j;
    }
    return x;
  }

}
