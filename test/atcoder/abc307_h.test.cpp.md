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
    path: src/math/convolution/modint-convolution.hpp
    title: src/math/convolution/modint-convolution.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic/mod-pow.hpp
    title: src/math/modular-arithmetic/mod-pow.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic/static-modint.hpp
    title: src/math/modular-arithmetic/static-modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/string/wildcard-pattern-matching.hpp
    title: src/string/wildcard-pattern-matching.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc307/tasks/abc307_ex
    links:
    - https://atcoder.jp/contests/abc307/tasks/abc307_ex
    - https://atcoder.jp/contests/abc307/tasks/abc307_h
  bundledCode: "#line 1 \"test/atcoder/abc307_h.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc307/tasks/abc307_h\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc307/tasks/abc307_ex\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n}\n#line 2 \"src/math/modular-arithmetic/static-modint.hpp\"\
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
    \ = StaticPrimeModInt< 1000000007 >;\n\n} // namespace luz\n#line 2 \"src/string/wildcard-pattern-matching.hpp\"\
    \n\n#line 2 \"src/math/convolution/modint-convolution.hpp\"\n\n#line 2 \"src/math/modular-arithmetic/mod-pow.hpp\"\
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
    \ + m - 1);\n    return res;\n  }\n\n}\n#line 6 \"src/string/wildcard-pattern-matching.hpp\"\
    \n\n#line 9 \"src/string/wildcard-pattern-matching.hpp\"\n\nnamespace luz {\n\n\
    \  // [warning] false positive occur expect O(1/M)\n  //           when values\
    \ are randomized\n  // [note] try to use multiple mods if necessary\n  // [note]\
    \ all of values are needed \\in [1, mod)\n  template < class Iter >\n  std::vector<\
    \ i32 > wildcard_pattern_matching(Iter f1, Iter l1,\n                        \
    \                       Iter f2, Iter l2,\n                                  \
    \             const i64 wildcard,\n                                          \
    \     i64 mod) {\n    usize n = l1 - f1, m = l2 - f2;\n    assert(m <= n);\n\n\
    \    std::vector< i64 > as(n), bs(n), cs(n), ss(m), ts(m), us(m);\n\n    for (Iter\
    \ iter = f1; iter != l1; ++iter) {\n      i64 x(*iter == wildcard ? 0 : *iter);\n\
    \      i64 y(*iter == wildcard ? 0 : 1);\n      usize i = iter - f1;\n      as[i]\
    \   = y * x * x % mod;\n      bs[i]   = y * x * (mod - 2) % mod;\n      cs[i]\
    \   = y;\n    }\n\n    for (Iter iter = f2; iter != l2; ++iter) {\n      i64 x(*iter\
    \ == wildcard ? 0 : *iter);\n      i64 y(*iter == wildcard ? 0 : 1);\n      usize\
    \ i = l2 - iter - 1;\n      ss[i]   = y;\n      ts[i]   = y * x;\n      us[i]\
    \   = y * x * x % mod;\n    }\n\n    auto f = modint_convolution(as, ss, mod);\n\
    \    auto g = modint_convolution(bs, ts, mod);\n    auto h = modint_convolution(cs,\
    \ us, mod);\n\n    std::vector< i32 > result(n - m + 1);\n    for (usize i = 0;\
    \ i < result.size(); i++) {\n      usize j = i + m - 1;\n      i64 x((f[j] + g[j]\
    \ + h[j]) % mod);\n      if (x == 0) result[i] = 1;\n    }\n\n    return result;\n\
    \  }\n\n} // namespace luz\n#line 7 \"test/atcoder/abc307_h.test.cpp\"\n\n#include\
    \ <algorithm>\n#line 10 \"test/atcoder/abc307_h.test.cpp\"\n\nnamespace luz {\n\
    \n  void main_() {\n    const i64 mod = 998244353;\n\n    usize l, w;\n    std::string\
    \ s;\n\n    std::cin >> l >> w >> s;\n    s += std::string(w - 1, '.');\n    s\
    \ += s.substr(0, w - 1);\n\n    std::string p;\n    std::cin >> p;\n\n    auto\
    \ wpm = wildcard_pattern_matching(s.begin(), s.end(), p.begin(), p.end(), '_',\
    \ mod);\n\n    std::cout << std::count(wpm.begin(), wpm.end(), 1) << std::endl;\n\
    \  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc307/tasks/abc307_h\n\
    // verification-helper: PROBLEM https://atcoder.jp/contests/abc307/tasks/abc307_ex\n\
    \n#include \"src/cpp-template/header/size-alias.hpp\"\n#include \"src/math/modular-arithmetic/static-modint.hpp\"\
    \n#include \"src/string/wildcard-pattern-matching.hpp\"\n\n#include <algorithm>\n\
    #include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    const i64 mod\
    \ = 998244353;\n\n    usize l, w;\n    std::string s;\n\n    std::cin >> l >>\
    \ w >> s;\n    s += std::string(w - 1, '.');\n    s += s.substr(0, w - 1);\n\n\
    \    std::string p;\n    std::cin >> p;\n\n    auto wpm = wildcard_pattern_matching(s.begin(),\
    \ s.end(), p.begin(), p.end(), '_', mod);\n\n    std::cout << std::count(wpm.begin(),\
    \ wpm.end(), 1) << std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n\
    }\n"
  dependsOn:
  - src/cpp-template/header/size-alias.hpp
  - src/math/modular-arithmetic/static-modint.hpp
  - src/cpp-template/header/int-alias.hpp
  - src/string/wildcard-pattern-matching.hpp
  - src/math/convolution/modint-convolution.hpp
  - src/math/modular-arithmetic/mod-pow.hpp
  isVerificationFile: true
  path: test/atcoder/abc307_h.test.cpp
  requiredBy: []
  timestamp: '2023-11-23 07:06:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc307_h.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc307_h.test.cpp
- /verify/test/atcoder/abc307_h.test.cpp.html
title: test/atcoder/abc307_h.test.cpp
---
