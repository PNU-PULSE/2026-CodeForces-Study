#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k, t, sum = 0;
  cin >> n >> k;
  vector<pair<int, int>> arr(n + 1);
  vector<int> lim(k + 1);
  for (int i = 1; i <= k; i++) cin >> lim[i];
  for (int i = 1; i <= n; i++) {
    cin >> t;
    sum += t;
    arr[i] = {t, i};
  }
  sort(arr.begin(), arr.end(), greater<>{});
  cout << n * (k + 1) - sum << '\n';

  for (int i = 0; i < n; i++) {
    while (arr[i].first++ < k + 1) cout << arr[i].second << ' ';
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