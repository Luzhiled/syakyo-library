#pragma once

#include "src/cpp-template/header/size-alias.hpp"
#include "src/math/convolution/fast-walsh-hadamard-transform.hpp"

#include <cassert>
#include <vector>

namespace luz {

  // length of f and g must be 2^k
  template < typename T >
  std::vector< T > bitwise_and_convolution(std::vector< T > f,
                                           std::vector< T > g) {
    assert(f.size() == g.size());

    auto zeta   = [](T &lo, T hi) { return lo += hi; };
    auto mobius = [](T &lo, T hi) { return lo -= hi; };

    fast_walsh_hadamard_transform(f, zeta);
    fast_walsh_hadamard_transform(g, zeta);

    for (usize i = 0; i < f.size(); i++) {
      f[i] *= g[i];
    }

    fast_walsh_hadamard_transform(f, mobius);
    return f;
  }

} // namespace luz
