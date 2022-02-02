/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
struct Node
{
    char letter;
    bool end;
    vector<Node *> vec;
    Node(): letter(' '), end(false), vec(26, nullptr) {}
    Node(char l): letter(l), end(false), vec(26, nullptr) {}
};
class Trie
{
public:
    Node *root;
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (node->vec[word[i] - 'a'])
                node = node->vec[word[i] - 'a'];
            else {
                Node *tmp = new Node(word[i]);
                node->vec[word[i] - 'a'] = tmp;
                node = tmp;
            }
        }
        node->end = true;
    }
    
    bool search(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (!node->vec[word[i] - 'a'])
                return false;
            node = node->vec[word[i] - 'a'];
        }
        return node->end;
    }

    bool startsWith(string prefix) {
        Node *node = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            if (!node->vec[prefix[i] - 'a'])
                return false;
            node = node->vec[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

