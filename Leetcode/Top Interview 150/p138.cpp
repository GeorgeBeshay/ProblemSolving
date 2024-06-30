/*
 * Created By George on 6/29/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/copy-list-with-random-pointer/
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

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        Node* newHead;
        map<Node*, Node*> mapper;

        Node* tempOldPtr = head;
        Node* tempNewPtr = nullptr;

        while (tempOldPtr != nullptr) {

            if (tempNewPtr == nullptr) {
                newHead = new Node(tempOldPtr->val);
                tempNewPtr = newHead;
            } else {
                tempNewPtr->next = new Node(tempOldPtr->val);
                tempNewPtr = tempNewPtr->next;
            }
            mapper[tempOldPtr] = tempNewPtr;

            tempOldPtr = tempOldPtr->next;
        }

        tempOldPtr = head;
        tempNewPtr = newHead;
        while(tempOldPtr != nullptr) {
            if (mapper.count(tempOldPtr->random) > 0)
                tempNewPtr->random = mapper[tempOldPtr->random];
            tempOldPtr = tempOldPtr->next;
            tempNewPtr = tempNewPtr->next;
        }

        return newHead;
    }
};

int main() {

    // [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    Solution solution;
    solution.copyRandomList(nullptr);

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    return 0;
}