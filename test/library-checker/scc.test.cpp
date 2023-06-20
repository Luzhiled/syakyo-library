// verification-helper: PROBLEM https://judge.yosupo.jp/problem/scc

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/graph/class/edge/edge.hpp"
#include "src/graph/class/dynamic-graph.hpp"
#include "src/graph/decomposition/strongly-connected-components.hpp"

#include <iostream>
#include <vector>

namespace luz {

  void main_() {
    using edge  = Edge< i32 >;
    using graph = DynamicGraph< edge >;

    usize n, m;
    std::cin >> n >> m;
    graph g(n);

    while (m--) {
      usize u, v;
      std::cin >> u >> v;
      g.add_directed_edge(u, v);
    }

    StronglyConnectedComponents<graph> scc(g);

    auto groups = scc.groups();
    std::cout << groups.size() << std::endl;

    for (auto& group: groups) {
      std::cout << group.size() << " ";
      for (auto &v: group) {
        std::cout << v << " ";
      }
      std::cout << std::endl;
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
