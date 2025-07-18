#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);

    map<int, int> m;
    int Q;
    cin >> Q;
    char op;
    int temp;
    for (int i = 0; i < Q; i++) {
        cin >> op;
        if (op == 'f') {
            cin >> temp;
            if (m.find(temp) != m.end()) {
                cout << "YES " << m[temp] << "\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else if (op == 'a') {
            cin >> temp;
            m[temp]++;
        }
        else {
            cout << m.size() << "\n";
        }
    }

    return 0;
}