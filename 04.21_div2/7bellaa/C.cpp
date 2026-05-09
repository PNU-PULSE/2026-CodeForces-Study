#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  string a, b;
  cin >> n >> a >> b;

  int cnt = 0;
  for (int i = 0, j = 0; i < n && j < n; i++, j++) {
    if (a[i] == b[j]) continue;

    if (i + 1 < n) {
      if (a[i] == a[i + 1] && b[j] == b[j + 1]) {
        i++, j++;
        continue;
      } else if (a[i] == a[i + 1]) {
        i++, j++, cnt++;
        continue;
      } else if (b[j] == b[j + 1]) {
        i++, j++, cnt++;
        continue;
      }
    }
    cnt++;
  }
  cout << cnt << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}