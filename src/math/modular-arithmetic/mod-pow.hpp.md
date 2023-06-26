---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/int-alias.hpp
    title: src/cpp-template/header/int-alias.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/convolution/mod-convolution.hpp
    title: src/math/convolution/mod-convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/modint_convolution.test.cpp
    title: test/library-checker/modint_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/modular-arithmetic/mod-pow.hpp\"\n\n#line 2 \"\
    src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\nnamespace luz\
    \ {\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n  using u32 =\
    \ std::uint32_t;\n  using u64 = std::uint64_t;\n\n}\n#line 4 \"src/math/modular-arithmetic/mod-pow.hpp\"\
    \n\nnamespace luz {\n\n  i64 mod_pow(i64 b, i64 e, i64 mod) {\n    i64 ans{1};\n\
    \n    while (e) {\n      if (e & 1) {\n        ans = ans * b % mod;\n      }\n\
    \      b = b * b % mod;\n      e /= 2;\n    }\n\n    return ans;\n  }\n\n}\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/int-alias.hpp\"\n\nnamespace\
    \ luz {\n\n  i64 mod_pow(i64 b, i64 e, i64 mod) {\n    i64 ans{1};\n\n    while\
    \ (e) {\n      if (e & 1) {\n        ans = ans * b % mod;\n      }\n      b =\
    \ b * b % mod;\n      e /= 2;\n    }\n\n    return ans;\n  }\n\n}\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  isVerificationFile: false
  path: src/math/modular-arithmetic/mod-pow.hpp
  requiredBy:
  - src/math/convolution/mod-convolution.hpp
  timestamp: '2023-06-24 23:47:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/modint_convolution.test.cpp
documentation_of: src/math/modular-arithmetic/mod-pow.hpp
layout: document
redirect_from:
- /library/src/math/modular-arithmetic/mod-pow.hpp
- /library/src/math/modular-arithmetic/mod-pow.hpp.html
title: src/math/modular-arithmetic/mod-pow.hpp
---
