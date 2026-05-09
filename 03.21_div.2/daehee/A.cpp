#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, c, k;

void solve() {
  cin >> n >> c >> k;

  vector<int> arr(n);
  for (auto &i : arr) cin >> i;
  sort(arr.begin(), arr.end());

  for (int i=0 ; i<n ; i++) {
    if (c < arr[i]) break;
    ll gap = c - arr[i];
    if (gap <= k) {
      c += c;
      k -= gap;
    } else {
      c += k + arr[i];
      k = 0;
    }
  }

  cout << c << "\n";
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t; cin >> t;
  while (t--) solve();

}