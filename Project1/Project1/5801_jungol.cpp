#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N;
    queue<int> q;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
        q.push(q.front());
        q.pop();
    }
    return 0;
}