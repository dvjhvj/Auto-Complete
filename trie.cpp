#include "trie.h"

/*
 * TrieNode constructor
 */
TrieNode::TrieNode() {
    isEnd = false;
}

/*
 * Trie constructor
 */
Trie::Trie() {
    root = new TrieNode();
}

/*
 * Insert a word into the Trie
 * Time complexity: O(L), L = length of the word
 */
void Trie::insert(const string& word) {
    TrieNode* cur = root;

    for (char c : word) {
        if (!cur->children.contains(c)) {
            cur->children.put(c, new TrieNode());
        }
        cur = cur->children.get(c);
    }
    cur->isEnd = true;
}

/*
 * Search for the node corresponding to a prefix
 * Returns nullptr if prefix does not exist
 * Time complexity: O(L)
 */
TrieNode* Trie::searchPrefix(const string& prefix) {
    TrieNode* cur = root;

    for (char c : prefix) {
        if (!cur->children.contains(c)) {
            return nullptr;
        }
        cur = cur->children.get(c);
    }
    return cur;
}

/*
 * DFS traversal from a given Trie node
 * Collects all complete words below this node
 */
void Trie::dfs(TrieNode* node,
               string current,
               vector<string>& result) {
    if (node->isEnd) {
        result.push_back(current);
    }

    // Traverse all children
    for (auto& item : node->children.items()) {
        char nextChar = item.first;
        TrieNode* nextNode = item.second;
        dfs(nextNode, current + nextChar, result);
    }
}

/*
 * Autocomplete function
 * Returns all words that start with the given prefix
 */
vector<string> Trie::autocomplete(const string& prefix) {
    vector<string> result;
    TrieNode* node = searchPrefix(prefix);

    if (node == nullptr) {
        return result;
    }

    dfs(node, prefix, result);
    return result;
}
