#pragma once

#include "src/cpp-template/header/size-alias.hpp"

namespace luz {

  template < typename T >
  struct Edge {
    using cost_type = T;

    usize from, to;
    T cost;
    usize id;

    Edge() = default;
    
    Edge(usize f, usize t, T c, usize i) : from(f), to(t), cost(c), id(i) {}
  };

} // namespace luz
