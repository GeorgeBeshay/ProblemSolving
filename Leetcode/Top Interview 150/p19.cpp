/*
 * Created By George on 6/29/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int listSize = 0;
        ListNode* tempPtr = head;

        while (tempPtr != nullptr) {
            listSize++;
            tempPtr = tempPtr->next;
        }

        ListNode* grandParent = nullptr;
        tempPtr = head;

        for (int i = 0 ; i < listSize ; i++, tempPtr = tempPtr->next) {

            if (i == listSize - n - 1) {
                grandParent = tempPtr;
            }
            else if (i == listSize - n) {
                if (grandParent != nullptr) {
                    grandParent->next = tempPtr->next;
                    break;
                } else {
                    head = tempPtr->next;
                }
            }

        }

        return head;
    }
};

int main() {

    auto* n1 = new ListNode(1);
    auto* n2 = new ListNode(2);
    auto* n3 = new ListNode(3);
    auto* n4 = new ListNode(4);
    auto* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Solution solution;
    solution.removeNthFromEnd(n1, 2);

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    return 0;
}