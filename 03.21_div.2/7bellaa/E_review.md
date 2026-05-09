# 📝 Codeforces 2209E — A Trivial String Problem

> **Contest:** Codeforces Round 1087 (Div. 2)
> **Rating:** 2200 · **Tags:** `dp` `strings` `hashing` `string suffix structures` `brute force`
> **Time Limit:** 4.0 s · **Memory Limit:** 1024 MB

---

## 📌 문제 설명

### 정의

함수 $f(t)$를 다음과 같이 정의한다.

> $f(t)$ = 문자열 $t$를 $t$ **자기 자신의 prefix(접두사)** 조각으로 쪼갤 때, **최대 조각 수**.

즉, $f(t)$는 아래를 만족하는 **최대** 양의 정수 $k$이다.

$$t = p_1 + p_2 + \cdots + p_k$$

여기서 각 $p_i$는 $t$의 **non-empty prefix**.

### 쿼리

길이 $n$인 문자열 $s$가 주어지고, $q$개의 쿼리 $(l_i, r_i)$가 주어진다.
각 쿼리에 대해 다음 값을 구하라:

$$\sum_{j=l_i}^{r_i} f\bigl(s[l_i \dots j]\bigr)$$

### 제한

| 변수 | 범위 |
|---|---|
| 테스트 케이스 수 $t$ | $1 \le t \le 10^3$ |
| 문자열 길이 $n$ | $1 \le n \le 10^6$ |
| 쿼리 수 $q$ | $1 \le q \le 100$ |
| 전체 $n$의 합 | $\le 10^6$ |

### 예제

**Input**
```
6
1 1
a
1 1
5 2
aaaaa
1 5
2 4
6 2
abcdef
1 6
3 5
6 3
abaaba
1 6
1 3
2 6
7 3
abcabca
1 7
2 7
4 7
8 3
aababaac
1 8
2 8
3 7
```

**Output**
```
1
15
6
6
3
14
4
7
12
9
5
13
14
7
```

### 예제 해설

- **Test 1:** $f(\text{"a"}) = 1$
- **Test 2 — Query (1, 5):** 문자열 `"aaaaa"` 에서
  $f(\text{"a"}) + f(\text{"aa"}) + f(\text{"aaa"}) + f(\text{"aaaa"}) + f(\text{"aaaaa"}) = 1+2+3+4+5 = 15$
- **Test 3 — Query (1, 6):** 문자열 `"abcdef"` 는 모든 문자가 다르므로
  각 prefix를 자기 자신 외엔 쪼갤 수 없음 → 합 = $6$

---

## 💡 풀이 방식: KMP + DP

### 핵심 관찰

부분 문자열 $sv = s[l \dots r]$의 각 prefix $sv[0 \dots i]$ 에 대해 $f$를 구해야 한다.

**KMP Failure Function(Pi 배열)의 성질**을 활용하면:

- $F[i]$ = `sv[0..i]`의 가장 긴 proper prefix이면서 suffix인 것의 길이
- 최소 주기: $t = (i+1) - F[i]$

### DP 점화식

$\text{dp}[i]$ = $f\bigl(sv[0 \dots i]\bigr)$ 로 정의하면:

1. $\text{dp}[0] = 1$ (길이 1인 문자열은 항상 1)
2. 길이 $i+1$인 prefix의 최소 주기가 $t$일 때:
   - 몫 $\text{quo} = \lfloor(i+1) / t\rfloor$, 나머지 $\text{rem} = (i+1) \bmod t$
   - $\text{dp}[i] = \text{dp}[t-1] \times \text{quo}$
   - 만약 $\text{rem} > 0$ 이면 $\text{dp}[i] += \text{dp}[\text{rem} - 1]$
3. 정답 = $\displaystyle\sum_{i=0}^{|sv|-1} \text{dp}[i]$

### 직관적 이해

문자열 `"ababab"` (길이 6)의 경우:
- 최소 주기 $t = 2$ (`"ab"`)
- 몫 = 3, 나머지 = 0
- $f(\text{"ababab"}) = f(\text{"ab"}) \times 3 = 2 \times 3 = 6$
  → `"a" + "b" + "a" + "b" + "a" + "b"` 처럼 6조각으로 쪼갤 수 있음

나머지가 있는 경우, 예를 들어 `"ababa"` (길이 5):
- 최소 주기 $t = 2$, 몫 = 2, 나머지 = 1
- $f(\text{"ababa"}) = f(\text{"ab"}) \times 2 + f(\text{"a"}) = 2 \times 2 + 1 = 5$

### 전체 시간 복잡도

- 쿼리당: $O(R - L + 1)$ (KMP + DP 선형)
- 전체: $O(Q \times N)$ (최악의 경우)

---

## 📎 원본 코드

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, q;
  string s;
  cin >> n >> q >> s;

  auto failure = [](string_view sv) -> vector<int> {
    vector<int> f(sv.size());
    for (int i = 1, j = 0; i < (int)sv.size(); i++) {
      while (j > 0 && sv[i] != sv[j]) j = f[j - 1];
      if (sv[i] == sv[j]) f[i] = ++j;
    }
    return f;
  };

  auto query = [&](int l, int r) -> ll {
    string_view sv(s.begin() + l - 1, s.begin() + r);
    vector<ll> dp(sv.size());
    auto F = failure(sv);
    ll res = dp[0] = 1;

    for (int i = 1; i < (int)sv.size(); i++) {
      dp[i] = 1;
      int t = i + 1 - F[i];
      int q = (i + 1) / t, r = (i + 1) % t;

      dp[i] = dp[t - 1] * q;
      if (r) dp[i] += dp[r - 1];
      res += dp[i];
    }
    return res;
  };

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << query(l, r) << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
```
