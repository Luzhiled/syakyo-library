// verification-helper: PROBLEM https://judge.yosupo.jp/problem/convolution_mod

#include "src/math/convolution/mod-convolution.hpp"

#include <iostream>
#include <vector>

namespace luz {

  void main_() {
    usize n, m;
    std::cin >> n >> m;

    constexpr i64 mod = 998244353;
    std::vector< i64 > f(n), g(m);
    for (auto &a: f) std::cin >> a;
    for (auto &b: g) std::cin >> b;

    auto c = modint_convolution(f, g, mod);
    for (usize i = 0; i < c.size(); i++) {
      std::cout << c[i] << (i + 1 == c.size() ? "\n" : " ");
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
