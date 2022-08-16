# Problem Link:     https://codeforces.com/problemset/problem/975/B
# Problem Status:   Accepted.
# ------------------------------ SEPARATOR ------------------------------
# IDEA:
#   Iterate over each index, taking all the positive stones in it (Make A[i] = 0)
#   Then keep distributing the stones in your hand one by one on the upcoming stones.
#   After the stones are finally distributed, now count all the even stones in each spot
#   your count is the answer if you have selected the spot A[i] to take the stones in it.
#   finally keep track of the Answer for each spot if it has been selected in array "Answer"
#   get the max Answer[i] from the array "Answer"
# ------------------------------ SEPARATOR ------------------------------
# Solving Function:
def SolvingFunctionA(B):
    Answer = []
    for H in range(14):
        Answer.append(0)
    for T in range(14):
        A = B.copy()
        Temp = A[T]
        A[T] = 0
        if Temp < 14:
            Y = T + 1
            while Temp > 0:
                Y = Y % 14
                A[Y] += 1
                Temp -= 1
                Y += 1
        else:
            L = int(Temp / 14)
            for X in range(14):
                A[X] += L
            for P in range(T+1, T+(Temp % 14)+1):
                P = P % 14
                A[P] += 1
        for K in range(14):
            if ((A[K]) % 2) == 0:
                Answer[T] += A[K]
            else:
                continue
    # print(Answer)
    Max = 0
    for U in range(14):
        if Answer[U] > Max:
            Max = Answer[U]
        else:
            continue
    return Max
# ------------------------------ SEPARATOR ------------------------------


# Scanning Input:
Reader = input().split()
Arr = []
for i in range(14):
    Arr.append(int(Reader[i]))
print(SolvingFunctionA(Arr))
# ------------------------------ SEPARATOR ------------------------------
