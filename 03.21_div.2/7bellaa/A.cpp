#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll arr[101];

void solve() {
  ll n, c, k;
  cin >> n >> c >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
    if (arr[i] > c) break;
    int gap = min(k, c - arr[i]);
    k -= gap;
    c += arr[i] + gap;
  }

  cout << c << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}