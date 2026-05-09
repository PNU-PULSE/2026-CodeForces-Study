#include <bits/stdc++.h>
using namespace std;

string s;
int t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> s;

    int cnt = 0;
    for (int i = 1; i < s.length(); i++) {
      if (s[i] == s[i - 1]) cnt++;
    }
    if (cnt > 2)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}