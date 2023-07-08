---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/knuth-morris-pratt.hpp\"\n\n#include <vector>\n\
    #include <string>\n\nnamespace luz {\n  // vs[i] := how many characters match\
    \ the\n  //          prefix and suffix of s[0,i) ?\n  // O(|s|)\n  std::vector<int>\
    \ kmp(const std::string &s){\n    int n = s.size();\n    std::vector<int> vs(n\
    \ + 1,-1);\n    for (int i = 0, j = -1; i < n; i++){\n      while (j >= 0 and\
    \ s[i] != s[j]) j = vs[j];\n      vs[i + 1] = ++j;\n    }\n    return vs;\n  }\n\
    }\n"
  code: "#pragma once\n\n#include <vector>\n#include <string>\n\nnamespace luz {\n\
    \  // vs[i] := how many characters match the\n  //          prefix and suffix\
    \ of s[0,i) ?\n  // O(|s|)\n  std::vector<int> kmp(const std::string &s){\n  \
    \  int n = s.size();\n    std::vector<int> vs(n + 1,-1);\n    for (int i = 0,\
    \ j = -1; i < n; i++){\n      while (j >= 0 and s[i] != s[j]) j = vs[j];\n   \
    \   vs[i + 1] = ++j;\n    }\n    return vs;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/knuth-morris-pratt.hpp
  requiredBy: []
  timestamp: '2023-07-06 05:50:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/knuth-morris-pratt.hpp
layout: document
redirect_from:
- /library/src/string/knuth-morris-pratt.hpp
- /library/src/string/knuth-morris-pratt.hpp.html
title: src/string/knuth-morris-pratt.hpp
---
