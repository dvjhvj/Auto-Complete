#ifndef TRIE_H
#define TRIE_H

#include "hash_table.h"
#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    bool isEnd;
    HashTable children;
    vector<char> childrenKeys; // để DFS

    TrieNode();
};

class Trie {
private:
    TrieNode* root;

    void dfs(TrieNode* node, string current, vector<string>& result);

    TrieNode* searchPrefix(const string& prefix);

public:
    Trie();
    ~Trie();

    void insert(const string& word);
    vector<string> autocomplete(const string& prefix);
};

#endif
