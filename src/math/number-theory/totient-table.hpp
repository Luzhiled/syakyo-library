#include <vector>
#include <numeric>

// calculate totient(i) (i \in [0, n])
// O(n loglog n)
std::vector<int> totient_table(int n){
  std::vector<int> ts(n+1);
  std::iota(ts.begin(), ts.end(),0);

  for (int i = 2; i <= n; i++){
    if (ts[i] != i) continue;
    for (int j = i; j <= n; j += i) {
      ts[j] = ts[j] / i * (i-1);
    }
  }
  return ts;
}
