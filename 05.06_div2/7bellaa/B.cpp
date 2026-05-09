#include <bits/stdc++.h>
using namespace std;

int n, a[200002];

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);

  long long ans = a[n - 1], mex = 0, cnt = 0;
  ans *= n;
  if (mex == a[n - 1]) ans += ++mex;

  for (int i = 0; i < n - 1; i++) {
    if (i > 0 && a[i] == a[i - 1]) {
      ++cnt;
      continue;
    }

    if (a[i] == mex) ++mex;
    if (mex == a[n - 1]) ++mex;
    ans += mex;
  }
  ans += mex * cnt;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();
}