---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/int-alias.hpp
    title: src/cpp-template/header/int-alias.hpp
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: src/cpp-template/header/size-alias.hpp
  - icon: ':question:'
    path: src/graph/class/dynamic-graph.hpp
    title: src/graph/class/dynamic-graph.hpp
  - icon: ':question:'
    path: src/graph/class/edge/edge.hpp
    title: src/graph/class/edge/edge.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/decomposition/strongly-connected-components.hpp
    title: src/graph/decomposition/strongly-connected-components.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/library-checker/scc.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/scc\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
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
    \ {\n      return g[v];\n    }\n\n  };\n\n} // namespace luz\n#line 2 \"src/graph/decomposition/strongly-connected-components.hpp\"\
    \n\n#line 4 \"src/graph/decomposition/strongly-connected-components.hpp\"\n\n\
    #line 6 \"src/graph/decomposition/strongly-connected-components.hpp\"\n\nnamespace\
    \ luz {\n\n  template < class G >\n  class StronglyConnectedComponents {\n   \
    \ using graph     = G;\n    using cost_type = typename graph::cost_type;\n\n \
    \   using groups_type = std::vector< std::vector< usize > >;\n\n    graph g;\n\
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
    \ const {\n      return group_id;\n    }\n  };\n\n} // namespace luz\n#line 8\
    \ \"test/library-checker/scc.test.cpp\"\n\n#include <iostream>\n#line 11 \"test/library-checker/scc.test.cpp\"\
    \n\nnamespace luz {\n\n  void main_() {\n    using edge  = Edge< i32 >;\n    using\
    \ graph = DynamicGraph< edge >;\n\n    usize n, m;\n    std::cin >> n >> m;\n\
    \    graph g(n);\n\n    while (m--) {\n      usize u, v;\n      std::cin >> u\
    \ >> v;\n      g.add_directed_edge(u, v);\n    }\n\n    StronglyConnectedComponents<graph>\
    \ scc(g);\n\n    auto groups = scc.groups();\n    std::cout << groups.size() <<\
    \ std::endl;\n\n    for (auto& group: groups) {\n      std::cout << group.size()\
    \ << \" \";\n      for (auto &v: group) {\n        std::cout << v << \" \";\n\
    \      }\n      std::cout << std::endl;\n    }\n  }\n\n} // namespace luz\n\n\
    int main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/scc\n\n#include\
    \ \"src/cpp-template/header/int-alias.hpp\"\n#include \"src/cpp-template/header/size-alias.hpp\"\
    \n#include \"src/graph/class/edge/edge.hpp\"\n#include \"src/graph/class/dynamic-graph.hpp\"\
    \n#include \"src/graph/decomposition/strongly-connected-components.hpp\"\n\n#include\
    \ <iostream>\n#include <vector>\n\nnamespace luz {\n\n  void main_() {\n    using\
    \ edge  = Edge< i32 >;\n    using graph = DynamicGraph< edge >;\n\n    usize n,\
    \ m;\n    std::cin >> n >> m;\n    graph g(n);\n\n    while (m--) {\n      usize\
    \ u, v;\n      std::cin >> u >> v;\n      g.add_directed_edge(u, v);\n    }\n\n\
    \    StronglyConnectedComponents<graph> scc(g);\n\n    auto groups = scc.groups();\n\
    \    std::cout << groups.size() << std::endl;\n\n    for (auto& group: groups)\
    \ {\n      std::cout << group.size() << \" \";\n      for (auto &v: group) {\n\
    \        std::cout << v << \" \";\n      }\n      std::cout << std::endl;\n  \
    \  }\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/graph/class/edge/edge.hpp
  - src/graph/class/dynamic-graph.hpp
  - src/graph/decomposition/strongly-connected-components.hpp
  isVerificationFile: true
  path: test/library-checker/scc.test.cpp
  requiredBy: []
  timestamp: '2023-06-20 08:43:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/scc.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/scc.test.cpp
- /verify/test/library-checker/scc.test.cpp.html
title: test/library-checker/scc.test.cpp
---
