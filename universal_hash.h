#ifndef UNIVERSAL_HASH_H
#define UNIVERSAL_HASH_H

class UniversalHash {
private:
    long long a; // Random coefficient
    long long b; // Random coefficient
    int p;       // Large prime number
    int m;       // Number of buckets (table size)

public:
    // Constructor: initializes random a, b based on table size m
    UniversalHash(int tableSize);

    // The hashing formula: ((ak + b) % p) % m
    int hash(char key) const;
};

#endif
