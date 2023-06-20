// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/graph/class/edge/edge.hpp"
#include "src/graph/class/dynamic-graph.hpp"
#include "src/graph/single-source-shortest-path/in-weighted-graph.hpp"

#include <iostream>

namespace luz {

  void main_() {
    usize n, m, source;
    std::cin >> n >> m >> source;

    using edge  = Edge< i32 >;
    using graph = DynamicGraph< edge >;

    graph g(n);
    while (m--) {
      usize s, t;
      i32 d;

      std::cin >> s >> t >> d;
      g.add_directed_edge(s, t, d);
    }

    sssp::InWeightedGraph< graph > solver(g, source);
    for (usize v = 0; v < n; v++) {
      if (solver.distance(v) == solver.negative_inf) {
        std::cout << "NEGATIVE CYCLE" << std::endl;
        return;
      }
    }

    for (usize v = 0; v < n; v++) {
      if (solver.distance(v) == solver.inf) {
        std::cout << "INF" << std::endl;
      } else {
        std::cout << solver.distance(v) << std::endl;
      }
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
