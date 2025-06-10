#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
    string S;
    int A, B;
    while (true) {
        cin >> A;
        if (A == 0) break;
        cin >> S >> B;
        if (S == "0") {
            cout << 0 << endl;
            continue;
        }
        //A진법 -> 10진법
        long long temp = 0;
        for (int i = 0;i < S.size(); i++) {
            temp = temp * A + ((S[i] >= '0' && S[i] <= '9') ? S[i] - '0' : S[i] - 'A' + 10);
        }
        //10진법 -> B진법
        long long temp2;
        stack<int> ans;
        while (temp != 0) {
            temp2 = temp % B;
            ans.push(temp2);
            temp /= B;
        }
        while (!ans.empty()) {
            cout << (ans.top() <= 9 ? char(ans.top() + '0') : char(ans.top() - 10 + 'A'));
            ans.pop();
        }
        cout << endl;
    }

    return 0;
}