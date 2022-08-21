# Problem Link:     https://codeforces.com/problemset/problem/651/B
# Problem Status:   Accepted.
# ------------------------------- SEPARATOR -------------------------------
# IDEA:
#   Sort The Given List, Scan For The Repeated Integers, Copy Them To A New List
#   Iterate over the new list selecting only the 1 element from the repeated elements.
#   For example from [1,1,1,2,2,2,3,3,3] select [1,2,3], and remove them >> [1,1,2,2,3,3]
#   So A Set will be used for this purpose.
#   Add The set to the end of the Primary List, Empty it, Repeat
# ------------------------------- SEPARATOR -------------------------------
A = []
Repeated = []
RepeatedPro = set()
RepeatedNew = []
StartFlag = True
Answer = 0
# ------------------------------- SEPARATOR -------------------------------
Line = input()
N = int(Line)
# ------------------------------- SEPARATOR -------------------------------
Line = input().split()
for x in Line:
    A.append(int(x))
A.sort()
# ------------------------------- SEPARATOR -------------------------------
for i in range(1, len(A)):
    if A[i] == A[i-1]:
        Repeated.append(A[i])
# ------------------------------- SEPARATOR -------------------------------
Repeated.sort()
# ------------------------------- SEPARATOR -------------------------------
while len(RepeatedPro) > 0 or StartFlag:
    StartFlag = False
    RPL = list(RepeatedPro)
    RPL.sort()
    A += RPL
    RepeatedPro.clear()
    for i in range(len(Repeated)):
        temp1 = len(RepeatedPro)
        RepeatedPro.add(Repeated[i])
        if len(RepeatedPro) > temp1:
            continue
        else:
            RepeatedNew.append(Repeated[i])
    Repeated = RepeatedNew.copy()
    RepeatedNew.clear()
# ------------------------------- SEPARATOR -------------------------------
for i in range(1, len(A)):
    if A[i] > A[i-1]:
        Answer += 1
print(Answer)
# ------------------------------- SEPARATOR -------------------------------
