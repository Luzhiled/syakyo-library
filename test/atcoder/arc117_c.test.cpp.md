---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/int-alias.hpp
    title: src/cpp-template/header/int-alias.hpp
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: src/cpp-template/header/size-alias.hpp
  - icon: ':x:'
    path: src/math/modular-arithmetic/modular-combinatorics.hpp
    title: src/math/modular-arithmetic/modular-combinatorics.hpp
  - icon: ':x:'
    path: src/math/modular-arithmetic/small-mod-combination.hpp
    title: src/math/modular-arithmetic/small-mod-combination.hpp
  - icon: ':x:'
    path: src/math/modular-arithmetic/static-modint.hpp
    title: src/math/modular-arithmetic/static-modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/arc117/tasks/arc117_c
    links:
    - https://atcoder.jp/contests/arc117/tasks/arc117_c
  bundledCode: "#line 1 \"test/atcoder/arc117_c.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/arc117/tasks/arc117_c\n\n#line 2 \"src/math/modular-arithmetic/small-mod-combination.hpp\"\
    \n\n#line 2 \"src/math/modular-arithmetic/modular-combinatorics.hpp\"\n\n#line\
    \ 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\nnamespace\
    \ luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\n}\n\
    #line 4 \"src/math/modular-arithmetic/modular-combinatorics.hpp\"\n\n#include\
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
    \ luz\n#line 4 \"src/math/modular-arithmetic/small-mod-combination.hpp\"\n\nnamespace\
    \ luz {\n\n  template < typename modint >\n  class SmallModCombination {\n   \
    \ static constexpr auto mod = modint::get_mod();\n    Combinatorics< modint >\
    \ mc;\n\n   public:\n    SmallModCombination(): mc(mod - 1) {}\n\n    modint combination(isize\
    \ n, isize r) {\n      if (r < 0 or n < r) return 0;\n\n      modint result(1);\n\
    \      while (n) {\n        result *= mc.combination(n % mod, r % mod);\n    \
    \    n /= mod;\n        r /= mod;\n      }\n\n      return result;\n    }\n\n\
    \    modint C(isize n, isize r) {\n      return combination(n, r);\n    }\n  };\n\
    \n} // namespace luz\n#line 2 \"src/math/modular-arithmetic/static-modint.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\n\
    namespace luz {\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\n}\n#line 4 \"src/math/modular-arithmetic/static-modint.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n\nnamespace luz {\n\n  template <\
    \ u32 mod >\n  class StaticPrimeModInt {\n    using modint = StaticPrimeModInt;\n\
    \n    u32 v;\n\n   public:\n    StaticPrimeModInt(): v(0) {}\n\n    template <\
    \ typename T >\n    StaticPrimeModInt(T t) {\n      i64 x = (i64)(t % (i64)mod);\n\
    \      if (x < 0) x += mod;\n      v = (u32)x;\n    }\n\n    u32 val() const {\n\
    \      return v;\n    }\n\n    modint &operator+=(const modint &rhs) {\n     \
    \ v += rhs.v;\n      if (v >= mod) v -= mod;\n      return *this;\n    }\n\n \
    \   modint &operator-=(const modint &rhs) {\n      v += mod - rhs.v; // <-\n \
    \     if (v >= mod) v -= mod;\n      return *this;\n    }\n\n    modint &operator*=(const\
    \ modint &rhs) {\n      v = (u32)(u64(1) * v * rhs.v % mod);\n      return *this;\n\
    \    }\n\n    modint &operator/=(const modint &rhs) {\n      *this *= rhs.inverse();\n\
    \      return *this;\n    }\n\n    modint operator+() const {\n      return *this;\n\
    \    }\n\n    modint operator-() const {\n      return modint() - *this;\n   \
    \ }\n\n    friend modint operator+(const modint &lhs, const modint &rhs) {\n \
    \     return modint(lhs) += rhs;\n    }\n\n    friend modint operator-(const modint\
    \ &lhs, const modint &rhs) {\n      return modint(lhs) -= rhs;\n    }\n\n    friend\
    \ modint operator*(const modint &lhs, const modint &rhs) {\n      return modint(lhs)\
    \ *= rhs;\n    }\n\n    friend modint operator/(const modint &lhs, const modint\
    \ &rhs) {\n      return modint(lhs) /= rhs;\n    }\n\n    friend bool operator==(const\
    \ modint &lhs, const modint &rhs) {\n      return lhs.v == rhs.v;\n    }\n\n \
    \   friend bool operator!=(const modint &lhs, const modint &rhs) {\n      return\
    \ lhs.v != rhs.v;\n    }\n\n    modint pow(i64 n) const {\n      assert(0 <= n);\n\
    \      modint x = *this, r = 1;\n      while (n) {\n        if (n & 1) r *= x;\n\
    \        x *= x;\n        n >>= 1;\n      }\n      return r;\n    }\n\n    modint\
    \ inverse() const {\n      assert(v != 0);\n      return pow(mod - 2);\n    }\n\
    \n    static constexpr u32 get_mod() {\n      return mod;\n    }\n\n    friend\
    \ std::ostream &operator<<(std::ostream &os,\n                               \
    \     const modint &m) {\n      os << m.val();\n      return os;\n    }\n  };\n\
    \n  using modint998244353  = StaticPrimeModInt< 998244353 >;\n  using modint1000000007\
    \ = StaticPrimeModInt< 1000000007 >;\n\n} // namespace luz\n#line 5 \"test/atcoder/arc117_c.test.cpp\"\
    \n\n#line 7 \"test/atcoder/arc117_c.test.cpp\"\n#include <string>\n\nnamespace\
    \ luz {\n\n  void main_() {\n    using mint = StaticPrimeModInt< 3 >;\n    SmallModCombination<\
    \ mint > mc;\n\n    usize n;\n    std::cin >> n;\n\n    std::string s;\n    std::cin\
    \ >> s;\n\n    auto convert = [](char c) {\n      switch (c) {\n        case 'B':\n\
    \          return 0;\n        case 'W':\n          return 1;\n        case 'R':\n\
    \          return 2;\n        default:\n          exit(-1);\n      }\n    };\n\
    \n    mint sum;\n    for (usize i = 0; i < n; i++) {\n      sum +=\n         \
    \ (n & 1 ? 1 : -1) * convert(s[i]) * mc.combination(n - 1, i);\n    }\n\n    auto\
    \ inverse = [](mint x) {\n      switch (x.val()) {\n        case 0:\n        \
    \  return 'B';\n        case 1:\n          return 'W';\n        case 2:\n    \
    \      return 'R';\n        default:\n          exit(-1);\n      }\n    };\n\n\
    \    std::cout << inverse(sum) << std::endl;\n  }\n\n} // namespace luz\n\nint\
    \ main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/arc117/tasks/arc117_c\n\
    \n#include \"src/math/modular-arithmetic/small-mod-combination.hpp\"\n#include\
    \ \"src/math/modular-arithmetic/static-modint.hpp\"\n\n#include <iostream>\n#include\
    \ <string>\n\nnamespace luz {\n\n  void main_() {\n    using mint = StaticPrimeModInt<\
    \ 3 >;\n    SmallModCombination< mint > mc;\n\n    usize n;\n    std::cin >> n;\n\
    \n    std::string s;\n    std::cin >> s;\n\n    auto convert = [](char c) {\n\
    \      switch (c) {\n        case 'B':\n          return 0;\n        case 'W':\n\
    \          return 1;\n        case 'R':\n          return 2;\n        default:\n\
    \          exit(-1);\n      }\n    };\n\n    mint sum;\n    for (usize i = 0;\
    \ i < n; i++) {\n      sum +=\n          (n & 1 ? 1 : -1) * convert(s[i]) * mc.combination(n\
    \ - 1, i);\n    }\n\n    auto inverse = [](mint x) {\n      switch (x.val()) {\n\
    \        case 0:\n          return 'B';\n        case 1:\n          return 'W';\n\
    \        case 2:\n          return 'R';\n        default:\n          exit(-1);\n\
    \      }\n    };\n\n    std::cout << inverse(sum) << std::endl;\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/math/modular-arithmetic/small-mod-combination.hpp
  - src/math/modular-arithmetic/modular-combinatorics.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/math/modular-arithmetic/static-modint.hpp
  - src/cpp-template/header/int-alias.hpp
  isVerificationFile: true
  path: test/atcoder/arc117_c.test.cpp
  requiredBy: []
  timestamp: '2023-06-20 08:49:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/arc117_c.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc117_c.test.cpp
- /verify/test/atcoder/arc117_c.test.cpp.html
title: test/atcoder/arc117_c.test.cpp
---
