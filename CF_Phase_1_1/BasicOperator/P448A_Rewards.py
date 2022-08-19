# Problem Link:         https://codeforces.com/problemset/problem/448/A
# Problem Status:       Accepted.
# ------------------------------- SEPARATOR -------------------------------
import math
# ------------------------------- SEPARATOR -------------------------------
Reader = input().split()
a1 = int(Reader[0])
a2 = int(Reader[1])
a3 = int(Reader[2])
cups = a1+a2+a3
Reader = input().split()
b1 = int(Reader[0])
b2 = int(Reader[1])
b3 = int(Reader[2])
medals = b1 + b2 + b3
N = int(input())
if math.ceil(cups / 5) + math.ceil(medals / 10) <= N:
    print("YES")
else:
    print("NO")
# ------------------------------- SEPARATOR -------------------------------
