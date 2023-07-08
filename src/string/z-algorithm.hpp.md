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
  bundledCode: "#line 2 \"src/string/z-algorithm.hpp\"\n\n#include <vector>\n#include\
    \ <string>\n\nnamespace luz {\n  // vs[i] := length of longest common prefix of\
    \ s and s[i:].\n  // e.g. z_algorithm(\"aaabaaaab\")\n  //                 = 921034210\n\
    \  // O(|s|)\n  std::vector< int > z_algorithm(std::string s) {\n    int n = s.size();\n\
    \    std::vector< int > vs(n + 1, n);\n    int i = 1, j = 0;\n    while (i < n)\
    \ {\n      while (i + j < n and vs[j] == vs[i + j]) j++;\n      vs[i] = j;\n \
    \     if (j == 0) {\n        i++;\n        continue;\n      }\n\n      int k =\
    \ 1;\n      while (i + k < n and k + vs[k] < j) {\n        vs[i + k] = vs[k];\n\
    \        k++;\n      }\n      i += k;\n      j += k;\n    }\n    return vs;\n\
    \  }\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <string>\n\nnamespace luz {\n\
    \  // vs[i] := length of longest common prefix of s and s[i:].\n  // e.g. z_algorithm(\"\
    aaabaaaab\")\n  //                 = 921034210\n  // O(|s|)\n  std::vector< int\
    \ > z_algorithm(std::string s) {\n    int n = s.size();\n    std::vector< int\
    \ > vs(n + 1, n);\n    int i = 1, j = 0;\n    while (i < n) {\n      while (i\
    \ + j < n and vs[j] == vs[i + j]) j++;\n      vs[i] = j;\n      if (j == 0) {\n\
    \        i++;\n        continue;\n      }\n\n      int k = 1;\n      while (i\
    \ + k < n and k + vs[k] < j) {\n        vs[i + k] = vs[k];\n        k++;\n   \
    \   }\n      i += k;\n      j += k;\n    }\n    return vs;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/z-algorithm.hpp
  requiredBy: []
  timestamp: '2023-07-06 05:58:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/z-algorithm.hpp
layout: document
redirect_from:
- /library/src/string/z-algorithm.hpp
- /library/src/string/z-algorithm.hpp.html
title: src/string/z-algorithm.hpp
---
