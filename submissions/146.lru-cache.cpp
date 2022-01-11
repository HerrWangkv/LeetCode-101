/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <unordered_map>
using namespace std;
struct LinkedNode {
    int key, value;
    LinkedNode *prev;
    LinkedNode *next;
    LinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    LinkedNode(int _key, int _val) : key(_key), value(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
public:
    unordered_map<int, LinkedNode*> dict;
    LinkedNode *head;
    LinkedNode *tail;
    int size;
    int capacity;
    LRUCache(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        this->head = new LinkedNode();
        this->tail = new LinkedNode();
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }

    int get(int key) {
        if (!this->dict.count(key))
            return -1;
        LinkedNode *node = this->dict[key];
        removeNode(node);
        AddtoHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (this->dict.count(key)) {
            LinkedNode *node = this->dict[key];
            node->value = value;
            removeNode(node);
            AddtoHead(node);
            return;
        }
        LinkedNode *node = new LinkedNode(key, value);
        AddtoHead(node);
        this->dict[key] = node;
        if (this->size > this->capacity)
        {
            this->dict.erase(this->tail->prev->key);
            // 防止内存泄漏
            delete removeNode(this->tail->prev);
        }
    }
    LinkedNode* removeNode(LinkedNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = nullptr;
        node->next = nullptr;
        --this->size;
        return node;
    }
    void AddtoHead(LinkedNode *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        ++this->size;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

