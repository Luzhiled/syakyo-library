#pragma once

#include "src/cpp-template/header/size-alias.hpp"

#include <algorithm>
#include <queue>
#include <vector>
#include <limits>
#include <functional>

namespace luz {

  // O(FE \log(V))
  // [note]: cost_t must be signed type
  template< typename flow_t, typename cost_t >
  struct MinCostFFlowGraph {

    template< typename T >
    using vector = std::vector< T >;

    using P = std::pair< cost_t, usize >;

    struct edge {
      usize to;
      flow_t cap;
      cost_t cost;
      usize rev;
      bool isrev;
    };

    usize n;
    vector< vector< edge > > g;
    vector< cost_t > potential, min_cost;
    vector< usize > pvs, pes;

    const cost_t inf;

    MinCostFFlowGraph(usize n) : n(n), g(n), inf(std::numeric_limits< cost_t >::max()) {}

    void add_directed_edge(usize from, usize to, flow_t cap, cost_t cost) {
      g[from].emplace_back(edge {to, cap, cost, g[to].size(), false});
      g[to].emplace_back(edge {from, 0, -cost, g[from].size() - 1, true});
    }

    cost_t min_cost_f_flow(usize s, usize t, flow_t f) {
      cost_t ret = 0;

      std::priority_queue< P, vector< P >, std::greater< P > > que;
      potential.assign(n, 0);
      pes.assign(n, -1);
      pvs.assign(n, -1);

      while (f > 0) {
        min_cost.assign(n, inf);

        que.emplace(0, s);
        min_cost[s] = 0;

        while(!que.empty()) {
          auto [cost, v] = que.top();
          que.pop();

          if (min_cost[v] < cost) continue;

          for (usize i = 0; i < g[v].size(); i++) {
            edge &e = g[v][i];
            usize u = e.to;

            cost_t next_cost = min_cost[v] + e.cost + potential[v] - potential[u];

            if (e.cap == 0 or min_cost[u] <= next_cost) {
              continue;
            }

            min_cost[u] = next_cost;
            pvs[u] = v;
            pes[u] = i;
            que.emplace(min_cost[u], u);
          }
        }

        if (min_cost[t] == inf) return -1;

        for (usize v = 0; v < n; v++) {
          potential[v] += min_cost[v];
        }

        flow_t addflow = f;

        for (usize v = t; v != s; v = pvs[v]) {
          addflow = std::min(addflow, g[pvs[v]][pes[v]].cap);
        }

        f -= addflow;
        ret += addflow * potential[t];

        for (usize v = t; v != s; v = pvs[v]) {
          edge &e = g[pvs[v]][pes[v]];
          e.cap -= addflow;
          g[v][e.rev].cap += addflow;
        }
      }

      return ret;
    }
  };

}
