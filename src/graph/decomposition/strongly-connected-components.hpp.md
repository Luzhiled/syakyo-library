---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: src/cpp-template/header/size-alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/scc.test.cpp
    title: test/library-checker/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/decomposition/strongly-connected-components.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n}\n#line 4 \"src/graph/decomposition/strongly-connected-components.hpp\"\n\n\
    #include <vector>\n\nnamespace luz {\n\n  template < class G >\n  class StronglyConnectedComponents\
    \ {\n    using graph     = G;\n    using cost_type = typename graph::cost_type;\n\
    \n    using groups_type = std::vector< std::vector< usize > >;\n\n    graph g;\n\
    \    usize n;\n\n    std::vector< usize > low, ord, visited, group_id;\n\n   \
    \ usize ord_cnt, group_cnt;\n\n    void dfs(usize v) {\n      low[v] = ord[v]\
    \ = ord_cnt++;\n      visited.emplace_back(v);\n\n      for (auto &e: g[v]) {\n\
    \        if (ord[e.to] == n) {\n          dfs(e.to);\n          low[v] = std::min(low[v],\
    \ low[e.to]);\n        } else {\n          low[v] = std::min(low[v], ord[e.to]);\n\
    \        }\n      }\n\n      if (low[v] != ord[v]) return;\n\n      while (true)\
    \ {\n        usize u = visited.back();\n        visited.pop_back();\n\n      \
    \  ord[u]      = n + 1;\n        group_id[u] = group_cnt;\n\n        if (u ==\
    \ v) break;\n      }\n\n      group_cnt++;\n    }\n\n   public:\n    explicit\
    \ StronglyConnectedComponents(const graph& g_)\n        : g(g_), n(g.size()),\
    \ low(n), ord(n, n), group_id(n), ord_cnt(0), group_cnt(0) {\n      visited.reserve(n);\n\
    \n      for (usize v = 0; v < n; v++) {\n        if (ord[v] != n) continue;\n\
    \        dfs(v);\n      }\n\n      for (auto &id: group_id) {\n        id = group_cnt\
    \ - id - 1;\n      }\n    }\n\n    groups_type groups() const {\n      std::vector<\
    \ usize > counts(group_cnt);\n      for (usize i = 0; i < n; i++) {\n        counts[group_id[i]]++;\n\
    \      }\n\n      groups_type groups(group_cnt);\n      for (usize i = 0; i <\
    \ group_cnt; i++) {\n        groups[i].reserve(counts[i]);\n      }\n\n      for\
    \ (usize i = 0; i < n; i++) {\n        groups[group_id[i]].emplace_back(i);\n\
    \      }\n\n      return groups;\n    }\n\n    std::vector< usize > group_ids()\
    \ const {\n      return group_id;\n    }\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/size-alias.hpp\"\n\n#include\
    \ <vector>\n\nnamespace luz {\n\n  template < class G >\n  class StronglyConnectedComponents\
    \ {\n    using graph     = G;\n    using cost_type = typename graph::cost_type;\n\
    \n    using groups_type = std::vector< std::vector< usize > >;\n\n    graph g;\n\
    \    usize n;\n\n    std::vector< usize > low, ord, visited, group_id;\n\n   \
    \ usize ord_cnt, group_cnt;\n\n    void dfs(usize v) {\n      low[v] = ord[v]\
    \ = ord_cnt++;\n      visited.emplace_back(v);\n\n      for (auto &e: g[v]) {\n\
    \        if (ord[e.to] == n) {\n          dfs(e.to);\n          low[v] = std::min(low[v],\
    \ low[e.to]);\n        } else {\n          low[v] = std::min(low[v], ord[e.to]);\n\
    \        }\n      }\n\n      if (low[v] != ord[v]) return;\n\n      while (true)\
    \ {\n        usize u = visited.back();\n        visited.pop_back();\n\n      \
    \  ord[u]      = n + 1;\n        group_id[u] = group_cnt;\n\n        if (u ==\
    \ v) break;\n      }\n\n      group_cnt++;\n    }\n\n   public:\n    explicit\
    \ StronglyConnectedComponents(const graph& g_)\n        : g(g_), n(g.size()),\
    \ low(n), ord(n, n), group_id(n), ord_cnt(0), group_cnt(0) {\n      visited.reserve(n);\n\
    \n      for (usize v = 0; v < n; v++) {\n        if (ord[v] != n) continue;\n\
    \        dfs(v);\n      }\n\n      for (auto &id: group_id) {\n        id = group_cnt\
    \ - id - 1;\n      }\n    }\n\n    groups_type groups() const {\n      std::vector<\
    \ usize > counts(group_cnt);\n      for (usize i = 0; i < n; i++) {\n        counts[group_id[i]]++;\n\
    \      }\n\n      groups_type groups(group_cnt);\n      for (usize i = 0; i <\
    \ group_cnt; i++) {\n        groups[i].reserve(counts[i]);\n      }\n\n      for\
    \ (usize i = 0; i < n; i++) {\n        groups[group_id[i]].emplace_back(i);\n\
    \      }\n\n      return groups;\n    }\n\n    std::vector< usize > group_ids()\
    \ const {\n      return group_id;\n    }\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/graph/decomposition/strongly-connected-components.hpp
  requiredBy: []
  timestamp: '2023-06-20 08:29:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/scc.test.cpp
documentation_of: src/graph/decomposition/strongly-connected-components.hpp
layout: document
redirect_from:
- /library/src/graph/decomposition/strongly-connected-components.hpp
- /library/src/graph/decomposition/strongly-connected-components.hpp.html
title: src/graph/decomposition/strongly-connected-components.hpp
---
