# Problem Link:         https://codeforces.com/problemset/problem/879/B
# Problem Status:       Accepted.
# ------------------------------------ SEPARATOR ------------------------------------
# IDEA:
#   You will notice that if K is greater than or equal number of teams - 1, then certainly the winner will be the
#   strongest player among them.
#   If K < N, then you can keep tracking the winner player, you won't face a time limit error, as the number of players
#   range from 2 to 500, so no need to worry about time limit.
# ------------------------------------ SEPARATOR ------------------------------------
# Scanning Input
N, K = list(map(int, input().split()))
A = list(map(int, input().split()))
# ------------------------------------ SEPARATOR ------------------------------------
Answer = 0
if K >= (N-1):
    A.sort()
    Answer = A[-1]
else:
    Answer = A[0]
    NumberOfWins = 0
    for i in range(1, N):
        if A[i] > Answer:
            Answer = A[i]
            NumberOfWins = 1
        else:
            NumberOfWins += 1
        if NumberOfWins == K:
            break
print(Answer)
# ------------------------------------ SEPARATOR ------------------------------------
