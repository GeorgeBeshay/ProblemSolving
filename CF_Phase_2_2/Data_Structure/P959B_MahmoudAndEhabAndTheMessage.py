# Problem Link:         https://codeforces.com/problemset/problem/959/B
# Problem Status:       Accepted.
# -------------------------- SEPARATOR --------------------------
# IDEA:
#   Create And Store a list of the groups given, SORTING each of them.
#   For each word store the index of its corresponding group in a hashTable (dict)
#   Finally iterating over each word in the required message, getting its corresponding group index from the dict
#   then getting the least value in this group which will be in index Groups[X][0], because we have sorted it.
# -------------------------- SEPARATOR --------------------------
N, K, M = list(map(int, input().split()))
Lang = input().split()
Values = list(map(int, input().split()))
Table = dict()
Groups = []
GroupsPointers = dict()
Answer = 0
# -------------------------- SEPARATOR --------------------------
for i in range(N):
    Table.update({Lang[i]: Values[i]})
for i in range(K):
    Text = list(map(int, input().split()))
    Groups.append([])
    for j in range(1, Text[0]+1):
        Groups[-1].append(Table.get(Lang[Text[j]-1]))
        GroupsPointers.update({Lang[Text[j]-1]: len(Groups)-1})
    Groups[-1].sort()
Message = input().split()
# -------------------------- SEPARATOR --------------------------
for i in range(M):
    Answer += Groups[GroupsPointers.get(str(Message[i]))][0]
# -------------------------- SEPARATOR --------------------------
print(Answer)
# -------------------------- SEPARATOR --------------------------
