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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/single-source-shortest-path/in-weighted-graph.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n}\n#line 4 \"src/graph/single-source-shortest-path/in-weighted-graph.hpp\"\n\
    \n#include <limits>\n#include <queue>\n#include <vector>\n\nnamespace luz::sssp\
    \ {\n\n  template < class G >\n  class InWeightedGraph {\n    using cost_type\
    \ = typename G::cost_type;\n    using graph     = G;\n\n    graph g;\n    usize\
    \ n;\n\n    std::vector< cost_type > ds;\n    std::vector< usize > parents, ids;\n\
    \n    // O(nm)\n    void spfa(usize s) {\n      std::queue< usize > que;\n   \
    \   std::vector< usize > ds_update_cnt(n);\n      std::vector< bool > in_que(n);\n\
    \n      ds[s]            = 0;\n      in_que[s]        = true;\n      ds_update_cnt[s]\
    \ = 0;\n      que.emplace(s);\n\n      while (not que.empty()) {\n        usize\
    \ v = que.front();\n        que.pop();\n        in_que[v] = false;\n\n       \
    \ for (const auto &e: g[v]) {\n          usize u        = e.to;\n          cost_type\
    \ cost = e.cost;\n          if (ds[v] + cost >= ds[u]) {\n            continue;\n\
    \          }\n\n          ds[u]      = ds[v] + cost;\n          parents[u] = v;\n\
    \          ids[u]     = e.id;\n\n          if (in_que[u]) {\n            continue;\n\
    \          }\n\n          in_que[u] = true;\n          ds_update_cnt[u]++;\n\n\
    \          if (ds_update_cnt[u] < 2 * n) {\n            que.emplace(u);\n    \
    \      }\n        }\n      }\n\n      for (usize v = 0; v < n; v++) {\n      \
    \  if (ds_update_cnt[v] >= n) {\n          ds[v]      = negative_inf;\n      \
    \    parents[v] = undefined;\n          ids[v]     = undefined;\n        }\n \
    \     }\n    }\n\n   public:\n    static constexpr cost_type inf = std::numeric_limits<\
    \ cost_type >::max();\n    static constexpr cost_type negative_inf = std::numeric_limits<\
    \ cost_type >::min();\n    static constexpr usize undefined = std::numeric_limits<\
    \ usize >::max();\n\n    explicit InWeightedGraph(const graph &g, usize s)\n \
    \       : g(g),\n          n(g.size()),\n          ds(n, inf),\n          parents(n,\
    \ undefined),\n          ids(n, undefined) {\n      spfa(s);\n    }\n\n    inline\
    \ cost_type distance(const usize v) const {\n      return ds[v];\n    }\n\n  \
    \  inline usize parent(const usize v) const {\n      return parents[v];\n    }\n\
    \n    inline usize edge_label(const usize v) const {\n      return ids[v];\n \
    \   }\n\n  };\n\n} // namespace luz::sssp\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/size-alias.hpp\"\n\n#include\
    \ <limits>\n#include <queue>\n#include <vector>\n\nnamespace luz::sssp {\n\n \
    \ template < class G >\n  class InWeightedGraph {\n    using cost_type = typename\
    \ G::cost_type;\n    using graph     = G;\n\n    graph g;\n    usize n;\n\n  \
    \  std::vector< cost_type > ds;\n    std::vector< usize > parents, ids;\n\n  \
    \  // O(nm)\n    void spfa(usize s) {\n      std::queue< usize > que;\n      std::vector<\
    \ usize > ds_update_cnt(n);\n      std::vector< bool > in_que(n);\n\n      ds[s]\
    \            = 0;\n      in_que[s]        = true;\n      ds_update_cnt[s] = 0;\n\
    \      que.emplace(s);\n\n      while (not que.empty()) {\n        usize v = que.front();\n\
    \        que.pop();\n        in_que[v] = false;\n\n        for (const auto &e:\
    \ g[v]) {\n          usize u        = e.to;\n          cost_type cost = e.cost;\n\
    \          if (ds[v] + cost >= ds[u]) {\n            continue;\n          }\n\n\
    \          ds[u]      = ds[v] + cost;\n          parents[u] = v;\n          ids[u]\
    \     = e.id;\n\n          if (in_que[u]) {\n            continue;\n         \
    \ }\n\n          in_que[u] = true;\n          ds_update_cnt[u]++;\n\n        \
    \  if (ds_update_cnt[u] < 2 * n) {\n            que.emplace(u);\n          }\n\
    \        }\n      }\n\n      for (usize v = 0; v < n; v++) {\n        if (ds_update_cnt[v]\
    \ >= n) {\n          ds[v]      = negative_inf;\n          parents[v] = undefined;\n\
    \          ids[v]     = undefined;\n        }\n      }\n    }\n\n   public:\n\
    \    static constexpr cost_type inf = std::numeric_limits< cost_type >::max();\n\
    \    static constexpr cost_type negative_inf = std::numeric_limits< cost_type\
    \ >::min();\n    static constexpr usize undefined = std::numeric_limits< usize\
    \ >::max();\n\n    explicit InWeightedGraph(const graph &g, usize s)\n       \
    \ : g(g),\n          n(g.size()),\n          ds(n, inf),\n          parents(n,\
    \ undefined),\n          ids(n, undefined) {\n      spfa(s);\n    }\n\n    inline\
    \ cost_type distance(const usize v) const {\n      return ds[v];\n    }\n\n  \
    \  inline usize parent(const usize v) const {\n      return parents[v];\n    }\n\
    \n    inline usize edge_label(const usize v) const {\n      return ids[v];\n \
    \   }\n\n  };\n\n} // namespace luz::sssp\n"
  dependsOn:
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/graph/single-source-shortest-path/in-weighted-graph.hpp
  requiredBy: []
  timestamp: '2023-06-20 07:35:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl_1_b/dynamic-graph.test.cpp
documentation_of: src/graph/single-source-shortest-path/in-weighted-graph.hpp
layout: document
redirect_from:
- /library/src/graph/single-source-shortest-path/in-weighted-graph.hpp
- /library/src/graph/single-source-shortest-path/in-weighted-graph.hpp.html
title: src/graph/single-source-shortest-path/in-weighted-graph.hpp
---
