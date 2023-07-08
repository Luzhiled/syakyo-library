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
  bundledCode: "#line 2 \"src/string/manacher.hpp\"\n\n#include <vector>\n#include\
    \ <string>\n\nnamespace luz {\n  // calculate a sequence of odd-length palindromic\
    \ radii\n  //   centered at each index.\n  // e.g. manacher(\"abac\") = (1, 2,\
    \ 1, 1)\n  // to support even-length, insert a dummy character.\n  //   [!] be\
    \ careful with the post-processing.\n  //       exec `vs[i] -= ((i ^ vs[i]) &\
    \ 1) == 0;`\n  std::vector<int> manacher(std::string s){\n    int n = s.size();\n\
    \    std::vector<int> vs(n);\n    int i = 0, j = 0;\n    while (i < n) {\n   \
    \   while (i - j >= 0 and i + j < n and s[i - j] == s[i + j]) j++;\n      vs[i]\
    \ = j;\n      int k = 1;\n      while (i - k >= 0 and i + k < n and k + vs[i -\
    \ k] < j) {\n        vs[i + k] = vs[i - k];\n        k++;\n      }\n      i +=\
    \ k;\n      j -= k;\n    }\n    return vs;\n  }\n\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <string>\n\nnamespace luz {\n\
    \  // calculate a sequence of odd-length palindromic radii\n  //   centered at\
    \ each index.\n  // e.g. manacher(\"abac\") = (1, 2, 1, 1)\n  // to support even-length,\
    \ insert a dummy character.\n  //   [!] be careful with the post-processing.\n\
    \  //       exec `vs[i] -= ((i ^ vs[i]) & 1) == 0;`\n  std::vector<int> manacher(std::string\
    \ s){\n    int n = s.size();\n    std::vector<int> vs(n);\n    int i = 0, j =\
    \ 0;\n    while (i < n) {\n      while (i - j >= 0 and i + j < n and s[i - j]\
    \ == s[i + j]) j++;\n      vs[i] = j;\n      int k = 1;\n      while (i - k >=\
    \ 0 and i + k < n and k + vs[i - k] < j) {\n        vs[i + k] = vs[i - k];\n \
    \       k++;\n      }\n      i += k;\n      j -= k;\n    }\n    return vs;\n \
    \ }\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/manacher.hpp
  requiredBy: []
  timestamp: '2023-07-06 05:59:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/manacher.hpp
layout: document
redirect_from:
- /library/src/string/manacher.hpp
- /library/src/string/manacher.hpp.html
title: src/string/manacher.hpp
---
