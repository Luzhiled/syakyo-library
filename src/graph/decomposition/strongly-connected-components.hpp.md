---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/scc.test.cpp
    title: test/library-checker/scc.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/decomposition/strongly-connected-components.hpp\"\
    \n\n#include <vector>\n#include <cstddef>\n\nnamespace luz {\n\n  struct SCCGraph\
    \ {\n    using usize = std::size_t;\n    using graph = std::vector< std::vector<\
    \ usize > >;\n\n    usize n;\n    graph g;\n\n    std::vector< usize > S, B, I;\n\
    \n    void dfs(usize v, graph &scc) {\n      B.emplace_back(I[v] = S.size());\n\
    \      S.emplace_back(v);\n\n      for (auto u: g[v]) {\n        if (not I[u])\
    \ {\n          dfs(u, scc);\n          continue;\n        }\n        while (I[u]\
    \ < B.back()) B.pop_back();\n      }\n\n      if (I[v] != B.back()) return;\n\n\
    \      scc.emplace_back();\n      B.pop_back();\n      while (I[v] < S.size())\
    \ {\n        scc.back().emplace_back(S.back());\n        I[S.back()] = n + scc.size();\n\
    \        S.pop_back();\n      }\n    }\n\n   public:\n    SCCGraph(usize n) :\
    \ n(n), g(n) {}\n\n    void add_directed_edge(usize from, usize to) {\n      g[from].emplace_back(to);\n\
    \    }\n\n    graph get_scc_list() {\n      graph scc;\n      I.assign(n, 0);\n\
    \      S = B = {};\n      for (usize v = 0; v < n; v++) {\n        if (not I[v])\
    \ dfs(v, scc);\n      }\n      return {scc.rbegin(), scc.rend()};\n    }\n\n \
    \ };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include <vector>\n#include <cstddef>\n\nnamespace luz {\n\
    \n  struct SCCGraph {\n    using usize = std::size_t;\n    using graph = std::vector<\
    \ std::vector< usize > >;\n\n    usize n;\n    graph g;\n\n    std::vector< usize\
    \ > S, B, I;\n\n    void dfs(usize v, graph &scc) {\n      B.emplace_back(I[v]\
    \ = S.size());\n      S.emplace_back(v);\n\n      for (auto u: g[v]) {\n     \
    \   if (not I[u]) {\n          dfs(u, scc);\n          continue;\n        }\n\
    \        while (I[u] < B.back()) B.pop_back();\n      }\n\n      if (I[v] != B.back())\
    \ return;\n\n      scc.emplace_back();\n      B.pop_back();\n      while (I[v]\
    \ < S.size()) {\n        scc.back().emplace_back(S.back());\n        I[S.back()]\
    \ = n + scc.size();\n        S.pop_back();\n      }\n    }\n\n   public:\n   \
    \ SCCGraph(usize n) : n(n), g(n) {}\n\n    void add_directed_edge(usize from,\
    \ usize to) {\n      g[from].emplace_back(to);\n    }\n\n    graph get_scc_list()\
    \ {\n      graph scc;\n      I.assign(n, 0);\n      S = B = {};\n      for (usize\
    \ v = 0; v < n; v++) {\n        if (not I[v]) dfs(v, scc);\n      }\n      return\
    \ {scc.rbegin(), scc.rend()};\n    }\n\n  };\n\n} // namespace luz\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/decomposition/strongly-connected-components.hpp
  requiredBy: []
  timestamp: '2023-06-27 00:36:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/scc.test.cpp
documentation_of: src/graph/decomposition/strongly-connected-components.hpp
layout: document
redirect_from:
- /library/src/graph/decomposition/strongly-connected-components.hpp
- /library/src/graph/decomposition/strongly-connected-components.hpp.html
title: src/graph/decomposition/strongly-connected-components.hpp
---
