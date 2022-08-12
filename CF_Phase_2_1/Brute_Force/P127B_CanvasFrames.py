# Problem Link:         https://codeforces.com/problemset/problem/127/B
# Problem Status:       Accepted.
# ----------------------- SEPARATOR -----------------------
# IDEA:
#   Sort the list ascending, iterate over each element, when even 2 same integers are passed, half a frame can be made
#   increment the answer += .5
#   At the End, ONLY Whole number of frames should be printed (Ex 3.5 >> 3 Frames)
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
