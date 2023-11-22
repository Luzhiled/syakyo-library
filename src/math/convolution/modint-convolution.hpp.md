---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/int-alias.hpp
    title: src/cpp-template/header/int-alias.hpp
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: src/cpp-template/header/size-alias.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic/mod-pow.hpp
    title: src/math/modular-arithmetic/mod-pow.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/string/wildcard-pattern-matching.hpp
    title: src/string/wildcard-pattern-matching.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc307_h.test.cpp
    title: test/atcoder/abc307_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/modint_convolution.test.cpp
    title: test/library-checker/modint_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/convolution/modint-convolution.hpp\"\n\n#line 2\
    \ \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\nnamespace\
    \ luz {\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n  using u32\
    \ = std::uint32_t;\n  using u64 = std::uint64_t;\n\n}\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n}\n#line 2 \"src/math/modular-arithmetic/mod-pow.hpp\"\
    \n\n#line 4 \"src/math/modular-arithmetic/mod-pow.hpp\"\n\nnamespace luz {\n\n\
    \  i64 mod_pow(i64 b, i64 e, i64 mod) {\n    if (mod == 1) return 0;\n    i64\
    \ ans{1};\n\n    while (e) {\n      if (e & 1) {\n        ans = ans * b % mod;\n\
    \      }\n      b = b * b % mod;\n      e /= 2;\n    }\n\n    return ans;\n  }\n\
    \n}\n#line 6 \"src/math/convolution/modint-convolution.hpp\"\n\n#include <vector>\n\
    \nnamespace luz {\n\n  usize bw(u64 x) {\n    if (x == 0) return 0;\n    return\
    \ 64 - __builtin_clzll(x);\n  }\n\n  void butterfly(std::vector< i64 > &vs, i64\
    \ mod) {\n    constexpr i64 root = 62;\n    usize n = vs.size(), h = bw(n) - 1;\n\
    \n    static std::vector< i64 > rt(2, 1);\n\n    for (static usize k = 2, s =\
    \ 2; k < n; k *= 2, s++) {\n      rt.resize(n);\n      i64 z[] = {1, mod_pow(root,\
    \ mod >> s, mod)};\n      for (usize i = k; i < 2 * k; i++) {\n        rt[i] =\
    \ rt[i / 2] * z[i & 1] % mod;\n      }\n    }\n\n    std::vector< i64 > rev(n);\n\
    \n    for (usize i = 0; i < n; i++) {\n      rev[i] = (rev[i / 2] | (i & 1) <<\
    \ h) / 2;\n    }\n\n    for (usize i = 0; i < n; i++) {\n      if ((i64)i >= rev[i])\
    \ continue;\n      std::swap(vs[i], vs[rev[i]]);\n    }\n\n    for (usize k =\
    \ 1; k < n; k *= 2) {\n      for (usize i = 0; i < n; i += 2 * k) {\n        for\
    \ (usize j = 0; j < k; j++) {\n          i64 z = rt[j + k] * vs[i + j + k] % mod;\n\
    \          i64 &vi = vs[i + j];\n\n          vs[i + j + k] = vi - z + (z > vi\
    \ ? mod : 0);\n          vi += (vi + z >= mod ? z - mod : z);\n        }\n   \
    \   }\n    }\n  }\n\n  std::vector< i64 > modint_convolution(std::vector< i64\
    \ > f,\n                                        std::vector< i64 > g,\n      \
    \                                  i64 mod) {\n    usize n = f.size(), m = g.size();\n\
    \n    if (not n or not m) return {};\n    \n    usize s = 1 << bw(n + m - 2);\n\
    \    i64 inv = mod_pow(s, mod - 2, mod);\n\n    f.resize(s);\n    g.resize(s);\n\
    \n    butterfly(f, mod);\n    butterfly(g, mod);\n\n    std::vector< i64 > res(s);\n\
    \    for (isize i = 0; (usize)i < s; i++) {\n      res[-i & (s - 1)] = f[i] *\
    \ g[i] % mod * inv % mod;\n    }\n    butterfly(res, mod);\n\n    res.resize(n\
    \ + m - 1);\n    return res;\n  }\n\n}\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/int-alias.hpp\"\n#include\
    \ \"src/cpp-template/header/size-alias.hpp\"\n#include \"src/math/modular-arithmetic/mod-pow.hpp\"\
    \n\n#include <vector>\n\nnamespace luz {\n\n  usize bw(u64 x) {\n    if (x ==\
    \ 0) return 0;\n    return 64 - __builtin_clzll(x);\n  }\n\n  void butterfly(std::vector<\
    \ i64 > &vs, i64 mod) {\n    constexpr i64 root = 62;\n    usize n = vs.size(),\
    \ h = bw(n) - 1;\n\n    static std::vector< i64 > rt(2, 1);\n\n    for (static\
    \ usize k = 2, s = 2; k < n; k *= 2, s++) {\n      rt.resize(n);\n      i64 z[]\
    \ = {1, mod_pow(root, mod >> s, mod)};\n      for (usize i = k; i < 2 * k; i++)\
    \ {\n        rt[i] = rt[i / 2] * z[i & 1] % mod;\n      }\n    }\n\n    std::vector<\
    \ i64 > rev(n);\n\n    for (usize i = 0; i < n; i++) {\n      rev[i] = (rev[i\
    \ / 2] | (i & 1) << h) / 2;\n    }\n\n    for (usize i = 0; i < n; i++) {\n  \
    \    if ((i64)i >= rev[i]) continue;\n      std::swap(vs[i], vs[rev[i]]);\n  \
    \  }\n\n    for (usize k = 1; k < n; k *= 2) {\n      for (usize i = 0; i < n;\
    \ i += 2 * k) {\n        for (usize j = 0; j < k; j++) {\n          i64 z = rt[j\
    \ + k] * vs[i + j + k] % mod;\n          i64 &vi = vs[i + j];\n\n          vs[i\
    \ + j + k] = vi - z + (z > vi ? mod : 0);\n          vi += (vi + z >= mod ? z\
    \ - mod : z);\n        }\n      }\n    }\n  }\n\n  std::vector< i64 > modint_convolution(std::vector<\
    \ i64 > f,\n                                        std::vector< i64 > g,\n  \
    \                                      i64 mod) {\n    usize n = f.size(), m =\
    \ g.size();\n\n    if (not n or not m) return {};\n    \n    usize s = 1 << bw(n\
    \ + m - 2);\n    i64 inv = mod_pow(s, mod - 2, mod);\n\n    f.resize(s);\n   \
    \ g.resize(s);\n\n    butterfly(f, mod);\n    butterfly(g, mod);\n\n    std::vector<\
    \ i64 > res(s);\n    for (isize i = 0; (usize)i < s; i++) {\n      res[-i & (s\
    \ - 1)] = f[i] * g[i] % mod * inv % mod;\n    }\n    butterfly(res, mod);\n\n\
    \    res.resize(n + m - 1);\n    return res;\n  }\n\n}\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/math/modular-arithmetic/mod-pow.hpp
  isVerificationFile: false
  path: src/math/convolution/modint-convolution.hpp
  requiredBy:
  - src/string/wildcard-pattern-matching.hpp
  timestamp: '2023-11-23 06:28:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/modint_convolution.test.cpp
  - test/atcoder/abc307_h.test.cpp
documentation_of: src/math/convolution/modint-convolution.hpp
layout: document
redirect_from:
- /library/src/math/convolution/modint-convolution.hpp
- /library/src/math/convolution/modint-convolution.hpp.html
title: src/math/convolution/modint-convolution.hpp
---
