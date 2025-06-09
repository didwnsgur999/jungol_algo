#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    stack<int> S;
    int N;
    cin >> N;
    char op;
    for (int i = 0; i < N; i++) {
        cin >> op;
        if (op == 'i') {
            int a;
            cin >> a;
            S.push(a);
        }
        else if (op == 'o') {
            if (S.empty()) {
                cout << "empty" << endl;
            }
            else {
                cout << S.top() << endl;
                S.pop();
            }
        }
        else if (op == 'c') {
            cout << S.size() << endl;
        }
    }
    return 0;
}