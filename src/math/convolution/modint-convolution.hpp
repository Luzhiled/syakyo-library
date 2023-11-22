#pragma once

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/math/modular-arithmetic/mod-pow.hpp"

#include <vector>

namespace luz {

  usize bw(u64 x) {
    if (x == 0) return 0;
    return 64 - __builtin_clzll(x);
  }

  void butterfly(std::vector< i64 > &vs, i64 mod) {
    constexpr i64 root = 62;
    usize n = vs.size(), h = bw(n) - 1;

    static std::vector< i64 > rt(2, 1);

    for (static usize k = 2, s = 2; k < n; k *= 2, s++) {
      rt.resize(n);
      i64 z[] = {1, mod_pow(root, mod >> s, mod)};
      for (usize i = k; i < 2 * k; i++) {
        rt[i] = rt[i / 2] * z[i & 1] % mod;
      }
    }

    std::vector< i64 > rev(n);

    for (usize i = 0; i < n; i++) {
      rev[i] = (rev[i / 2] | (i & 1) << h) / 2;
    }

    for (usize i = 0; i < n; i++) {
      if ((i64)i >= rev[i]) continue;
      std::swap(vs[i], vs[rev[i]]);
    }

    for (usize k = 1; k < n; k *= 2) {
      for (usize i = 0; i < n; i += 2 * k) {
        for (usize j = 0; j < k; j++) {
          i64 z = rt[j + k] * vs[i + j + k] % mod;
          i64 &vi = vs[i + j];

          vs[i + j + k] = vi - z + (z > vi ? mod : 0);
          vi += (vi + z >= mod ? z - mod : z);
        }
      }
    }
  }

  std::vector< i64 > modint_convolution(std::vector< i64 > f,
                                        std::vector< i64 > g,
                                        i64 mod) {
    usize n = f.size(), m = g.size();

    if (not n or not m) return {};
    
    usize s = 1 << bw(n + m - 2);
    i64 inv = mod_pow(s, mod - 2, mod);

    f.resize(s);
    g.resize(s);

    butterfly(f, mod);
    butterfly(g, mod);

    std::vector< i64 > res(s);
    for (isize i = 0; (usize)i < s; i++) {
      res[-i & (s - 1)] = f[i] * g[i] % mod * inv % mod;
    }
    butterfly(res, mod);

    res.resize(n + m - 1);
    return res;
  }

}
