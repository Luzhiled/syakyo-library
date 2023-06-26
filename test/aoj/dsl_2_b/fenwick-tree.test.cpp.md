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
    path: src/data-structure/fenwick-tree.hpp
    title: src/data-structure/fenwick-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
  bundledCode: "#line 1 \"test/aoj/dsl_2_b/fenwick-tree.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace luz {\n\n  using i32 = std::int32_t;\n  using\
    \ i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n}\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n}\n#line 2 \"src/data-structure/fenwick-tree.hpp\"\n\n#include <algorithm>\n\
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
    \    }\n  };\n\n} // namespace luz\n#line 6 \"test/aoj/dsl_2_b/fenwick-tree.test.cpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    usize n, q;\n\
    \    std::cin >> n >> q;\n\n    FenwickTree< u32 > ft(n);\n    while (q--) {\n\
    \      usize com, x, y;\n      std::cin >> com >> x >> y;\n\n      if (not com)\
    \ {\n        ft.add(x - 1, y);\n      } else {\n        std::cout << ft.sum(x\
    \ - 1, y) << std::endl;\n      }\n    }\n  }\n\n} // namespace luz\n\nint main()\
    \ {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\n\
    \n#include \"src/cpp-template/header/int-alias.hpp\"\n#include \"src/cpp-template/header/size-alias.hpp\"\
    \n#include \"src/data-structure/fenwick-tree.hpp\"\n\n#include <iostream>\n\n\
    namespace luz {\n\n  void main_() {\n    usize n, q;\n    std::cin >> n >> q;\n\
    \n    FenwickTree< u32 > ft(n);\n    while (q--) {\n      usize com, x, y;\n \
    \     std::cin >> com >> x >> y;\n\n      if (not com) {\n        ft.add(x - 1,\
    \ y);\n      } else {\n        std::cout << ft.sum(x - 1, y) << std::endl;\n \
    \     }\n    }\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/data-structure/fenwick-tree.hpp
  isVerificationFile: true
  path: test/aoj/dsl_2_b/fenwick-tree.test.cpp
  requiredBy: []
  timestamp: '2023-06-20 08:03:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl_2_b/fenwick-tree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl_2_b/fenwick-tree.test.cpp
- /verify/test/aoj/dsl_2_b/fenwick-tree.test.cpp.html
title: test/aoj/dsl_2_b/fenwick-tree.test.cpp
---
