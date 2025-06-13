#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int main(void) {
    int N, h;
    stack<int> S;
    cin >> N;
    S.push(1000000001);//base
    long long cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> h;
        while (S.top() <= h) {
            S.pop();
        }
        cnt += S.size() - 1;
        S.push(h);
    }
    cout << cnt;
}