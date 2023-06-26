#pragma once

#include <vector>
#include <cstddef>

namespace luz {

  struct SCCGraph {
    using usize = std::size_t;
    using graph = std::vector< std::vector< usize > >;

    usize n;
    graph g;
    std::vector< usize > S, B, I;

    void dfs(usize v, graph &scc) {
      B.emplace_back(I[v] = S.size());
      S.emplace_back(v);

      for (auto u: g[v]) {
        if (I[u]) {
          while (I[u] < B.back()) B.pop_back();
        } else {
          dfs(u, scc);
        }
      }
      if (I[v] != B.back()) return;

      scc.emplace_back();
      B.pop_back();
      while (I[v] < S.size()) {
        scc.back().emplace_back(S.back());
        I[S.back()] = n + scc.size();
        S.pop_back();
      }
    }

   public:
    SCCGraph(usize n) : n(n), g(n) {}

    void add_directed_edge(usize from, usize to) {
      g[from].emplace_back(to);
    }

    graph get_scc_list() {
      graph scc;
      I.assign(n, 0);
      S = B = {};
      for (usize v = 0; v < n; v++) {
        if (not I[v]) dfs(v, scc);
      }
      return {scc.rbegin(), scc.rend()};
    }

  };

} // namespace luz
