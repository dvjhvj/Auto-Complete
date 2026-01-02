#include "universal_hash.h"
#include <random>
#include <ctime>

// Use a static random device to ensure true randomness across different nodes
static std::mt19937 rng(time(0)); 

UniversalHash::UniversalHash(int tableSize) {
    this->m = tableSize;
    this->p = 10007; // Prime larger than char range (255) [cite: 17]

    // Generate random coefficients for this specific instance [cite: 16]
    // a must be in range [1, p-1]
    std::uniform_int_distribution<int> distA(1, p - 1);
    this->a = distA(rng);

    // b must be in range [0, p-1]
    std::uniform_int_distribution<int> distB(0, p - 1);
    this->b = distB(rng);
}

int UniversalHash::hash(char key) const {
    int k = static_cast<int>(key);
    // Formula: ((a * k + b) % p) % m [cite: 18]
    return ((a * k + b) % p) % m;
}
