#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "trie.h"

using namespace std;

/*
 * Load dictionary from a text file and insert words into the Trie
 */
void loadDictionary(const string& filename, Trie& trie) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Error: Cannot open dictionary file.\n";
        return;
    }

    string word;
    while (fin >> word) {
        trie.insert(word);
    }

    fin.close();
}

/*
 * Simple terminal-based auto-complete system
 */
int main() {
    Trie trie;

    // ====== Build Phase ======
    cout << "Loading dictionary...\n";
    loadDictionary("dictionary.txt", trie);
    cout << "Dictionary loaded successfully.\n\n";

    // ====== Query Phase ======
    cout << "Secure Auto-Complete System\n";
    cout << "Type a prefix (type 'exit' to quit)\n\n";

    while (true) {
        string prefix;
        cout << "Enter prefix: ";
        cin >> prefix;

        if (prefix == "exit") {
            cout << "Exiting program.\n";
            break;
        }

        vector<string> suggestions = trie.autocomplete(prefix);

        if (suggestions.empty()) {
            cout << "No suggestions found.\n";
        } else {
            cout << "Suggestions:\n";
            for (const string& s : suggestions) {
                cout << "  " << s << "\n";
            }
        }

        cout << "-----------------------------\n";
    }

    return 0;
}
