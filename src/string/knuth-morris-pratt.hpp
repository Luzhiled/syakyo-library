#pragma once

#include <vector>
#include <string>

namespace luz {
  // vs[i] := how many characters match the
  //          prefix and suffix of s[0,i) ?
  // O(|s|)
  std::vector<int> kmp(const std::string &s){
    int n = s.size();
    std::vector<int> vs(n + 1,-1);
    for (int i = 0, j = -1; i < n; i++){
      while (j >= 0 and s[i] != s[j]) j = vs[j];
      vs[i + 1] = ++j;
    }
    return vs;
  }
}
