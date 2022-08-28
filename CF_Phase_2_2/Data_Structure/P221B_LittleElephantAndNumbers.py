# Problem Link:         https://codeforces.com/contest/221/problem/B
# Problem Status:       Accepted.
# ----------------------------- Imports -----------------------------
import math


# ----------------------------- IDEA -----------------------------
# The Primary Idea is to use set in all of your calculations
# To be able to minimize the number of characters in the main num
# and the divisor.
# Also Number Theory Would help you to get the divisors of a number
# in O(sqrt(n)) not O(n) which makes really a huge difference in the
# code efficiency.
# ----------------------------- Functions -----------------------------
def TheAmazingFunction(X):
    Answer = 0
    DivisorsList = set()
    table = dict()
    NumbersInX = []
    stringX = str(X)
    # ---------------------------- SEPARATOR ----------------------------
    for i in range(1, int(math.sqrt(X))+1):
        if X % i == 0:
            s = len(DivisorsList)
            DivisorsList.add(RemoveRepeatsInNumber(i))
            if s == len(DivisorsList):
                if table.get(RemoveRepeatsInNumber(i)) is None:
                    table.update({RemoveRepeatsInNumber(i): 2})
                else:
                    table.update({RemoveRepeatsInNumber(i): table.get(RemoveRepeatsInNumber(i))+1})
            if i != X // i:
                s = len(DivisorsList)
                DivisorsList.add(RemoveRepeatsInNumber(X // i))
                if s == len(DivisorsList):
                    if table.get(RemoveRepeatsInNumber(X // i)) is None:
                        table.update({RemoveRepeatsInNumber(X // i): 2})
                    else:
                        table.update({RemoveRepeatsInNumber(X // i): table.get(RemoveRepeatsInNumber(X // i))+1})
    # ---------------------------- SEPARATOR ----------------------------
    for i in range(10):
        if stringX.__contains__(str(i)):
            NumbersInX.append(i)
    NumbersInX = str(NumbersInX).removeprefix("[").removesuffix("]").replace(", ", "")
    # ---------------------------- SEPARATOR ----------------------------
    for i in range(len(DivisorsList)):
        tempString = DivisorsList.pop()
        tempSet = set(tempString)
        sizeA = len(tempSet)
        tempSet.update(NumbersInX)
        if len(tempSet) < sizeA+len(NumbersInX):
            if table.get(tempString) is None:
                Answer += 1
            else:
                Answer += table.get(tempString)
    # ---------------------------- SEPARATOR ----------------------------
    return Answer


def RemoveRepeatsInNumber(A):
    A_ = set()
    Answer = []
    for i in range(len(str(A))):
        A_.add(str(A)[i])
    for i in range(len(A_)):
        Answer.append(int(A_.pop()))
    Answer.sort()
    return Answer.__str__().removeprefix("[").removesuffix("]").replace(", ", "")


# ----------------------------- Driver Code -----------------------------
X_ = int(input())
print(TheAmazingFunction(X_))
# ----------------------------- SEPARATOR -----------------------------
