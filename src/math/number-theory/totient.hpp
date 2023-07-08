// count k \in [1, n]
//   s.t. k and n are relatively prime.
// O(sqrt(n))
template<typename T>
T totient(T n){
  T res = n;

  for (T i = 2; i * i <= n; i++) {
    if (n % i) continue;
    res = res / i * (i - 1);
    while (n % i == 0) n /= i;
  }

  if (n != 1) res = res / n * (n - 1);
  return res;
}
