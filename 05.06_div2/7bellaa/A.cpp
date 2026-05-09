#include <bits/stdc++.h>
using namespace std;

long long n, a[200002];

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  int ans = 0;
  for (int i = n - 1; i > 0; i--) {
    if (a[i] > 0) {
      ++ans;
      a[i - 1] += a[i];
    }
  }
  if (a[0] > 0) ++ans;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}