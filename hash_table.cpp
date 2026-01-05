/*
FullName: NGUYEN QUOC BAO KHANG
ID Student: 24110099
Purpose: Hash_table
Date: Jan 2nd, 2025.
*/

#include "hash_table.h"
#include <cstddef> // for NULL/nullptr

HashTable::HashTable(int size) {
    this->capacity = size;
    this->collisionCount = 0;

    // Create the secure hasher for this specific table
    this->hasher = new UniversalHash(capacity);

    // Initialize buckets to nullptr
    this->buckets = new HashNode * [capacity];
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

void HashTable::insert(char key, TrieNode* node) {
    int index = hasher->hash(key);

    HashNode* entry = buckets[index];

    // Check if bucket is empty
    if (entry == nullptr) {
        buckets[index] = new HashNode{ key, node, nullptr};
        return;
    }

    // Bucket not empty
    HashNode* prev = nullptr;
    while (entry != nullptr) {
        if (entry->key == key) {
            entry->value = node;
            return;
        }
        prev = entry;
        entry = entry->next;
    }

    // Key not found in chain, append new node
    prev->next = new HashNode{ key, node, nullptr };
    this->collisionCount++;
}

TrieNode* HashTable::find(char key) { 
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
