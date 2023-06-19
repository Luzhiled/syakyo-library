#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

namespace luz {

  template < typename T >
  class FenwickTree {
    usize n;
    std::vector< T > tree;

    T sum(usize k) const {
      T result();
      while (k > 0) {
        result += tree[k];
        k -= k & -k;
      }
      return result;
    }

   public:
    FenwickTree() = default;
    explicit FenwickTree(usize n): n(n), tree(n + 1, T()) {}

    explicit FenwickTree(const std::vector< T > &as) : n(as.size()), tree(n + 1, T()) {
      std::copy(as.begin(), as.end(), tree.begin() + 1);

      for (usize i = 1; i <= n; i++) {
        usize j = i + (i & -i);
        if (j <= n) {
          tree[j] += tree[i];
        }
      }
    }

    void add(usize k, const T &v) {
      assert(0 <= k and k < n);

      k++;
      while (k <= n) {
        tree[k] += v;
        k += k & -k;
      }
    }

    T sum(usize l, usize r) const {
      assert(0 <= l and l <= r and r <= n);
      return sum(r) - sum(l);
    }
  };

} // namespace luz
