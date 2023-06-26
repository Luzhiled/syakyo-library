---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: src/cpp-template/header/size-alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_6_a.test.cpp
    title: test/aoj/grl_6_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/flow/max-flow.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n}\n#line 4 \"src/graph/flow/max-flow.hpp\"\n\n\
    #include <algorithm>\n#include <cassert>\n#include <limits>\n#include <queue>\n\
    #include <vector>\n\nnamespace luz {\n\n  template < typename cap_type >\n  class\
    \ MaxFlowGraph {\n    static constexpr cap_type INF =\n        std::numeric_limits<\
    \ cap_type >::max();\n\n    struct Edge {\n      usize to;\n      cap_type cap;\n\
    \      usize rev;\n      Edge() = default;\n      Edge(usize to, cap_type cap,\
    \ usize rev)\n          : to(to),\n            cap(cap),\n            rev(rev)\
    \ {}\n    };\n\n    usize n;\n    std::vector< i32 > min_cost;\n    std::vector<\
    \ usize > iter;\n    std::vector< std::vector< Edge > > g;\n\n    bool build_augment_path(usize\
    \ s, usize t) {\n      min_cost.assign(n, -1);\n      std::queue< usize > que;\n\
    \n      min_cost[s] = 0;\n      que.push(s);\n\n      while (not que.empty() and\
    \ min_cost[t] == -1) {\n        usize v = que.front();\n        que.pop();\n\n\
    \        for (const auto &e: g[v]) {\n          if (e.cap > 0 and min_cost[e.to]\
    \ == -1) {\n            min_cost[e.to] = min_cost[v] + 1;\n            que.push(e.to);\n\
    \          }\n        }\n      }\n\n      return min_cost[t] != -1;\n    }\n\n\
    \    cap_type find_augment_path(usize v, usize t, cap_type flow_limit) {\n   \
    \   if (v == t) return flow_limit;\n\n      for (usize &i = iter[v]; i < g[v].size();\
    \ i++) {\n        Edge &e = g[v][i];\n\n        if (e.cap > 0 and min_cost[v]\
    \ + 1 == min_cost[e.to]) {\n          cap_type d = find_augment_path(e.to, t,\
    \ std::min(flow_limit, e.cap));\n\n          if (d > 0) {\n            e.cap -=\
    \ d;\n            g[e.to][e.rev].cap += d;\n            return d;\n          }\n\
    \        }\n      }\n\n      return 0;\n    }\n\n   public:\n    MaxFlowGraph()\
    \ = default;\n\n    explicit MaxFlowGraph(usize n): n(n), g(n) {}\n\n    void\
    \ add_directed_edge(usize from, usize to, cap_type cap) {\n      assert(from <\
    \ n and to < n and from != to);\n\n      g[from].emplace_back(to, cap, g[to].size());\n\
    \      g[to].emplace_back(from, 0, g[from].size() - 1);\n    }\n\n    inline cap_type\
    \ inf() const {\n      return INF;\n    }\n\n    // 1. O(n^2 m) in general\n \
    \   // 2. other case: see docs \"dinic-time-complexity.pdf\"\n    cap_type max_flow(usize\
    \ s, usize t) {\n      return max_flow(s, t, inf());\n    }\n\n    cap_type max_flow(usize\
    \ s, usize t, cap_type flow_limit) {\n      assert(s < n and t < n and s != t);\n\
    \      cap_type flow = 0, add = 0;\n\n      while (build_augment_path(s, t) and\
    \ flow < flow_limit) {\n        iter.assign(n, 0);\n\n        do {\n         \
    \ add = find_augment_path(s, t, flow_limit - add);\n          flow += add;\n \
    \       } while (add > 0);\n      }\n\n      return flow;\n    }\n  };\n\n} //\
    \ namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/size-alias.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <limits>\n#include <queue>\n#include\
    \ <vector>\n\nnamespace luz {\n\n  template < typename cap_type >\n  class MaxFlowGraph\
    \ {\n    static constexpr cap_type INF =\n        std::numeric_limits< cap_type\
    \ >::max();\n\n    struct Edge {\n      usize to;\n      cap_type cap;\n     \
    \ usize rev;\n      Edge() = default;\n      Edge(usize to, cap_type cap, usize\
    \ rev)\n          : to(to),\n            cap(cap),\n            rev(rev) {}\n\
    \    };\n\n    usize n;\n    std::vector< i32 > min_cost;\n    std::vector< usize\
    \ > iter;\n    std::vector< std::vector< Edge > > g;\n\n    bool build_augment_path(usize\
    \ s, usize t) {\n      min_cost.assign(n, -1);\n      std::queue< usize > que;\n\
    \n      min_cost[s] = 0;\n      que.push(s);\n\n      while (not que.empty() and\
    \ min_cost[t] == -1) {\n        usize v = que.front();\n        que.pop();\n\n\
    \        for (const auto &e: g[v]) {\n          if (e.cap > 0 and min_cost[e.to]\
    \ == -1) {\n            min_cost[e.to] = min_cost[v] + 1;\n            que.push(e.to);\n\
    \          }\n        }\n      }\n\n      return min_cost[t] != -1;\n    }\n\n\
    \    cap_type find_augment_path(usize v, usize t, cap_type flow_limit) {\n   \
    \   if (v == t) return flow_limit;\n\n      for (usize &i = iter[v]; i < g[v].size();\
    \ i++) {\n        Edge &e = g[v][i];\n\n        if (e.cap > 0 and min_cost[v]\
    \ + 1 == min_cost[e.to]) {\n          cap_type d = find_augment_path(e.to, t,\
    \ std::min(flow_limit, e.cap));\n\n          if (d > 0) {\n            e.cap -=\
    \ d;\n            g[e.to][e.rev].cap += d;\n            return d;\n          }\n\
    \        }\n      }\n\n      return 0;\n    }\n\n   public:\n    MaxFlowGraph()\
    \ = default;\n\n    explicit MaxFlowGraph(usize n): n(n), g(n) {}\n\n    void\
    \ add_directed_edge(usize from, usize to, cap_type cap) {\n      assert(from <\
    \ n and to < n and from != to);\n\n      g[from].emplace_back(to, cap, g[to].size());\n\
    \      g[to].emplace_back(from, 0, g[from].size() - 1);\n    }\n\n    inline cap_type\
    \ inf() const {\n      return INF;\n    }\n\n    // 1. O(n^2 m) in general\n \
    \   // 2. other case: see docs \"dinic-time-complexity.pdf\"\n    cap_type max_flow(usize\
    \ s, usize t) {\n      return max_flow(s, t, inf());\n    }\n\n    cap_type max_flow(usize\
    \ s, usize t, cap_type flow_limit) {\n      assert(s < n and t < n and s != t);\n\
    \      cap_type flow = 0, add = 0;\n\n      while (build_augment_path(s, t) and\
    \ flow < flow_limit) {\n        iter.assign(n, 0);\n\n        do {\n         \
    \ add = find_augment_path(s, t, flow_limit - add);\n          flow += add;\n \
    \       } while (add > 0);\n      }\n\n      return flow;\n    }\n  };\n\n} //\
    \ namespace luz\n"
  dependsOn:
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/graph/flow/max-flow.hpp
  requiredBy: []
  timestamp: '2023-06-20 07:27:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl_6_a.test.cpp
documentation_of: src/graph/flow/max-flow.hpp
layout: document
redirect_from:
- /library/src/graph/flow/max-flow.hpp
- /library/src/graph/flow/max-flow.hpp.html
title: src/graph/flow/max-flow.hpp
---
