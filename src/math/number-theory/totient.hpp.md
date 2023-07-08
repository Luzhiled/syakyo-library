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
  bundledCode: "#line 1 \"src/math/number-theory/totient.hpp\"\n// count k \\in [1,\
    \ n]\n//   s.t. k and n are relatively prime.\n// O(sqrt(n))\ntemplate<typename\
    \ T>\nT totient(T n){\n  T res = n;\n\n  for (T i = 2; i * i <= n; i++) {\n  \
    \  if (n % i) continue;\n    res = res / i * (i - 1);\n    while (n % i == 0)\
    \ n /= i;\n  }\n\n  if (n != 1) res = res / n * (n - 1);\n  return res;\n}\n"
  code: "// count k \\in [1, n]\n//   s.t. k and n are relatively prime.\n// O(sqrt(n))\n\
    template<typename T>\nT totient(T n){\n  T res = n;\n\n  for (T i = 2; i * i <=\
    \ n; i++) {\n    if (n % i) continue;\n    res = res / i * (i - 1);\n    while\
    \ (n % i == 0) n /= i;\n  }\n\n  if (n != 1) res = res / n * (n - 1);\n  return\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/number-theory/totient.hpp
  requiredBy: []
  timestamp: '2023-07-06 04:39:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/number-theory/totient.hpp
layout: document
redirect_from:
- /library/src/math/number-theory/totient.hpp
- /library/src/math/number-theory/totient.hpp.html
title: src/math/number-theory/totient.hpp
---
