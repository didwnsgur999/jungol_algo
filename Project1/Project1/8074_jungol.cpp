#include <queue>
#include <iostream>

using namespace std;
struct Data {
    int x, y, z;
};

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    queue<Data> q;
    int n;
    cin >> n;
    char ops;
    int chtemp;
    Data temp;
    int x, y, z;
    for (int i = 0; i < n; i++) {
        cin >> ops;
        if (ops == 'i') {
            cin >> temp.x >> temp.y >> temp.z;
            q.push(temp);
        }
        else if (ops == 'o') {
            if (!q.empty()) {
                temp = q.front();
                cout << temp.x << " " << temp.y << " " << temp.z << "\n";
                q.pop();
            }
            else {
                cout << "empty\n";
            }
        }
        else if (ops == 'c') {
            cout << q.size() << "\n";
        }
        else if (ops == 'z') {
            cin >> chtemp;
            if (!q.empty()) {
                if (chtemp == q.front().z)
                    cout << "yes\n";
                else
                    cout << "no\n";
            }
            else
                cout << "no\n";
        }
    }
    return 0;
}