#pragma once

#include "src/cpp-template/header/size-alias.hpp"

#include <algorithm>
#include <cassert>
#include <vector>

namespace luz {

  class DisjointSetUnion {
    usize n;

    // vals[v] :=
    //   if v is root node: -1 * component size
    //   otherwise: parent node
    std::vector< isize > vals;

   public:
    DisjointSetUnion() = default;
    explicit DisjointSetUnion(usize n): n(n), vals(n, -1) {}

    usize leader(usize v) {
      if (vals[v] < 0) return v;
      return vals[v] = leader(vals[v]);
    }

    bool same(usize u, usize v) {
      return impl_leader(u) == impl_leader(v);
    }

    usize merge(usize u, usize v) {
      isize x = impl_leader(u);
      isize y = impl_leader(v);
      if (x == y) return x;

      if (-vals[x] < -vals[y]) std::swap(x, y);

      vals[x] += vals[y];
      vals[y] = x;
      return x;
    }

    usize group_size(usize v) {
      return -vals[leader(v)];
    }
  };

} // namespace luz
