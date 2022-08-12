# Problem Link:         https://codeforces.com/problemset/problem/127/B
# Problem Status:       Accepted.
# ----------------------- SEPARATOR -----------------------
# Scanning The Input
uselessLine = input()
Reader = input()
ArrayOfLengths = []
for X in Reader.split():
    ArrayOfLengths.append(int(X))
# ----------------------- SEPARATOR -----------------------
ArrayOfLengths.sort()
count = 1
Answer = 0.0
for i in range(1, len(ArrayOfLengths)):
    if ArrayOfLengths[i] == ArrayOfLengths[i-1]:
        count += 1
    else:
        count = 1
    if count == 2:
        Answer += 0.5
        count = 0
# ----------------------- SEPARATOR -----------------------
print(Answer.__trunc__())
# ----------------------- SEPARATOR -----------------------
