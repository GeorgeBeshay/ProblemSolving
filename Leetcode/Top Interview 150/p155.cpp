/*
 * Created By George on 6/27/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/min-stack/
 * Problem Status:      Accepted
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
#define MIN_INT numeric_limits<int>::min()

class StackNode {
public:
    StackNode() {
        val = MIN_INT;
        correspondingMinVal = MIN_INT;
        nextNode = nullptr;
        prevNode = nullptr;
    }

    explicit StackNode(int tempVal) {
        val = tempVal;
        correspondingMinVal = tempVal;
        nextNode = nullptr;
        prevNode = nullptr;
    }

    int val;
    int correspondingMinVal;
    StackNode* nextNode;
    StackNode* prevNode;
};

class MinStack {
public:
    MinStack() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int val) {
        if (tail == nullptr) {
            head = new StackNode(val);
            head->prevNode = nullptr;
            tail = head;
        } else {
            tail->nextNode = new StackNode(val);
            tail->nextNode->prevNode = tail;
            tail->nextNode->correspondingMinVal = min (tail->correspondingMinVal, tail->nextNode->val);
            tail = tail->nextNode;
        }
    }

    void pop() {
        if (tail == nullptr)
            throw EXIT_FAILURE;
        tail = tail->prevNode;
    }

    int top() {
        return tail->val;
    }

    int getMin() {
        return tail->correspondingMinVal;
    }

private:
    StackNode* head;
    StackNode* tail;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {

    auto* minStack = new MinStack();

    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);

    cout << minStack->getMin() << endl;

    minStack->pop();

    cout << minStack->top() << endl;
    cout << minStack->getMin() << endl;

    free(minStack);

    return 0;
}