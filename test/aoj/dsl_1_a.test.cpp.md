---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/int-alias.hpp
    title: src/cpp-template/header/int-alias.hpp
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: src/cpp-template/header/size-alias.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/disjoint-set-union.hpp
    title: src/data-structure/disjoint-set-union.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A
  bundledCode: "#line 1 \"test/aoj/dsl_1_a.test.cpp\"\n// verification-helper: PROBLEM\
    \ https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace luz {\n\n  using i32 = std::int32_t;\n  using\
    \ i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n}\n#line 2 \"src/data-structure/disjoint-set-union.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n}\n#line 4 \"src/data-structure/disjoint-set-union.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace luz\
    \ {\n\n  class DisjointSetUnion {\n    usize n;\n\n    // vals[v] :=\n    // \
    \  if v is root node: -1 * component size\n    //   otherwise: parent node\n \
    \   std::vector< isize > vals;\n\n   public:\n    DisjointSetUnion() = default;\n\
    \    explicit DisjointSetUnion(usize n): n(n), vals(n, -1) {}\n\n    usize leader(usize\
    \ v) {\n      if (vals[v] < 0) return v;\n      return vals[v] = leader(vals[v]);\n\
    \    }\n\n    bool same(usize u, usize v) {\n      return leader(u) == leader(v);\n\
    \    }\n\n    usize merge(usize u, usize v) {\n      isize x = leader(u);\n  \
    \    isize y = leader(v);\n      if (x == y) return x;\n\n      if (-vals[x] <\
    \ -vals[y]) std::swap(x, y);\n\n      vals[x] += vals[y];\n      vals[y] = x;\n\
    \      return x;\n    }\n\n    usize group_size(usize v) {\n      return -vals[leader(v)];\n\
    \    }\n  };\n\n} // namespace luz\n#line 5 \"test/aoj/dsl_1_a.test.cpp\"\n\n\
    #include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    usize n, q;\n\
    \    std::cin >> n >> q;\n\n    DisjointSetUnion d(n);\n    while (q--) {\n  \
    \    usize com, x, y;\n      std::cin >> com >> x >> y;\n\n      if (not com)\
    \ {\n        d.merge(x, y);\n      } else {\n        std::cout << (d.same(x, y))\
    \ << std::endl;\n      }\n    }\n  }\n\n} // namespace luz\n\nint main() {\n \
    \ luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A\n\
    \n#include \"src/cpp-template/header/int-alias.hpp\"\n#include \"src/data-structure/disjoint-set-union.hpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    usize n, q;\n\
    \    std::cin >> n >> q;\n\n    DisjointSetUnion d(n);\n    while (q--) {\n  \
    \    usize com, x, y;\n      std::cin >> com >> x >> y;\n\n      if (not com)\
    \ {\n        d.merge(x, y);\n      } else {\n        std::cout << (d.same(x, y))\
    \ << std::endl;\n      }\n    }\n  }\n\n} // namespace luz\n\nint main() {\n \
    \ luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  - src/data-structure/disjoint-set-union.hpp
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: true
  path: test/aoj/dsl_1_a.test.cpp
  requiredBy: []
  timestamp: '2023-06-20 08:00:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl_1_a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl_1_a.test.cpp
- /verify/test/aoj/dsl_1_a.test.cpp.html
title: test/aoj/dsl_1_a.test.cpp
---
