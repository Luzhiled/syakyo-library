---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/rolling-hash.hpp\"\n\n#include <algorithm>\n\
    #include <cstdint>\n#include <vector>\n\nnamespace luz {\n  struct RollingHash\
    \ {\n    using u64 = std::uint64_t;\n    using u128 = __uint128_t;\n    static\
    \ const u64 mod = (1ull << 61ull) - 1;\n\n    const u64 base;\n    std::vector<\
    \ u64 > power;\n\n    static inline u64 add(u64 a, u64 b) {\n      if((a += b)\
    \ >= mod) a -= mod;\n      return a;\n    }\n\n    static inline u64 mul(u64 a,\
    \ u64 b) {\n      u128 c = u128(a) * b;\n      return add(c >> 61, c & mod);\n\
    \    }\n\n    inline void expand(int sz) {\n      int pre_sz = power.size();\n\
    \      if(pre_sz < sz + 1) {\n        power.resize(sz + 1);\n        for(int i\
    \ = pre_sz - 1; i < sz; i++) {\n          power[i + 1] = mul(power[i], base);\n\
    \        }\n      }\n    }\n\n    RollingHash() : base(mod - 5), power{1} {}\n\
    \n    template< class Iter >\n    std::vector< u64 > build(Iter f, Iter l) const\
    \ {\n      std::vector< u64 > hs(1);\n      hs.reserve(l - f + 1);\n      while\
    \ (f != l) {\n        u64 h = add(mul(hs.back(), base), *f);\n        hs.emplace_back(h);\n\
    \        ++f;\n      }\n      return hs;\n    }\n\n    u64 query(const std::vector<\
    \ u64 > &s, int l, int r) {\n      expand(r - l);\n      return add(s[r], mod\
    \ - mul(s[l], power[r - l]));\n    }\n\n    u64 combine(u64 h1, u64 h2, size_t\
    \ h2len) {\n      expand(h2len);\n      return add(mul(h1, power[h2len]), h2);\n\
    \    }\n\n    int lcp(const std::vector< u64 > &a, int l1, int r1,\n         \
    \   const std::vector< u64 > &b, int l2, int r2) {\n      int len = std::min(r1\
    \ - l1, r2 - l2);\n      int low = 0, high = len + 1;\n\n      while (high - low\
    \ > 1) {\n        int mid = (low + high) / 2;\n        if (query(a, l1, l1 + mid)\
    \ == query(b, l2, l2 + mid)) low = mid;\n        else high = mid;\n      }\n \
    \     return low;\n    }\n  };\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cstdint>\n#include <vector>\n\
    \nnamespace luz {\n  struct RollingHash {\n    using u64 = std::uint64_t;\n  \
    \  using u128 = __uint128_t;\n    static const u64 mod = (1ull << 61ull) - 1;\n\
    \n    const u64 base;\n    std::vector< u64 > power;\n\n    static inline u64\
    \ add(u64 a, u64 b) {\n      if((a += b) >= mod) a -= mod;\n      return a;\n\
    \    }\n\n    static inline u64 mul(u64 a, u64 b) {\n      u128 c = u128(a) *\
    \ b;\n      return add(c >> 61, c & mod);\n    }\n\n    inline void expand(int\
    \ sz) {\n      int pre_sz = power.size();\n      if(pre_sz < sz + 1) {\n     \
    \   power.resize(sz + 1);\n        for(int i = pre_sz - 1; i < sz; i++) {\n  \
    \        power[i + 1] = mul(power[i], base);\n        }\n      }\n    }\n\n  \
    \  RollingHash() : base(mod - 5), power{1} {}\n\n    template< class Iter >\n\
    \    std::vector< u64 > build(Iter f, Iter l) const {\n      std::vector< u64\
    \ > hs(1);\n      hs.reserve(l - f + 1);\n      while (f != l) {\n        u64\
    \ h = add(mul(hs.back(), base), *f);\n        hs.emplace_back(h);\n        ++f;\n\
    \      }\n      return hs;\n    }\n\n    u64 query(const std::vector< u64 > &s,\
    \ int l, int r) {\n      expand(r - l);\n      return add(s[r], mod - mul(s[l],\
    \ power[r - l]));\n    }\n\n    u64 combine(u64 h1, u64 h2, size_t h2len) {\n\
    \      expand(h2len);\n      return add(mul(h1, power[h2len]), h2);\n    }\n\n\
    \    int lcp(const std::vector< u64 > &a, int l1, int r1,\n            const std::vector<\
    \ u64 > &b, int l2, int r2) {\n      int len = std::min(r1 - l1, r2 - l2);\n \
    \     int low = 0, high = len + 1;\n\n      while (high - low > 1) {\n       \
    \ int mid = (low + high) / 2;\n        if (query(a, l1, l1 + mid) == query(b,\
    \ l2, l2 + mid)) low = mid;\n        else high = mid;\n      }\n      return low;\n\
    \    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2023-07-06 06:27:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/rolling-hash.hpp
layout: document
redirect_from:
- /library/src/string/rolling-hash.hpp
- /library/src/string/rolling-hash.hpp.html
title: src/string/rolling-hash.hpp
---
