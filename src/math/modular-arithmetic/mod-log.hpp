#pragma once

#include <numeric>
#include <map>

#include "src/cpp-template/header/int-alias.hpp"

namespace luz {

  // calculate minimum x s.t. a^{x} = b (mod p),
  //   return -1 if answer is not exists.
  i64 mod_log(i64 a, i64 b, i64 p) {
    i64 g = 1;
    for (i64 i = p; i; i /= 2) (g *= a) %= p;
    g = std::gcd(g, p);

    i64 t = 1, c = 0;
    while (t % g) {
      if (t == b) return c;
      (t *= a) %= p;
      c++;
    }
    if (b % g) return -1;

    t /= g;
    b /= g;
    i64 n = p / g, h = 0, gs = 1;
    while (h * h < n) {
      (gs *= a) %= n;
      h++;
    }

    std::unordered_map< i64, i64 > bs;
    for (i64 s = 0, e = b; s < h; bs[e] = ++s) {
      (e *= a) %= n;
    }

    for (i64 s = 0, e = t; s < n;) {
      (e *= gs) %= n;
      s += h;
      if (bs.count(e)) return c + s - bs[e];
    }
    return -1;
  }

}
