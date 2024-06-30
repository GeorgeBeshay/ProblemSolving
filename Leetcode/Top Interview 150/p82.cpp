/*
 * Created By George on 6/29/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* lastNode = nullptr;
        ListNode* currentNode = head;
        ListNode* newHead = nullptr;
        int tempVal = MAX_INT;

        while (currentNode != nullptr) {

            while (currentNode != nullptr && (currentNode->val == tempVal ||
            (currentNode->next != nullptr && currentNode->next->val == currentNode->val))) {
                tempVal = currentNode->val;
                currentNode = currentNode->next;
            }
            tempVal = MAX_INT;
            if (currentNode == nullptr)
                break;

            if (lastNode == nullptr) {
                newHead = new ListNode(currentNode->val);
                lastNode = newHead;
            } else {
                lastNode->next = new ListNode(currentNode->val);
                lastNode = lastNode->next;
            }

            currentNode = currentNode->next;
        }

        return newHead;
    }
};

int main() {

}