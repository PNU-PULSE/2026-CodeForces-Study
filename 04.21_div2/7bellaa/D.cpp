#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int DIV = 998244353;

long long count_mod(long long max_val, long long target_mod) {
  if (max_val < target_mod) return 0;
  return (max_val - target_mod) / 4 + 1;
}

void solve() {
  long long n, x;
  cin >> n >> x;
  // XOR은 아벨군을 만족하므로 +처럼 누적합으로 생각할수있다

  long long l = count_mod(x - 1, 1), r = count_mod(n, 1) - l;
  long long ans = (l % DIV) * (r % DIV) % DIV;

  // L의 범위: [0, x-1]
  // P(L) = 0 인 조건: (L % 4 == 3) 이거나 (L == 0)
  l = count_mod(x - 1, 3) + 1;
  r = count_mod(n, 3) - count_mod(x - 1, 3);
  ans = (ans + (l % DIV) * (r % DIV)) % DIV;
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}

/*
관찰
각 자리수가 주기성을 가진다
2^0: 0101 0101 0101 0101 0101010101010101
2^1: 0011 0011 0011 0011 0011001100110011
2^2: 0000 1111 0000 1111 0000111100001111
2^3: 0000 0000 1111 1111 0000000011111111
2^4: 0000 0000 0000 0000 1111111111111111

*/