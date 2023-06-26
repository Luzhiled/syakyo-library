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
    path: src/math/convolution/bitwise-xor-convolution.hpp
    title: src/math/convolution/bitwise-xor-convolution.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/convolution/fast-walsh-hadamard-transform.hpp
    title: src/math/convolution/fast-walsh-hadamard-transform.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic/static-modint.hpp
    title: src/math/modular-arithmetic/static-modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"test/library-checker/bitwise_xor_convolution.test.cpp\"\n\
    // verification-helper: PROBLEM https://judge.yosupo.jp/problem/bitwise_xor_convolution\n\
    \n#line 2 \"src/math/convolution/bitwise-xor-convolution.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n}\n#line 2 \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\
    \n\n#line 4 \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace luz {\n\n  // length of f must be\
    \ 2^k\n  template < typename T, typename F >\n  void fast_walsh_hadamard_transform(std::vector<\
    \ T > &f, F op) {\n    const usize n = f.size();\n    assert((n & (n - 1)) ==\
    \ 0);\n\n    usize i = 1;\n    while (i < n) {\n      usize j = 0;\n\n      while\
    \ (j < n) {\n        for (usize k = 0; k < i; k++) {\n          op(f[j + k], f[j\
    \ + k + i]);\n        }\n\n        j += i << 1;\n      }\n\n      i <<= 1;\n \
    \   }\n  }\n\n} // namespace luz\n#line 5 \"src/math/convolution/bitwise-xor-convolution.hpp\"\
    \n\n#line 8 \"src/math/convolution/bitwise-xor-convolution.hpp\"\n\nnamespace\
    \ luz {\n\n  // length of f and g must be 2^k\n  template < typename T >\n  std::vector<\
    \ T > bitwise_xor_convolution(std::vector< T > f,\n                          \
    \                 std::vector< T > g) {\n    assert(f.size() == g.size());\n\n\
    \    T inv2    = T(1) / T(2);\n\n    auto zeta = [](T &lo, T &hi) {\n      T x\
    \ = lo + hi;\n      T y = lo - hi;\n      lo  = x;\n      hi  = y;\n    };\n\n\
    \    auto mobius = [inv2](T &lo, T &hi) {\n      T x = lo + hi;\n      T y = lo\
    \ - hi;\n      lo  = x * inv2;\n      hi  = y * inv2;\n    };\n\n    fast_walsh_hadamard_transform(f,\
    \ zeta);\n    fast_walsh_hadamard_transform(g, zeta);\n\n    for (usize i = 0;\
    \ i < f.size(); i++) {\n      f[i] *= g[i];\n    }\n\n    fast_walsh_hadamard_transform(f,\
    \ mobius);\n    return f;\n  }\n\n} // namespace luz\n#line 2 \"src/math/modular-arithmetic/static-modint.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\n\
    namespace luz {\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\n}\n#line 4 \"src/math/modular-arithmetic/static-modint.hpp\"\
    \n\n#line 6 \"src/math/modular-arithmetic/static-modint.hpp\"\n#include <iostream>\n\
    \nnamespace luz {\n\n  template < u32 mod >\n  class StaticPrimeModInt {\n   \
    \ using modint = StaticPrimeModInt;\n\n    u32 v;\n\n   public:\n    StaticPrimeModInt():\
    \ v(0) {}\n\n    template < typename T >\n    StaticPrimeModInt(T t) {\n     \
    \ i64 x = (i64)(t % (i64)mod);\n      if (x < 0) x += mod;\n      v = (u32)x;\n\
    \    }\n\n    u32 val() const {\n      return v;\n    }\n\n    modint &operator+=(const\
    \ modint &rhs) {\n      v += rhs.v;\n      if (v >= mod) v -= mod;\n      return\
    \ *this;\n    }\n\n    modint &operator-=(const modint &rhs) {\n      v += mod\
    \ - rhs.v; // <-\n      if (v >= mod) v -= mod;\n      return *this;\n    }\n\n\
    \    modint &operator*=(const modint &rhs) {\n      v = (u32)(u64(1) * v * rhs.v\
    \ % mod);\n      return *this;\n    }\n\n    modint &operator/=(const modint &rhs)\
    \ {\n      *this *= rhs.inverse();\n      return *this;\n    }\n\n    modint operator+()\
    \ const {\n      return *this;\n    }\n\n    modint operator-() const {\n    \
    \  return modint() - *this;\n    }\n\n    friend modint operator+(const modint\
    \ &lhs, const modint &rhs) {\n      return modint(lhs) += rhs;\n    }\n\n    friend\
    \ modint operator-(const modint &lhs, const modint &rhs) {\n      return modint(lhs)\
    \ -= rhs;\n    }\n\n    friend modint operator*(const modint &lhs, const modint\
    \ &rhs) {\n      return modint(lhs) *= rhs;\n    }\n\n    friend modint operator/(const\
    \ modint &lhs, const modint &rhs) {\n      return modint(lhs) /= rhs;\n    }\n\
    \n    friend bool operator==(const modint &lhs, const modint &rhs) {\n      return\
    \ lhs.v == rhs.v;\n    }\n\n    friend bool operator!=(const modint &lhs, const\
    \ modint &rhs) {\n      return lhs.v != rhs.v;\n    }\n\n    modint pow(i64 n)\
    \ const {\n      assert(0 <= n);\n      modint x = *this, r = 1;\n      while\
    \ (n) {\n        if (n & 1) r *= x;\n        x *= x;\n        n >>= 1;\n     \
    \ }\n      return r;\n    }\n\n    modint inverse() const {\n      assert(v !=\
    \ 0);\n      return pow(mod - 2);\n    }\n\n    static constexpr u32 get_mod()\
    \ {\n      return mod;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os,\n                                    const modint &m) {\n      os << m.val();\n\
    \      return os;\n    }\n  };\n\n  using modint998244353  = StaticPrimeModInt<\
    \ 998244353 >;\n  using modint1000000007 = StaticPrimeModInt< 1000000007 >;\n\n\
    } // namespace luz\n#line 5 \"test/library-checker/bitwise_xor_convolution.test.cpp\"\
    \n\n#line 8 \"test/library-checker/bitwise_xor_convolution.test.cpp\"\n\nnamespace\
    \ luz {\n\n  void main_() {\n    usize n;\n    std::cin >> n;\n\n    using mint\
    \ = modint998244353;\n    std::vector< mint > as(1 << n);\n    for (mint &a: as)\
    \ {\n      i32 v;\n      std::cin >> v;\n      a = mint(v);\n    }\n\n    std::vector<\
    \ mint > bs(1 << n);\n    for (mint &b: bs) {\n      i32 v;\n      std::cin >>\
    \ v;\n      b = mint(v);\n    }\n\n    auto cs = bitwise_xor_convolution(as, bs);\n\
    \    for (usize i = 0; i < (1 << n); i++) {\n      std::cout << cs[i].val()\n\
    \                << (i + 1 == (usize(1) << n) ? \"\\n\" : \" \");\n    }\n  }\n\
    \n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/bitwise_xor_convolution\n\
    \n#include \"src/math/convolution/bitwise-xor-convolution.hpp\"\n#include \"src/math/modular-arithmetic/static-modint.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nnamespace luz {\n\n  void main_()\
    \ {\n    usize n;\n    std::cin >> n;\n\n    using mint = modint998244353;\n \
    \   std::vector< mint > as(1 << n);\n    for (mint &a: as) {\n      i32 v;\n \
    \     std::cin >> v;\n      a = mint(v);\n    }\n\n    std::vector< mint > bs(1\
    \ << n);\n    for (mint &b: bs) {\n      i32 v;\n      std::cin >> v;\n      b\
    \ = mint(v);\n    }\n\n    auto cs = bitwise_xor_convolution(as, bs);\n    for\
    \ (usize i = 0; i < (1 << n); i++) {\n      std::cout << cs[i].val()\n       \
    \         << (i + 1 == (usize(1) << n) ? \"\\n\" : \" \");\n    }\n  }\n\n} //\
    \ namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/math/convolution/bitwise-xor-convolution.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/math/convolution/fast-walsh-hadamard-transform.hpp
  - src/math/modular-arithmetic/static-modint.hpp
  - src/cpp-template/header/int-alias.hpp
  isVerificationFile: true
  path: test/library-checker/bitwise_xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2023-06-24 22:09:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/bitwise_xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/bitwise_xor_convolution.test.cpp
- /verify/test/library-checker/bitwise_xor_convolution.test.cpp.html
title: test/library-checker/bitwise_xor_convolution.test.cpp
---
