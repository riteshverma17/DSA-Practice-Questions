#include <iostream>
#include <vector>
#include <string>
using namespace std;

class DirectAddressTable {
private:
    vector<int> table;

public:
    DirectAddressTable(int n) {
        table.resize(n, -1);  
    }

    void insert(int key, int value) {
        table[key] = value;
    }

    void search(int key) {
        if (table[key] == -1) {
            cout << "NOT FOUND" << endl;
        } else {
            cout << table[key] << endl;
        }
    }

    void deleteKey(int key) {
        table[key] = -1;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    DirectAddressTable dat(n);

    for (int i = 0; i < q; ++i) {
        string query;
        cin >> query;

        if (query == "INSERT") {
            int key, value;
            cin >> key >> value;
            dat.insert(key, value);
        } else if (query == "SEARCH") {
            int key;
            cin >> key;
            dat.search(key);
        } else if (query == "DELETE") {
            int key;
            cin >> key;
            dat.deleteKey(key);
        }
    }

    return 0;
}
