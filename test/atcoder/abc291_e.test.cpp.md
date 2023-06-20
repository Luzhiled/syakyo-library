---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: src/cpp-template/header/size-alias.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/class/dynamic-graph.hpp
    title: src/graph/class/dynamic-graph.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/class/edge/edge.hpp
    title: src/graph/class/edge/edge.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/topological-ordering/lexical-order-topological-sort.hpp
    title: src/graph/topological-ordering/lexical-order-topological-sort.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc291/tasks/abc291_e
    links:
    - https://atcoder.jp/contests/abc291/tasks/abc291_e
  bundledCode: "#line 1 \"test/atcoder/abc291_e.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc291/tasks/abc291_e\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n}\n#line 2 \"src/graph/class/edge/edge.hpp\"\n\
    \n#line 4 \"src/graph/class/edge/edge.hpp\"\n\nnamespace luz {\n\n  template <\
    \ typename T >\n  struct Edge {\n    using cost_type = T;\n\n    usize from, to;\n\
    \    T cost;\n    usize id;\n\n    Edge() = default;\n    \n    Edge(usize f,\
    \ usize t, T c, usize i) : from(f), to(t), cost(c), id(i) {}\n  };\n\n} // namespace\
    \ luz\n#line 2 \"src/graph/class/dynamic-graph.hpp\"\n\n#line 4 \"src/graph/class/dynamic-graph.hpp\"\
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
    \ &v) const {\n      return g[v];\n    }\n\n  };\n\n} // namespace luz\n#line\
    \ 2 \"src/graph/topological-ordering/lexical-order-topological-sort.hpp\"\n\n\
    #include <queue>\n#line 5 \"src/graph/topological-ordering/lexical-order-topological-sort.hpp\"\
    \n\n// usage\n// - min: lexical_order_topological_sort< G, std::greater< usize\
    \ > >(g);\n// - max: lexical_order_topological_sort< G, std::less< usize > >(g);\n\
    // !!! it returns {} if G is disconnected or not DAG.\nnamespace luz {\n\n  template\
    \ < class G, class Compare >\n  std::vector< usize > lexical_order_topological_sort(const\
    \ G &g) {\n    usize n = g.size();\n\n    std::vector< usize > indegrees(n);\n\
    \    for (usize v = 0; v < n; v++) {\n      for (auto &&e: g[v]) {\n        indegrees[e.to]++;\n\
    \      }\n    }\n\n    std::priority_queue< usize, std::vector< usize >, Compare\
    \ > pq;\n    for (usize v = 0; v < n; v++) {\n      if (indegrees[v]) continue;\n\
    \      pq.emplace(v);\n    }\n\n    std::vector< usize > result;\n    result.reserve(n);\n\
    \    while (not pq.empty()) {\n      auto v = pq.top();\n      pq.pop();\n\n \
    \     result.emplace_back(v);\n      for (auto &&e: g[v]) {\n        if (--indegrees[e.to])\
    \ continue;\n        pq.emplace(e.to);\n      }\n    }\n\n    if (result.size()\
    \ != n) {\n      return {};\n    }\n\n    return result;\n  }\n\n} // namespace\
    \ luz\n#line 7 \"test/atcoder/abc291_e.test.cpp\"\n\n#include <functional>\n#include\
    \ <iostream>\n\nnamespace luz {\n\n  void main_() {\n    using edge  = Edge< usize\
    \ >;\n    using graph = DynamicGraph< edge >;\n\n    usize n, m;\n    std::cin\
    \ >> n >> m;\n\n    graph g(n);\n    while (m--) {\n      usize t, f;\n      std::cin\
    \ >> t >> f;\n      g.add_directed_edge(t - 1, f - 1);\n    }\n\n    auto ord\
    \ =\n        lexical_order_topological_sort< graph,\n                        \
    \                std::greater< usize > >(g);\n    auto rev =\n        lexical_order_topological_sort<\
    \ graph, std::less< usize > >(\n            g);\n\n    if (ord == rev) {\n   \
    \   std::cout << \"Yes\" << std::endl;\n\n      std::vector< usize > ans(n);\n\
    \      for (usize i = 0; i < n; i++) {\n        ans[ord[i]] = i + 1;\n      }\n\
    \n      for (usize i = 0; i < n; i++) {\n        std::cout << ans[i] << (i + 1\
    \ == n ? '\\n' : ' ');\n      }\n    } else {\n      std::cout << \"No\" << std::endl;\n\
    \    }\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc291/tasks/abc291_e\n\
    \n#include \"src/cpp-template/header/size-alias.hpp\"\n#include \"src/graph/class/edge/edge.hpp\"\
    \n#include \"src/graph/class/dynamic-graph.hpp\"\n#include \"src/graph/topological-ordering/lexical-order-topological-sort.hpp\"\
    \n\n#include <functional>\n#include <iostream>\n\nnamespace luz {\n\n  void main_()\
    \ {\n    using edge  = Edge< usize >;\n    using graph = DynamicGraph< edge >;\n\
    \n    usize n, m;\n    std::cin >> n >> m;\n\n    graph g(n);\n    while (m--)\
    \ {\n      usize t, f;\n      std::cin >> t >> f;\n      g.add_directed_edge(t\
    \ - 1, f - 1);\n    }\n\n    auto ord =\n        lexical_order_topological_sort<\
    \ graph,\n                                        std::greater< usize > >(g);\n\
    \    auto rev =\n        lexical_order_topological_sort< graph, std::less< usize\
    \ > >(\n            g);\n\n    if (ord == rev) {\n      std::cout << \"Yes\" <<\
    \ std::endl;\n\n      std::vector< usize > ans(n);\n      for (usize i = 0; i\
    \ < n; i++) {\n        ans[ord[i]] = i + 1;\n      }\n\n      for (usize i = 0;\
    \ i < n; i++) {\n        std::cout << ans[i] << (i + 1 == n ? '\\n' : ' ');\n\
    \      }\n    } else {\n      std::cout << \"No\" << std::endl;\n    }\n  }\n\n\
    } // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/size-alias.hpp
  - src/graph/class/edge/edge.hpp
  - src/graph/class/dynamic-graph.hpp
  - src/graph/topological-ordering/lexical-order-topological-sort.hpp
  isVerificationFile: true
  path: test/atcoder/abc291_e.test.cpp
  requiredBy: []
  timestamp: '2023-06-20 08:43:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc291_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc291_e.test.cpp
- /verify/test/atcoder/abc291_e.test.cpp.html
title: test/atcoder/abc291_e.test.cpp
---
