---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: src/cpp-template/header/size-alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_1_a.test.cpp
    title: test/aoj/dsl_1_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/disjoint-set-union.hpp\"\n\n#line 2 \"\
    src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\nnamespace luz\
    \ {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\n}\n#line\
    \ 4 \"src/data-structure/disjoint-set-union.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace luz {\n\n  class DisjointSetUnion\
    \ {\n    usize n;\n\n    // vals[v] :=\n    //   if v is root node: -1 * component\
    \ size\n    //   otherwise: parent node\n    std::vector< isize > vals;\n\n  \
    \ public:\n    DisjointSetUnion() = default;\n    explicit DisjointSetUnion(usize\
    \ n): n(n), vals(n, -1) {}\n\n    usize leader(usize v) {\n      if (vals[v] <\
    \ 0) return v;\n      return vals[v] = leader(vals[v]);\n    }\n\n    bool same(usize\
    \ u, usize v) {\n      return leader(u) == leader(v);\n    }\n\n    usize merge(usize\
    \ u, usize v) {\n      isize x = leader(u);\n      isize y = leader(v);\n    \
    \  if (x == y) return x;\n\n      if (-vals[x] < -vals[y]) std::swap(x, y);\n\n\
    \      vals[x] += vals[y];\n      vals[y] = x;\n      return x;\n    }\n\n   \
    \ usize group_size(usize v) {\n      return -vals[leader(v)];\n    }\n  };\n\n\
    } // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/size-alias.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace luz {\n\n  class\
    \ DisjointSetUnion {\n    usize n;\n\n    // vals[v] :=\n    //   if v is root\
    \ node: -1 * component size\n    //   otherwise: parent node\n    std::vector<\
    \ isize > vals;\n\n   public:\n    DisjointSetUnion() = default;\n    explicit\
    \ DisjointSetUnion(usize n): n(n), vals(n, -1) {}\n\n    usize leader(usize v)\
    \ {\n      if (vals[v] < 0) return v;\n      return vals[v] = leader(vals[v]);\n\
    \    }\n\n    bool same(usize u, usize v) {\n      return leader(u) == leader(v);\n\
    \    }\n\n    usize merge(usize u, usize v) {\n      isize x = leader(u);\n  \
    \    isize y = leader(v);\n      if (x == y) return x;\n\n      if (-vals[x] <\
    \ -vals[y]) std::swap(x, y);\n\n      vals[x] += vals[y];\n      vals[y] = x;\n\
    \      return x;\n    }\n\n    usize group_size(usize v) {\n      return -vals[leader(v)];\n\
    \    }\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/data-structure/disjoint-set-union.hpp
  requiredBy: []
  timestamp: '2023-06-20 08:00:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl_1_a.test.cpp
documentation_of: src/data-structure/disjoint-set-union.hpp
layout: document
redirect_from:
- /library/src/data-structure/disjoint-set-union.hpp
- /library/src/data-structure/disjoint-set-union.hpp.html
title: src/data-structure/disjoint-set-union.hpp
---
