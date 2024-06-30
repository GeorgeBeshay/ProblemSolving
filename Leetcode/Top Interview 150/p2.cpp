/*
 * Created By George on 5/24/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/add-two-numbers/
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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto* result = new ListNode();
        ListNode* tempPointer = nullptr;
        ListNode* tempL1Pointer = nullptr;
        ListNode* tempL2Pointer = nullptr;
        bool carry = false;

        do {
            if (tempPointer == nullptr) {
                tempPointer = result;
                tempL1Pointer = l1;
                tempL2Pointer = l2;
            } else {
                tempPointer->next = new ListNode();
                tempPointer = tempPointer->next;
                tempL1Pointer =  tempL1Pointer->next;
                tempL2Pointer =  tempL2Pointer->next;
            }

            tempPointer->val = tempL1Pointer->val + tempL2Pointer->val;
            tempPointer->val += 1 * (carry ? 1 : 0);
            carry = false;
            if (tempPointer->val >= 10) {
                tempPointer->val -= 10;
                carry = true;
            }

            if (tempL1Pointer->next != nullptr && tempL2Pointer->next == nullptr)
                tempL2Pointer->next = new ListNode(0);
            if (tempL1Pointer->next == nullptr && tempL2Pointer->next != nullptr)
                tempL1Pointer->next = new ListNode(0);
        }
        while (tempL1Pointer->next != nullptr || tempL2Pointer->next != nullptr);

        if (carry)
            tempPointer->next = new ListNode(1);

        return result;
    }

};

int main() {

    Solution solution;

    auto* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    auto* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    solution.addTwoNumbers(l1, l2);

    return 0;
}