---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
    path: test/library-checker/scc.test.cpp
    title: test/library-checker/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/class/dynamic-graph.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n}\n#line 4 \"src/graph/class/dynamic-graph.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\nnamespace luz {\n\n  template < typename\
    \ Edge >\n  class DynamicGraph {\n\n    using Edges = std::vector< Edge >;\n\n\
    \   protected:\n    std::vector< Edges > g;\n    usize edge_count;\n\n   public:\n\
    \    using cost_type = typename Edge::cost_type;\n\n    DynamicGraph() = default;\n\
    \    explicit DynamicGraph(usize n): g(n), edge_count(0) {}\n\n    usize size()\
    \ const {\n      return g.size();\n    }\n\n    void add_directed_edge(usize from,\
    \ usize to, cost_type cost = 1) {\n      g[from].emplace_back(from, to, cost,\
    \ edge_count++);\n    }\n\n    void add_undirected_edge(usize u, usize v, cost_type\
    \ cost = 1) {\n      assert(u != v);\n      g[u].emplace_back(u, v, cost, edge_count);\n\
    \      g[v].emplace_back(v, u, cost, edge_count++);\n    }\n\n    Edges operator[](const\
    \ usize &v) {\n      return g[v];\n    }\n\n    const Edges operator[](const usize\
    \ &v) const {\n      return g[v];\n    }\n\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/size-alias.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace luz {\n\n  template < typename Edge\
    \ >\n  class DynamicGraph {\n\n    using Edges = std::vector< Edge >;\n\n   protected:\n\
    \    std::vector< Edges > g;\n    usize edge_count;\n\n   public:\n    using cost_type\
    \ = typename Edge::cost_type;\n\n    DynamicGraph() = default;\n    explicit DynamicGraph(usize\
    \ n): g(n), edge_count(0) {}\n\n    usize size() const {\n      return g.size();\n\
    \    }\n\n    void add_directed_edge(usize from, usize to, cost_type cost = 1)\
    \ {\n      g[from].emplace_back(from, to, cost, edge_count++);\n    }\n\n    void\
    \ add_undirected_edge(usize u, usize v, cost_type cost = 1) {\n      assert(u\
    \ != v);\n      g[u].emplace_back(u, v, cost, edge_count);\n      g[v].emplace_back(v,\
    \ u, cost, edge_count++);\n    }\n\n    Edges operator[](const usize &v) {\n \
    \     return g[v];\n    }\n\n    const Edges operator[](const usize &v) const\
    \ {\n      return g[v];\n    }\n\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/graph/class/dynamic-graph.hpp
  requiredBy: []
  timestamp: '2023-06-20 08:43:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/scc.test.cpp
  - test/atcoder/abc291_e.test.cpp
  - test/aoj/grl_1_b/dynamic-graph.test.cpp
documentation_of: src/graph/class/dynamic-graph.hpp
layout: document
redirect_from:
- /library/src/graph/class/dynamic-graph.hpp
- /library/src/graph/class/dynamic-graph.hpp.html
title: src/graph/class/dynamic-graph.hpp
---
