#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    stack<pair<int, int>> S;
    vector<int> V;
    int N;
    cin >> N;
    V.resize(N);
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;int flag = 0;
        //낮은 빌딩이 뒤에 있으면, V에 넣고 제거.
        while (!S.empty()) {
            if (S.top().first >= temp) {
                break;
            }
            V[S.top().second] = i + 1;
            S.pop();
        }
        S.push({ temp,i });
    }
    for (auto i : V)
        cout << i << endl;
    return 0;
}