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
  bundledCode: "#line 2 \"src/string/online-z-algorithm.hpp\"\n\n#include <vector>\n\
    \nnamespace luz {\n\n  template< typename T = char >\n  struct OnlineZalgorithm\
    \ {\n    private:\n      std::vector< T > s;\n      std::vector< int > deleted;\n\
    \      std::vector< std::vector< int > > hists;\n      std::vector< int > z;\n\
    \      queue< int > cur;\n    public:\n      OnlineZalgorithm() : hists{{}} {}\n\
    \n      template< typename S >\n        OnlineZalgorithm(const S &s) : OnlineZalgorithm()\
    \ {\n          for(auto &c: s) push_back(c);\n        }\n\n      // do s.push_back(c)\n\
    \      void push_back(const T &c) {\n        s.emplace_back(c);\n        hists.emplace_back();\n\
    \        deleted.emplace_back(0);\n        z.emplace_back(0);\n        z[0]++;\n\
    \n        int len = s.size();\n        if (len == 1) return;\n        if (s[0]\
    \ == c) cur.emplace(len - 1);\n        else deleted[len - 1] = 1;\n\n        auto\
    \ set = [&](int t, int len) {\n          deleted[t] = 1;\n          hists[len].emplace_back(t);\n\
    \          z[t] = len - t - 1;\n        };\n\n        while (not cur.empty())\
    \ {\n          int t = cur.front();\n          if (deleted[t]) {\n           \
    \ cur.pop();\n          } else if (s[len - t - 1] == s.back()) {\n           \
    \ break;\n          } else {\n            set(t, len);\n            cur.pop();\n\
    \          }\n        }\n\n        if(not cur.empty()) {\n          int t = cur.front();\n\
    \          for(auto &p: hists[len - t]) {\n            set(p + t, len);\n    \
    \      }\n        }\n      }\n\n      // z_algorithm(s)[k] for current s.\n  \
    \    int get(int k) const {\n        return deleted[k] ? z[k] : (int)s.size()\
    \ - k;\n      }\n\n      std::vector< int > get() {\n        std::vector< int\
    \ > ret(s.size());\n        for(int i = 0; i < (int) s.size(); i++) {\n      \
    \    ret[i] = get(i);\n        }\n        return ret;\n      }\n  };\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace luz {\n\n  template< typename\
    \ T = char >\n  struct OnlineZalgorithm {\n    private:\n      std::vector< T\
    \ > s;\n      std::vector< int > deleted;\n      std::vector< std::vector< int\
    \ > > hists;\n      std::vector< int > z;\n      queue< int > cur;\n    public:\n\
    \      OnlineZalgorithm() : hists{{}} {}\n\n      template< typename S >\n   \
    \     OnlineZalgorithm(const S &s) : OnlineZalgorithm() {\n          for(auto\
    \ &c: s) push_back(c);\n        }\n\n      // do s.push_back(c)\n      void push_back(const\
    \ T &c) {\n        s.emplace_back(c);\n        hists.emplace_back();\n       \
    \ deleted.emplace_back(0);\n        z.emplace_back(0);\n        z[0]++;\n\n  \
    \      int len = s.size();\n        if (len == 1) return;\n        if (s[0] ==\
    \ c) cur.emplace(len - 1);\n        else deleted[len - 1] = 1;\n\n        auto\
    \ set = [&](int t, int len) {\n          deleted[t] = 1;\n          hists[len].emplace_back(t);\n\
    \          z[t] = len - t - 1;\n        };\n\n        while (not cur.empty())\
    \ {\n          int t = cur.front();\n          if (deleted[t]) {\n           \
    \ cur.pop();\n          } else if (s[len - t - 1] == s.back()) {\n           \
    \ break;\n          } else {\n            set(t, len);\n            cur.pop();\n\
    \          }\n        }\n\n        if(not cur.empty()) {\n          int t = cur.front();\n\
    \          for(auto &p: hists[len - t]) {\n            set(p + t, len);\n    \
    \      }\n        }\n      }\n\n      // z_algorithm(s)[k] for current s.\n  \
    \    int get(int k) const {\n        return deleted[k] ? z[k] : (int)s.size()\
    \ - k;\n      }\n\n      std::vector< int > get() {\n        std::vector< int\
    \ > ret(s.size());\n        for(int i = 0; i < (int) s.size(); i++) {\n      \
    \    ret[i] = get(i);\n        }\n        return ret;\n      }\n  };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/online-z-algorithm.hpp
  requiredBy: []
  timestamp: '2023-07-06 06:07:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/online-z-algorithm.hpp
layout: document
redirect_from:
- /library/src/string/online-z-algorithm.hpp
- /library/src/string/online-z-algorithm.hpp.html
title: src/string/online-z-algorithm.hpp
---
