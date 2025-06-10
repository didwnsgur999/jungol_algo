#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(void) {
    int N, B;
    cin >> N >> B;
    stack<int> S;
    if (N == 0) {
        cout << 0;
        return 0;
    }
    while (N != 0) {
        int temp = N % B;
        S.push(temp);
        N /= B;
    }
    while (!S.empty()) {
        cout << (S.top() > 9 ? char(S.top() - 10 + 'A') : char(S.top() + '0'));
        S.pop();
    }
    return 0;
}