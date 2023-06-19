// verification-helper: PROBLEM https://atcoder.jp/contests/abc291/tasks/abc291_e

#include "src/cpp-template/header/size-alias.hpp"
#include "src/graph/class/edge/edge.hpp"
#include "src/graph/class/dynamic-graph.hpp"
#include "src/graph/topological-ordering/lexical-order-topological-sort.hpp"

#include <functional>
#include <iostream>

namespace luz {

  void main_() {
    using edge  = Edge< usize >;
    using graph = DynamicGraph< edge >;

    usize n, m;
    std::cin >> n >> m;

    graph g(n);
    while (m--) {
      usize t, f;
      std::cin >> t >> f;
      g.add_directed_edge(t - 1, f - 1);
    }

    auto ord =
        lexical_order_topological_sort< graph,
                                        std::greater< usize > >(g);
    auto rev =
        lexical_order_topological_sort< graph, std::less< usize > >(
            g);

    if (ord == rev) {
      std::cout << "Yes" << std::endl;

      std::vector< usize > ans(n);
      for (usize i = 0; i < n; i++) {
        ans[ord[i]] = i + 1;
      }

      for (usize i = 0; i < n; i++) {
        std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
      }
    } else {
      std::cout << "No" << std::endl;
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
