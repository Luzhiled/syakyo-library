#pragma once

#include "src/cpp-template/header/size-alias.hpp"

#include <limits>
#include <queue>
#include <vector>

namespace luz::sssp {

  template < class G >
  class InWeightedGraph {
    using cost_type = typename G::cost_type;
    using graph     = G;

    graph g;
    usize n;

    std::vector< cost_type > ds;
    std::vector< usize > parents, ids;

    // O(nm)
    void spfa(usize s) {
      std::queue< usize > que;
      std::vector< usize > ds_update_cnt(n);
      std::vector< bool > in_que(n);

      ds[s]            = 0;
      in_que[s]        = true;
      ds_update_cnt[s] = 0;
      que.emplace(s);

      while (not que.empty()) {
        usize v = que.front();
        que.pop();
        in_que[v] = false;

        for (const auto &e: g[v]) {
          usize u        = e.to;
          cost_type cost = e.cost;
          if (ds[v] + cost >= ds[u]) {
            continue;
          }

          ds[u]      = ds[v] + cost;
          parents[u] = v;
          ids[u]     = e.id;

          if (in_que[u]) {
            continue;
          }

          in_que[u] = true;
          ds_update_cnt[u]++;

          if (ds_update_cnt[u] < 2 * n) {
            que.emplace(u);
          }
        }
      }

      for (usize v: rep(0, n)) {
        if (ds_update_cnt[v] >= n) {
          ds[v]      = negative_inf;
          parents[v] = undefined;
          ids[v]     = undefined;
        }
      }
    }

   public:
    static constexpr cost_type inf = std::numeric_limits< cost_type >::max();
    static constexpr cost_type negative_inf = std::numeric_limits< cost_type >::min();
    static constexpr usize undefined = std::numeric_limits< usize >::max();

    explicit InWeightedGraph(const graph &g, usize s)
        : g(g),
          n(g.size()),
          ds(n, inf),
          parents(n, undefined),
          ids(n, undefined) {
      spfa(s);
    }

    inline cost_type distance(const usize v) const {
      return ds[v];
    }

    inline usize parent(const usize v) const {
      return parents[v];
    }

    inline usize edge_label(const usize v) const {
      return ids[v];
    }

  };

} // namespace luz::sssp
