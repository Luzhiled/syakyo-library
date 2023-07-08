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
  bundledCode: "#line 1 \"src/math/number-theory/totient-table.hpp\"\n#include <vector>\n\
    #include <numeric>\n\n// calculate totient(i) (i \\in [0, n])\n// O(n loglog n)\n\
    std::vector<int> totient_table(int n){\n  std::vector<int> ts(n+1);\n  std::iota(ts.begin(),\
    \ ts.end(),0);\n\n  for (int i = 2; i <= n; i++){\n    if (ts[i] != i) continue;\n\
    \    for (int j = i; j <= n; j += i) {\n      ts[j] = ts[j] / i * (i-1);\n   \
    \ }\n  }\n  return ts;\n}\n"
  code: "#include <vector>\n#include <numeric>\n\n// calculate totient(i) (i \\in\
    \ [0, n])\n// O(n loglog n)\nstd::vector<int> totient_table(int n){\n  std::vector<int>\
    \ ts(n+1);\n  std::iota(ts.begin(), ts.end(),0);\n\n  for (int i = 2; i <= n;\
    \ i++){\n    if (ts[i] != i) continue;\n    for (int j = i; j <= n; j += i) {\n\
    \      ts[j] = ts[j] / i * (i-1);\n    }\n  }\n  return ts;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/number-theory/totient-table.hpp
  requiredBy: []
  timestamp: '2023-07-06 04:39:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/number-theory/totient-table.hpp
layout: document
redirect_from:
- /library/src/math/number-theory/totient-table.hpp
- /library/src/math/number-theory/totient-table.hpp.html
title: src/math/number-theory/totient-table.hpp
---
