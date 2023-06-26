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
    path: src/graph/flow/min-cost-f-flow.hpp
    title: src/graph/flow/min-cost-f-flow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B
  bundledCode: "#line 1 \"test/aoj/grl_6_b.test.cpp\"\n// verification-helper: PROBLEM\
    \ https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace luz {\n\n  using i32 = std::int32_t;\n  using\
    \ i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n}\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n}\n#line 2 \"src/graph/flow/min-cost-f-flow.hpp\"\n\n#line 4 \"src/graph/flow/min-cost-f-flow.hpp\"\
    \n\n#include <algorithm>\n#include <queue>\n#include <vector>\n#include <limits>\n\
    #include <functional>\n\nnamespace luz {\n\n  // O(FE \\log(V))\n  // [note]:\
    \ cost_t must be signed type\n  template< typename flow_t, typename cost_t >\n\
    \  struct MinCostFFlowGraph {\n\n    template< typename T >\n    using vector\
    \ = std::vector< T >;\n\n    using P = std::pair< cost_t, usize >;\n\n    struct\
    \ edge {\n      usize to;\n      flow_t cap;\n      cost_t cost;\n      usize\
    \ rev;\n      bool isrev;\n    };\n\n    usize n;\n    vector< vector< edge >\
    \ > g;\n    vector< cost_t > potential, min_cost;\n    vector< usize > pvs, pes;\n\
    \n    const cost_t inf;\n\n    MinCostFFlowGraph(usize n) : n(n), g(n), inf(std::numeric_limits<\
    \ cost_t >::max()) {}\n\n    void add_directed_edge(usize from, usize to, flow_t\
    \ cap, cost_t cost) {\n      g[from].emplace_back(edge {to, cap, cost, g[to].size(),\
    \ false});\n      g[to].emplace_back(edge {from, 0, -cost, g[from].size() - 1,\
    \ true});\n    }\n\n    cost_t min_cost_f_flow(usize s, usize t, flow_t f) {\n\
    \      cost_t ret = 0;\n\n      std::priority_queue< P, vector< P >, std::greater<\
    \ P > > que;\n      potential.assign(n, 0);\n      pes.assign(n, -1);\n      pvs.assign(n,\
    \ -1);\n\n      while (f > 0) {\n        min_cost.assign(n, inf);\n\n        que.emplace(0,\
    \ s);\n        min_cost[s] = 0;\n\n        while(!que.empty()) {\n          auto\
    \ [cost, v] = que.top();\n          que.pop();\n\n          if (min_cost[v] <\
    \ cost) continue;\n\n          for (usize i = 0; i < g[v].size(); i++) {\n   \
    \         edge &e = g[v][i];\n            usize u = e.to;\n\n            cost_t\
    \ next_cost = min_cost[v] + e.cost + potential[v] - potential[u];\n\n        \
    \    if (e.cap == 0 or min_cost[u] <= next_cost) {\n              continue;\n\
    \            }\n\n            min_cost[u] = next_cost;\n            pvs[u] = v;\n\
    \            pes[u] = i;\n            que.emplace(min_cost[u], u);\n         \
    \ }\n        }\n\n        if (min_cost[t] == inf) return -1;\n\n        for (usize\
    \ v = 0; v < n; v++) {\n          potential[v] += min_cost[v];\n        }\n\n\
    \        flow_t addflow = f;\n\n        for (usize v = t; v != s; v = pvs[v])\
    \ {\n          addflow = std::min(addflow, g[pvs[v]][pes[v]].cap);\n        }\n\
    \n        f -= addflow;\n        ret += addflow * potential[t];\n\n        for\
    \ (usize v = t; v != s; v = pvs[v]) {\n          edge &e = g[pvs[v]][pes[v]];\n\
    \          e.cap -= addflow;\n          g[v][e.rev].cap += addflow;\n        }\n\
    \      }\n\n      return ret;\n    }\n  };\n\n}\n#line 6 \"test/aoj/grl_6_b.test.cpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    usize n, m,\
    \ f;\n    std::cin >> n >> m >> f;\n\n    MinCostFFlowGraph< u32, i32 > g(n);\n\
    \    while (m--) {\n      usize u, v;\n      u32 cap, cost;\n      std::cin >>\
    \ u >> v >> cap >> cost;\n      g.add_directed_edge(u, v, cap, cost);\n    }\n\
    \n    std::cout << g.min_cost_f_flow(0, n - 1, f) << std::endl;\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B\n\
    \n#include \"src/cpp-template/header/int-alias.hpp\"\n#include \"src/cpp-template/header/size-alias.hpp\"\
    \n#include \"src/graph/flow/min-cost-f-flow.hpp\"\n\n#include <iostream>\n\nnamespace\
    \ luz {\n\n  void main_() {\n    usize n, m, f;\n    std::cin >> n >> m >> f;\n\
    \n    MinCostFFlowGraph< u32, i32 > g(n);\n    while (m--) {\n      usize u, v;\n\
    \      u32 cap, cost;\n      std::cin >> u >> v >> cap >> cost;\n      g.add_directed_edge(u,\
    \ v, cap, cost);\n    }\n\n    std::cout << g.min_cost_f_flow(0, n - 1, f) <<\
    \ std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/graph/flow/min-cost-f-flow.hpp
  isVerificationFile: true
  path: test/aoj/grl_6_b.test.cpp
  requiredBy: []
  timestamp: '2023-06-25 11:08:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl_6_b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl_6_b.test.cpp
- /verify/test/aoj/grl_6_b.test.cpp.html
title: test/aoj/grl_6_b.test.cpp
---
