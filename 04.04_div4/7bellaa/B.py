import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a = list(map(int, input().split()))
    a.sort()
    print(sum([-x for x in a]) + 2 * a[-1])