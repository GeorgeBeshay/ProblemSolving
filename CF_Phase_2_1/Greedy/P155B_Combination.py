# Problem Link:             https://codeforces.com/problemset/problem/155/B
# Problem Status:           Accepted.
# ------------- Separator -------------
N = int(input())
A = []
B = []
X = []
Ans = 0
Count = 1
# Garbage = input()
while N > 0:
    A.append(0)
    B.append(0)
    X.append(list(map(int, input().split())))
    X[-1].reverse()
    # if N != 1:
    #     Garbage = input()
    N -= 1
X.sort(reverse=True)
for H in X:
    if Count == 0:
        break
    Ans += H[1]
    Count += H[0]
    Count -= 1

print(Ans)
# ------------- Separator -------------
