#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "universal_hash.h"

// Forward declaration of TrieNode (Member B's struct)
// We don't need the full definition here, just the name.
struct TrieNode; 

// Bucket Node for Separate Chaining [cite: 29]
struct HashNode {
    char key;
    TrieNode* value; // The child node in the Trie
    HashNode* next;  // Pointer to next entry if collision occurs
};

class HashTable {
private:
    HashNode** buckets;      // Array of pointers to HashNodes
    int capacity;            // Size of the array
    UniversalHash* hasher;   // The security component
    int collisionCount;      // Statistic for your report [cite: 34]

public:
    HashTable(int size = 8); // Default size 8 is enough for sparse nodes
    ~HashTable();

    // Interface required by Member B [cite: 8]
    void insert(char key, TrieNode* node);
    TrieNode* find(char key);

    // For your Security Report [cite: 54]
    int getCollisionCount();
};

#endif
