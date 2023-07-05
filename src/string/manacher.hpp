#pragma once

#include <vector>
#include <string>

namespace luz {
  // calculate a sequence of odd-length palindromic radii
  //   centered at each index.
  // e.g. manacher("abac") = (1, 2, 1, 1)
  // to support even-length, insert a dummy character.
  //   [!] be careful with the post-processing.
  //       exec `vs[i] -= ((i ^ vs[i]) & 1) == 0;`
  std::vector<int> manacher(string s){
    int n = s.size();
    std::vector<int> vs(n);
    int i = 0, j = 0;
    while (i < n) {
      while (i - j >= 0 and i + j < n and s[i - j] == s[i + j]) j++;
      vs[i] = j;
      int k = 1;
      while (i - k >= 0 and i + k < n and k + vs[i - k] < j) {
        vs[i + k] = vs[i - k];
        k++;
      }
      i += k;
      j -= k;
    }
    return vs;
  }

}
