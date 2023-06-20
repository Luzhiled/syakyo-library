---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_b/fenwick-tree.test.cpp
    title: test/aoj/dsl_2_b/fenwick-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/fenwick-tree.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\nnamespace luz {\n\n  template < typename\
    \ T >\n  class FenwickTree {\n    usize n;\n    std::vector< T > tree;\n\n   \
    \ T sum(usize k) const {\n      T result{};\n      while (k > 0) {\n        result\
    \ += tree[k];\n        k -= k & -k;\n      }\n      return result;\n    }\n\n\
    \   public:\n    FenwickTree() = default;\n    explicit FenwickTree(usize n):\
    \ n(n), tree(n + 1, T()) {}\n\n    explicit FenwickTree(const std::vector< T >\
    \ &as) : n(as.size()), tree(n + 1, T()) {\n      std::copy(as.begin(), as.end(),\
    \ tree.begin() + 1);\n\n      for (usize i = 1; i <= n; i++) {\n        usize\
    \ j = i + (i & -i);\n        if (j <= n) {\n          tree[j] += tree[i];\n  \
    \      }\n      }\n    }\n\n    void add(usize k, const T &v) {\n      assert(0\
    \ <= k and k < n);\n\n      k++;\n      while (k <= n) {\n        tree[k] += v;\n\
    \        k += k & -k;\n      }\n    }\n\n    T sum(usize l, usize r) const {\n\
    \      assert(0 <= l and l <= r and r <= n);\n      return sum(r) - sum(l);\n\
    \    }\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \nnamespace luz {\n\n  template < typename T >\n  class FenwickTree {\n    usize\
    \ n;\n    std::vector< T > tree;\n\n    T sum(usize k) const {\n      T result{};\n\
    \      while (k > 0) {\n        result += tree[k];\n        k -= k & -k;\n   \
    \   }\n      return result;\n    }\n\n   public:\n    FenwickTree() = default;\n\
    \    explicit FenwickTree(usize n): n(n), tree(n + 1, T()) {}\n\n    explicit\
    \ FenwickTree(const std::vector< T > &as) : n(as.size()), tree(n + 1, T()) {\n\
    \      std::copy(as.begin(), as.end(), tree.begin() + 1);\n\n      for (usize\
    \ i = 1; i <= n; i++) {\n        usize j = i + (i & -i);\n        if (j <= n)\
    \ {\n          tree[j] += tree[i];\n        }\n      }\n    }\n\n    void add(usize\
    \ k, const T &v) {\n      assert(0 <= k and k < n);\n\n      k++;\n      while\
    \ (k <= n) {\n        tree[k] += v;\n        k += k & -k;\n      }\n    }\n\n\
    \    T sum(usize l, usize r) const {\n      assert(0 <= l and l <= r and r <=\
    \ n);\n      return sum(r) - sum(l);\n    }\n  };\n\n} // namespace luz\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/fenwick-tree.hpp
  requiredBy: []
  timestamp: '2023-06-20 08:03:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl_2_b/fenwick-tree.test.cpp
documentation_of: src/data-structure/fenwick-tree.hpp
layout: document
redirect_from:
- /library/src/data-structure/fenwick-tree.hpp
- /library/src/data-structure/fenwick-tree.hpp.html
title: src/data-structure/fenwick-tree.hpp
---
