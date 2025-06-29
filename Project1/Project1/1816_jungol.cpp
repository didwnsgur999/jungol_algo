#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int M, S, C;
    vector<int> v;
    priority_queue<int, vector<int>, greater<int>> q;
    cin >> M >> S >> C;
    v.resize(C);
    for (int i = 0; i < C; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int first = v[0];
    int last = v[C - 1];
    //최종 길이
    int length = last - first + 1;
    if (M == 1) {
        cout << length;
        return 0;
    }
    else {
        for (int i = 1; i < C; i++) {
            int gap = v[i] - v[i - 1];
            if (q.size() < M - 1) {
                q.push(gap);
            }
            else {
                if (q.top() < gap) {
                    q.pop();
                    q.push(gap);
                }
            }
        }
    }

    while (!q.empty()) {
        length -= (q.top() - 1);
        q.pop();
    }

    cout << length;
    return 0;
}