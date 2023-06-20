---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc291_e.test.cpp
    title: test/atcoder/abc291_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/topological-ordering/lexical-order-topological-sort.hpp\"\
    \n\n#include <queue>\n#include <vector>\n\n// usage\n// - min: lexical_order_topological_sort<\
    \ G, std::greater< usize > >(g);\n// - max: lexical_order_topological_sort< G,\
    \ std::less< usize > >(g);\n// !!! it returns {} if G is disconnected or not DAG.\n\
    namespace luz {\n\n  template < class G, class Compare >\n  std::vector< usize\
    \ > lexical_order_topological_sort(const G &g) {\n    usize n = g.size();\n\n\
    \    std::vector< usize > indegrees(n);\n    for (usize v = 0; v < n; v++) {\n\
    \      for (auto &&e: g[v]) {\n        indegrees[e.to]++;\n      }\n    }\n\n\
    \    std::priority_queue< usize, std::vector< usize >, Compare > pq;\n    for\
    \ (usize v = 0; v < n; v++) {\n      if (indegrees[v]) continue;\n      pq.emplace(v);\n\
    \    }\n\n    std::vector< usize > result;\n    result.reserve(n);\n    while\
    \ (not pq.empty()) {\n      auto v = pq.top();\n      pq.pop();\n\n      result.emplace_back(v);\n\
    \      for (auto &&e: g[v]) {\n        if (--indegrees[e.to]) continue;\n    \
    \    pq.emplace(e.to);\n      }\n    }\n\n    if (result.size() != n) {\n    \
    \  return {};\n    }\n\n    return result;\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include <queue>\n#include <vector>\n\n// usage\n// - min:\
    \ lexical_order_topological_sort< G, std::greater< usize > >(g);\n// - max: lexical_order_topological_sort<\
    \ G, std::less< usize > >(g);\n// !!! it returns {} if G is disconnected or not\
    \ DAG.\nnamespace luz {\n\n  template < class G, class Compare >\n  std::vector<\
    \ usize > lexical_order_topological_sort(const G &g) {\n    usize n = g.size();\n\
    \n    std::vector< usize > indegrees(n);\n    for (usize v = 0; v < n; v++) {\n\
    \      for (auto &&e: g[v]) {\n        indegrees[e.to]++;\n      }\n    }\n\n\
    \    std::priority_queue< usize, std::vector< usize >, Compare > pq;\n    for\
    \ (usize v = 0; v < n; v++) {\n      if (indegrees[v]) continue;\n      pq.emplace(v);\n\
    \    }\n\n    std::vector< usize > result;\n    result.reserve(n);\n    while\
    \ (not pq.empty()) {\n      auto v = pq.top();\n      pq.pop();\n\n      result.emplace_back(v);\n\
    \      for (auto &&e: g[v]) {\n        if (--indegrees[e.to]) continue;\n    \
    \    pq.emplace(e.to);\n      }\n    }\n\n    if (result.size() != n) {\n    \
    \  return {};\n    }\n\n    return result;\n  }\n\n} // namespace luz\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/topological-ordering/lexical-order-topological-sort.hpp
  requiredBy: []
  timestamp: '2023-06-20 07:40:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc291_e.test.cpp
documentation_of: src/graph/topological-ordering/lexical-order-topological-sort.hpp
layout: document
redirect_from:
- /library/src/graph/topological-ordering/lexical-order-topological-sort.hpp
- /library/src/graph/topological-ordering/lexical-order-topological-sort.hpp.html
title: src/graph/topological-ordering/lexical-order-topological-sort.hpp
---
