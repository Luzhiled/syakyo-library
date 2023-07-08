---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: src/cpp-template/header/size-alias.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/convolution/bitwise-and-convolution.hpp
    title: src/math/convolution/bitwise-and-convolution.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/convolution/bitwise-xor-convolution.hpp
    title: src/math/convolution/bitwise-xor-convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/bitwise_and_convolution.test.cpp
    title: test/library-checker/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/bitwise_xor_convolution.test.cpp
    title: test/library-checker/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n}\n#line 4 \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace luz {\n\n  // length of f must be\
    \ 2^k\n  template < typename T, typename F >\n  void fast_walsh_hadamard_transform(std::vector<\
    \ T > &f, F op) {\n    const usize n = f.size();\n    assert((n & (n - 1)) ==\
    \ 0);\n\n    usize i = 1;\n    while (i < n) {\n      usize j = 0;\n\n      while\
    \ (j < n) {\n        for (usize k = 0; k < i; k++) {\n          op(f[j + k], f[j\
    \ + k + i]);\n        }\n\n        j += i << 1;\n      }\n\n      i <<= 1;\n \
    \   }\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/size-alias.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace luz {\n\n  // length of f must be\
    \ 2^k\n  template < typename T, typename F >\n  void fast_walsh_hadamard_transform(std::vector<\
    \ T > &f, F op) {\n    const usize n = f.size();\n    assert((n & (n - 1)) ==\
    \ 0);\n\n    usize i = 1;\n    while (i < n) {\n      usize j = 0;\n\n      while\
    \ (j < n) {\n        for (usize k = 0; k < i; k++) {\n          op(f[j + k], f[j\
    \ + k + i]);\n        }\n\n        j += i << 1;\n      }\n\n      i <<= 1;\n \
    \   }\n  }\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/math/convolution/fast-walsh-hadamard-transform.hpp
  requiredBy:
  - src/math/convolution/bitwise-xor-convolution.hpp
  - src/math/convolution/bitwise-and-convolution.hpp
  timestamp: '2023-06-24 21:59:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/bitwise_xor_convolution.test.cpp
  - test/library-checker/bitwise_and_convolution.test.cpp
documentation_of: src/math/convolution/fast-walsh-hadamard-transform.hpp
layout: document
redirect_from:
- /library/src/math/convolution/fast-walsh-hadamard-transform.hpp
- /library/src/math/convolution/fast-walsh-hadamard-transform.hpp.html
title: src/math/convolution/fast-walsh-hadamard-transform.hpp
---
