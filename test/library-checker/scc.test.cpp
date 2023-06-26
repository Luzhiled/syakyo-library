// verification-helper: PROBLEM https://judge.yosupo.jp/problem/scc

#include "src/cpp-template/header/size-alias.hpp"
#include "src/graph/decomposition/strongly-connected-components.hpp"

#include <iostream>
#include <vector>

namespace luz {

  void main_() {
    usize n, m;
    std::cin >> n >> m;

    SCCGraph g(n);
    while (m--) {
      usize u, v;
      std::cin >> u >> v;
      g.add_directed_edge(u, v);
    }

    auto groups = g.get_scc_list();
    std::cout << groups.size() << std::endl;

    for (auto& group: groups) {
      std::cout << group.size();
      for (auto &v: group) {
        std::cout << " " << v;
      }
      std::cout << std::endl;
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
