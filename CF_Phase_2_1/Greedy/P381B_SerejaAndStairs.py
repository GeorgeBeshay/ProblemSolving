# Problem Link:         https://codeforces.com/problemset/problem/381/B
# Problem Status:       Accepted.
# -------------- Separator --------------
def TheAmazingFunction(Arr: list):
    Arr.sort()
    Answer = []
    Duplicate = []
    Answer.append(Arr[-1])
    for X in range(len(Arr)-2, -1, -1):
        if Arr[X] == Arr[X+1]:
            Duplicate.append(Arr[X])
        else:
            Answer.append(Arr[X])
    Duplicate = list(set(Duplicate))
    Duplicate.sort()
    index = len(Duplicate)-1
    while index >= 0 and Duplicate[index] >= Answer[0]:
        index -= 1
    if index >= 0:
        Answer = Duplicate[0: index+1] + Answer
    print(len(Answer))
    for T in Answer:
        print(T, end=" ")


# -------------- Separator --------------
N = int(input())
A = list(map(int, input().split()))
TheAmazingFunction(A)
# -------------- Separator --------------
