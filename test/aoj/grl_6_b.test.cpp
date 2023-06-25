// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/graph/flow/min-cost-f-flow.hpp"

#include <iostream>

namespace luz {

  void main_() {
    usize n, m, f;
    std::cin >> n >> m >> f;

    MinCostFFlowGraph< u32, i32 > g(n);
    while (m--) {
      usize u, v;
      u32 cap, cost;
      std::cin >> u >> v >> cap >> cost;
      g.add_directed_edge(u, v, cap, cost);
    }

    std::cout << g.min_cost_f_flow(0, n - 1, f) << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
