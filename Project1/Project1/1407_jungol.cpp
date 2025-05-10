#include <iostream>
#include <string>
using namespace std;

int dp[41];

int main(void) {
    cin.tie(0);
    string s;
    cin >> s;
    int length = s.size();
    dp[0] = 1;
    dp[1] = 1;
    int twodigit = 0;
    if (length == 1) {
        cout << 1;
        return 0;
    }
    for (int i = 2; i <= length; i++) {
        twodigit = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
        if (s[i - 1] == '0') {
            dp[i] += dp[i - 2];
            if (twodigit < 10 || twodigit>35) {
                cout << 0;
                return 0;
            }
        }
        else {
            dp[i] += dp[i - 1];
            if (twodigit < 35 && twodigit>10)
                dp[i] += dp[i - 2];
        }
    }
    cout << dp[length];
    return 0;
}