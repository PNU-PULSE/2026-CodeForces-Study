# 🔎 Code Review — 2209E: A Trivial String Problem

> **풀이자:** 7bellaa · **접근법:** KMP Failure Function + DP
> **언어:** C++23 · **결과:** AC (1593 ms / 10752 KB)

---

## ⏱️ Complexity Analysis / 시간 및 공간 복잡도

| | 현재 코드 | 비고 |
|---|---|---|
| **시간 복잡도** | $O(Q \times N)$ | 쿼리당 $O(R-L+1)$으로 KMP + DP 수행 |
| **공간 복잡도** | 쿼리당 $O(N)$ | 매 쿼리마다 `vector<int>` + `vector<ll>` 동적 할당 |

- $Q \le 100$, $N \le 10^6$ 이므로 최악 $10^8$ 연산. 제한 시간 4초로 AC 가능하지만 빡빡합니다.
- 매 쿼리마다 `vector`를 새로 할당/해제하므로 **allocator 오버헤드**가 누적됩니다.

---

## 🚀 Better Approach / 더 나은 접근 방식

### 1. 상수 최적화 (실전에서 가장 효과적)

현재 코드에서 가장 큰 병목은 **반복적인 `vector` 동적 할당**입니다.

```diff
- auto failure = [](string_view sv) -> vector<int> {
-   vector<int> f(sv.size());           // 매번 heap 할당
-   ...
-   return f;
- };
+ // solve() 스코프에 미리 할당
+ vector<int> f(n);
+ vector<ll> dp(n);
```

`f`와 `dp`를 **`solve()` 내부에서 1회만 할당**하고, 쿼리마다 인덱스 범위만 바꿔가며 재사용하면 메모리 할당 횟수가 $Q$번 → $1$번으로 줄어들어 **상수 배 개선**됩니다.

### 2. 알고리즘적 개선 가능성

- 이 문제의 태그에 `string suffix structures`, `hashing`이 포함되어 있어, **Suffix Automaton**이나 **Hashing + Segment Tree** 기반으로 쿼리당 $O(\log N)$ 이하로 풀 수 있는 정해가 존재할 수 있습니다.
- 다만 현재 KMP + DP 풀이도 로직이 정확하고 깔끔하며, 제한 조건($Q \le 100$)에서 충분히 효율적입니다.

---

## 🔍 Review & Diagnosis / 코드 리뷰 및 진단

### ⚠️ Issue 1: 변수 섀도잉 (Variable Shadowing)

```cpp
void solve() {
  int n, q;              // ← 쿼리 개수 'q'
  // ...
  auto query = [&](int l, int r) -> ll {
    // ...
    int q = (i + 1) / t;  // ← 몫 'q' — 이름 충돌!
    int r = (i + 1) % t;  // ← 나머지 'r' — 매개변수 'r'과 충돌!
  };
}
```

**문제점:**
- 외부 스코프의 `q` (쿼리 개수)와 람다 내부의 `q` (몫)가 **같은 이름**입니다.
- 마찬가지로 람다 매개변수 `r`과 내부 변수 `r`이 충돌합니다.
- 현재는 캡처 방식(`[&]`) 덕분에 논리 오류가 발생하지 않지만, 디버깅 시 혼란을 줄 수 있고 컴파일러 경고(`-Wshadow`)가 발생합니다.

**수정:** `quo`, `rem` 등으로 변경 권장.

### ⚠️ Issue 2: 매 쿼리 vector 동적 할당

```cpp
auto failure = [](string_view sv) -> vector<int> {
  vector<int> f(sv.size());  // heap allocation
  // ...
  return f;                  // RVO 적용되더라도 할당 자체는 발생
};

auto query = [&](int l, int r) -> ll {
  vector<ll> dp(sv.size());  // 또 heap allocation
  auto F = failure(sv);      // 여기서도 할당
  // ...
};
```

- $Q$개 쿼리 × 최대 $N = 10^6$ 크기의 `vector` 2개 = 최대 200회의 대형 heap 할당.
- `std::vector`의 할당/해제 비용은 무시할 수 없으며, 특히 PS 환경에서 TLE의 주 원인이 됩니다.

### ✅ Good: `string_view` 활용

```cpp
string_view sv(s.begin() + l - 1, s.begin() + r);
```

- 부분 문자열 복사 없이 **O(1)** 로 뷰를 생성한 것은 아주 모범적인 C++17 활용입니다.

### ✅ Good: Fast I/O 적용

```cpp
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
```

- 올바르게 적용되어 있습니다. `endl` 대신 `'\n'`을 사용한 것도 좋습니다.

---

## 💡 Improved Code / 개선된 코드

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, q_cnt;
  string s;
  cin >> n >> q_cnt >> s;

  // 미리 최대 크기로 할당하여 쿼리 루프 내 동적 할당 제거
  vector<int> f(n);
  vector<ll> dp(n);

  auto query = [&](int l, int r) -> ll {
    string_view sv(s.begin() + l - 1, s.begin() + r);
    const int len = static_cast<int>(sv.size());

    // KMP Failure Function (버퍼 재사용)
    f[0] = 0;
    for (int i = 1, j = 0; i < len; i++) {
      while (j > 0 && sv[i] != sv[j]) j = f[j - 1];
      if (sv[i] == sv[j]) ++j;
      f[i] = j;
    }

    // DP 계산
    ll res = dp[0] = 1;
    for (int i = 1; i < len; i++) {
      dp[i] = 1;
      int t = i + 1 - f[i];
      int quo = (i + 1) / t;
      int rem = (i + 1) % t;

      dp[i] = dp[t - 1] * quo;
      if (rem) dp[i] += dp[rem - 1];
      res += dp[i];
    }
    return res;
  };

  while (q_cnt--) {
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

### 개선 사항 요약

| 항목 | 변경 전 | 변경 후 |
|---|---|---|
| 메모리 할당 | 쿼리마다 `vector` 2개 생성 | `solve()` 내 1회 할당, 재사용 |
| 변수명 `q`, `r` | 외부 스코프와 섀도잉 | `q_cnt`, `quo`, `rem`으로 분리 |
| `failure` 람다 | 별도 람다 + 반환 | `query` 내부로 통합 (함수 호출 오버헤드 제거) |
| `sv.size()` 캐싱 | 반복 호출 | `const int len`으로 1회 캐싱 |

---

## 📚 Core Concepts & Techniques / 핵심 개념 및 테크닉

### 🔑 KMP Pi 배열과 문자열 주기성

KMP의 Failure Array $F[i]$를 이용하면 문자열의 **최소 주기**를 $O(1)$로 구할 수 있습니다:

$$\text{period}(s[0..i]) = (i + 1) - F[i]$$

이 성질이 이 문제 DP의 핵심입니다:
- 주기 $t$로 문자열을 **반복 단위**로 분해
- 각 반복 단위에 대해 이미 계산된 $\text{dp}[t-1]$을 **재활용**
- 나머지 부분은 $\text{dp}[\text{rem}-1]$로 처리

### 💻 PS에서의 메모리 관리 팁

```cpp
// ❌ 느림: 루프 내 반복 할당
for (int q = 0; q < Q; q++) {
  vector<int> arr(N);  // 매번 heap alloc + dealloc
}

// ✅ 빠름: 루프 밖 1회 할당
vector<int> arr(N);
for (int q = 0; q < Q; q++) {
  fill(arr.begin(), arr.begin() + len, 0);  // 필요한 범위만 초기화
}
```

$N$이 $10^5$ 이상이고 반복 횟수가 많을 때, 이 차이만으로 **2~3배 속도 향상**이 가능합니다.
