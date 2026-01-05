#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include "trie.h"

using namespace std;

string tolowerString(const string& st) {
    string result = "";
    for (char c : st) {
        if (isalpha(c)) result += tolower(c);
    }
    return result;
}

void loadDictionary(const string& filename, Trie& trie) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Error: Cannot open dictionary file." << endl;
        return;
    }

    string tmp;
    int count = 0;
    while (fin >> tmp) {
        string word = tolowerString(tmp);
        if (!word.empty()) {
            trie.insert(word);
            count++;
        }
    }
    fin.close();
    cout << "Uploaded successfully " << count << " words into the system." << endl;
}

int main() {
    Trie trie;

    loadDictionary("dictionary.txt", trie);
    cout << "Dictionary loaded successfully." << endl;

    while (true) {
        cout << "===== Secure Auto-Complete System =====" << endl;
        cout << "1. Search" << endl;
        cout << "0. Exit" << endl;
        cout << "Pick a number: ";

        int choice;
        cin >> choice;

        if (choice < 0 || choice > 1) {
            cout << "Invalid choice. Please try again!" << endl;
            continue;
        }

        if (!cin) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); 
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 0) {
            cout << "Goodbye and have a nice day!" << endl;
            break;
        }
        else {
            string rawPrefix;
            cout << "Type the start of the word: ";
            cin >> rawPrefix;

            string prefix;
            for (char c : rawPrefix) {
                prefix += tolower(c);
            }

            vector<string> suggestions = trie.autocomplete(prefix);

            if (suggestions.empty()) {
                cout << "Found nothing! That word is too obscure for me." << endl;
            } else {
                cout << "Suggestions:" << endl;
                int limit = min(7, (int)suggestions.size());
                for (int i = 0; i < limit; i++) {
                    cout << "  " << suggestions[i] << "" << endl;
                }
            }
            cout << "-----------------------------" << endl;
            }
    }
    return 0;
}
