#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll DIV = 998244353;

struct Fraction {
  ll numer, denom;

  bool operator<(const Fraction& other) const {
    return numer * other.denom < other.numer * denom;
  }
};

ll power(ll n, ll k) {
  ll res = 1;
  while (k) {
    if (k & 1) res = res * n % DIV;
    n = (n * n) % DIV;
    k >>= 1;
  }
  return res;
}

void solve() {
  // input
  int n, sz;
  cin >> n;
  sz = n * (n - 1);
  vector<int> a(n), b(n);
  vector<Fraction> allA, allB;
  allA.reserve(sz / 2);
  allB.reserve(sz);

  for (int& i : a) cin >> i;
  for (int& i : b) cin >> i;

  // make a_i / a_j (i < j)
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) allA.push_back(Fraction{a[i], a[j]});
  }
  // make b_i / b_j (i != j)
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) [[unlikely]]
        continue;
      allB.push_back(Fraction{b[i], b[j]});
    }
  }

  sort(allB.begin(), allB.end());

  ll sum = 0;
  for (auto& i : allA) {
    ll cnt = distance(allB.begin(), lower_bound(allB.begin(), allB.end(), i));
    sum = (sum + cnt) % DIV;
  }
  cout << sum * power(sz, DIV - 2) % DIV << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();
}