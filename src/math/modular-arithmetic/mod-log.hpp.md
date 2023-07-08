---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/int-alias.hpp
    title: src/cpp-template/header/int-alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/modular-arithmetic/mod-log.hpp\"\n\n#include <numeric>\n\
    #include <map>\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include\
    \ <cstdint>\n\nnamespace luz {\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\n}\n#line 7 \"src/math/modular-arithmetic/mod-log.hpp\"\
    \n\nnamespace luz {\n\n  // calculate minimum x s.t. a^{x} = b (mod p),\n  //\
    \   return -1 if answer is not exists.\n  i64 mod_log(i64 a, i64 b, i64 p) {\n\
    \    i64 g = 1;\n    for (i64 i = p; i; i /= 2) (g *= a) %= p;\n    g = std::gcd(g,\
    \ p);\n\n    i64 t = 1, c = 0;\n    while (t % g) {\n      if (t == b) return\
    \ c;\n      (t *= a) %= p;\n      c++;\n    }\n    if (b % g) return -1;\n\n \
    \   t /= g;\n    b /= g;\n    i64 n = p / g, h = 0, gs = 1;\n    while (h * h\
    \ < n) {\n      (gs *= a) %= n;\n      h++;\n    }\n\n    std::unordered_map<\
    \ i64, i64 > bs;\n    for (i64 s = 0, e = b; s < h; bs[e] = ++s) {\n      (e *=\
    \ a) %= n;\n    }\n\n    for (i64 s = 0, e = t; s < n;) {\n      (e *= gs) %=\
    \ n;\n      s += h;\n      if (bs.count(e)) return c + s - bs[e];\n    }\n   \
    \ return -1;\n  }\n\n}\n"
  code: "#pragma once\n\n#include <numeric>\n#include <map>\n\n#include \"src/cpp-template/header/int-alias.hpp\"\
    \n\nnamespace luz {\n\n  // calculate minimum x s.t. a^{x} = b (mod p),\n  //\
    \   return -1 if answer is not exists.\n  i64 mod_log(i64 a, i64 b, i64 p) {\n\
    \    i64 g = 1;\n    for (i64 i = p; i; i /= 2) (g *= a) %= p;\n    g = std::gcd(g,\
    \ p);\n\n    i64 t = 1, c = 0;\n    while (t % g) {\n      if (t == b) return\
    \ c;\n      (t *= a) %= p;\n      c++;\n    }\n    if (b % g) return -1;\n\n \
    \   t /= g;\n    b /= g;\n    i64 n = p / g, h = 0, gs = 1;\n    while (h * h\
    \ < n) {\n      (gs *= a) %= n;\n      h++;\n    }\n\n    std::unordered_map<\
    \ i64, i64 > bs;\n    for (i64 s = 0, e = b; s < h; bs[e] = ++s) {\n      (e *=\
    \ a) %= n;\n    }\n\n    for (i64 s = 0, e = t; s < n;) {\n      (e *= gs) %=\
    \ n;\n      s += h;\n      if (bs.count(e)) return c + s - bs[e];\n    }\n   \
    \ return -1;\n  }\n\n}\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  isVerificationFile: false
  path: src/math/modular-arithmetic/mod-log.hpp
  requiredBy: []
  timestamp: '2023-07-06 05:03:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/modular-arithmetic/mod-log.hpp
layout: document
redirect_from:
- /library/src/math/modular-arithmetic/mod-log.hpp
- /library/src/math/modular-arithmetic/mod-log.hpp.html
title: src/math/modular-arithmetic/mod-log.hpp
---
