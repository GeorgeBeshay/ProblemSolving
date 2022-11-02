# Problem Link:     https://codeforces.com/problemset/problem/112/B
# Problem Status:   Accepted.
# ------------ Separator ------------
N, X, Y = list(map(int, input().split()))
if X == N / 2 and (Y == N / 2 or Y == N / 2 + 1) \
        or X == N / 2 + 1 and (Y == N / 2 or Y == N / 2 + 1):
    print("NO")
else:
    print("YES")
