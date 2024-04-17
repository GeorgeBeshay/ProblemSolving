/*
 * Created By George on 4/17/2024.
 */

/*
 * Problem Link:        https://leetcode.com/problems/lru-cache/
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
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v, Node* prv, Node* nx) {
        key = k;
        value = v;
        prev = prv;
        next = nx;
    }

    void setPrev(Node* prv) {
        prev = prv;
    }

    void setNext(Node* nx) {
        next = nx;
    }

    void updateValue(int newVal) {
        value = newVal;
    }
};

class LRUCache {
public:
    int currentSize;
    int maxCapacity;
    Node* leftMost;
    Node* rightMost;
    map<int, Node*> keyToNodePointer;

    LRUCache(int capacity) {
        maxCapacity = capacity;
        leftMost = new Node(-1, -1, nullptr, nullptr);
        rightMost = new Node(-1, -1, nullptr, nullptr);
        leftMost->setNext(rightMost);
        rightMost->setPrev(leftMost);
        currentSize = 0;
    }

    int get(int key) {
        if (keyToNodePointer.count(key) != 0) {
            Node* node = keyToNodePointer[key];
            node->prev->next = node->next;
            node->next->prev = node->prev;

            rightMost->prev->next = node;
            node->prev = rightMost->prev;
            rightMost->prev = node;
            node->next = rightMost;

            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (keyToNodePointer.count(key) != 0) {
            get(key);
            keyToNodePointer[key]->value = value;
        } else {
            if (currentSize < maxCapacity) {
                Node* newNode = new Node(key, value, nullptr, nullptr);
                keyToNodePointer[key] = newNode;

                // update the ll
                rightMost->prev->next = newNode;
                newNode->prev = rightMost->prev;
                rightMost->prev = newNode;
                newNode->next = rightMost;

                currentSize++;
            } else {
                Node* nodeToRemove = leftMost->next;
                keyToNodePointer.erase(nodeToRemove->key);
                nodeToRemove->prev->next = nodeToRemove->next;
                nodeToRemove->next->prev = nodeToRemove->prev;
                delete nodeToRemove;

                Node* newNode = new Node(key, value, nullptr, nullptr);
                keyToNodePointer[key] = newNode;

                // update the ll
                rightMost->prev->next = newNode;
                newNode->prev = rightMost->prev;
                rightMost->prev = newNode;
                newNode->next = rightMost;
            }
        }
    }
};

//class LRUCache {
//public:
//    int currentTime;
//    int timeToRemoveAt;
//    int currentCapacity;
//    int maxCapacity;
//    map<int, int> keyToVal;
//    map<int, int> keyToTime;
//    map<int, int> timeToKey;
//
//    LRUCache(int capacity) {
//        currentTime = 0;
//        timeToRemoveAt = 0;
//        currentCapacity = 0;
//        maxCapacity = capacity;
//        timeToRemoveAt = 1;
//    }
//
//    int get(int key) {
//        int result;
//
//        currentTime++;
//
//        if (keyToVal.count(key) != 0) {
//            timeToKey.erase(keyToTime[key]);
//            keyToTime[key] = currentTime;
//            timeToKey[currentTime] = key;
//            result = keyToVal[key];
//        } else {
//            keyToVal.erase(key);
//            result = -1;
//        }
//
//        return result;
//
//        if (!check()) cout << "Something went wrong .." << endl;
//    }
//
//    void put(int key, int value) {
//        currentTime++;
//
//        if (keyToVal.count(key) != 0) {
//            keyToVal[key] = value;
//            timeToKey.erase(keyToTime[key]);
//            keyToTime[key] = currentTime;
//            timeToKey[currentTime] = key;
//        }
//        else
//        {
//            keyToVal.erase(key);
//            if (currentCapacity < maxCapacity) {
//                keyToVal[key] = value;
//                keyToTime[key] = currentTime;
//                timeToKey[currentTime] = key;
//                currentCapacity++;
//            } else {
//                // evict the LRU key
//                while (timeToKey.count(timeToRemoveAt) == 0) {
//                    timeToKey.erase(timeToRemoveAt);
//                    timeToRemoveAt++;
//                }
//                keyToVal.erase(timeToKey[timeToRemoveAt]);
//                keyToTime.erase(timeToKey[timeToRemoveAt]);
//                timeToKey.erase(timeToRemoveAt);
//                timeToRemoveAt++;
//
//                // add the new key
//                keyToVal[key] = value;
//                keyToTime[key] = currentTime;
//                timeToKey[currentTime] = key;
//            }
//        }
//
//        if (!check()) cout << "Something went wrong .." << endl;
//    }
//
//    bool check() {
//        if (keyToVal.size() > maxCapacity ||
//        keyToTime.size() > maxCapacity ||
//        timeToKey.size() > maxCapacity)
//            return false;
//        return true;
//    }
//};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {

//    LRUCache lruCache(2);
//
//    lruCache.put(1, 1);
//    lruCache.put(2, 2);
//    cout << lruCache.get(1) << endl;
//    lruCache.put(3, 3);
//    cout << lruCache.get(2) << endl;
//    lruCache.put(4, 4);
//    cout << lruCache.get(1) << endl;
//    cout << lruCache.get(3) << endl;
//    cout << lruCache.get(4) << endl;

    LRUCache lruCache(2);

    lruCache.put(1, 0);
    lruCache.put(2, 2);
    cout << lruCache.get(1) << endl;
    lruCache.put(3, 3);
    cout << lruCache.get(2) << endl;
    lruCache.put(4, 4);
    cout << lruCache.get(1) << endl;
    cout << lruCache.get(3) << endl;
    cout << lruCache.get(4) << endl;

    return 0;
}