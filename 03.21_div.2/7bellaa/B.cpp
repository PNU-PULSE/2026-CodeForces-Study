#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    v.push_back(t);
  }

  for (int i = 0; i < n; i++) {
    int mn = 0, mx = 0;
    for (int j = i + 1; j < n; j++) {
      if (v[i] > v[j])
        mx++;
      else if (v[i] < v[j])
        mn++;
    }
    cout << max(mx, mn) << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}