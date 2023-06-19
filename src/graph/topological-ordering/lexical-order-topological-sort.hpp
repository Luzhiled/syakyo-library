#pragma once

#include <queue>
#include <vector>

// usage
// - min: lexical_order_topological_sort< G, std::greater< usize > >(g);
// - max: lexical_order_topological_sort< G, std::less< usize > >(g);
// !!! it returns {} if G is disconnected or not DAG.
namespace luz {

  template < class G, class Compare >
  std::vector< usize > lexical_order_topological_sort(const G &g) {
    usize n = g.size();

    std::vector< usize > indegrees(n);
    for (usize v = 0; v < n; v++) {
      for (auto &&e: g[v]) {
        indegrees[e.to]++;
      }
    }

    std::priority_queue< usize, std::vector< usize >, Compare > pq;
    for (usize v = 0; v < n; v++) {
      if (indegrees[v]) continue;
      pq.emplace(v);
    }

    std::vector< usize > result;
    result.reserve(n);
    while (not pq.empty()) {
      auto v = pq.top();
      pq.pop();

      result.emplace_back(v);
      for (auto &&e: g[v]) {
        if (--indegrees[e.to]) continue;
        pq.emplace(e.to);
      }
    }

    if (result.size() != n) {
      return {};
    }

    return result;
  }

} // namespace luz
