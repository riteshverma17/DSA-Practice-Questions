#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
private:
    int size;
    vector<list<int>> table; // For CHAINING method
    vector<int> openTable;   // For OPEN_ADDRESSING method
    string method;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int m, string method) {
        this->size = m;
        this->method = method;

        if (method == "CHAINING") {
            table.resize(size);
        } else {
            openTable.resize(size, -1); // -1 indicates empty slot
        }
    }

    void insert(int key) {
        int idx = hashFunction(key);
        if (method == "CHAINING") {
            table[idx].push_back(key);
        } else {
            while (openTable[idx] != -1) {
                idx = (idx + 1) % size;
            }
            openTable[idx] = key;
        }
    }

    string search(int key) {
        int idx = hashFunction(key);
        if (method == "CHAINING") {
            for (int item : table[idx]) {
                if (item == key) {
                    return "FOUND";
                }
            }
            return "NOT FOUND";
        } else {
            int startIdx = idx;
            while (openTable[idx] != -1) {
                if (openTable[idx] == key) {
                    return "FOUND";
                }
                idx = (idx + 1) % size;
                if (idx == startIdx) {
                    break;
                }
            }
            return "NOT FOUND";
        }
    }

    void remove(int key) {
        int idx = hashFunction(key);
        if (method == "CHAINING") {
            table[idx].remove(key);
        } else {
            int startIdx = idx;
            while (openTable[idx] != -1) {
                if (openTable[idx] == key) {
                    openTable[idx] = -1;
                    return;
                }
                idx = (idx + 1) % size;
                if (idx == startIdx) {
                    break;
                }
            }
        }
    }
};

int main() {
    int m;
    string method;
    int q;
    cin >> m >> method >> q;

    HashTable hashTable(m, method);

    while (q--) {
        string operation;
        int key;
        cin >> operation >> key;

        if (operation == "INSERT") {
            hashTable.insert(key);
        } else if (operation == "SEARCH") {
            cout << hashTable.search(key) << endl;
        } else if (operation == "DELETE") {
            hashTable.remove(key);
        }
    }

    return 0;
}
