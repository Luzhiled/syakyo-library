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
    path: src/graph/class/dynamic-graph.hpp
    title: src/graph/class/dynamic-graph.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/class/edge/edge.hpp
    title: src/graph/class/edge/edge.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/single-source-shortest-path/in-weighted-graph.hpp
    title: src/graph/single-source-shortest-path/in-weighted-graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
  bundledCode: "#line 1 \"test/aoj/grl_1_b/dynamic-graph.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace luz {\n\n  using i32 = std::int32_t;\n  using\
    \ i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n}\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n}\n#line 2 \"src/graph/class/edge/edge.hpp\"\n\n#line 4 \"src/graph/class/edge/edge.hpp\"\
    \n\nnamespace luz {\n\n  template < typename T >\n  struct Edge {\n    using cost_type\
    \ = T;\n\n    usize from, to;\n    T cost;\n    usize id;\n\n    Edge() = default;\n\
    \    \n    Edge(usize f, usize t, T c, usize i) : from(f), to(t), cost(c), id(i)\
    \ {}\n  };\n\n} // namespace luz\n#line 2 \"src/graph/class/dynamic-graph.hpp\"\
    \n\n#line 4 \"src/graph/class/dynamic-graph.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace luz {\n\n  template < typename Edge >\n  class DynamicGraph\
    \ {\n\n    using Edges = std::vector< Edge >;\n\n   protected:\n    std::vector<\
    \ Edges > g;\n    usize edge_count;\n\n   public:\n    using cost_type = typename\
    \ Edge::cost_type;\n\n    DynamicGraph() = default;\n    explicit DynamicGraph(usize\
    \ n): g(n), edge_count(0) {}\n\n    usize size() const {\n      return g.size();\n\
    \    }\n\n    void add_directed_edge(usize from, usize to, cost_type cost = 1)\
    \ {\n      g[from].emplace_back(from, to, cost, edge_count++);\n    }\n\n    void\
    \ add_undirected_edge(usize u, usize v, cost_type cost = 1) {\n      assert(u\
    \ != v);\n      g[u].emplace_back(u, v, cost, edge_count);\n      g[v].emplace_back(v,\
    \ u, cost, edge_count++);\n    }\n\n    Edges operator[](const usize &v) {\n \
    \     return g[v];\n    }\n\n    const Edges operator[](const usize &v) const\
    \ {\n      return g[v];\n    }\n\n  };\n\n} // namespace luz\n#line 2 \"src/graph/single-source-shortest-path/in-weighted-graph.hpp\"\
    \n\n#line 4 \"src/graph/single-source-shortest-path/in-weighted-graph.hpp\"\n\n\
    #include <limits>\n#include <queue>\n#line 8 \"src/graph/single-source-shortest-path/in-weighted-graph.hpp\"\
    \n\nnamespace luz::sssp {\n\n  template < class G >\n  class InWeightedGraph {\n\
    \    using cost_type = typename G::cost_type;\n    using graph     = G;\n\n  \
    \  graph g;\n    usize n;\n\n    std::vector< cost_type > ds;\n    std::vector<\
    \ usize > parents, ids;\n\n    // O(nm)\n    void spfa(usize s) {\n      std::queue<\
    \ usize > que;\n      std::vector< usize > ds_update_cnt(n);\n      std::vector<\
    \ bool > in_que(n);\n\n      ds[s]            = 0;\n      in_que[s]        = true;\n\
    \      ds_update_cnt[s] = 0;\n      que.emplace(s);\n\n      while (not que.empty())\
    \ {\n        usize v = que.front();\n        que.pop();\n        in_que[v] = false;\n\
    \n        for (const auto &e: g[v]) {\n          usize u        = e.to;\n    \
    \      cost_type cost = e.cost;\n          if (ds[v] + cost >= ds[u]) {\n    \
    \        continue;\n          }\n\n          ds[u]      = ds[v] + cost;\n    \
    \      parents[u] = v;\n          ids[u]     = e.id;\n\n          if (in_que[u])\
    \ {\n            continue;\n          }\n\n          in_que[u] = true;\n     \
    \     ds_update_cnt[u]++;\n\n          if (ds_update_cnt[u] < 2 * n) {\n     \
    \       que.emplace(u);\n          }\n        }\n      }\n\n      for (usize v\
    \ = 0; v < n; v++) {\n        if (ds_update_cnt[v] >= n) {\n          ds[v]  \
    \    = negative_inf;\n          parents[v] = undefined;\n          ids[v]    \
    \ = undefined;\n        }\n      }\n    }\n\n   public:\n    static constexpr\
    \ cost_type inf = std::numeric_limits< cost_type >::max();\n    static constexpr\
    \ cost_type negative_inf = std::numeric_limits< cost_type >::min();\n    static\
    \ constexpr usize undefined = std::numeric_limits< usize >::max();\n\n    explicit\
    \ InWeightedGraph(const graph &g, usize s)\n        : g(g),\n          n(g.size()),\n\
    \          ds(n, inf),\n          parents(n, undefined),\n          ids(n, undefined)\
    \ {\n      spfa(s);\n    }\n\n    inline cost_type distance(const usize v) const\
    \ {\n      return ds[v];\n    }\n\n    inline usize parent(const usize v) const\
    \ {\n      return parents[v];\n    }\n\n    inline usize edge_label(const usize\
    \ v) const {\n      return ids[v];\n    }\n\n  };\n\n} // namespace luz::sssp\n\
    #line 8 \"test/aoj/grl_1_b/dynamic-graph.test.cpp\"\n\n#include <iostream>\n\n\
    namespace luz {\n\n  void main_() {\n    usize n, m, source;\n    std::cin >>\
    \ n >> m >> source;\n\n    using edge  = Edge< i32 >;\n    using graph = DynamicGraph<\
    \ edge >;\n\n    graph g(n);\n    while (m--) {\n      usize s, t;\n      i32\
    \ d;\n\n      std::cin >> s >> t >> d;\n      g.add_directed_edge(s, t, d);\n\
    \    }\n\n    sssp::InWeightedGraph< graph > solver(g, source);\n    for (usize\
    \ v = 0; v < n; v++) {\n      if (solver.distance(v) == solver.negative_inf) {\n\
    \        std::cout << \"NEGATIVE CYCLE\" << std::endl;\n        return;\n    \
    \  }\n    }\n\n    for (usize v = 0; v < n; v++) {\n      if (solver.distance(v)\
    \ == solver.inf) {\n        std::cout << \"INF\" << std::endl;\n      } else {\n\
    \        std::cout << solver.distance(v) << std::endl;\n      }\n    }\n  }\n\n\
    } // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B\n\
    \n#include \"src/cpp-template/header/int-alias.hpp\"\n#include \"src/cpp-template/header/size-alias.hpp\"\
    \n#include \"src/graph/class/edge/edge.hpp\"\n#include \"src/graph/class/dynamic-graph.hpp\"\
    \n#include \"src/graph/single-source-shortest-path/in-weighted-graph.hpp\"\n\n\
    #include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    usize n, m, source;\n\
    \    std::cin >> n >> m >> source;\n\n    using edge  = Edge< i32 >;\n    using\
    \ graph = DynamicGraph< edge >;\n\n    graph g(n);\n    while (m--) {\n      usize\
    \ s, t;\n      i32 d;\n\n      std::cin >> s >> t >> d;\n      g.add_directed_edge(s,\
    \ t, d);\n    }\n\n    sssp::InWeightedGraph< graph > solver(g, source);\n   \
    \ for (usize v = 0; v < n; v++) {\n      if (solver.distance(v) == solver.negative_inf)\
    \ {\n        std::cout << \"NEGATIVE CYCLE\" << std::endl;\n        return;\n\
    \      }\n    }\n\n    for (usize v = 0; v < n; v++) {\n      if (solver.distance(v)\
    \ == solver.inf) {\n        std::cout << \"INF\" << std::endl;\n      } else {\n\
    \        std::cout << solver.distance(v) << std::endl;\n      }\n    }\n  }\n\n\
    } // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/graph/class/edge/edge.hpp
  - src/graph/class/dynamic-graph.hpp
  - src/graph/single-source-shortest-path/in-weighted-graph.hpp
  isVerificationFile: true
  path: test/aoj/grl_1_b/dynamic-graph.test.cpp
  requiredBy: []
  timestamp: '2023-06-20 08:43:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl_1_b/dynamic-graph.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl_1_b/dynamic-graph.test.cpp
- /verify/test/aoj/grl_1_b/dynamic-graph.test.cpp.html
title: test/aoj/grl_1_b/dynamic-graph.test.cpp
---
