/*
 * Created By George on 4/13/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/reverse-linked-list-ii/?envType=study-plan-v2&envId=top-interview-150
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* newNode = nullptr;
        ListNode* currentNode = nullptr;
        stack<int> st;
        int currentIdx = 1;

        while (head != nullptr) {
            if (currentIdx >= left && currentIdx <= right) {
                st.push(head->val);
                if (currentIdx == right) {
                    while (!st.empty()) {
                        if (currentNode == nullptr) {
                            newNode = new ListNode(st.top());
                            currentNode = newNode;
                            st.pop();
                        }
                        else {
                            currentNode->next = new ListNode(st.top());
                            currentNode = currentNode->next;
                            st.pop();
                        }
                    }
                }
            }
            else {
                if (currentNode == nullptr) {
                    newNode = new ListNode(head->val);
                    currentNode = newNode;
                }
                else {
                    currentNode->next = new ListNode(head->val);
                    currentNode = currentNode->next;
                }
            }
            currentIdx++;
            head = head->next;
        }

        return newNode;
    }
};

int main() {

    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* ans = solution.reverseBetween(head, 2, 4);

    while (ans != nullptr) {
        cout << ans->val << endl;
        ans = ans->next;
    }

    free(head);
    return 0;
}