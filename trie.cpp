#include "trie.h"

#define BUCKET_SIZE 53

TrieNode::TrieNode() : isEnd(false), children(BUCKET_SIZE) {}

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const string& word) {
    TrieNode* cur = root;

    for (char c : word) {
        TrieNode* next = cur->children.find(c);
        if (next == nullptr) {
            next = new TrieNode();
            cur->children.insert(c, next);
            cur->childrenKeys.push_back(c);
        }
        cur = next;
    }
    cur->isEnd = true;
}

TrieNode* Trie::searchPrefix(const string& prefix) {
    TrieNode* cur = root;

    for (char c : prefix) {
        cur = cur->children.find(c);
        if (cur == nullptr) return nullptr;
    }
    return cur;
}

void Trie::dfs(TrieNode* node, string current, vector<string>& result) {
    if (node->isEnd) {
        result.push_back(current);
    }

    for (char c : node->childrenKeys) {
        TrieNode* next = node->children.find(c);
        if (next != nullptr) {
            dfs(next, current + c, result);
        }
    }
}

vector<string> Trie::autocomplete(const string& prefix) {
    vector<string> result;
    TrieNode* node = searchPrefix(prefix);

    if (node == nullptr) return result;

    dfs(node, prefix, result);
    return result;
}

Trie::~Trie() {
    if (root != nullptr) {
        delete root; 
    }
}
    // quy trình hủy:
    // 1. delete root -> gọi ~TrieNode()
    // 2. ~TrieNode() -> tự động gọi ~HashTable() của biến thành viên 'children'
    // 3. ~HashTable() -> chạy vòng lặp delete các HashNode
    // 4. delete HashNode->value (là TrieNode con) -> Quay lại bước 1 với node con

