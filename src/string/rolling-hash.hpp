#pragma once

#include <algorithm>
#include <cstdint>
#include <vector>

namespace luz {
  struct RollingHash {
    using u64 = std::uint64_t;
    using u128 = __uint128_t;
    static const u64 mod = (1ull << 61ull) - 1;

    const u64 base;
    std::vector< u64 > power;

    static inline u64 add(u64 a, u64 b) {
      if((a += b) >= mod) a -= mod;
      return a;
    }

    static inline u64 mul(u64 a, u64 b) {
      u128 c = u128(a) * b;
      return add(c >> 61, c & mod);
    }

    inline void expand(int sz) {
      int pre_sz = power.size();
      if(pre_sz < sz + 1) {
        power.resize(sz + 1);
        for(int i = pre_sz - 1; i < sz; i++) {
          power[i + 1] = mul(power[i], base);
        }
      }
    }

    RollingHash() : base(mod - 5), power{1} {}

    template< class Iter >
    std::vector< u64 > build(Iter f, Iter l) const {
      std::vector< u64 > hs(1);
      hs.reserve(l - f + 1);
      while (f != l) {
        u64 h = add(mul(hs.back(), base), *f);
        hs.emplace_back(h);
        ++f;
      }
      return hs;
    }

    u64 query(const std::vector< u64 > &s, int l, int r) {
      expand(r - l);
      return add(s[r], mod - mul(s[l], power[r - l]));
    }

    u64 combine(u64 h1, u64 h2, size_t h2len) {
      expand(h2len);
      return add(mul(h1, power[h2len]), h2);
    }

    int lcp(const std::vector< u64 > &a, int l1, int r1,
            const std::vector< u64 > &b, int l2, int r2) {
      int len = std::min(r1 - l1, r2 - l2);
      int low = 0, high = len + 1;

      while (high - low > 1) {
        int mid = (low + high) / 2;
        if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid)) low = mid;
        else high = mid;
      }
      return low;
    }
  };
}
