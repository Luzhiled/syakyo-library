#pragma once

#include "src/cpp-template/header/int-alias.hpp"

namespace luz {

  i64 mod_pow(i64 b, i64 e, i64 mod) {
    i64 ans{1};

    while (e) {
      if (e & 1) {
        ans = ans * b % mod;
      }
      b = b * b % mod;
      e /= 2;
    }

    return ans;
  }

}
