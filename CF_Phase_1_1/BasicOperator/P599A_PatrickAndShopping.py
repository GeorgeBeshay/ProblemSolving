# Problem Link:     https://codeforces.com/problemset/problem/599/A
# Problem Status:   Accepted.
# ------------- Separator -------------
A, B, C = list(map(int, input().split()))
Ans = 0
if A <= B + C:
    Ans += A
    if B <= A + C:
        Ans += B
    else:
        Ans += A + C
    if A + B <= C:
        Ans += A + B
    else:
        Ans += C
else:
    Ans += 2 * (B+C)
print(Ans)
# ------------- Separator -------------
