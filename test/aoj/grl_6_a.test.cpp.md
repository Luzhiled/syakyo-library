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
    path: src/graph/flow/max-flow.hpp
    title: src/graph/flow/max-flow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
  bundledCode: "#line 1 \"test/aoj/grl_6_a.test.cpp\"\n// verification-helper: PROBLEM\
    \ https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace luz {\n\n  using i32 = std::int32_t;\n  using\
    \ i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n}\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n}\n#line 2 \"src/graph/flow/max-flow.hpp\"\n\n#include <algorithm>\n#include\
    \ <limits>\n#include <queue>\n#include <vector>\n\nnamespace luz {\n\n  class\
    \ MaxFlowGraph {\n    using usize = std::size_t;\n    using Cap = long long;\n\
    \n    struct Edge {\n      usize to, rev;\n      Cap cap;\n    };\n\n    usize\
    \ n;\n    std::vector< Cap > min_cost;\n    std::vector< usize > iter;\n    std::vector<\
    \ std::vector< Edge > > g;\n\n    bool build_augment_path(usize s, usize t) {\n\
    \      min_cost.assign(n, -1);\n      std::queue< usize > que;\n\n      min_cost[s]\
    \ = 0;\n      que.push(s);\n\n      while (not que.empty() and min_cost[t] ==\
    \ -1) {\n        usize v = que.front();\n        que.pop();\n\n        for (const\
    \ auto &e: g[v]) {\n          if (e.cap > 0 and min_cost[e.to] == -1) {\n    \
    \        min_cost[e.to] = min_cost[v] + 1;\n            que.push(e.to);\n    \
    \      }\n        }\n      }\n\n      return min_cost[t] != -1;\n    }\n\n   \
    \ Cap find_augment_path(usize v, usize t, Cap flow_limit) {\n      if (v == t)\
    \ return flow_limit;\n\n      for (usize &i = iter[v]; i < g[v].size(); i++) {\n\
    \        Edge &e = g[v][i];\n\n        if (e.cap > 0 and min_cost[v] + 1 == min_cost[e.to])\
    \ {\n          Cap d = find_augment_path(e.to, t, std::min(flow_limit, e.cap));\n\
    \n          if (d > 0) {\n            e.cap -= d;\n            g[e.to][e.rev].cap\
    \ += d;\n            return d;\n          }\n        }\n      }\n\n      return\
    \ 0;\n    }\n\n   public:\n    const Cap INF = std::numeric_limits< Cap >::max();\n\
    \n    explicit MaxFlowGraph(usize n): n(n), g(n) {}\n\n    usize add_directed_edge(usize\
    \ from, usize to, Cap cap) {\n      // assert(from < n and to < n and from !=\
    \ to);\n      usize idx = g[from].size();\n      g[from].emplace_back(Edge { to,\
    \ g[to].size(), cap });\n      g[to].emplace_back(Edge { from, idx, 0 });\n  \
    \    return idx;\n    }\n\n    // 1. O(n^2 m) in general\n    // 2. other case:\
    \ see docs \"dinic-time-complexity.pdf\"\n    Cap max_flow(usize s, usize t, Cap\
    \ flow_limit) {\n      // assert(s < n and t < n and s != t);\n      Cap flow\
    \ = 0, add = 0;\n\n      while (build_augment_path(s, t) and flow < flow_limit)\
    \ {\n        iter.assign(n, 0);\n\n        do {\n          add = find_augment_path(s,\
    \ t, flow_limit - add);\n          flow += add;\n        } while (add > 0);\n\
    \      }\n\n      return flow;\n    }\n\n    Cap max_flow(usize s, usize t) {\n\
    \      return max_flow(s, t, INF);\n    }\n\n    // === no need to implement from\
    \ here ===\n    // to use F += link(s, t, ...)\n    Cap link(usize s, usize t,\
    \ usize from, usize idx, Cap f){\n      g[from][idx].cap += f;\n      return max_flow(s,\
    \ t, f);\n    }\n\n    // to use F += cut(s, t, ...)\n    Cap cut(usize s, usize\
    \ t, usize from, usize idx){\n      auto &e = g[from][idx];\n      usize to =\
    \ e.to;\n      Cap rem = g[to][e.rev].cap;\n\n      if(rem == 0) return e.cap\
    \ = 0;\n      e.cap = g[to][e.rev].cap = 0;\n\n      Cap cap = rem - max_flow(from,\
    \ to, rem);\n      if (from != s and cap != 0) max_flow(from, s, cap);\n     \
    \ if (t != to and cap != 0) max_flow(t, to, cap);\n      return -cap;\n    }\n\
    \n  };\n\n} // namespace luz\n#line 6 \"test/aoj/grl_6_a.test.cpp\"\n\n#include\
    \ <iostream>\n\nnamespace luz {\n\n  void main_() {\n    usize n, m;\n    std::cin\
    \ >> n >> m;\n\n    MaxFlowGraph g(n);\n    while (m--) {\n      usize u, v;\n\
    \      u32 c;\n      std::cin >> u >> v >> c;\n      g.add_directed_edge(u, v,\
    \ c);\n    }\n    std::cout << g.max_flow(0, n - 1) << std::endl;\n  }\n\n} //\
    \ namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\n\
    \n#include \"src/cpp-template/header/int-alias.hpp\"\n#include \"src/cpp-template/header/size-alias.hpp\"\
    \n#include \"src/graph/flow/max-flow.hpp\"\n\n#include <iostream>\n\nnamespace\
    \ luz {\n\n  void main_() {\n    usize n, m;\n    std::cin >> n >> m;\n\n    MaxFlowGraph\
    \ g(n);\n    while (m--) {\n      usize u, v;\n      u32 c;\n      std::cin >>\
    \ u >> v >> c;\n      g.add_directed_edge(u, v, c);\n    }\n    std::cout << g.max_flow(0,\
    \ n - 1) << std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n\
    }\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/graph/flow/max-flow.hpp
  isVerificationFile: true
  path: test/aoj/grl_6_a.test.cpp
  requiredBy: []
  timestamp: '2023-07-03 12:42:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl_6_a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl_6_a.test.cpp
- /verify/test/aoj/grl_6_a.test.cpp.html
title: test/aoj/grl_6_a.test.cpp
---
