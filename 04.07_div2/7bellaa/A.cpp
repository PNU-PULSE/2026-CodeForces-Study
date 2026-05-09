#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k, t, sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> t;
      sum += t;
    }
    if (k & 1) {
      if ((~sum & 1) && (1 & n))
        cout << "NO\n";
      else
        cout << "YES\n";
    } else {
      cout << "YES\n";
    }
  }
}