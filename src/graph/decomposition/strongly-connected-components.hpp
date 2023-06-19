#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"

#include <vector>

namespace luz {

  template < class G >
  class StronglyConnectedComponents {
    using graph     = G;
    using cost_type = typename graph::cost_type;

    using groups_type = std::vector< std::vector< usize > >;

    graph g;
    usize n;

    std::vector< usize > low, ord, visited, group_id;

    usize ord_cnt, group_cnt;

    void dfs(usize v) {
      low[v] = ord[v] = ord_cnt++;
      visited.emplace_back(v);

      for (auto &e: g[v]) {
        if (ord[e.to] == n) {
          dfs(e.to);
        }
        low[v] = std::min(low[v], low[e.to]);
      }

      if (low[v] != ord[v]) return;

      while (true) {
        usize u = visited.back();
        visited.pop_back();

        ord[u]      = n + 1;
        group_id[u] = group_cnt;

        if (u == v) break;
      }

      group_cnt++;
    }

   public:
    explicit StronglyConnectedComponents(const graph& g_)
        : g(g_), n(g.size()), low(n), ord(n, n), group_id(n), ord_cnt(0), group_cnt(0) {
      visited.reserve(n);

      for (usize v = 0; v < n; v++) {
        if (ord[v] != n) continue;
        dfs(v);
      }

      for (auto &id: group_id) {
        id = group_cnt - id - 1;
      }
    }

    groups_type groups() const {
      std::vector< usize > counts(group_cnt);
      for (usize i = 0; i < n; i++) {
        counts[group_id[i]]++;
      }

      groups_type groups(group_cnt);
      for (usize i = 0; i < group_cnt; i++) {
        groups[i].reserve(counts[i]);
      }

      for (usize i = 0; i < n; i++) {
        groups[group_id[i]].emplace_back(i);
      }

      return groups;
    }

    std::vector< usize > group_ids() const {
      return group_id;
    }
  };

} // namespace luz
