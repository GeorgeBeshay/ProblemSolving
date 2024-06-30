/*
 * Created By George on 6/30/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/partition-list/
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
    ListNode* partition(ListNode* head, int x) {
        /*
         * General Approach:
         * 1. Fetch the parent of the node that has a value greater than or equal to x. Call this pointer lastSmall
         * 2. Create another pointer that starts traversing the list and when finding a node that contains a value
         *      less than x, then remove it (let its parent point to its child) and add it as the next node of the "lastSmall"
         *      node.
         */

        // step 0, to prevent corner cases
        ListNode* dummyStartNode = new ListNode(-MAX_INT);
        dummyStartNode->next = head;
        head = dummyStartNode;

        // step 1
        ListNode* lastSmall = head;

        while (lastSmall != nullptr && lastSmall->next != nullptr && lastSmall->next->val < x) {
            lastSmall = lastSmall->next;
        }

        if (lastSmall == nullptr) {
            head = head->next;
            delete dummyStartNode;
            return head;
        }    // no nodes should be transferred, then return.

        // step 2
        ListNode* tempNode = lastSmall->next;
        while (tempNode != nullptr) {
            if (tempNode->next != nullptr && tempNode->next->val < x) {
                ListNode* tempNodeRef = lastSmall->next;
                lastSmall->next = tempNode->next;
                tempNode->next = tempNode->next->next;
                lastSmall->next->next = tempNodeRef;
                lastSmall = lastSmall->next;
            } else
                tempNode = tempNode->next;
        }

        head = head->next;
        delete dummyStartNode;

        return head;

    }
};

int main() {

    auto* n1 = new ListNode(1);
    auto* n2 = new ListNode(4);
    auto* n3 = new ListNode(3);
    auto* n4 = new ListNode(0);
    auto* n5 = new ListNode(2);
    auto* n6 = new ListNode(5);
    auto* n7 = new ListNode(2);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;

    Solution solution;
    solution.partition(n1, 3);

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
    return 0;
}