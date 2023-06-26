---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: src/cpp-template/header/size-alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_b/dynamic-graph.test.cpp
    title: test/aoj/grl_1_b/dynamic-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc291_e.test.cpp
    title: test/atcoder/abc291_e.test.cpp
  - icon: ':x:'
    path: test/library-checker/scc.test.cpp
    title: test/library-checker/scc.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/class/edge/edge.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n}\n#line 4 \"src/graph/class/edge/edge.hpp\"\n\
    \nnamespace luz {\n\n  template < typename T >\n  struct Edge {\n    using cost_type\
    \ = T;\n\n    usize from, to;\n    T cost;\n    usize id;\n\n    Edge() = default;\n\
    \    \n    Edge(usize f, usize t, T c, usize i) : from(f), to(t), cost(c), id(i)\
    \ {}\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/size-alias.hpp\"\n\nnamespace\
    \ luz {\n\n  template < typename T >\n  struct Edge {\n    using cost_type = T;\n\
    \n    usize from, to;\n    T cost;\n    usize id;\n\n    Edge() = default;\n \
    \   \n    Edge(usize f, usize t, T c, usize i) : from(f), to(t), cost(c), id(i)\
    \ {}\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/graph/class/edge/edge.hpp
  requiredBy: []
  timestamp: '2023-06-20 08:29:17+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/scc.test.cpp
  - test/atcoder/abc291_e.test.cpp
  - test/aoj/grl_1_b/dynamic-graph.test.cpp
documentation_of: src/graph/class/edge/edge.hpp
layout: document
redirect_from:
- /library/src/graph/class/edge/edge.hpp
- /library/src/graph/class/edge/edge.hpp.html
title: src/graph/class/edge/edge.hpp
---
