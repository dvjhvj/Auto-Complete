/*
FullName: NGUYEN QUOC BAO KHANG
ID Student: 24110099
Purpose: Hash_table.h
Date: Jan 2nd, 2025.
*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "universal_hash.h"
struct TrieNode;

// Bucket Node for Separate Chaining [cite: 29]
struct HashNode {
    char key;
    TrieNode* value;
    HashNode* next; 
};

class HashTable {
private:
    HashNode** buckets;      
    int capacity;            
    UniversalHash* hasher;  
    int collisionCount;      // Statistic for your report [cite: 34]

public:
    HashTable(int size = 8); 
    ~HashTable();

    // Interface required by Member B [cite: 8]
    void insert(char key, TrieNode* node);
    TrieNode* find(char key);

    // For your Security Report [cite: 54]
    int getCollisionCount();
};

#endif
