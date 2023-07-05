#pragma once

#include <vector>
#include <string>

namespace luz {
  // vs[i] := length of longest common prefix of s and s[i:].
  // e.g. z_algorithm("aaabaaaab")
  //                 = 921034210
  // O(|s|)
  std::vector< int > z_algorithm(std::string s) {
    int n = s.size();
    std::vector< int > vs(n + 1, n);
    int i = 1, j = 0;
    while (i < n) {
      while (i + j < n and vs[j] == vs[i + j]) j++;
      vs[i] = j;
      if (j == 0) {
        i++;
        continue;
      }

      int k = 1;
      while (i + k < n and k + vs[k] < j) {
        vs[i + k] = vs[k];
        k++;
      }
      i += k;
      j += k;
    }
    return vs;
  }
}
