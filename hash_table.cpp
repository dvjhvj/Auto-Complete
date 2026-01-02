#include "hash_table.h"
#include <cstddef> // for NULL/nullptr

HashTable::HashTable(int size) {
    this->capacity = size;
    this->collisionCount = 0;
    
    // Create the secure hasher for this specific table
    this->hasher = new UniversalHash(capacity);

    // Initialize buckets to nullptr
    this->buckets = new HashNode*[capacity];
    for (int i = 0; i < capacity; i++) {
        buckets[i] = nullptr;
    }
}

HashTable::~HashTable() {
    // Clean up all nodes
    for (int i = 0; i < capacity; i++) {
        HashNode* entry = buckets[i];
        while (entry != nullptr) {
            HashNode* prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
    delete[] buckets;
    delete hasher;
}

void HashTable::insert(char key, TrieNode* node) { // [cite: 31]
    int index = hasher->hash(key);
    
    HashNode* entry = buckets[index];
    
    // Check if bucket is empty
    if (entry == nullptr) {
        buckets[index] = new HashNode{key, node, nullptr};
        return;
    }

    // Bucket not empty -> Collision or Update
    HashNode* prev = nullptr;
    while (entry != nullptr) {
        if (entry->key == key) {
            entry->value = node; // Update existing key
            return;
        }
        prev = entry;
        entry = entry->next;
    }

    // Key not found in chain, append new node (Collision handled)
    prev->next = new HashNode{key, node, nullptr};
    this->collisionCount++; // Track for report [cite: 34]
}

TrieNode* HashTable::find(char key) { // [cite: 32]
    int index = hasher->hash(key);
    HashNode* entry = buckets[index];

    while (entry != nullptr) {
        if (entry->key == key) {
            return entry->value;
        }
        entry = entry->next;
    }
    return nullptr;
}

int HashTable::getCollisionCount() {
    return this->collisionCount;
}
