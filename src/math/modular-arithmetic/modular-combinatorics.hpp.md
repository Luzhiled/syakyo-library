---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: src/cpp-template/header/size-alias.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic/small-mod-combination.hpp
    title: src/math/modular-arithmetic/small-mod-combination.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc117_c.test.cpp
    title: test/atcoder/arc117_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/modular-arithmetic/modular-combinatorics.hpp\"\n\
    \n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\n\
    namespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n}\n#line 4 \"src/math/modular-arithmetic/modular-combinatorics.hpp\"\n\n#include\
    \ <vector>\n\nnamespace luz {\n\n  template < typename mint >\n  class Combinatorics\
    \ {\n    static usize bound;\n    static std::vector< mint > fact, finv, inv;\n\
    \n    static void expand(usize n) {\n      n += 1;\n      if (fact.size() >= n)\
    \ return;\n\n      if (bound == 0) bound = 1;\n\n      fact.resize(n, mint(1));\n\
    \      finv.resize(n, mint(1));\n      inv.resize(n, mint(1));\n\n      for (usize\
    \ i = bound; i < n; i++) {\n        fact[i] = fact[i - 1] * i;\n      }\n\n  \
    \    finv.back() = mint(1) / fact.back();\n      for (usize i = n - 1; i >= bound;\
    \ i--) {\n        finv[i - 1] = finv[i] * i;\n      }\n\n      for (usize i =\
    \ bound; i < n; i++) {\n        inv[i] = finv[i] * fact[i - 1];\n      }\n\n \
    \     bound = n;\n    }\n\n   public:\n    explicit Combinatorics(usize n = 0)\
    \ {\n      expand(n);\n    }\n\n    static mint factorial(usize n) {\n      expand(n);\n\
    \      return fact[n];\n    }\n\n    static mint factorial_inverse(usize n) {\n\
    \      expand(n);\n      return finv[n];\n    }\n\n    static mint inverse(usize\
    \ n) {\n      expand(n);\n      return inv[n];\n    }\n\n    static mint permutation(isize\
    \ n, isize r) {\n      if (r < 0 or n < r) return 0;\n\n      expand(n);\n   \
    \   return fact[n] * finv[n - r];\n    }\n\n    static mint combination(isize\
    \ n, isize r) {\n      if (r < 0 or n < r) return 0;\n\n      expand(n);\n   \
    \   return fact[n] * finv[r] * finv[n - r];\n    }\n\n    static mint combination_with_repetitions(isize\
    \ n, isize r) {\n      if (n < 0 or r < 0) return 0;\n      return (r ? combination(n\
    \ + r - 1, r) : 1);\n    }\n\n    static mint P(isize n, isize r) {\n      return\
    \ permutation(n, r);\n    }\n\n    static mint C(isize n, isize r) {\n      return\
    \ combination(n, r);\n    }\n\n    static mint H(isize n, isize r) {\n      return\
    \ combination_with_repetitions(n, r);\n    }\n  };\n\n  template < typename mint\
    \ >\n  usize Combinatorics< mint >::bound = 0;\n\n  template < typename mint >\n\
    \  std::vector< mint > Combinatorics< mint >::fact =\n      std::vector< mint\
    \ >();\n\n  template < typename mint >\n  std::vector< mint > Combinatorics< mint\
    \ >::finv =\n      std::vector< mint >();\n\n  template < typename mint >\n  std::vector<\
    \ mint > Combinatorics< mint >::inv =\n      std::vector< mint >();\n\n} // namespace\
    \ luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/size-alias.hpp\"\n\n#include\
    \ <vector>\n\nnamespace luz {\n\n  template < typename mint >\n  class Combinatorics\
    \ {\n    static usize bound;\n    static std::vector< mint > fact, finv, inv;\n\
    \n    static void expand(usize n) {\n      n += 1;\n      if (fact.size() >= n)\
    \ return;\n\n      if (bound == 0) bound = 1;\n\n      fact.resize(n, mint(1));\n\
    \      finv.resize(n, mint(1));\n      inv.resize(n, mint(1));\n\n      for (usize\
    \ i = bound; i < n; i++) {\n        fact[i] = fact[i - 1] * i;\n      }\n\n  \
    \    finv.back() = mint(1) / fact.back();\n      for (usize i = n - 1; i >= bound;\
    \ i--) {\n        finv[i - 1] = finv[i] * i;\n      }\n\n      for (usize i =\
    \ bound; i < n; i++) {\n        inv[i] = finv[i] * fact[i - 1];\n      }\n\n \
    \     bound = n;\n    }\n\n   public:\n    explicit Combinatorics(usize n = 0)\
    \ {\n      expand(n);\n    }\n\n    static mint factorial(usize n) {\n      expand(n);\n\
    \      return fact[n];\n    }\n\n    static mint factorial_inverse(usize n) {\n\
    \      expand(n);\n      return finv[n];\n    }\n\n    static mint inverse(usize\
    \ n) {\n      expand(n);\n      return inv[n];\n    }\n\n    static mint permutation(isize\
    \ n, isize r) {\n      if (r < 0 or n < r) return 0;\n\n      expand(n);\n   \
    \   return fact[n] * finv[n - r];\n    }\n\n    static mint combination(isize\
    \ n, isize r) {\n      if (r < 0 or n < r) return 0;\n\n      expand(n);\n   \
    \   return fact[n] * finv[r] * finv[n - r];\n    }\n\n    static mint combination_with_repetitions(isize\
    \ n, isize r) {\n      if (n < 0 or r < 0) return 0;\n      return (r ? combination(n\
    \ + r - 1, r) : 1);\n    }\n\n    static mint P(isize n, isize r) {\n      return\
    \ permutation(n, r);\n    }\n\n    static mint C(isize n, isize r) {\n      return\
    \ combination(n, r);\n    }\n\n    static mint H(isize n, isize r) {\n      return\
    \ combination_with_repetitions(n, r);\n    }\n  };\n\n  template < typename mint\
    \ >\n  usize Combinatorics< mint >::bound = 0;\n\n  template < typename mint >\n\
    \  std::vector< mint > Combinatorics< mint >::fact =\n      std::vector< mint\
    \ >();\n\n  template < typename mint >\n  std::vector< mint > Combinatorics< mint\
    \ >::finv =\n      std::vector< mint >();\n\n  template < typename mint >\n  std::vector<\
    \ mint > Combinatorics< mint >::inv =\n      std::vector< mint >();\n\n} // namespace\
    \ luz\n"
  dependsOn:
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/math/modular-arithmetic/modular-combinatorics.hpp
  requiredBy:
  - src/math/modular-arithmetic/small-mod-combination.hpp
  timestamp: '2023-06-20 07:50:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/arc117_c.test.cpp
documentation_of: src/math/modular-arithmetic/modular-combinatorics.hpp
layout: document
redirect_from:
- /library/src/math/modular-arithmetic/modular-combinatorics.hpp
- /library/src/math/modular-arithmetic/modular-combinatorics.hpp.html
title: src/math/modular-arithmetic/modular-combinatorics.hpp
---