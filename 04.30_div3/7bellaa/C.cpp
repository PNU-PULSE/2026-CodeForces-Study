#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& i : v) cin >> i;

  vector<int> v2, v3, no;
  for (int i : v) {
    if (i % 6 == 0)
      cout << i << ' ';
    else if (i % 2 == 0)
      v2.push_back(i);
    else if (i % 3 == 0)
      v3.push_back(i);
    else
      no.push_back(i);
  }
  for (int i : v2) cout << i << ' ';
  for (int i : no) cout << i << ' ';
  for (int i : v3) cout << i << ' ';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();
}