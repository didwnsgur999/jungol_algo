#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int P, N;
    cin >> P >> N;
    bool cmd;
    queue<int> q[N + 1];
    int p, m;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> cmd;
        if (cmd) {
            cin >> p;
            if (!q[p].empty()) {
                sum += q[p].front();
                q[p].pop();
            }
        }
        else {
            cin >> p >> m;
            q[p].push(m);
        }
    }
    cout << sum;
    return 0;
}