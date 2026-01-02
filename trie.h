#ifndef TRIE_H
#define TRIE_H

#include "hash_table.h"
#include <string>
#include <vector>

using namespace std;

/*
 * TrieNode represents a single character in the Trie.
 * Children are stored in a hash table (secure against hash flooding).
 */
struct TrieNode {
    bool isEnd;                         // true if this node ends a word
    HashTable<char, TrieNode*> children;

    TrieNode();
};

/*
 * Trie data structure for secure auto-complete
 */
class Trie {
private:
    TrieNode* root;

    // DFS helper function for autocomplete
    void dfs(TrieNode* node,
             string current,
             vector<string>& result);

    // Find the node corresponding to a prefix
    TrieNode* searchPrefix(const string& prefix);

public:
    Trie();

    // Insert a word into the Trie
    void insert(const string& word);

    // Return all words starting with prefix
    vector<string> autocomplete(const string& prefix);
};

#endif
