// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/2313

#include "src/graph/flow/max-flow.hpp"

#include <iostream>
#include <map>
#include <vector>

int main() {
  using usize = std::size_t;

  usize n, e, q;
  std::cin >> n >> e >> q;
  
  luz::MaxFlowGraph g(n);
  std::vector< std::map< usize, usize > > eidxs(n);
  while (e--) {
    usize u, v;
    std::cin >> u >> v;
    u--; v--;
    eidxs[u][v] = g.add_directed_edge(u, v, 1);
    eidxs[v][u] = g.add_directed_edge(v, u, 1);
  }

  std::vector< usize > qs(q), us(q), vs(q);
  for (usize i = 0; i < q; i++) {
    usize u, v;
    std::cin >> qs[i] >> u >> v;
    u--; v--;

    us[i] = u;
    vs[i] = v;

    if (eidxs[u].count(v)) continue;
    eidxs[u][v] = g.add_directed_edge(u, v, 0);
    eidxs[v][u] = g.add_directed_edge(v, u, 0);
  }

  usize s = 0, t = n - 1;
  int flow = g.max_flow(s, t);
  for (usize i = 0; i < q; i++) {
    usize u = us[i], v = vs[i];
    
    if (qs[i] == 1) {
      flow += g.link(s, t, u, eidxs[u][v], 1);
      flow += g.link(s, t, v, eidxs[v][u], 1);
    }
    
    if (qs[i] == 2) {
      flow += g.cut(s, t, u, eidxs[u][v]);
      flow += g.cut(s, t, v, eidxs[v][u]);
    }

    std::cout << flow << std::endl;
  }
}

