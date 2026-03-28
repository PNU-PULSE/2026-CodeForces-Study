#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &i : arr) cin >> i;
  for (int i=0 ; i<n ; i++) {
    int left=0, right=0;
    for (int j=i+1 ; j<n ; j++) {
      if (arr[i] < arr[j]) ++right;
      if (arr[i] > arr[j]) ++left;
    }

    cout << max(left, right) << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t; cin >> t;
  while (t--) solve();
}