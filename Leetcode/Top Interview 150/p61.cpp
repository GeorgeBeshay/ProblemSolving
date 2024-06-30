/*
 * Created By George on 6/30/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/rotate-list/
 * Problem Status:      Accepted.
 */

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> veci;
typedef vector<vector<int>> vveci;
typedef pair<int, int> pr;

#define ffor(i, n, j, m) for(int i = 0 ; i < n ; i++)for(int j = 0 ; j < m ; j++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_INT numeric_limits<int>::max()

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // apply k %= listSize
        int listSize = 0;

        ListNode* tempNode = head;
        while (tempNode != nullptr) {
            listSize++;
            tempNode = tempNode->next;
        }
        if (k != 0 && listSize != 0)
            k %= listSize;
        if(k == 0)
            return head;

        // now, let's fetch the parent node to remove its .next pointer to be a nullptr.
        int parentIdx = listSize - k - 1;
        int currentIdx = 0;
        tempNode = head;

        while (currentIdx < parentIdx) {
            tempNode = tempNode->next;
            currentIdx++;
        }
        if (tempNode == nullptr)
            return head;
        // also keep track of the new head of the list, to return it at the end.
        ListNode* newHead = tempNode->next;
        tempNode->next = nullptr;

        tempNode = newHead;

        while (tempNode->next != nullptr) {
            tempNode = tempNode->next;
        }
        // one thing is remaining, that is, to let the old last node to points to the old head, as if rotated.
        // 1 -> 2 -> 3 -> 4. Then when rotating with k = 1, let the old last node (4) points to the old head (1).
        // result: 4 -> 1 -> 2 -> 3
        tempNode->next = head;

        return newHead;
    }
};

int main() {



    return 0;
}