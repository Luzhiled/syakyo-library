#pragma once

#include <vector>

namespace luz {

  template< typename T = char >
  struct OnlineZalgorithm {
    private:
      std::vector< T > s;
      std::vector< int > deleted;
      std::vector< std::vector< int > > hists;
      std::vector< int > z;
      queue< int > cur;
    public:
      OnlineZalgorithm() : hists{{}} {}

      template< typename S >
        OnlineZalgorithm(const S &s) : OnlineZalgorithm() {
          for(auto &c: s) push_back(c);
        }

      // do s.push_back(c)
      void push_back(const T &c) {
        s.emplace_back(c);
        hists.emplace_back();
        deleted.emplace_back(0);
        z.emplace_back(0);
        z[0]++;

        int len = s.size();
        if (len == 1) return;
        if (s[0] == c) cur.emplace(len - 1);
        else deleted[len - 1] = 1;

        auto set = [&](int t, int len) {
          deleted[t] = 1;
          hists[len].emplace_back(t);
          z[t] = len - t - 1;
        };

        while (not cur.empty()) {
          int t = cur.front();
          if (deleted[t]) {
            cur.pop();
          } else if (s[len - t - 1] == s.back()) {
            break;
          } else {
            set(t, len);
            cur.pop();
          }
        }

        if(not cur.empty()) {
          int t = cur.front();
          for(auto &p: hists[len - t]) {
            set(p + t, len);
          }
        }
      }

      // z_algorithm(s)[k] for current s.
      int get(int k) const {
        return deleted[k] ? z[k] : (int)s.size() - k;
      }

      std::vector< int > get() {
        std::vector< int > ret(s.size());
        for(int i = 0; i < (int) s.size(); i++) {
          ret[i] = get(i);
        }
        return ret;
      }
  };
