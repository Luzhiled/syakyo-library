#pragma once

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/math/convolution/modint-convolution.hpp"

#include <cassert>
#include <vector>

namespace luz {

  // [warning] false positive occur expect O(1/M)
  //           when values are randomized
  // [note] try to use multiple mods if necessary
  // [note] all of values are needed \in [1, mod)
  template < class Iter >
  std::vector< i32 > wildcard_pattern_matching(Iter f1, Iter l1,
                                               Iter f2, Iter l2,
                                               const i64 wildcard,
                                               i64 mod) {
    usize n = l1 - f1, m = l2 - f2;
    assert(m <= n);

    std::vector< i64 > as(n), bs(n), cs(n), ss(m), ts(m), us(m);

    for (Iter iter = f1; iter != l1; ++iter) {
      i64 x(*iter == wildcard ? 0 : *iter);
      i64 y(*iter == wildcard ? 0 : 1);
      usize i = iter - f1;
      as[i]   = y * x * x % mod;
      bs[i]   = y * x * (mod - 2) % mod;
      cs[i]   = y;
    }

    for (Iter iter = f2; iter != l2; ++iter) {
      i64 x(*iter == wildcard ? 0 : *iter);
      i64 y(*iter == wildcard ? 0 : 1);
      usize i = l2 - iter - 1;
      ss[i]   = y;
      ts[i]   = y * x;
      us[i]   = y * x * x % mod;
    }

    auto f = modint_convolution(as, ss, mod);
    auto g = modint_convolution(bs, ts, mod);
    auto h = modint_convolution(cs, us, mod);

    std::vector< i32 > result(n - m + 1);
    for (usize i = 0; i < result.size(); i++) {
      usize j = i + m - 1;
      i64 x((f[j] + g[j] + h[j]) % mod);
      if (x == 0) result[i] = 1;
    }

    return result;
  }

} // namespace luz
