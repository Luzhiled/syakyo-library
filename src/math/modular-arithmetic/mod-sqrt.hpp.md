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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/modular-arithmetic/mod-pow.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/int-alias.hpp\"\n#include\
    \ \"src/modular-arithmetic/mod-pow.hpp\"\n\nnamespace luz {\n\n  // a^{(p-1)/2}\
    \ == 1 (mod p, p is prime)\n  //   iff. a has sqrt on mod p.\n  // [!] mod-sqrt\
    \ is not always unique.\n  // O(log^2 p)\n  i64 mod_sqrt(i64 a, i64 p) {\n   \
    \ if (a == 0) return 0;\n    if (p == 2) return a;\n    if (mod_pow(a, (p - 1)\
    \ >> 1, p) != 1) return -1;\n\n    i64 b = 1;\n    while (mod_pow(b, (p - 1) >>\
    \ 1, p) == 1) ++b;\n\n    i64 e = 0, m = p - 1;\n    while (m % 2 == 0) m >>=\
    \ 1, ++e;\n\n    i64 x = mod_pow(a, (m - 1) >> 1, p);\n    i64 y = a * (x * x\
    \ % p) % p;\n    (x *= a) %= p;\n    i64 z = mod_pow(b, m, p);\n    while (y !=\
    \ 1) {\n      i64 j = 0, t = y;\n      while (t != 1) {\n        j += 1;\n   \
    \     (t *= t) %= p;\n      }\n      z = mod_pow(z, i64(1) << (e - j - 1), p);\n\
    \      (x *= z) %= p;\n      (z *= z) %= p;\n      (y *= z) %= p;\n      e = j;\n\
    \    }\n    return x;\n  }\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/modular-arithmetic/mod-sqrt.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/modular-arithmetic/mod-sqrt.hpp
layout: document
redirect_from:
- /library/src/math/modular-arithmetic/mod-sqrt.hpp
- /library/src/math/modular-arithmetic/mod-sqrt.hpp.html
title: src/math/modular-arithmetic/mod-sqrt.hpp
---
