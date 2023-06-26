---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: src/cpp-template/header/size-alias.hpp
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
    \ PROBLEM https://judge.yosupo.jp/problem/scc\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n}\n#line 2 \"src/graph/decomposition/strongly-connected-components.hpp\"\
    \n\n#include <vector>\n#line 5 \"src/graph/decomposition/strongly-connected-components.hpp\"\
    \n\nnamespace luz {\n\n  struct SCCGraph {\n    using usize = std::size_t;\n \
    \   using graph = std::vector< std::vector< usize > >;\n\n    usize n;\n    graph\
    \ g;\n    std::vector< usize > S, B, I;\n\n    void dfs(usize v, graph &scc) {\n\
    \      B.emplace_back(I[v] = S.size());\n      S.emplace_back(v);\n\n      for\
    \ (auto u: g[v]) {\n        if (I[u]) {\n          while (I[u] < B.back()) B.pop_back();\n\
    \        } else {\n          dfs(u, scc);\n        }\n      }\n      if (I[v]\
    \ != B.back()) return;\n\n      scc.emplace_back();\n      B.pop_back();\n   \
    \   while (I[v] < S.size()) {\n        scc.back().emplace_back(S.back());\n  \
    \      I[S.back()] = n + scc.size();\n        S.pop_back();\n      }\n    }\n\n\
    \   public:\n    SCCGraph(usize n) : n(n), g(n) {}\n\n    void add_directed_edge(usize\
    \ from, usize to) {\n      g[from].emplace_back(to);\n    }\n\n    graph get_scc_list()\
    \ {\n      graph scc;\n      I.assign(n, 0);\n      S = B = {};\n      for (usize\
    \ v = 0; v < n; v++) {\n        if (not I[v]) dfs(v, scc);\n      }\n      return\
    \ {scc.rbegin(), scc.rend()};\n    }\n\n  };\n\n} // namespace luz\n#line 5 \"\
    test/library-checker/scc.test.cpp\"\n\n#include <iostream>\n#line 8 \"test/library-checker/scc.test.cpp\"\
    \n\nnamespace luz {\n\n  void main_() {\n    usize n, m;\n    std::cin >> n >>\
    \ m;\n\n    SCCGraph g(n);\n    while (m--) {\n      usize u, v;\n      std::cin\
    \ >> u >> v;\n      g.add_directed_edge(u, v);\n    }\n\n    auto groups = g.get_scc_list();\n\
    \    std::cout << groups.size() << std::endl;\n\n    for (auto& group: groups)\
    \ {\n      std::cout << group.size();\n      for (auto &v: group) {\n        std::cout\
    \ << \" \" << v;\n      }\n      std::cout << std::endl;\n    }\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/scc\n\n#include\
    \ \"src/cpp-template/header/size-alias.hpp\"\n#include \"src/graph/decomposition/strongly-connected-components.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nnamespace luz {\n\n  void main_()\
    \ {\n    usize n, m;\n    std::cin >> n >> m;\n\n    SCCGraph g(n);\n    while\
    \ (m--) {\n      usize u, v;\n      std::cin >> u >> v;\n      g.add_directed_edge(u,\
    \ v);\n    }\n\n    auto groups = g.get_scc_list();\n    std::cout << groups.size()\
    \ << std::endl;\n\n    for (auto& group: groups) {\n      std::cout << group.size();\n\
    \      for (auto &v: group) {\n        std::cout << \" \" << v;\n      }\n   \
    \   std::cout << std::endl;\n    }\n  }\n\n} // namespace luz\n\nint main() {\n\
    \  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/size-alias.hpp
  - src/graph/decomposition/strongly-connected-components.hpp
  isVerificationFile: true
  path: test/library-checker/scc.test.cpp
  requiredBy: []
  timestamp: '2023-06-27 00:42:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/scc.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/scc.test.cpp
- /verify/test/library-checker/scc.test.cpp.html
title: test/library-checker/scc.test.cpp
---
