#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  int lo = 1, hi = 3 * n;
  for (int i = 0; i < n; i++) {
    cout << lo << ' ' << hi << ' ' << hi - 1 << ' ';
    lo++;
    hi -= 2;
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}