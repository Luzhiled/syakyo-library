---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: src/cpp-template/header/size-alias.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/convolution/fast-walsh-hadamard-transform.hpp
    title: src/math/convolution/fast-walsh-hadamard-transform.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/bitwise_and_convolution.test.cpp
    title: test/library-checker/bitwise_and_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/convolution/bitwise-and-convolution.hpp\"\n\n#line\
    \ 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\nnamespace\
    \ luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\n}\n\
    #line 2 \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\n\n#line 4\
    \ \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace luz {\n\n  // length of f must be 2^k\n  template\
    \ < typename T, typename F >\n  void fast_walsh_hadamard_transform(std::vector<\
    \ T > &f, F op) {\n    const usize n = f.size();\n    assert((n & (n - 1)) ==\
    \ 0);\n\n    usize i = 1;\n    while (i < n) {\n      usize j = 0;\n\n      while\
    \ (j < n) {\n        for (usize k = 0; k < i; k++) {\n          op(f[j + k], f[j\
    \ + k + i]);\n        }\n\n        j += i << 1;\n      }\n\n      i <<= 1;\n \
    \   }\n  }\n\n} // namespace luz\n#line 5 \"src/math/convolution/bitwise-and-convolution.hpp\"\
    \n\n#line 8 \"src/math/convolution/bitwise-and-convolution.hpp\"\n\nnamespace\
    \ luz {\n\n  // length of f and g must be 2^k\n  template < typename T >\n  std::vector<\
    \ T > bitwise_and_convolution(std::vector< T > f,\n                          \
    \                 std::vector< T > g) {\n    assert(f.size() == g.size());\n\n\
    \    auto zeta   = [](T &lo, T hi) { return lo += hi; };\n    auto mobius = [](T\
    \ &lo, T hi) { return lo -= hi; };\n\n    fast_walsh_hadamard_transform(f, zeta);\n\
    \    fast_walsh_hadamard_transform(g, zeta);\n\n    for (usize i = 0; i < f.size();\
    \ i++) {\n      f[i] *= g[i];\n    }\n\n    fast_walsh_hadamard_transform(f, mobius);\n\
    \    return f;\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/size-alias.hpp\"\n#include\
    \ \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace luz {\n\n  // length of f and g must be 2^k\n \
    \ template < typename T >\n  std::vector< T > bitwise_and_convolution(std::vector<\
    \ T > f,\n                                           std::vector< T > g) {\n \
    \   assert(f.size() == g.size());\n\n    auto zeta   = [](T &lo, T hi) { return\
    \ lo += hi; };\n    auto mobius = [](T &lo, T hi) { return lo -= hi; };\n\n  \
    \  fast_walsh_hadamard_transform(f, zeta);\n    fast_walsh_hadamard_transform(g,\
    \ zeta);\n\n    for (usize i = 0; i < f.size(); i++) {\n      f[i] *= g[i];\n\
    \    }\n\n    fast_walsh_hadamard_transform(f, mobius);\n    return f;\n  }\n\n\
    } // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/size-alias.hpp
  - src/math/convolution/fast-walsh-hadamard-transform.hpp
  isVerificationFile: false
  path: src/math/convolution/bitwise-and-convolution.hpp
  requiredBy: []
  timestamp: '2023-06-24 21:59:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/bitwise_and_convolution.test.cpp
documentation_of: src/math/convolution/bitwise-and-convolution.hpp
layout: document
redirect_from:
- /library/src/math/convolution/bitwise-and-convolution.hpp
- /library/src/math/convolution/bitwise-and-convolution.hpp.html
title: src/math/convolution/bitwise-and-convolution.hpp
---
