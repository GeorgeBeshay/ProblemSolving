# Problem Link:        https://codeforces.com/problemset/problem/122/B
# Problem Status:      Accepted.
# ---------------------------- SEPARATOR ----------------------------
# IDEA:
#   Iterate over the string and store all th possible substrings that satisfies the requirements.
#   Two Filtration Processes Should Be Applied To The Collected Substrings.
#   First:
#       Choose the most frequently appeared substrings.
#   Second:
#       Choose From The Final List Of Substrings Reached, The one with the least lexicographical order.
# ---------------------------- SEPARATOR ----------------------------
# Scanning The Input
Reader = input()
Container = {}
Stored = ""
# ---------------------------- SEPARATOR ----------------------------
for i in range(len(Reader)):
    if Reader[i] != '4' and Reader[i] != '7':
        Stored = ""
        continue
    else:
        Stored += Reader[i]
        if Container.get(Reader[i]) is None:
            Container.update({Reader[i]: 1})
        else:
            Container.update({Reader[i]: Container.get(Reader[i])+1})
        if Stored != Reader[i]:
            if Container.get(Stored) is None:
                Container.update({Stored: 1})
            else:
                Container.update({Stored: Container.get(Stored)+1})
# ---------------------------- SEPARATOR ----------------------------
A = []
L = 0
for X in Container.keys():
    if Container.get(X) > L:
        A.clear()
        A.append(X)
        L = Container.get(X)
    elif Container.get(X) == L:
        A.append(X)
    else:
        continue
# ---------------------------- SEPARATOR ----------------------------
A.sort()
if len(A) == 0:
    print(-1)
else:
    print(A[0])
# ---------------------------- SEPARATOR ----------------------------
