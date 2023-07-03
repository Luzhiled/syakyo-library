#pragma once

#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

namespace luz {

  class MaxFlowGraph {
    using usize = std::size_t;
    using Cap = long long;

    struct Edge {
      usize to, rev;
      Cap cap;
    };

    usize n;
    std::vector< Cap > min_cost;
    std::vector< usize > iter;
    std::vector< std::vector< Edge > > g;

    bool build_augment_path(usize s, usize t) {
      min_cost.assign(n, -1);
      std::queue< usize > que;

      min_cost[s] = 0;
      que.push(s);

      while (not que.empty() and min_cost[t] == -1) {
        usize v = que.front();
        que.pop();

        for (const auto &e: g[v]) {
          if (e.cap > 0 and min_cost[e.to] == -1) {
            min_cost[e.to] = min_cost[v] + 1;
            que.push(e.to);
          }
        }
      }

      return min_cost[t] != -1;
    }

    Cap find_augment_path(usize v, usize t, Cap flow_limit) {
      if (v == t) return flow_limit;

      for (usize &i = iter[v]; i < g[v].size(); i++) {
        Edge &e = g[v][i];

        if (e.cap > 0 and min_cost[v] + 1 == min_cost[e.to]) {
          Cap d = find_augment_path(e.to, t, std::min(flow_limit, e.cap));

          if (d > 0) {
            e.cap -= d;
            g[e.to][e.rev].cap += d;
            return d;
          }
        }
      }

      return 0;
    }

   public:
    const Cap INF = std::numeric_limits< Cap >::max();

    explicit MaxFlowGraph(usize n): n(n), g(n) {}

    usize add_directed_edge(usize from, usize to, Cap cap) {
      // assert(from < n and to < n and from != to);
      usize idx = g[from].size();
      g[from].emplace_back(Edge { to, g[to].size(), cap });
      g[to].emplace_back(Edge { from, idx, 0 });
      return idx;
    }

    // 1. O(n^2 m) in general
    // 2. other case: see docs "dinic-time-complexity.pdf"
    Cap max_flow(usize s, usize t, Cap flow_limit) {
      // assert(s < n and t < n and s != t);
      Cap flow = 0, add = 0;

      while (build_augment_path(s, t) and flow < flow_limit) {
        iter.assign(n, 0);

        do {
          add = find_augment_path(s, t, flow_limit - add);
          flow += add;
        } while (add > 0);
      }

      return flow;
    }

    Cap max_flow(usize s, usize t) {
      return max_flow(s, t, INF);
    }

    // === no need to implement from here ===
    // to use F += link(s, t, ...)
    Cap link(usize s, usize t, usize from, usize idx, Cap f){
      g[from][idx].cap += f;
      return max_flow(s, t, f);
    }

    // to use F += cut(s, t, ...)
    Cap cut(usize s, usize t, usize from, usize idx){
      auto &e = g[from][idx];
      usize to = e.to;
      Cap rem = g[to][e.rev].cap;

      if(rem == 0) return e.cap = 0;
      e.cap = g[to][e.rev].cap = 0;

      Cap cap = rem - max_flow(from, to, rem);
      if (from != s and cap != 0) max_flow(from, s, cap);
      if (t != to and cap != 0) max_flow(t, to, cap);
      return -cap;
    }

  };

} // namespace luz
