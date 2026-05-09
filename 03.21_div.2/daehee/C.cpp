#include <bits/stdc++.h>
using namespace std;

int query(int a, int b) {
  int result;
  cout << "? " << a << " " << b << "\n";
  cout.flush();
  cin >> result;
  return result;
}

void report(int a) {
  cout << "! " << a << "\n";
  cout.flush();
}

void solve() {
  int n, result;
  cin >> n;
  int q1 = query(1, 2);
  if (q1) {
    report(1);
    return;
  }
  int q2 = query(2, 3);
  if (q2) {
    report(2);
    return;
  }
  int q3 = query(1, 3);
  if (q3) {
    report(3);
    return;
  }

  for (int i=4 ; i<=2*n-2 ; i+=2) {
    int q = query(i, i+1);
    if (q) {
      report(i);
      return;
    }
  }

  report(2*n);
}

int main() {
  ios_base::sync_with_stdio(false);

  int t; cin >> t;
  while (t--) solve();
}